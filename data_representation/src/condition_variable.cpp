#include <iostream>
#include <vector>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>

class player{
public:
    //entry of thread for receiving message
    void inMsgRecvQueue()
    {
        for(int i = 0; i < 100; ++i)
        {
            std::unique_lock<std::mutex> lck(my_mutex);
            std::cout<<"MSG received: "<<i<<std::endl;
            msgRecvQueue.push_back(i);
            cond_lck.notify_one(); //wait(), call cond_lck.
        }
    }
    
    bool outMsgCheck(int &command)
    {
        while(true){
            std::unique_lock<std::mutex> lck(my_mutex);
            //If pred is specified (2), the function only blocks if pred returns false, 
            //and notifications can only unblock the thread when it becomes true (which is specially useful to check against spurious wake-up calls). 
            //This version (2) behaves as if implemented as:
            //while (!pred()) wait(lck);
            cond_lck.wait(lck,[this]{
                if(!msgRecvQueue.empty())
                    return true;
                return false;
            }
            );
            command = msgRecvQueue.front();
            msgRecvQueue.pop_front();
            lck.unlock(); //unlock in advance
            std::cout<<"message out is: "<<command<<std::endl;
        }
    }

    //entry of thread for sending message
    void outMsgRecvQueue()
    {
        int command = -1;
        for(int i = 0; i < 100; ++i)
        {
            bool result = outMsgCheck(command);
            if(result == true)
            {
                std::cout<<"outMsg executed, "<<command<<std::endl;
            }
            else
            {
                std::cout<<"outMsgRecvQueue is empty: "<<i<<std::endl;
            }
        }
        std::cout<<"end front value is: "<<command<<std::endl;
    }

private:
    std::list<int> msgRecvQueue; //message sent by player
    std::mutex my_mutex;
    std::condition_variable cond_lck;
};


int main(int, char**) {
    player user;
    std::thread myOutMsgObj(&player::outMsgRecvQueue, &user); //pass by reference
    std::thread myInMsgObj(&player::inMsgRecvQueue, &user);

    myOutMsgObj.join();
    myInMsgObj.join();


    //myobj.join();
    std::cout << "main thread is finished\n";
}

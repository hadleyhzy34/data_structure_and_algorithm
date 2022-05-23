#include <iostream>
#include <vector>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>

//reference: https://en.cppreference.com/w/cpp/thread/condition_variable/wait
//reference: https://www.cplusplus.com/reference/condition_variable/condition_variable/wait/
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id){
    std::unique_lock<std::mutex> lck(mtx);
    while(!ready){
        std::cout<<"thread "<<id<<" is already being started in the while loop\n";
        //Atomically unlocks lock, blocks the current executing thread, and adds it to the list of threads waiting on *this. 
        //The thread will be unblocked when notify_all() or notify_one() is executed. 
        //It may also be unblocked spuriously. When unblocked, regardless of the reason, lock is reacquired and wait exits.
        cv.wait(lck);
        std::cout<<"thread: "<<id<<" is being processed\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    //...
    std::cout<<"thread "<<id<<'\n';
}

void go(){
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all(); //notify one condition_variable at a time, make sure all waited condition_variable have been called
}

void go_one(){
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_one(); //notify only one of waited thread in the thread waiting list
}

int main(){
    std::thread threads[10];
    for(int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_id, i);
    
    std::cout<<"10 threads ready to race ... \n";
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //go_one();
    go();
    for(auto &thread:threads) thread.join();

    return 0;
}

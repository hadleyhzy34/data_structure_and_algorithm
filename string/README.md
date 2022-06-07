# sharing data between threads

## Notes

The arguments to the thread function are moved or copied by value. If a reference argument needs to be passed to the thread function, it has to be wrapped(eg., with std::ref or std::cref).

## Protecting shared data with mutexes

Key idea: If you could mark all the pieces of code that acces thae data structure as mutually exclusive, so that if any thread was running one of them, any other thread that tried to access that data structure had to wait until the first thread was finished. 

In C++ mutex is created by constructing an instance of std::mutex, lock it with a call to the `lock()` member function and unlock it with a call to the `unlock()` member function. But it isn't recommended practice to call the member functions directly, because this means that you have to remember to call `unlock()` on every code path out of a function.

Instead, the standard C++ Library prodives the `std::lock_guard` class template, it locks the supplied mutex on construction and unlocks it on destruction.

```
std::mutex some_mutex;

void func(){
    std::lock_guard<std::mutex> guard(some_mutex);
    //...
    //all data members will be locked here until guard is destructed
    //...
}
```



## thread

### concept

Once the program is started, a new process is started, and main thread that belongs to this process is automatically started.

main thread is started from begining of `main()` this part, other generated threads would also need a function to get it started, and that function os called init function.

When this function running process is ended, our new generated process will also be called ended.

The signal that this process has been executed and finished is whether main thread is finished or not. If main thread is finished, then the whole process is finished.

### issue

what if main thread finished while child threads not finished, normally child processes will be forcely ended. In general, if you want to keep child threads in running status,
then it would normally need to keep main thread also in running status.(there's exception for it)

### implementation

1.include thread process

```
#include <thread>
```

2.create a new thread function

```
void myprint();
```

3.main thread declration and execution

```
std::thread obj(myprint);
```

## join

### concept

`join` is to block main thread. Main thread waited until child threads executed and finished.

### implementation

```
obj.join();
```

### issue

* what if we comment `obj.join()`?

```
main thread is running 
terminate called without an active exception
Aborted (core dumped)
```

analysis: child thread is not finished while main thread is in exist status


## detach

### concept

`detach` child thread from main thread, main thread does not need to wait until child thread is finished to get itself restarted.

Once child thread is `detached`, connection between main thread and child thread is lost, at this time, child thread will be executed at the back end or systemtically, which is called daemon thread, a special process in linux system.

Note that `detach` and `join` cannot be used at the same time.

## joinable

### concept

decide whether thread could be used by `join()` or `detach()`, it returns true or false. If it returns true, then currently thread is joinable or detachable, else it is not joinable or detachable.

## create std::thread callable object using class

### implementation

#### overloading `()`

```
class obj:
{
public:
    void operator() ()
    {
        //...
    }
}
```

```
std::thread myjob(obj);
myjob.join()
```

1.Note that callable function must be declared as public function inside class
1.Note that callable function must be called without `()` given this format: `std::thread(function&& f, Arg&&... args)`

#### member function

```
class obj
{
public:
    void print(){
        //...
    }
};
```

```
obj OBJ;
std::thread myjob(&obj::print, OBJ);
myjob.join();
```
* Note that OBJ is passed by value, another copy is made when thread is declared.
* Note that in C++ member functions have an implicit first parameter that binds to `this`. When creating a thread, the `this` pointer must be passed. You must also qualify the member function with a class name.
* Note that member function you called is not neccessary to be a static function.

#### copy constructor && move constructor

```
class threadTest
{
public:
    //default constructor
    threadTest(int id):myid(id){
        std::cout<<"constructor is called at this address: "<<this<<std::endl;
    }
    
    //copy constructor
    threadTest(const threadTest &tt):myid(tt.myid){
        std::cout<<"copy constructor is callled at this address: "<<this<<std::endl;
    }
    
    //move constructor
    threadTest(threadTest&& tt):myid(tt.myid){
        std::cout<<"move constructor is called at this address: "<<this<<std::endl;
    }

    ~threadTest(){
        std::cout<<"destructor is called at this address: "<<this<<std::endl;
    }
}

int main(){
    int myid = 5;
    
    threadTest tt(myid); 
    std::thread myfirstjob(&threadTest::printtest, tt);
    myfirstjob.join();

    std::cout<<"--------------main thread is running 0--------------"<<std::endl;
```
Terminal Output:

```
constructor is called at this address: 0x7ffcfee16c70
copy constructor is callled at this address: 0x7ffcfee16be0
move constructor is called at this address: 0x557481c50288
destructor is called at this address: 0x7ffcfee16be0
printtest is started
printtest is finished
destructor is called at this address: 0x557481c50288
```

!Note that when std::thread is called and object member function passed by value, a copy of object is created temporarily which in this case located at address 0x7ffcfee16be0, then it was copied or moved(if you explicilty set move constructor or `std::move`) into storage that belongs to newly created thread.


#### issue

Be careful that once thread is finished, variables that are declared from this thread will also no longer be available. Any member function or variables that are still referencing this variable will return unexpected behaviour.

```
class obj
{
public:
    obj(int id):myid(id){}
    void print(){
        //...
    }
private:
    int &myid;
};
```

In this case, `myid` value could output unexpected behaviour.

However, object that is declared inside the thread will not affect other threads that are using this object member function cause other threads have to first copy this object, not calling this object directly.
As long as there's no reference or pointer inside class, it should not product any unexpected errors.

Note that `obj{}` is also callable which equals to `obj::obj()` which refers to constructor calls. You could also idrectly call:

```
int main(){
    obj() (); //valid, obj() is callable
}
```

## lamda expression

```
auto <thread_name> = [] {};
std::thread obj(<thread_name>);
obj.join();
```


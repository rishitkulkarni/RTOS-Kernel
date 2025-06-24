#include <thread>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <atomic>

class Mutex {
    private:
    std::atomic <bool> mutX  {false} ;
    public:
    void lock(){
        while (mutX.exchange(true, std::memory_order_acquire)) {
            std::this_thread::sleep_for(std::chrono::microseconds(50));
        }
    }

    void unlock(){
        mutX.store(false);
    }


};

//trying part
int ctr = 0;
Mutex mtx;

void task1 (){
    for (int i = 0; i < 1000; ++i) {
        mtx.lock();
        ctr++;
        mtx.unlock();
    }
}

void task2(){
    for (int i = 0; i < 500; ++i) {
        mtx.lock();
        ctr--;
        mtx.unlock();
    }
}

int main(){
    std::thread t1(task1);
    std::thread t2(task2);
    t1.join();
    t2.join();

    std::cout << "Final value of ctr: " << ctr << std::endl;
    return 0;
}
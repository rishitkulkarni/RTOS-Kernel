#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <bits/stdc++.h>
using namespace std::literals::chrono_literals;

static bool xyz = false;
static bool abc = false;


void PrintHW(){
    std::cout<<"the thread for the fn is "<<std::this_thread::get_id()<<std::endl;
    while (!xyz){
        std::cout << "Hello World!" << std::endl;
        std::this_thread::sleep_for(1s);
    }
    
}

void onThread2(){
    std::cout<<"the thread 2nd for the fn is "<<std::this_thread::get_id()<<std::endl;
    while (!abc){
        std::cout<<"2nd2nd2nd"<<std::endl;
        std::this_thread::sleep_for(1s);
    }
}
int main(){
    std::thread worker (PrintHW);
    std::thread worker2 (onThread2);
    
    std::cin.get();
    xyz = true; // signal the thread to stop
    worker.join(); // wait for the thread to finish
    std::cout<<"the thread for the fn is "<<std::this_thread::get_id()<<std::endl;
    std::cout << "Thread has finished execution." << std::endl;
    return 0;
}
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <bits/stdc++.h>
using namespace std::literals::chrono_literals;

static bool xyz = false;

void PrintHW(){
    std::cout<<"the thread for the fn is "<<std::this_thread::get_id()<<std::endl;
    while (!xyz){
        std::cout << "Hello World!" << std::endl;
    }
    
}
int main(){

}
#include <thread>
#include <typeinfo>
#include <iostream>
#include <vector>

void PrintValue (int a ){
    std::cout<<a << std::endl;
}
void Square (int a){
    std::cout<<a*a<<std::endl;
}

void Increment(int a){
    std::cout<<a+1<<std::endl;
}

void fn(const std::vector<int>& vec,void (*functionPtr)(int)) {
    for (int i : vec){
        functionPtr(i);
    }
}

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout<<"choose a function 1. PrintValue 2. Square 3. Increment"<<std::endl;
    int choice ;
    std::cin>>choice;
    void (*fnPtr)(int);
    if (choice ==1 ){
        fnPtr = PrintValue;
    }
    else if (choice == 2){
        fnPtr = Square;
    }
    else if (choice == 3 ){
        fnPtr = Increment;
    }    

    fn(vec,fnPtr);
   
}
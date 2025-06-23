//if the function is small , time to execute is less than the time to call the function hence inline function
#include <iostream>

inline int printVal(int a){
    std::cout<<a<<std::endl;
    return a;
}
int main(){
    printVal(5);
}
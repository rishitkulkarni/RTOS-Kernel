//lamda is a way to define a anonymous function 
using namespace std;
#include <iostream>

int main(){
    std::cout << [](int x,int y ){return x+y;}(2,7);

}
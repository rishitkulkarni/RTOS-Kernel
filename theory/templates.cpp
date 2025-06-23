//essentially for code reusability and modularity different classes made for different datatypes
//also known as parameterized classes
//parameter for a template is a dataype 
using namespace std;
#include <vector>  
#include <string>  
#include <iostream>


template <typename T> T add(T a , T b){
    return a +  b;
}

template <typename T> class MyVector {
    public :
    vector<T> vec ;
    MyVector(vector<T> v) : vec(v) {vec = v ; }
    void print() {
        for (const auto& item : vec) {
            cout << item << endl;
        }
    }
};

int main(){
    cout<<add<int>(2,3)<<endl; 
    cout<<add<double>(2.5,3.21)<<endl; 
    
    MyVector<int> ages  ({18,19,20});
    ages.print();
    MyVector<string> names  ({"drake","eminem","Bigl"});
    names.print();
}

#include <iostream>  
#include <typeinfo>  
using namespace std;  
  
class A  
{  
  virtual void fun(){};  
};  
class B :public A  
{  
  virtual void fun(){};  
};  
  
int main()  
{  
    B b;  
    A *p = &b;  
    cout << typeid(*p).name() << endl;  
    return 0;  
}  

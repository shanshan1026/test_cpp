#include <iostream>  
#include <typeinfo>  
using namespace std;  
class Shape  
{  
public:  virtual void fun(){};  
};  

class Rect :public Shape  
{  
public:  
    void fun(){};  
    void print(){ cout << "I am Rect" << endl; }  
};  

class Circle :public Shape  
{  
public:  
    void fun(){};  
    void print(){ cout << "I am Circle" << endl; }  
};  

void fun(Shape *p)  
{  
    if (typeid(*p) == typeid(Rect))  
    {  
        Rect *r = dynamic_cast<Rect *>(p);  
        cout << "p: " << p << endl;
        cout << "r: " << r << endl;
        r->print();  
    }
    if (typeid(*p) == typeid(Circle))  
    {  
        Circle *c = dynamic_cast<Circle *>(p);  
        cout << "p: " << p << endl;
        cout << "c: " << c << endl;
        c->print();  
    }
}  

int main()  
{  
    Rect r;  
    cout << "first call func" << endl;  
    fun(&r);  
  
    Circle c;  
    cout << "second call func" << endl;  
    fun(&c);  

    return 0;  
}   


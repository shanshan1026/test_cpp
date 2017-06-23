#include <iostream>
using namespace std;
class CBase {
public:
    CBase(){print();}
    virtual void print(){cout << "I am Base" << endl;}
};
class CDerived: public CBase {
public:
    CDerived(){print();}
    virtual void print(){cout << "I am Derived" << endl;}
};
 
int main()
{
    cout << "Base construct" << endl;
    CBase b;
    cout << "Derived construct" << endl;
    CDerived d;
    CBase* pb;
    CDerived* pd;
 
    cout << "Base pointer" << endl;
    pb = &b;   
    pb->print();
    pb = &d;    
    pb->print();

} 


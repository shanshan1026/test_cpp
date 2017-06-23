#include <iostream>
using namespace std;
class CBase {
public:
    virtual void print(){cout << "I am Base" << endl;}
};
class CDerived: public CBase {
public:
    virtual void print(){cout << "I am Derived" << endl;}
};
 
int main()
{
    CBase b; CBase* pb;
    CDerived d; CDerived* pd;
 
    pb = dynamic_cast<CBase*>(&d);     // ok: derived-to-base
    pd = dynamic_cast<CDerived*>(&b);  // wrong: base-to-derived 
    cout << "pb: " << pb << endl;
    cout << "pd: " << pd << endl;
    pb->print();
    //pd->print();
} 

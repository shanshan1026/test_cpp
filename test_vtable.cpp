#include <iostream>
using namespace std;

class BaseClass
{
public:
    BaseClass() = default;
    virtual void fun()
    {
        cout << "BaseClass::fun()" << endl;
    }
    virtual void fun2()
    {
        cout << "BaseClass::fun2()" << endl;
    }
    virtual ~BaseClass(){}
};

class DrivedClass: public BaseClass
{
public:
    DrivedClass() = default;
    virtual void fun()
    {
        cout << "DrivedClass::fun()" << endl;
    }
    virtual void fun2()
    {
        cout << "DrivedClass::fun2()" << endl;
    }
    virtual ~DrivedClass(){};
};

void *getp(void *p)
{
    return (void*)*(unsigned long *)p; //
}

typedef void (*fun)();
fun getfun(void* obj, unsigned int off)
{
    void *vptr = getp(obj);
    unsigned char *p = (unsigned char *)vptr;
    p += sizeof(void*) * off;
    return (fun)getp(p);
}

int main(void)
{
	
    BaseClass a;
    BaseClass *b = new DrivedClass();
    a.fun();
	b->fun();
	
	//find vptr and vtable
    fun f1 = getfun(b, 0);
    fun f2 = getfun(b, 1);
    (*f1)();
    (*f2)();
    delete b;
    return 0;
}


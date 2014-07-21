// consoledemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
class fruit
{
public:
    void func()
    {
        printf("fruit\n");
    }
    virtual void vfunc()
    {
        printf("v fruit\n");
    }
};

class apple:public fruit
{
public:
    void func()
    {
        printf("apple\n");
    }
    void vfunc()
    {
        printf("v apple\n");
    }
};

typedef void (*pFunc)(void);
#define V_FUN_ADDR(base, offset)  (pFunc)*((int *)*(int *)(base) + offset)
#define V_FUN_ADDR1(base, offset)  (pFunc)*((int *)*((int *)(base)+1) + offset)
class parent
{
public:
    virtual void f() { cout << "parent Func f()" << endl; }
    virtual void g() { cout << "parent Func g()" << endl; }
    virtual void h() { cout << "parent Func h()" << endl; }
};
class mother
{
public:
    virtual void f() { cout << "Mother f()" << endl; }
    virtual void g() { cout << "Mother g()" << endl; }
    virtual void h() { cout << "Mother h()" << endl; }
};
class father
{
public:
    virtual void f() { cout << "Father f()" << endl; }
    virtual void g() { cout << "Father g()" << endl; }
    virtual void h() { cout << "Father h()" << endl; }
};
class child : public parent, public mother, public father
{
public:
    virtual void f()  { cout << "Child Func f()" << endl; }
    virtual void g() { cout << "Child Func g()" << endl; }
    virtual void h1() { cout << "Child Func h1()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
    pFunc pMethod;
    parent *p = new parent();
    cout << "p addr: " << (int *)p << endl;
    cout << "virtual table addr: " << (int *)*(int *)p << endl;
    //cout << "f() addr: " << (int *)(p->f) << endl;
    //p->f();
    pMethod = V_FUN_ADDR(p, 0);
    (*pMethod)();
    pMethod = V_FUN_ADDR(p, 1);
    (*pMethod)();

    child *pChild = new child();
    pMethod = V_FUN_ADDR(pChild, 0);
    (*pMethod)();
    pMethod = V_FUN_ADDR(pChild, 1);
    (*pMethod)();

    pMethod = V_FUN_ADDR1(pChild, 0);
    (*pMethod)();
    delete(p);
    delete(pChild);
    return 0;
}


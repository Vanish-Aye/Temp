
#include <string>
#include <iostream>

template <typename TempB>
class control
{
public:
    TempB* ToControlA;
    control() {};
    control(TempB* A1) :ToControlA(A1){}
};


template <typename Temp>
class A: public control<A<Temp>>
{
public:
    Temp* ToB;
    A() {};
    A(Temp* B_in):ToB(B_in)
    {
        A::control(this);
    }
};

class B : public A<B>
{
public:
    B()
    {
        A(this);
    }
    void ME()
    {
        printf("我被调用了???\n");
    }
};

int main()
{
    B B1;
    A<B> A1(&B1);
    control<A<B>> ControlA(&A1);
    ControlA.ToControlA->ToB->ME();
}

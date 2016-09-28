#include <stdio.h>

class A
{
public:
	A(int a = 0)
	{
		printf("A : %d\n" , a);
	}
	~A(){}
};
class B : public A
{
public:
	B(int a = 1 , int b = 2) : A(a)
	{
		printf("B : %d\n" , b);
	}
	~B(){}
};

class C : public B
{
public:
	C(int a = 3 , int b = 4 , int c = 5) :  B(a , b)
	{
		printf("C : %d\n" , c);
	}
	~C(){}
	B b;
	A a;
};

int main()
{
	C c;
	return 0;
}

#include <stdio.h>

class A
{
public:
	void  Aprint()
	{
		printA();
	}
//private:
public:
	virtual void printA()
	{
		printf("A\n");
	}
//	virtual ~A(){}
	virtual void show(){}
};

class B : public A
{
private:

	void printA()
	{
		printf("B\n");
	}
//	virtual ~B(){}
};
class C : public B
{
	
};
int main()
{
	A *pA = new B;
	pA->Aprint();
	C c;
	delete pA;
	return 0;
}
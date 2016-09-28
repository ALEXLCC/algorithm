
#include<stdio.h>

class A
{
public:
	A(int a = 0)
	{
		printf("Enter A constructor ");
		printf("%d\n" , a);
	}
};
class B : public A
{
public:
	A m_aA;
	B(int a = 1 , int b = 2):A(a)
	{
//		printf("Enter B constructor ");
		printf("%d\n" , b);
	}
};
int main()
{
	B b;
	return 0;
}
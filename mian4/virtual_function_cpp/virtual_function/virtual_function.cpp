#include <iostream>
using namespace std;
class A  
{  
public:  
    A()  
	{     
		cout << "A construct" << endl;
	}  
	A operator=(const A &a)
	{
		cout << "operator = " << endl;
		return a;
	}
	A(const A& a)
	{
		cout << "const A&" << endl;
	}
    ~A() 
	{    
		cout<<"~A"<<endl;   
	}  
};  
   
class B:public A  
{  
    public:  
        B(A &a):_a(a)  
        {  
          //  _a = a;
        }  
        ~B()  
        {  
            cout<<"~B"<<endl;  
        }  
    private:  
        A _a;  
    };  
       
int main(void)  
 {  
        A a;       //很简单，定义a的时候调用了一次构造函数  
        B b(a); 
		return 0;
}
#include<iostream>
#include<typeinfo>
using namespace std;
class Person{
	public:
		virtual void f(){}
};
class Student:public Person{};
int main(){
	int a;
	double d;
	unsigned u;
	char c;
	Person p;
	Student s;
    cout<<typeid(a).name()<<","<<typeid(u).name()<<","<<typeid(d).name()<<","<<typeid(c).name()<<","<<typeid(p).name()<<","<<endl;
	cout<<typeid(Student).name()<<endl;
	Person* pp=new Student;
	cout<<typeid(*pp).name()<<endl;//6Person if virtual 7Student
	cout<<typeid(pp).name()<<endl;//P6Person
	cout<<(typeid(*pp)==typeid(Student))<<endl;
	return 0;
}

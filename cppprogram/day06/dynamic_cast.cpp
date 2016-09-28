#include<iostream>
using namespace std;
class Person{
	public:
		virtual void show(){
		}
		~Person(){}
};
class Teacher:public Person{
	public:
		~Teacher(){}
};
class Student:public Person{
	public:
		~Student(){}
};
class CppTeacher:public Teacher{
	public:
		~CppTeacher(){}
};
class Computer{
	void start(){}
};
class Company{
	public:
		void test(Person* p){
			if(dynamic_cast<CppTeacher*>(p)){
				cout<<"a teacher.."<<endl;
			}else if(dynamic_cast<Student*>(p)){
				cout<<"a student.."<<endl;
			}else if(dynamic_cast<Teacher*>(p)){
				cout<<"a cppteacher.."<<endl;
			}else if(dynamic_cast<Person*>(p)){
				cout<<"a person.."<<endl;
			}else{
				cout<<"other ...."<<endl;
			}
		}
};
class NoteBook:public Computer{};
int main(){
	Computer* c=new NoteBook();
//	dynamic_cast<NoteBook*>(c);
	Person* ps=new Student;
	Person* pt=new Teacher;
	Person* pc=new CppTeacher;
//	dynamic_cast<Student*>(ps);
	Company it;
	it.test(ps);
	it.test(pt);
	it.test(pc);
	return 0;
}

#include<iostream>
using namespace std;
#include<string>
class Person{
	protected:
		string name;
	public:
		Person(const char* n):name(n){
			cout<<"Person("<<name<<")"<<endl;
		}
		const string& Name()const{
			return name;
		}
};
class Teacher: public Person{
	protected:
		string course;
	public:
		Teacher(const char* n,const char* c):Person(n),course(c){
			cout<<"Teacher("<<name<<","<<course<<")"<<endl;
		}
		void teach(const char* c){
			cout<<name<<" teach for "<<c<<" class."<<endl;
		}
};
class Student: public Person{
	protected:
		string sid;
	public:
		Student(const char* n,const char* s):Person(n),sid(s){
			cout<<"Student("<<n<<","<<s<<")"<<endl;
		}
		void study(const char* c){
			cout<<name<<" study "<<c<<endl;
		}
};
class Worker:public Student,public Teacher{
	public:
		Worker(const char*n,const char* s,const char*c):Student(n,s),Teacher(n,c){
			cout<<n<<","<<s<<","<<c<<endl;
		}
};
int main(){
	Worker w("alien","Cpp","A01");
	return 0;
}

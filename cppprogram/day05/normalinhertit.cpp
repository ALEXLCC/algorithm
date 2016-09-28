#include<iostream>
using namespace std;
#include<string>
class Person{
	protected:
		string name;
		bool gender;
	public:
		Person(const char* n,bool g):name(n),gender(g){
			cout<<"Person() constructed......"<<endl;
		}
		void show(){
			cout<<"hello everyone,I am a  "<<(gender?"handsome boy":"beauty")<<endl;
		}
};
class Teacher:public Person{
	private:
		string course;
	public:
		Teacher(const char* n,const char* c,bool g):Person(n,g),course(c){
		cout<<"Teacher() constructed....."<<endl;
		}
		void show(){
			cout<<"hello ladies and gentleman,I am a "<<course<<" teacher"<<endl;
		}
};
int main(){
	Person* p=new Teacher("Alien","c progrram language",true);
	p->show();
	delete p;
	return 0;
}

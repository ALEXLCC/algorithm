#include<iostream>
#include<string>
using namespace std;
class Person{
	protected:
		string name;
	public:
		Person(const char* n){
			name=n;
			cout<<"Person("<<name<<")"<<endl;
		}
		~Person(){
			cout<<"~Person()"<<endl;
		}
		void setName(const char* n){
			name=n;
		}
		void eat(string food){
			cout<<name<<"  eat  "<<food<<endl;
		}
		void speak(string words){
			cout<<name<<"  speak:\""<<words<<"\""<<endl;
		}
		void show(){
			cout<<name<<"  person  show run.."<<endl;
		}
		void show(const char* p){
			cout<<p<<"  person  show run.."<<endl;
		}
};
class Teacher:public Person{
	private:
	   string course;
	public:
	   Teacher(const char* n,const char* c):Person(n),course(c){
	   		cout<<"Teacher("<<n<<","<<c<<")"<<endl;
	   }
	   ~Teacher(){
	   		cout<<"~Teacher()"<<endl;
	   }
	   void teach(string someclass){
	   		cout<<name<<" for "<<someclass<<" teach "<<course<<endl;
	   }	   
	   void setCourse(string course){
	   		this->course=course;
	   }
		void show(){
			cout<<name<<" teacher  show run.."<<endl;
		}
};
int main(){
	Person a("person");
	a.setName("alien");
	a.eat("fish");
	a.speak("hello!");
	a.show();
	Teacher t("teacher","cpp");
	t.setName("Mars");
	t.speak("hello cpp");
	t.eat("dog");
	t.setCourse("c program language");
	t.teach("A01");
	t.show();
	t.Person::show("PPPPPPP");
	return 0;
}

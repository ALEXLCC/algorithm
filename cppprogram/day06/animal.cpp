#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
class Animal{
	private:
		string name;
		char gender;
	public:
		virtual void eat(){
			cout<<"animals eat foods...."<<endl;
		}
		virtual void shout(){
			cout<<"animal shout...."<<endl;
		}
};
class Cat:public Animal{
	public:
		virtual void eat(){
			cout<<"cat eat foods...."<<endl;
		}
		virtual void shout(){
			cout<<"cat shout...."<<endl;
		}
};
class Jeifei:public Cat{
	public:
		virtual void eat(){
			cout<<"jeifei eat foods...."<<endl;
		}
		virtual void shout(){
			cout<<"jeifei shout...."<<endl;
		}
};
class Person{
	public:
		void play(Animal& a){
			a.eat();
			a.shout();
		}
};
int main(){
	cout<<sizeof(Animal)<<endl;
	Person p;
	Animal a;
	Cat c;
	Jeifei j;
	p.play(j);
	p.play(c);
	p.play(a);
	return 0;
}

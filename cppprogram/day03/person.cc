#include "Person.h"
#include<iostream>
using std::cout;
using std::endl;
using std::string;;
Person::Person(){
	age=0;
	name="";
}
Person::Person(int age,string name){
	this->age=age;
	this->name=name;
}
void Person::SetAge(int age){
	this->age=age;
}
int Person::GetAge(){
	return this->age;
}
void Person::SetName(string name){
	this->name=name;
}
string Person::GetName(){
	return this->name;
}
void Person::Show(){
	cout<<"name:"<<name<<","<<"age:"<<age<<endl;
}

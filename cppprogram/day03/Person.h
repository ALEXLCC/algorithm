#ifndef _MY_PERSON_H
#define _MY_PERSON_H
#include<string>
using std::string;
class Person{
private:
	int age;
	string name;
public:
	Person();
	Person(int age,string name);
	int GetAge();
	void SetAge(int age);
	string GetName();
	void SetName(string name);
	void Show();
};
#endif

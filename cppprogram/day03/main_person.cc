#include "Person.h"
//using std::string;
int main(){
	Person p1;
	string name("alien");
	p1.Show();
	p1.SetAge(100);
	p1.Show();
	p1.SetName(name);
	return 0;
}

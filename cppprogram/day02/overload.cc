#include<iostream>
using namespace std;
void show(int n){
	cout<<"Integer:"<<n<<endl;
}
void show(double d){
	cout<<"Double:"<<d<<endl;
}
void show(float d){
	cout<<"Float:"<<d<<endl;
}
void show(int n,int m){
	cout<<"Integer company:"<<n<<","<<m<<endl;
}
struct Person{
	char name[20];
	char gender;
};
void show(Person p){
	cout<<"A"<<(p.gender=='M'?"man":p.gender=='W'?"woman":"alien")<<","<<p.name<<endl;
}
int main(){
	show(123);
	Person fj={"SuperMan",'N'};
	show(fj);
	show(45.6);
	show(87,39);
	show(0.34F);
	return 0;
}

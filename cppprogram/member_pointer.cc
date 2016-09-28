#include<iostream>
using std::cout;
using std::endl;
struct Date{
	int year;
	int month;
	int day;
};
void swap(Date& a,Date& b){
	int temp=a.year;
	a.year=b.year;
	b.year=temp;
}
void sort(Date a[],int n,int Date::*p){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i].*p>a[j].*p){
				swap(a[i],a[j]);
			}
		}
	}
}
int main(){
	int Date::*p=&Date::year;
	Date a={2014,7,4},b={2013,1,16};
	cout<<a.*p<<","<<b.*p<<endl;
	p=&Date::day;
	cout<<a.*p<<","<<b.*p<<endl;
	return 0;
}

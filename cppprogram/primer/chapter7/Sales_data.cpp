#include<iostream>
using namespace std;
struct Sales_data{
	Sales_data()=default;
	Sales_data(const string &s):bookNo(s){}
	Sales_data(const string& s,unsigned n,double p):
		bookNo(s),units_sold(n),revenue(p*n){}
//	Sales_data(istream &);
	string bookNo;
//	unsigned units_sold=0;
///	double revenue=0.0;
	unsigned units_sold;
	double revenue;
};
int main(){
	Sales_data sd;
	return 0;
}

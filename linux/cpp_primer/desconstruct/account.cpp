#include<iostream>
using namespace std;
class Account{
	public:
		Account(){}
		Account(const char* _name,double=0.0){}
		Account(const char* _name,unsigned _nmber=0,double bal){
			this->_name=_name;
			this->_acct_nmber=_nmber;
			this->_balance=bal;
		}
		~Account(){
			
		}
	private:
		char *_name;
		unsigned int _acct_nmber;
		double _balance;
};

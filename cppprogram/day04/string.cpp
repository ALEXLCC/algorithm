#include<iostream>
#include<cstdio>
#include<cstring>
using std::cout;
using std::endl;
class S{
	private:
	char* ps;
	int len;
	public:
	S(const char* str=""):ps(new char[strlen(str)+1]){
		len=strlen(str);	
		strcpy(ps,str);
		printf("0x%p%s\n",ps,"   constructed ~~~~~~~~~~~~~~~");
	}
	S(const S& s){
		len=s.len;
		ps=new char[len];
		strcpy(ps,s.ps);
		printf("0x%p%s\n",ps,"   constructed ~~~~~~~~~~~~~~~");
	}
	~S(){
		printf("0x%p%s\n",ps,"  released ~~~~~~~~~~~~~");
		delete[] ps;
		ps=NULL;
	}
	S& operator=(const S& s){
		if(&s==this){
			return *this;
		}
		len=s.len;
		delete[] ps;	//release the old memory
		ps=new char[len+1];
		strcpy(ps,s.ps);
		return *this;	//return tempory object if not reference
	}
	char& operator[](int i){
		return ps[i];
	}
};
int main(){
	S s1("s1s1"),s2,s3;
	cout<<"-------------------------------"<<endl;
	s2=s3=s1;	//s2.operator=(s3)
	cout<<"-------------------------------"<<endl;
	cout<<s2[2]<<endl;
	cout<<"-------------------------------"<<endl;
	S s4="aaa";	//initialize not assign
	cout<<"-------------------------------"<<endl;
	return 0;
}

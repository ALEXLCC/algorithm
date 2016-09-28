#include<iostream>
using namespace std;
class ChairMan{
	private:
		string name;
		ChairMan(string name):name(name){
		}
	public:
	static ChairMan& GetInstance(){
		static ChairMan cm("alien");
		return cm;
	}
	void show(){
		cout<<"name:"<<name<<endl;
	}
};
int main(){
	ChairMan cm=ChairMan::GetInstance();
	cm.show();
	return 0;
}

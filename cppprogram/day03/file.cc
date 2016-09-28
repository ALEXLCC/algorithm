#include<iostream>
using std::cout;
using std::endl;
using std::string;
class Buffer{
	private:
		string name;
	public:
		Buffer(const string& name):name(name){
			cout<<"for "<<name<<" allocate buffer."<<endl;
		}
		~Buffer(){
			cout<<"clean "<<name<<"\'s buffer."<<endl;
		}
};
class File{
	private:
		string path;
		Buffer* buffer;
	public:
		File();
		File(const string& path, Buffer* buffer):path(path),buffer(buffer){
		cout<<"create file:"<<path<<endl;
	}
		~File();
		void open();
		void close();
};
void File::open(){
	cout<<path<<"   open start...."<<endl;
	buffer=new Buffer(path);
	cout<<path<<"   open end...."<<endl;
}
void File::close(){
	cout<<path<<"   close start...."<<endl;
	delete buffer;
	cout<<path<<"   close end...."<<endl;
}
File::~File(){
	cout<<path<<"\tdestruct"<<endl;
	close();
}
File::File(){
	cout<<"null"<<endl;
}
/*
File::File(const string& path,Buffer* buffer):path(path),buffer(buffer){
//	this->path=path;
	cout<<"create file:"<<path<<endl;
}
*/
//File global("global");
int main(){
	{
	//	File a("aaa");
		cout<<"_________________"<<endl;
	}
/*	File* pf1=new File;
	File* pf2=new File("/etc/passwd");
	File* pf3=new File[3];
	delete[] pf3;
	pf3=NULL;
	delete pf2;
	pf2=NULL;
	delete pf1;
	pf1=NULL;
	*/
	File f1;
	f1.open();
	File f2("abc",new Buffer("AAAAAA"));
	f2.open();
//	f1.close();
	return 0;
}

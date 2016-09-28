#include<iostream>
using std::cout;
using std::endl;
typedef int T;
class Array{
	private:
		T*a;
		int len;	
	public:
		Array(int n,T init=T()):a(new T[n]){
			for(int i=0;i<n;++i){
				a[i]=init;
			}
			len=n;
			cout<<a<<" create array "<<len<<" numbers. "<<"init value:"<<init<<endl;
		}
		Array(const Array& arr){
		//	a=arr.a;	//arr this  a the same address
			len=arr.len;
			a=new T[len];
			for(int i=0;i<len;++i){
				a[i]=arr.a[i];
			}
			cout<<"Create a Array object..."<<endl;
		}
		~Array(){
			cout<<a<<" release array..."<<len<<" numbers..."<<endl;
			delete[] a;
			a=NULL;
		}
	T& at(int n){
		if(n<0||n>len)
			throw n;
		return a[n];
	}
	T size(){
		return len;
	}
	void resize(int newsize,const T& val=T()){
		if(newsize<=len){
			len=newsize;
		}else{
			T* np=new T[newsize];
			for(int i=0;i<len;++i){
				np[i]=a[i];
			}
			for(int j=len;j<newsize;++j){
				np[j]=val;
			}
			delete[] a;
			a=np;
			len=newsize;
			np=NULL;
		}
	}
	void print(){
		for(int i=0;i<len;++i){
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	void fill(int start,int step=int ()){
		for(int i=0;i<len;++i){
			a[i]=start+step*i;
		}
	}
};
Array& filter(Array arr){
	for(int i=0;i<arr.size();++i){
		if(0==arr.at(i)&1){
			cout<<arr.at(i)<<' ';
		}
	}
	cout<<endl;
	return arr;	//copy argument arr initialized by arr
}
int main(){
	Array x(20);
	//x.at(30);
	x.at(3)=5;
	x.print();
	Array y(10,7);
	y.resize(15,9);
	y.print();
	y.fill(7,3);
	cout<<"__________________"<<endl;
	y.print();
	cout<<"*****************************"<<endl;
	filter(x).print();
	cout<<"*****************************"<<endl;
//	filter(y).print();
	return 0;
}

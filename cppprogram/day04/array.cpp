#include<iostream>
#include<ctime>
using std::cout;
using std::endl;
typedef int T;
class Array{
	private:
		T*a;
		int len;	
		mutable int cur;
	public:
		Array(int n,T init=T(),T cur=T()):a(new T[n]){
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
		Array& randfill(){
			srand(time(NULL));
			for(int i=0;i<len;++i){
				a[i]=rand()%100;
			}
			return *this;
		}
	T& at(int n)const{
		if(n<0||n>len)
			throw n;
		return a[n];
	}
	T size()const{
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
	void print()const{
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
	T& get(int index)const{
		return a[index];
	}
	T& next()const{
		return a[++cur%len];
	}
};
Array& filter(Array& arr){
	for(int i=0;i<arr.size();++i){
		if(0==arr.at(i)&1){
			cout<<arr.at(i)<<' ';
		}
	}
	cout<<endl;
	return arr;	//copy argument arr initialized by arr
}
void use( Array& x){
	for(int i=0;i<3;++i){
		cout<<x.next()<<' ';
	}
	cout<<endl;
	for(int i=0;i<5;++i){
		cout<<x.next()<<' ';
	}
	cout<<endl;
	for(int i=0;i<4;++i){
		cout<<x.next()<<' ';
	}
	cout<<endl;
}
int main(){
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	Array z(15);
	z.randfill().print();
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	use(z);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	return 0;
}

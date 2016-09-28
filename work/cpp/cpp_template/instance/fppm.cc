/*
 *	file:fppm.cc
 *
 * */
template<int N>
class X{
	public:
		typedef int I;
		void f(int){
		
		}
};
template<int N>
void fppm(void (X<N>:: *p)(typename X<N>:: I));
int main(){
	fppm(&X<33>:: f);
	return 0;
}

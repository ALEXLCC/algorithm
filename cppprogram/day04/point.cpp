#include<iostream>
using std::cout;
using std::endl;
struct Point{
	int x;	//int x,y; //deferent compiler determine the different order
	int y;
};
class Pos{
	private:
	Point p;
	public:
		Pos(int x=0,int y=0){
			p.x=x;
			p.y=y;
		}
		~Pos(){}
		void move(int cx,int cy){
			p.x+=cx;
			p.y+=cy;
		}
		void moveTo(int cx,int cy){
			p.x=cx;
			p.y=cy;
		}
		Point* operator->(){
			return &p;
		}
};
int main(){
	Pos a(80,20);
	cout<<a->x<<","<<a->y<<endl;
	return 0;
}

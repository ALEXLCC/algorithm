#include<iostream>
#include<string>
using namespace std;
class Graph{
	private:
		int x;
		int y;
	public:
		Graph(int x,int y):x(x),y(y){}
		virtual double area()=0;
		void show(){
			cout<<Type()<<"  positiion("<<x<<","<<y<<"),area="<<area()<<endl;
		}
		virtual string Type()=0;
};
class Rect:public Graph{
	private:
		int width;
		int height;
	public:
		Rect(int x,int y,int w,int h):Graph(x,y),width(w),height(h){}
		double area(){
			return width*height;
		}
		string Type(){
			return "Rectangle";
		}
};
class Circle:public Graph{
	private:
		int radius;
	public:
		Circle(int x,int y,int r):Graph(x,y),radius(r){}
		double area(){
			return 3.14*radius*radius;
		}
		string Type(){
			return "circle";
		}
};
class Computer{
	public:
		void useGraph(Graph& g){
			g.show();
		}
};
int main(){
	Circle c(8,8,10);
	Rect r(10,10,2,9);
	Computer com;
	com.useGraph(c);
	com.useGraph(r);
}

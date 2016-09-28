#include<iostream>
using std::cout;
using std::endl;
class Vehicle{
	public:
		virtual void stop(){
			cout<<"traffic tools stop...."<<endl;
		}
	//	virtual ~Vehicle(){}
};
class Car:public Vehicle{
	public:
	virtual	void stop(){
			cout<<"Car engine stop...."<<endl;
		}
	//	virtual ~Car(){}
};
class Bike:public  Vehicle{
	public:
	virtual	void stop(){
			cout<<"Bike strike ....."<<endl;
		}
	//	virtual ~Bike(){}
};
class Light{
	public:
		void stopVehicle(Vehicle& v){
			v.stop();
		}
};
int main(){
	Light light;
	Car car;
	Bike bike;
	light.stopVehicle(car);
	light.stopVehicle(bike);
	return 0;
}

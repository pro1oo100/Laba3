#include <iostream>
#include <cmath>
#include <iomanip>
bool input(double& xMin, double& xMax, double& step);
void func(double xMin, double xMax, double step);
int main(){
	double xMin, xMax, step;
	if(input(xMin,xMax,step)){
		func(xMin, xMax, step);
	}
	else{
		std::cout<<"Введите корректные значения"<<std::endl;
	}
	return 0;
}
bool input(double& xMin, double& xMax, double& step){
	bool isDone=1;
	if(!(std::cin>>xMin && std::cin>>xMax && std::cin>>step && step>0)){
		isDone=0;
	}
	return isDone;
}
void func(double xMin, double xMax, double step){
	double y;
	std::cout<<std::setw(5)<<"X"<<std::right<<std::setw(20)<<"Y"<<std::endl;
	std::cout<<std::setfill('-')<<std::setw(31)<<""<<std::setfill(' ')<<std::endl;
	while(xMin<=xMax){
		if(xMin<-2){
			y=-0.5*xMin-1.5;
		//	xMin+=step;
		}
		if(xMin>=-2 && xMin<=2){
			y=2*cos(2*xMin);
		//	xMin+=step;
		}
		if(xMin>2){
			y=0.5*xMin-1.5;
		//	xMin+=step;
		}
	std::cout<<std::fixed<<std::setprecision(4);
	std::cout<<std::setw(9)<<xMin;
	std::cout<<std::right<<std::setw(20)<<y<<std::endl;
	xMin+=step;
	}	
	std::cout<<std::setfill('-')<<std::setw(31)<<""<<std::setfill(' ')<<std::endl;
}

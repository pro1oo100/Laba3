#include <iostream>
#include <cmath>
int row(int first, int second);
bool input(int& first, int& second);
int gcd(int64_t idealNum, int64_t idealDin);
int main(){
	int first, second;
	if(input(first,second))
		row(first, second);
	else
		std::cout<<"Введите корректные значения"<<std::endl;
	return 0;
}
bool input(int& first, int& second){
	bool isDone=1;
	if(!(std::cin>>first && first>0 && first<11 && std::cin>>second && second>0 && second<11))
		isDone=0;
	return isDone;
}
int row(int first, int second){
	long double sum=0,idealError=1e14;
	if(second==1){
		std::cout<<"infinity"<<std::endl;
		return 0;
	}
	for(int n=1;n<200;++n){
		sum+=std::pow(n,first)/std::pow(second,n);
	}
	int64_t idealNum=0, idealDen=1;
	while(idealDen<10000){
		idealNum=std::round(sum*idealDen);
		long double error=std::abs(sum-(long double)idealNum/idealDen);	
		if(error<idealError){
			idealError=error;
			first=idealNum;
			second=idealDen;
		}
		++idealDen;
	}
	int del=gcd(first, second);
	std::cout<<first/del << "/" <<second/del <<std::endl;
	return 0;
}
int gcd(int64_t idealNum, int64_t idealDen){
	while(idealDen!=0){
		idealNum%=idealDen;
		std::swap(idealNum,idealDen);
	}
	return idealNum;
}

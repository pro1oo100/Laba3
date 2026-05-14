#include <iostream>
#include <vector>
bool input(std::vector<int>& row, int& numbers, int& amt);
int min(int a, int b);
int game(std::vector<int> row, int numbers, int amt);
int main(){
	std::vector<int>row;
	int numbers,amt;
	if(input(row,numbers,amt))
		std::cout<<game(row,numbers,amt)<<std::endl;
	else
		std::cout<<"Последовательность от 5 до 50000, ход от 2 до 100"<<std::endl;
	return 0;
}
bool input(std::vector<int>& row, int& numbers, int& amt){
	bool isDone=1;
	if(std::cin>>numbers && (numbers<=50000 && numbers>=5) && std::cin>>amt && (amt>=2 && amt<=100)){
		for(int i=0;i<numbers;++i){
			int number;
			std::cin>>number;
			row.push_back(number);
		}
	}
	else 
		isDone=0;
	return isDone;
}
int game(std::vector<int> row, int numbers, int amt){
	int i=0, player=0, ban;
	std::pair<int,int> score={0,0};
	std::pair<int,int> choice={0,0};
	while(i<numbers){
		int maxAmt=min(amt,numbers-i), idealSum=0, idealAmt=-1;
		if(player==0)
			ban=choice.first;
		else
			ban=choice.second;
		int sum=0;
		for(int j=1;j<=maxAmt;++j){
			sum+=row[i+j-1];
			if(j==ban)
				continue;
			else if(idealAmt==-1){
				idealAmt=j;
				idealSum=sum;
			}
			else if(sum>idealSum){
				idealSum=sum;
				idealAmt=j;	
			}
			else if(sum==idealSum && idealAmt>j)
				idealAmt=j;
		}
		if(idealAmt==-1){
			idealAmt=1;
			idealSum+=row[i];
		}
		if(player==0){
			score.first+=idealSum;
			choice.first=idealAmt;
		}
		else{
			score.second+=idealSum;
			choice.second=idealAmt;
		}
		player=1-player;
		i+=idealAmt;
	}
	return score.first>score.second?1:0;
}
int min(int a, int b){
	return a>b?b:a;
}	

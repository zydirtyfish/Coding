#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

void printv(vector<int> &num){
	for(int i = 0 ; i < num.size() ; i ++){
		printf("%d\t",num[i]);
	}
	printf("\n");
}

class BubbleSort{
public:
	void bubble_sort(vector<int> &num);
	void swap_num(int &a, int &b);
};

void BubbleSort::bubble_sort(vector<int> &num){
	for(int i = 0 ; i < num.size() ; ++ i){
		for(int j = i + 1 ; j < num.size() ; ++ j){
			if(num[i] > num[j])
				swap_num(num[i],num[j]);
		}
	}
}

void BubbleSort::swap_num(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	vector<int> num = {1,2,3,10,5,6,300,40,5,8,1002,50,2};
	vector<int> tmp;
	printv(num);
	BubbleSort bs;
	bs.bubble_sort(num);
	printv(num);
	return 0;
}

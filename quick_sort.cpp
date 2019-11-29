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

class QuickSort{
public:
	void quick_sort(vector<int> &num,int start,int end);
	void swap_num(int &a, int &b);
};

void QuickSort::quick_sort(vector<int> &num,int start,int end){
	if(start >= end) return;
	int i = start, j = end;
	int flag = num[start];
	while(i < j){
		while(num[j] > flag && j > i) j--;
		while(num[i] <= flag && j > i) i++;
		if(j > i)
			swap_num(num[i],num[j]);
	}
	swap_num(num[start],num[j]);
	quick_sort(num,start,j-1);
	quick_sort(num,j+1,end);
}

void QuickSort::swap_num(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	vector<int> num = {1,2,3,10,5,6,300,40,5,8,1002,50,2};
	vector<int> tmp;
	printv(num);
	QuickSort qs;
	qs.quick_sort(num,0,num.size()-1);
	printv(num);
	return 0;
}

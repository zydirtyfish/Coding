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

class MergeSort{
public:
	void merge_sort(vector<int> &num, int start, int end,vector<int> &tmp);
	void merge(vector<int> &num, int start, int mid, int end, vector<int> &tmp);
};

void MergeSort::merge_sort(vector<int> &num, int start, int end,vector<int> &tmp){
	if(start >= end) return;
	int mid = (start + end) / 2;
	merge_sort(num,start,mid,tmp);
	merge_sort(num,mid+1,end,tmp);
	merge(num,start,mid,end,tmp);
}

void MergeSort::merge(vector<int> &num, int start, int mid, int end, vector<int> &tmp){
	int i1=start,i2=mid+1,cnt=start;
	while((mid-i1+1)&&(end-i2+1)){
		if(num[i1] <= num[i2]){
			tmp.push_back(num[i1++]);
		}else{
			tmp.push_back(num[i2++]);
		}
	}
	while(mid-i1+1){tmp.push_back(num[i1++]);}
	while(end-i2+1){tmp.push_back(num[i2++]);}
	memcpy(&num[start],&tmp[0],(end-start+1)*sizeof(int));
	tmp.clear();
}

int main(){
	vector<int> num = {1,2,3,10,5,6,300,40,5,8,1002,50,2};
	vector<int> tmp;
	printv(num);
	MergeSort ms;
	ms.merge_sort(num,0,num.size()-1,tmp);
	printv(num);
	return 0;
}

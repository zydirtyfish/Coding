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

class ShellSort{
public:
	void shell_sort(vector<int> &num);
	void swap_num(int &a, int &b);
};

void ShellSort::shell_sort(vector<int> &num){
	int gap = num.size() / 2;
	while(gap){
		for(int i = gap ; i < num.size(); i ++){
			for(int j = i - gap ; j >= 0 ; j -= gap){
				if(num[j] > num[j+gap]){
					swap_num(num[j],num[j+gap]);
				}else{
					break;
				}
			}
		}
		gap /= 2;
	}
}

void ShellSort::swap_num(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	vector<int> num = {1,2,3,10,5,6,300,40,5,8,1002,50,2};
	vector<int> tmp;
	printv(num);
	ShellSort ss;
	ss.shell_sort(num);
	printv(num);
	return 0;
}

#ifndef _BLOOM_FILTER_H
#define _BLOOM_FILTER_H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

#include "common_types.h"
#define N 1000000
#define M 32

using namespace std;

/*https://blog.csdn.net/chinabhlt/article/details/49148373*/
class BloomFilter{
public:
	BloomFilter(int m, int n);
	~BloomFilter();

	uint32_t RSHash(const char *str, int seed);
	void add_key(const char *str);
	int is_exist(const char *str);
	void out_put();
	void reset();

private:
	//k:number of the hash functions 
	//m:the size of bitset
	//n:number of strings to hash (k = [m/n]*ln2)
	int m_k,m_m,m_n;
	uint32_t mn;
	bitset<N> * bit[M];
	vector<int> seed_array;
};
#endif

BloomFilter::BloomFilter(int m, int n){
	m_m = m;
	m_n = n;
	m_k = ceil((m/n) * log(2));
	mn = M*N;
	vector<int> vt = {5, 7, 11, 13, 31, 37, 61};
	seed_array.resize(vt.size());
	memcpy(&seed_array[0],&vt[0],vt.size()*sizeof(int));
	for(int i = 0 ; i < M ; i ++)
		bit[i] = new bitset<N>;
}

BloomFilter::~BloomFilter(){

}

uint32_t BloomFilter::RSHash(const char *str , int seed){
	uint32_t a = 63689;
	uint32_t hash = 0;
	while(*str){
		hash = hash * a + (*str++);
		a *= seed;
	}
	return (hash & 0x7FFFFFFF);
}

void BloomFilter::add_key(const char *str){
	for(int i = 0 ; i < m_k ; ++ i){
		uint32_t hash = RSHash(str, seed_array[i]) % (mn);
		int row = static_cast<int>(hash / N);
		int col = static_cast<int>(hash % N);
		(*bit[row])[col] = 1;
	}
}


int BloomFilter::is_exist(const char* str)
{
	int res = 1;
	for(int i=0;i<m_k;++i)
	{
		uint32_t hash = RSHash(str, seed_array[i]) % (mn);
		int row = static_cast<int>(hash / N);
		int col = static_cast<int>(hash % N);
		res &= (*bit[row])[col];
		if(!res){
			return 0;
		}
	}
	return 1;
}

void BloomFilter::out_put(){
	for(int i = 0 ; i < M ; i ++){
		cout << *bit[i] << endl;
	}
}

void BloomFilter::reset(){
	for(int i = 0 ; i < M ; i ++){
		(*bit[i]).reset();
	}
}


int main(){
	char str_tmp[50];
	sprintf(str_tmp,"%llu",123123213);
	BloomFilter bf(6,2);
	printf("%d\n",bf.is_exist(str_tmp));
	bf.add_key(str_tmp);
	printf("%d\n",bf.is_exist(str_tmp));
	//bf.out_put();

	sprintf(str_tmp,"%llu",123);
	printf("%d\n",bf.is_exist(str_tmp));
	bf.add_key(str_tmp);
	printf("%d\n",bf.is_exist(str_tmp));
	//bf.out_put();

	sprintf(str_tmp,"%llu",12399);
	printf("%d\n",bf.is_exist(str_tmp));
	return 0;
}


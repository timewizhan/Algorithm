/*
 * deer.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: ms-dev
 */

#include "deer.h"

#define max_two_antl(x) x/2

vector <int> DeerInZooDivTwo::getminmax (int N, int K){

	vector <int> minmax;
	int min_two_antl;

	//min
	if(N >= K){
		min_two_antl = 0;
	}else if(2*N == K){
	//	min_two_antl = max_two_antl(K);
		min_two_antl = N;
	}else{
		min_two_antl = K % N;
	}

	minmax.push_back(max_two_antl(K));
	minmax.push_back(min_two_antl);

	return minmax;
}




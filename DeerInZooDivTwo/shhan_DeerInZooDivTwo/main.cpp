/*
 * main.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: ms-dev
 */
#include <stdio.h>
#include "deer.h"

int main (void) {

	DeerInZooDivTwo find;

	int N, K;
	int cnt=0;

	vector <int> minmax;

	while(true){

		printf("(%d) \n", cnt++);
		scanf("%d %d", &N, &K);

		minmax = find.getminmax(N, 2*N - K);

		printf("Returns: {%d, %d} \n", minmax[1], minmax[0]);
	}

	return 0;
}



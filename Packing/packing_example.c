/*
 * knapsack.cpp
 *
 *  Created on: 2012. 7. 31.
 *      Author: jiwoong.yoo
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define NUM_OF_ITEMS    5
#define MAX_VALUE       20
#define MAX_WEIGHT      10
#define MAX_BOUND       3

#define KNAPSACK_CAPACITY   15

#define MAX(a,b)    (((a)>(b))?(a):(b))

int V[NUM_OF_ITEMS];
int W[NUM_OF_ITEMS];
int B[NUM_OF_ITEMS];

int D[NUM_OF_ITEMS+1][KNAPSACK_CAPACITY+1];

void gen_data();
void knapsack(int type);

int main() {

    gen_data();
    knapsack(0);

    return 0;
}


// type: 0: 0-1, 1: Bounded, others: Unbounded
void knapsack(int type) {
    int n, c, b, max_b;

    for(c = 0; c <= KNAPSACK_CAPACITY; c++)
        D[0][c] = 0;

    for(n = 0; n < NUM_OF_ITEMS; n++) {
        for(c = 1; c <= KNAPSACK_CAPACITY;  c++) {

            // Set bound
            if(type == 0)
                max_b = 1;
            else if(type == 1)
                max_b = B[n];
            else
                max_b = INT_MAX;

            for(b = 1; b <= max_b && W[n]*b <= KNAPSACK_CAPACITY; b++) {
                if(n == 0) {
                    if(c >= W[n]*b) {
                        D[n][c] = V[n]*b;
                    } else {
                        D[n][c] = 0;
                    }
                } else {
                    if(c >= W[n]*b) {
                        D[n][c] = MAX(D[n-1][c], D[n-1][c-W[n]*b]+V[n]*b);
                    } else {
                        D[n][c] = D[n-1][c];
                    }
                }
            }
        }
    }
    printf("[Type:%d][Capacity %d] Max Value = %d\n",
            type, KNAPSACK_CAPACITY, D[NUM_OF_ITEMS-1][KNAPSACK_CAPACITY]);


}

void gen_data() {
    srand(time(0));
    int i;
    for(i = 0; i < NUM_OF_ITEMS; i++) {
        V[i] = rand() % MAX_VALUE + 1;
        W[i] = rand() % MAX_WEIGHT + 1;
        B[i] = rand() % MAX_BOUND + 1;

        printf("[%2d]th item: V = %2d, W = %2d, B = %2d\n",
                i, V[i], W[i], B[i]);
    }
    printf("========================================\n");
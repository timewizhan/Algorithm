#include <stdio.h>

int K[5][21]; //num of objects, weight
int knapsack(int n, int W, int price[], int weight[]){
    for(int i=0;i<=n;i++){
        K[i][0] = 0;
    }
    for(int w=0;w<=W;w++){
        K[0][w] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(weight[i]>w)
                K[i][w] = K[i-1][w];
            else{
                int selected_val = K[i-1][w-weight[i]] + price[i];
                int unselected_val = K[i-1][w];
                K[i][w] = selected_val > unselected_val?selected_val:unselected_val;
            }
        }
    }
    return K[n][W];
}

int main(){
    int price[4] = {0, 10, 1, 100};
    int weight[4] = {0, 4, 1, 11};
    int Weight = 10; //º£³¶ 10kg
    int max_val = knapsack(3, Weight, price, weight);
    printf("max price: %d", max_val);
    return 0;
}
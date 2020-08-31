// Here, we also have to initialize row 2nd as well...
#include<stdio.h>
int static t[1000][1000];
int min(int a,int b){
    if(a<=b){
        return a;
    }
    else{
        return b;
    }
}
void knapsack(int arr[],int sum,int n){
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= min(1+ t[i][j-arr[i-1]], 0+ t[i-1][j]); // Adding 1 means we are including that element and counts it as 1.
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    // printing the 2-D array...
    for(int x=0;x<n+1;x++){
        for(int u=0;u<sum+1;u++){
            printf("%d ",t[x][u]);
        }
        printf("\n");
    }
    // printing the minimum no. of coins needed to achieve given sum value...
    printf("%d",t[n][sum]);
}

void main(){
    int coin[]={3,2,1};
    int sum=5,n=3;
    for(int i=0;i<n+1;i++){
        t[i][0]=0;
    }
    for(int j=0;j<sum+1;j++){
        t[0][j]=__INT_MAX__-1;
    }
    int i=1;
    for(int j=1;j<sum+1;j++){
        if(j% coin[0]==0){
            t[i][j]=(j/coin[0]);
        }
        else{
            t[i][j]=__INT_MAX__-1;
        }
    }
    knapsack(coin,sum,n);
}
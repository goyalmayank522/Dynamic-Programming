#include<stdio.h>
int static t[1000][1000];
void knapsack(int arr[],int sum,int n){
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    printf("%d",t[n][sum]);
    // Another solution is that replace '+' by "||" and print the count of no. of ones in last column.
}

void main(){
    int coin[]={1,2,3};
    int sum=6,n=3;
    for(int j=0;j<sum+1;j++){
        t[0][j]=0;
    }
    t[0][0]=1;
    knapsack(coin,sum,n);
}
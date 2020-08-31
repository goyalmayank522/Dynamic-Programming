#include<stdio.h>
int static t[1000][1000];
void knapsack(int arr[],int sum,int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j]; // here '||' is used bcoz true and false...
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    printf("%d",t[n][sum]);
}

void main(){
    int arr[]={2,6,4,9};
    int sum=8,n=4;
    for(int j=0;j<sum+1;j++){
        t[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        t[i][0]=1;
    }
    knapsack(arr,sum,n);
}
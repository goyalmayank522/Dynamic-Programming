#include<stdio.h>
int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int knapsack(int w[],int p[],int W,int n){
    if(W==0 || n==0){
        return 0;
    }

    if(w[n-1]<=W){
        return max((p[n-1]+ knapsack(w,p,W-w[n-1],n-1)), (knapsack(w,p,W,n-1)));
    }
    else{
        return (knapsack(w,p,W,n-1));
    }
}

void main(){
    int w[]={2,4,6,1,2};
    int p[]={5,8,1,3,2};
    int W=9;
    int n=5;
    int result;
    result= knapsack(w,p,W,n);
    printf("%d",result);
}
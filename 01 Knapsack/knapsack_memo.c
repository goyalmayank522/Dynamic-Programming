#include<stdio.h>
int static t[1000][1000];
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
    if(t[n][W]!=-1){
        return t[n][W];
    }
    if(w[n-1]<=W){
        return t[n][W]= max((p[n-1]+ knapsack(w,p,W-w[n-1],n-1)), (knapsack(w,p,W,n-1)));
    }
    else{
        return t[n][W]=knapsack(w,p,W,n-1);
    }
}

void main(){
    int w[]={2,4,6,1,2};
    int p[]={5,8,1,3,2};
    int W=9;
    int n=5;
    int result;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            t[i][j]=-1;
        }
    }
    result= knapsack(w,p,W,n);
    printf("%d",result);
}
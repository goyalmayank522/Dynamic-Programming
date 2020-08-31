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
void knapsack(int w[],int p[],int W,int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1]<=j){
                t[i][j]= max((p[i-1]+t[i-1][j-w[i-1]]),(t[i-1][j]));
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    printf("%d",t[n][W]);    
}

void main(){
    int w[]={2,4,6,1,2};
    int p[]={5,8,1,3,2};
    int W=9;
    int n=5;
    int result;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    knapsack(w,p,W,n);
}
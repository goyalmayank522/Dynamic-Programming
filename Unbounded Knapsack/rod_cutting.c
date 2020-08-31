// unbounded knapsack have multiple occurance...
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
void unbounded_knapsack(int w[],int p[],int W,int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1]<=j){
                t[i][j]= max((p[i-1]+t[i][j-w[i-1]]),(t[i-1][j])); // t[i-1] is replaced by t[i] bcoz if we accept that element then we can add it(or not) again and again.
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    printf("%d",t[n][W]);    
}

void main(){
    int length[]={2,4,5,7,9};
    int price[]={5,8,10,13,19};
    int max_len=9;
    int n=5;
    int result;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<max_len+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    unbounded_knapsack(length,price,max_len,n);
}
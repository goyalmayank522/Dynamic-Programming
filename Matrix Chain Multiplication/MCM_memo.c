#include<stdio.h>
int t[1000][1000];
int mcm(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int min=__INT_MAX__;
    for(int k=i;k<=j-1;k++){
        int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<min){
            min=temp;
        }
    }
    return t[i][j]=min;
}

void main(){
    int arr[]={1,3,3,4};
    int l=4;
    t[l][l];
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            t[i][j]=-1;
        }
    }
    int res=mcm(arr,1,l-1);
    printf("%d",res);
}
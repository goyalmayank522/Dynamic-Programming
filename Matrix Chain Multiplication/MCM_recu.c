#include<stdio.h>
int mcm(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    int min=__INT_MAX__;
    for(int k=i;k<=j-1;k++){
        int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<min){
            min=temp;
        }
    }
    return min;
}

void main(){
    int arr[]={1,3,3,4};
    int l=4;
    int res=mcm(arr,1,l-1);
    printf("%d",res);
}
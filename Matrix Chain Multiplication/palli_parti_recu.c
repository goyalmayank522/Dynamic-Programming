// (1) Find i and j value  (2) Find Base Condition  (3) Find for loop values (4) ans <- temp_ans (means min,max...)
#include<stdio.h>
int is_pallindrome(char arr[],int i,int j){
    if(i==j){
        return 1;
    }
    while(i<j)
    {
        if(arr[i]!=arr[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int mcm(char arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    if(is_pallindrome(arr,i,j)==1){
        return 0;
    }
    int min=__INT_MAX__;
    for(int k=i;k<=j-1;k++){
        int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+1;
        if(temp<min){
            min=temp;
        }
    }
    return min;
}

void main(){
    char arr[]="mayank";
    int l=6;
    int res=mcm(arr,0,l-1);
    printf("%d",res);
}
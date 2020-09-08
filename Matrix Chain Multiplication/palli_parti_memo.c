#include<stdio.h>
int t[1000][1000];
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
int mcm(char arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
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
    return t[i][j]=min;
}

void main(){
    char arr[]="mayank";
    int l=6;
    t[l][l];
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            t[i][j]=-1;
        }
    }
    int res=mcm(arr,0,l-1);
    printf("%d",res);
}
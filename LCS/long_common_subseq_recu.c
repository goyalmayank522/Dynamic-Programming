#include<stdio.h>
#include<string.h>
int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int lcs(char w[],char p[],int w_len,int p_len){
    if(w_len==0 || p_len==0){
        return 0;
    }
    if(w[w_len-1]==p[p_len-1]){
        return (1+ lcs(w,p,w_len-1,p_len-1));
    }
    else{
        return max(lcs(w,p,w_len-1,p_len),lcs(w,p,w_len,p_len-1));
    }
}

void main(){
    char w[]="mayank";
    char p[]="goyal";
    int w_len=6;
    int p_len=5;
    int result;
    result= lcs(w,p,w_len,p_len);
    printf("%d",result);
}
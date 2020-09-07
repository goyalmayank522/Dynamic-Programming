#include<stdio.h>
#include<string.h>
int t[1000][1000];
int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int lcs(char w[],char p[],int w_len,int p_len){
    for(int i=1;i<w_len+1;i++){
        for(int j=1;j<p_len+1;j++){
            if(w[i-1]==p[j-1] && i!=j){
                t[i][j]= 1+ t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    /*
    for(int x=0;x<w_len+1;x++){
        for(int y=0;y<p_len+1;y++){
            printf("%d  ",t[x][y]);
        }
        printf("\n");
    }*/
    return t[w_len][p_len];
}

void main(){
    char w[]="aacgbggbbded";
    int w_len=10;
    char p[w_len];
    for(int f=0;f<w_len;f++){
        p[f]=w[f];
    }
    int p_len=w_len;
    int result;
    for(int i=0;i<w_len+1;i++){
        for(int j=0;j<p_len+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    result= lcs(w,p,w_len,p_len);
    printf("%d",result);
}
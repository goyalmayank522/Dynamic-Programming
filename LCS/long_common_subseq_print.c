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
void lcs(char w[],char p[],int w_len,int p_len){
    for(int i=1;i<w_len+1;i++){
        for(int j=1;j<p_len+1;j++){
            if(w[i-1]==p[j-1]){
                t[i][j]= 1+ t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    int x=w_len,y=p_len,m=0;
    char f[w_len];
    while(x>0 && y>0){
        if(w[x-1]==p[y-1]){
            f[m]=w[x-1];
            x--;y--;m++;
        }
        else
        {
            if(t[x-1][y]<t[x][y-1]){
                y--;
            }
            else{
                x--;
            }
        }
    }
    for(int r=--m;r>=0;r--){
        printf("%c",f[r]);
    }
}

void main(){
    char w[]="mayank";
    char p[]="mayahtrnk";
    int w_len=6;
    int p_len=9;
    int result;
    for(int i=0;i<w_len+1;i++){
        for(int j=0;j<p_len+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }
    lcs(w,p,w_len,p_len);
}
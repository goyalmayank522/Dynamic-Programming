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
    int all_max=0;
    for(int i=1;i<w_len+1;i++){
        for(int j=1;j<p_len+1;j++){
            if(w[i-1]==p[j-1]){
                t[i][j]= 1+ t[i-1][j-1];
                if(t[i][j]>all_max){
                    all_max=t[i][j];
                }
            }
            else{
                t[i][j]=0;
            }
        }
    }
    /*
    for(int x=0;x<w_len+1;x++){
        for(int y=0;y<p_len+1;y++){
            printf("%d  ",t[x][y]);
        }
        printf("\n");
    }
    printf("%d",all_max);
    return t[w_len][p_len];
    */
    return all_max;
}

void main(){
    char w[]="mayank";
    char p[]="hayang";
    int w_len=6;
    int p_len=6;
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
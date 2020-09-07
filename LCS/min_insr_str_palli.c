// same as min. no. of deletion to form string a pallindrome bcoz no. of deletions == no. of insertions
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
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    printf("%d",w_len-t[w_len][p_len]);
}

void main(){
    char w[]="agbcba";
    int w_len=6;
    char p[w_len];
    int h=0;
    for(int i=w_len-1;i>=0;i--){
        p[h]=w[i];
        h++;  
    }
    int p_len=w_len;
    for(int i=0;i<w_len+1;i++){
        for(int j=0;j<p_len+1;j++){
            if(i==0|| j==0){
                t[i][j]=0;
            }
        }
    }
    lcs(w,p,w_len,p_len);
}
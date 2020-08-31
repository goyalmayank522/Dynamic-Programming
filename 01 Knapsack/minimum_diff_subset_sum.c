#include<stdio.h>
int static t[1000][1000];
void knapsack(int arr[],int sum,int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]= t[i-1][j];
            }
        }
    }

    /*
    for(int g=0;g<n+1;g++){
        for(int h=0;h<sum+1;h++){
            printf("%d ",t[g][h]);
        }
        printf("\n");
    }*/

    int all_min=sum;
    for(int k=0;k<=(sum)/2;k++){
        if(t[n][k]==1 && all_min>(sum-2*k)){
            all_min=sum-2*k;
        }
    }
    //printf("%d\n",(sum)/2);
    printf("%d",all_min);
}

void main(){
    int arr[]={1,3,7,10,20};
    int n=5,sum=0;
    for(int z=0;z<n;z++){
        sum+=arr[z];
    }
    for(int j=0;j<sum+1;j++){
        t[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        t[i][0]=1;
    }
    knapsack(arr,sum,n);
}
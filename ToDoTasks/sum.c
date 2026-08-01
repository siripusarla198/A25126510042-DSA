#include<stdio.h>
int main(){
    int n;
    int target;
    printf("enter the size of an array");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter the value of arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the target value:");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                printf("the indexes of these two numbers are %d and %d\n",i,j);
            }
        }
    }
    return 0;
}
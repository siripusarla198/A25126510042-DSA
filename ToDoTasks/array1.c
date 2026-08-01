#include<stdio.h>
#include<stdbool.h>
int main(){
int n,k;
scanf("%d",&n);
int arr[n],i;
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
int change;
printf("Do you want to change another value? (1=Yes, 0=No): ");
scanf("%d",&change);
while(change == 1){
    printf("Enter index to change: ");
    scanf("%d",&k);
    arr[k] = -1;
    printf("Do you want to change another value? (1=Yes, 0=No): ");
    scanf("%d",&change);
}
printf("the new array is:\n");
for(i=0;i<n;i++){
    printf("%d ",arr[i]);
}
   return 0;
}
#include<stdio.h>
int sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return 0;
}
int main(){
    int n1,n2,n3;
    printf("enter the size of first array:");
    scanf("%d",&n1);
    printf("enter the size of second array:");
    scanf("%d",&n2);
    n3=n1+n2;
    int a[n1],b[n2],c[n3];
    printf("enter the elements of first array:\n"); 
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the elements of second array:\n");
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    sort(a,n1);
    sort(b,n2);
    for(int i=0;i<n1;i++){
        c[i]=a[i];
    }
    for(int i=0;i<n2;i++){
        c[n1+i]=b[i];
    }
    sort(c,n3);
    for(int i=0;i<n3-1;i++){
        if(c[i]==c[i+1]){
            c[i]=-1;
        }
    }
    printf("sorted array of first array:\n");
    for(int i=0;i<n1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("sorted array of second array:\n");
    for(int i=0;i<n2;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    printf("merged array is :\n");
    for(int i=0;i<n3;i++){
        if(c[i]!=-1){
            printf("%d ",c[i]);
        }
    }

}
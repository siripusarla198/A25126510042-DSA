#include<stdio.h>
void  pattern6(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}
void pattern7(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }   
        printf("\n");
    }
}
void pattern8(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            printf("*");
        }
        for(int j=0;j<i;j++){
            printf(" ");
        }
        printf("\n");
    }
}
void pattern9(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("*");
        }
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            printf(" ");
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            printf("*");
        }
        for(int j=0;j<i;j++){
            printf(" ");
        }
        printf("\n");
    }
    
}
void pattern10(int n){
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>=n)
            stars=2*n-i;
            for(int j=1;j<=stars;j++){
                printf("*");
            }
        printf("\n");
        }
    }
void pattern11(int n){
for(int i=0;i<n;i++){
    int star;
    if(i%2==0){
        star=1;}
        else{
        star=0;}
    for(int j=0;j<=i;j++){
        printf("%d",star);
        star=1-star;
    }
    printf("\n");
}
}
void pattern12(int n){
    int space=2*(n-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        for(int j=1;j<=space;j++){
            printf(" ");
        }
        for(int j=i;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
        space-=2;
}
}
void pattern13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",num);
            num++;
        }
        printf("\n");
    }
    
}
void pattern14(int n){
    char ch[4] = {'A', 'B', 'C', 'D'};
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%c",ch[j]);
        }
        printf("\n");
    }
}
void pattern15(int n){
    char ch[4] = {'A', 'B', 'C', 'D'};
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            printf("%c",ch[j]);
        }
        printf("\n");
    }
}
void pattern16(int n){
    char ch[4] = {'A', 'B', 'C', 'D'};
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%c",ch[i]);
        }
        printf("\n");
    }
}
void pattern17(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        char ch='A';
        for(int j=0;j<2*i+1;j++){
            printf("%c",ch);
            if(j<i)
                ch++;
            else
                ch--;
        }
        for(int j=0;j<n-i-1;j++){
            printf(" ");
        }
        printf("\n");
    }
}
void pattern18(int n){
    char ch[]={'A','B','C','D','E','F','G','H'};
    for(int i=0;i<n;i++){
        for(int j=n-i-1;j<n;j++){
            printf("%c",ch[j]);
        }
        printf("\n");
    }
}
void pattern19(int n){
    int spaces=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            printf("*");
        }
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        for(int j=0;j<n-i;j++){
            printf("*");
        }
        spaces+=2;
        printf("\n");
    }
    spaces=2*(n-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        spaces-=2;
        printf("\n");
    }
}
void pattern20(int n){
    for(int i=0;i<2*n-1;i++){
        int stars=i;
        if(i>=n)
            stars=2*n-i-2;
        for(int j=0;j<stars;j++){
            printf("*");
        }
        int spaces=2*(n-stars);
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        for(int j=0;j<stars;j++){
            printf("*");
        }
        printf("\n");
    }
}
void pattern21(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||j==0||j==n-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
void pattern22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
        int bottom =j;
        int right=2*n-2-i;
        int left=2*n-2-j;
        printf("%d",n-((top<bottom?top:bottom)<(right<left?right:left)?(top<bottom?top:bottom):(right<left?right:left)));
        }   
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    pattern22(n);
    return 0;
}
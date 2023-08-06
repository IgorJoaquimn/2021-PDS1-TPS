#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    
    int matriz[n];
    int mm[n];

    for (int i=0; i<n; i++)
        matriz[i] = i;
    

    
    for (int i=0; i<n; i++)
        mm[i] = 55;

    for (int i=0; i<=n; i++)
        printf("%d ",mm[i]);

    printf("\n");
    for (int i=0; i<=n; i++)
        printf("%d ",matriz[i]);

}
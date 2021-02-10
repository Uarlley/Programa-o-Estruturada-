#include <stdio.h>

int main(){
    int x,n[10],i=0;
    scanf("%d",&x);
    n[i]=x;
    printf("N[%d] = %d\n",i,x);
    for(i=1;i<10;i++){
        x=x*2;
        printf("N[%d] = %d\n",i,x);
    }
    return 0;

}
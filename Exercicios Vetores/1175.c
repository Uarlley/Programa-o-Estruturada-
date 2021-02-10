#include <stdio.h>

int main(){
    int i1,i2=0,n[20],x,a[20];

    for (i1=0;i1<20;i1++){
        scanf("%d",&x);
        n[i1]=x;
    }
    i1=19;
    for(i2=0;i2<20;i2++){
        a[i2]=n[i1+1];
        printf("N[%d] = %d\n",i2,n[i1]);
        i1--;
    }
    return 0;
}
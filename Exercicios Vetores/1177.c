#include <stdio.h>

int main(){
    int a[1000],c1=0,c2=0,t;
    scanf("%d",&t);
    while(c1<=1000){
        while(c2<=(t-1)){
            if (c1==1000)
                return 0;
            a[c1]=c2;
            printf("N[%d] = %d\n",c1,a[c2]);
            c1++;
            c2++;
        }
        c2=0;
    }
}

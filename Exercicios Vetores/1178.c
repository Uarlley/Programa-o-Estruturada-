#include <stdio.h>

int main(){
    double a[100],x;
    int i;
    scanf("%lf",&x);
    a[0]=x;
    printf("N[%d] = %.4lf\n",0,a[0]);
    for(i=1;i<100;i++){
        a[i]=x/2;
        printf("N[%d] = %.4lf\n",i,a[i]);
        x=x/2;
    }
    return 0;
}
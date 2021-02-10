#include <stdio.h>

int main(){
    double a[100],x;
    int i;
    for(i=0;i<100;i++){
        scanf("%lf",&x);
        a[i]=x;
    }
    for(i=0;i<100;i++){
        if (a[i]<=10){
            printf("A[%d] = %.1lf\n",i,a[i]);
        }
    }
    return 0;

}

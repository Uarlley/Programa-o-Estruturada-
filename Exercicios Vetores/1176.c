#include <stdio.h>

int main(){
    unsigned long long int f[61];
    int i1,i2,t,n;
    f[0]=0;
    f[1]=1;
    scanf("%d",&t);
    for(i1=0;i1<t;i1++){
        scanf("%d",&n);
        for(i2=2;i2<=n;i2++){
            f[i2]=f[i2-1] + f[i2-2];
        }
        printf("Fib(%d) = %llu\n",n,f[n]);
    }
    return 0;
}
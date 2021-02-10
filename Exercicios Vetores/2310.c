#include <stdio.h>

int main(){
    int s[100],b[100],a[100],a2[100],b2[100],s2[100],j[100],n,i;
    float ts=0,tb=0,ta=0,ts2=0,tb2=0,ta2=0;
    char nome[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",nome);
        scanf("%d %d %d",&s[i],&b[i],&a[i]);
        scanf("%d %d %d",&s2[i],&b2[i],&a2[i]);
    }
    for(i=0;i<n;i++){
        ts=ts + s[i];
        tb=tb + b[i];
        ta=ta + a[i];
        ts2=ts2 + s2[i];
        tb2=tb2 + b2[i];
        ta2=ta2 + a2[i];
    }
    if (ts==0)
        ts=1;

    else if (ta==0)
        ta=1;

    else if (tb==0)
        tb=1;

    printf("Pontos de Saque: %.2f %%.\n",(ts2/ts)*100);
    printf("Pontos de Bloqueio: %.2f %%.\n",(tb2/tb)*100);
    printf("Pontos de Ataque: %.2f %%.\n",(ta2/ta)*100);
    return 0;

}
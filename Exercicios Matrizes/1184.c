#include <stdio.h>

void main(){
    float m[12][12],soma=0;
    int l,c,i=0;
    char t;
    scanf("%c",&t);

    for(l=0;l<12;l++){
        for(c=0;c<12;c++){
            scanf("%f",&m[l][c]);
        }
    }
    for(l=0;l<12;l++){
        for(c=0;c<12;c++){
            if (l>c){
                soma+=m[l][c];
                i++;
            }
        }
    }
    if (t=='S')
        printf("%.1f\n",soma);
    else if (t=='M')
        printf("%.1f\n",soma/i);
}
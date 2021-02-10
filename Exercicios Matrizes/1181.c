#include <stdio.h>
void main(){
    float m[12][12],soma;
    int l,c,i;
    char t;
    scanf("%d %c",&i,&t);
    
    for(l=0;l<12;l++){
        for(c=0;c<12;c++){
            scanf("%f",&m[l][c]);
        }
    }
    for(c=0;c<12;c++){
        soma+=m[i][c];
    }
    if (t=='S')
        printf("%.1f\n",soma);
    else if (t=='M')
        printf("%.1f\n",soma/12);

}
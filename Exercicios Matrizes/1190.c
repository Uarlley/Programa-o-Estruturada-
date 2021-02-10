#include <stdio.h>

void main(){
    float m[12][12],soma=0,n;
    int i,j,c,col,seg;
    char s;
    scanf(" %c",&s);
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            scanf("%f",&n);
            m[i][j]=n;
        }
    }
    i=0;
    while(j>i){
        for(c=0;i>c;c++){
            soma+=m[i][col];
            col--;
        }
        j--;
        i++;
        col=11;
    }
    seg=5;
    while(seg>0){
        for(c=0;seg>c;c++){
            soma+=m[i][col];
            col--;
        }
        seg--;
        i++;
        col=11;
    }
    if (s=='S')
        printf("%.1f\n",soma);
    else if(s=='M')
        printf("%.1f\n",soma/30);
}

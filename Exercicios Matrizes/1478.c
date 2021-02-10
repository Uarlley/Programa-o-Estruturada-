#include <stdio.h>

void entrada(int n){
    int m[100][100],i=0,j=0,d=1,cont;
    cont=0;
    while(i<n){
        for(j;j<n;j++){
            m[i][j]=d;
            d++;
        }
        d=1;
        j=cont;
        for(i;i<n;i++){
            m[i][j]=d;
            d++;
        }
        d=1;
        cont++;
        i=cont;
        j=cont;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (j+1==n){
                printf("%3d\n",m[i][j]);
                break;
            }
            printf("%3d ",m[i][j]);
        }
    }
    printf("\n");
}

int main(){
    int n=1;
    while(n!=0){
        scanf("%d",&n);
        if (n==0)
            break;
        entrada(n);
    }
}


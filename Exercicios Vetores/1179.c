#include <stdio.h>

int main(){
    int i,par[5],impar[5],x,cp=0,ci=0,v1,v2;
    for(i=0;i<17;i++){
        if (cp==5){
            for(v1=0;v1<cp;v1++){
                printf("par[%d] = %d\n",v1,par[v1]);
            }
            cp=0;
        }
        else if (ci==5){
            for(v2=0;v2<ci;v2++){
                printf("impar[%d] = %d\n",v2,impar[v2]);
            }
            ci=0;
        }
        else{
            scanf("%d",&x);
            if (x%2==0){
                par[cp]=x;
                cp++;
            }
            else{
                impar[ci]=x;
                ci++;
            }
        }

    }
    for(v2=0;v2<ci;v2++){
        printf("impar[%d] = %d\n",v2,impar[v2]);
    }

    for(v1=0;v1<cp;v1++){
        printf("par[%d] = %d\n",v1,par[v1]);
    }
    return 0;
}
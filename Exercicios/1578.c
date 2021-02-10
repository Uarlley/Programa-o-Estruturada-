#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned long long int maioral(unsigned long long int n[20],int q){
	unsigned long long int m=0,i;
	for(i=0;i<q;i++){
		if(n[i]>m)
			m=n[i];
	}
	return m;
}
int tam(unsigned long long n){
	int t=1;
	while(n>=10){
		n/=10;
		t++;
	}
	return t;
}
int main(void){
	int i,j,n,q,k,maiori=0,maiorj=0,g;
	unsigned long long int matriz[20][20],mm[20],e;
	char numero[21];
	scanf("%d",&q);
	for(k=0;k<q;k++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%llu",&matriz[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				matriz[i][j]=matriz[i][j]*matriz[i][j];
			}
		}
		printf("Quadrado da matriz #%d:\n",k+4);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(g=0;g<n;g++){
					mm[g]=matriz[g][j];
				}
				e=maioral(mm,n);
				if(j+1==n)
                    printf("%*llu",tam(e),matriz[i][j]);
                else
                    printf("%*llu ",tam(e),matriz[i][j]);
			}
            printf("\n");
		}
        if(k+1!=q)
            printf("\n");
	}
}

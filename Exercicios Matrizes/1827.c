#include <stdio.h>
int main(){
	int m[101][101],n,i,j,l,c,ini,fim;
	while(scanf("%d",&n)!=EOF){
		ini=(n-1)/3;
		fim= (n-1)-ini;
		//preenchendo a matriz 
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					m[i][j]=2;
				}
				else if(j+i==n-1){
					m[i][j]=3;
				}
				else{
					m[i][j]=0;
				}
			}
		}
		//preenchendo a matriz no meio
		if (n%3==0){
			for(i=ini+1;i<=fim-1;i++){
				for(j=ini+1;j<=fim-1;j++){
					if (i==n/2 && j==n/2){
						m[i][j]=4;
				}
					else{
						m[i][j]=1;
					}
				}
			}
		}
		else{
			for(i=ini;i<=fim;i++){
				for(j=ini;j<=fim;j++){
					if (i==n/2 && j==n/2){
						m[i][j]=4;
					}
					else{
						m[i][j]=1;
					}
				}
			}
		
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d",m[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
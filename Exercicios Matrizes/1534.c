#include <stdio.h>
#include <string.h>

void main(){
	int m[70][70],i,j,n=0;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if((i+j)==n-1){
					m[i][j]=2;
				}
				else if(i==j){
					m[i][j]=1;
				}
				else{
					m[i][j]=3;
				}	
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if (j+1==n){
					printf("%d\n",m[i][j]);
					break;
				}
				printf("%d",m[i][j]);
			}
		}
	}
}
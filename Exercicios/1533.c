#include <stdio.h>
int main(void){
	int suspeitos[1000],n,m,s=0,i;
	while(scanf("%d",&n)!=0){
		if(n==0)
			break;
		for(i=0;i<n;i++){
			scanf("%d",&suspeitos[i]);
			if(i==1){
				if(suspeitos[i-1]>suspeitos[i]){
					m=i;
					s=i+1;
				}
				else{
					m=i+1;
					s=i;
				}
			}
			else if(suspeitos[i]>suspeitos[m-1]){
				s=m;
				m=i+1;
			}
			else if(suspeitos[i]>suspeitos[s-1])
				s=i+1;
		}
		printf("%d\n",s);
	}
	
}
	
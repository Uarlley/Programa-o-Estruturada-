#include <stdio.h>

int main(){
	unsigned long long int atributos,m[100][100],l[100][100];
	int marc,luci,l1,c1,l2,c2,escm,escl,at_escolhido;
	while(scanf("%lld",&atributos)!=EOF){
		scanf("%d %d",&marc,&luci);
		//cartas de marcos
		for(l1=0;l1<marc;l1++){
			for(c1=0;c1<atributos;c1++){
				scanf("%lld",&m[l1][c1]);
			}
		}
		//cartas de luciano
		for(l2=0;l2<luci;l2++){
			for(c2=0;c2<atributos;c2++){
				scanf("%lld",&l[l2][c2]);
			}
		}
		scanf("%d %d",&escm,&escl);
		scanf("%d",&at_escolhido);
		//resultado
		if (m[escm-1][at_escolhido-1] > l[escl-1][at_escolhido-1]){
			printf("Marcos\n");
		}
		else if (l[escl-1][at_escolhido-1] > m[escm-1][at_escolhido-1]){
			printf("Leonardo\n");
		}
		else{
			printf("Empate\n");
		}
	}

    return 0;
}

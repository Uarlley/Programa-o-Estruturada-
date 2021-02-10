#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,p=0;
	long int amostras,mag[10000];
	scanf("%ld",&amostras);
	while(1){
		if (amostras==0)
			break;
		for(i=0;i<amostras;i++){
			scanf("%ld",&mag[i]);
		}
		if (amostras==2)
			p=2;
		else if(amostras!=2){
			for(i=0;i<amostras;i++){
				if (i+2==amostras){
					if((mag[i]<mag[i+1] && mag[i+1]>mag[0]) || (mag[i]>mag[i+1] && mag[i+1]<mag[0]))
						p++;
					if((mag[i+1]<mag[0] && mag[0]>mag[1]) || (mag[i+1]>mag[0] && mag[0]<mag[1]))
						p++;
					break;
				}	
				else if((mag[i]<mag[i+1] && mag[i+1]>mag[i+2]) || (mag[i]>mag[i+1] && mag[i+1]<mag[i+2]))
					p++;
			}
		}
		printf("%d\n",p);
		scanf("%ld",&amostras);
		p=0;
	}	
}
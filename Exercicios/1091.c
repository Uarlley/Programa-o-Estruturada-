#include <stdio.h>

int main(){
	long int k,m,n,x,y;
	int i;
	scanf("%ld",&k);
	while(1){
		if(k==0){
			break;
		}
		scanf("%ld %ld",&m,&n);
		for(i=0;i<k;i++){
			scanf("%ld %ld",&x,&y);
			if((x-m)>0 && (y-n)>0)
				printf("NE\n");
			else if((x-m)>0 && (y-n)<0)
				printf("SE\n");
			else if((x-m)<0 && (y-n)<0)
				printf("SO\n");
			else if((x-m)<0 && (y-n)>0)
				printf("NO\n");
			else if((x-m)==0 || (y-n)==0)
				printf("divisa\n");
		}
		scanf("%ld",&k);
	}
}
		
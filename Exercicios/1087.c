#include <stdio.h>
#include <stdlib.h>
void main(){
	int i1,i2,j1,j2;
	scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
	while(i1!=0 && i2!=0 && j1!=0 && j2!=0){
		if (i1==i2 && j1==j2)
			printf("0\n");
		else if ((abs(i1-i2)==abs(j1-j2)) || (i1==i2 || j1==j2))
			printf("1\n");
		else
			printf("2\n");
		scanf("%d%d%d%d",&i1,&j1,&i2,&j2);
	}
}

#include <stdio.h>

int subs(int a[10]){
	int i;
	for(i=0;i<10;i++){
		if (a[i]<0 || a[i]==0){
			a[i]=1;
		}
		printf("X[%d] = %d\n",i,a[i]);	
	}
	return 0;
}

int main(){
	int x,i=0;
	int a[10];
	while(i<10){
		scanf("%d",&x);
		a[i]=x;
		i++;
	}
	subs(a);
	return 0;
}

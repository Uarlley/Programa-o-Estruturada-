#include <stdio.h>
int veri(int sudoku[9][9]){
	int i,j,c,vetor[9],comp[9]={1,2,3,4,5,6,7,8,9},linha=0,jooj=0,coluna=0;
	for(c=0;c<9;c++){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(comp[c]==sudoku[i][j])
					linha=1;
				if(comp[c]==sudoku[j][i])
					coluna=1;
			}
			jooj+=linha+coluna;
			linha=0;
			coluna=0;	
		}
	}
	return jooj;
}
int veri2(int sudoku[9][9]){
    //preciso fazer essa funcao verificar cada submatriz 3x3 de uma matriz 9x9
	int i,j,comp[9]={1,2,3,4,5,6,7,8,9},c,m=0,k=3,l,n,t1=0,t2=0,t3=0,t4=0,t5=0,total=0,o,p;
    while(k<10){
        for(c=0;c<9;c++){
            for(i=m;i<k;i++){
                for(j=m;j<k;j++){
                    if(comp[c]==sudoku[i][j]){
                        t1=1;
                    }
                }
            }
            total+=t1;
            t1=0;
            if(k>3){
                for(l=m-3;l<m;l++){
                    for(n=m;n<k;n++){
                        if(comp[c]==sudoku[l][n]){
                            t2=1;
                        }
                        if(comp[c]==sudoku[l][n]){
                            t3=1;
                        }
                    }
                }
                total+=t2+t3;
                t2=0;
                t3=0;
            }
            if(k>6){
                for(o=m-6;o<m;o++){
                    for(p=m;p<k;p++){
                        if(comp[c]==sudoku[o][p]){
                            t4=1;
                        }
                        if(comp[c]==sudoku[p][o]){
                            t5=1;
                        }
                    }
                }
                total+=t4+t5;
                t4=0;
                t5=0;
            }
        }
        m=k;
        k+=3;
    }
    return total;
}
int main(void){
	int sudoku[9][9],i,j,testes=0,c,cu=0;
	scanf("%d",&testes);
	for(c=0;c<testes;c++){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				scanf("%d",&sudoku[i][j]);
				cu+=sudoku[i][j];
			}
		}
		if (cu!=405 || veri(sudoku)!=162 || veri2(sudoku)!=81){
			printf("Instancia %d\nNAO\n",c+1);
		}
		else{
			printf("Instancia %d\nSIM\n",c+1);
		}
		printf("\n");
		cu=0;
	}
}


	
	
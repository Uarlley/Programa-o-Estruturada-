#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno{
    char matricula[14];
    char nome[50];
    float cr;
}aluno;

aluno * criar(aluno *v,int tam){
    char mat[14],name[50];
    printf("Digite a matricula do aluno: ");
    fgets(mat,14,stdin);
    mat[strlen(mat)-1]=0;
    strcpy(v[tam].matricula,mat);
    printf("Digite o nome do aluno:");
    fgets(name,50,stdin);
    name[strlen(name)-1]=0;
    strcpy(v[tam].nome,name);
    printf("Digite o CR do aluno: ");
    scanf("%f",&v[tam].cr);
    getchar();
    return v;
}

void imprimir(aluno *v,int i){

}
int main(){
    aluno *lista = NULL,A;
    int capacidade = 100,tam=0,op=0;
    int i,j,k;
    FILE *arquivo;
    char nomearq[50];
    printf("Digite o nome do arquivo: ");
    scanf("%s",nomearq);
    arquivo = fopen(nomearq,"rb");
    if (arquivo==NULL){
        lista = (aluno *)calloc(capacidade,sizeof(aluno));
    }
    else{
        fread(&tam,sizeof(int),1,arquivo);
        if(tam>capacidade) capacidade = tam;
        lista = (aluno * )calloc(capacidade,sizeof(aluno));
        fread(lista,sizeof(aluno),tam,arquivo);
        fclose(arquivo);
    }
    while(1){
        printf("1 - Inserir um novo aluno\n");
        printf("2 - Imprimir dados de um aluno\n");
        printf("3 - Resgatar um aluno de uma posição na lista\n");
        printf("4 - Sair\n");
        scanf("%d",&op);
        getchar();

        if (op==1){
            if (tam>capacidade){
                capacidade*=2;
                lista = (aluno *)realloc(lista,capacidade*sizeof(aluno));
                lista = criar(lista,tam);
                tam++;
            }
            else {
                criar(lista,tam);
                tam++;
            }
        }
        else if (op==2){
            for(i=0;i<tam;i++){
                printf("\nMatricula : %s",lista[i].matricula);
                printf("\nNome: %s",lista[i].nome);
                printf("\nCR: %f\n",lista[i].cr);
            }
        }
        else if (op==3){
            arquivo=fopen(nomearq,"rb");
            if (arquivo==NULL){
                printf("\nNão foi possivel abrir o arquivo.\n");  
            }
            else{
                printf("\nDigite a posição: ");
                scanf("%d",&i);
                fseek(arquivo,sizeof(int),SEEK_SET);
                fseek(arquivo,i*sizeof(aluno),SEEK_CUR);
                fread(&A,sizeof(aluno),1,arquivo);
                printf("\nMatricula: %s\nNome: %s\nCR: %.2f\n",A.matricula,A.nome,A.cr);
                fclose(arquivo);
            }
        }
        else if (op==4){
            arquivo = fopen(nomearq,"wb");
            fwrite(&tam,sizeof(int),1,arquivo);
            fwrite(lista,sizeof(aluno),tam,arquivo);
            fclose(arquivo);
            return 0;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necess�rio para usar acentua��o
/*Grupo:
Uarlley do Nascimento Amorim
Christian Jonas Oliveira
Jo�o Victor do Roz�rio Recla
Lucas de Oliveira Suanderhus*/
void imprimir(int conjunto[100],int qnt){

    //Fun��o que apenas imprimi os elementos de um conjunto A
    int i;
    //Imprime o conjunto de entrada
    if (qnt==0)
        printf("Vazio");
    else if(qnt==1){
        printf("{ %d }",conjunto[0]);
    }
    else{
        for(i=0;i<qnt;i++){
            if (i==0)
                printf("{ %d , ",conjunto[i]);
            else if(i+1==qnt){
                printf("%d }",conjunto[i]);
                break;
            }
            else{
                printf("%d , ",conjunto[i]);
            }
        }
    }
}
void inserir(int conjunto[101],int qnt,char p){

    //Fun��o que insere um elemento dentro de um conjunto
    int i=0,n=0;
    //Entrada do elemento que ser� inserido no final do conjunto
    printf("\nDigite o elemento que deseja inserir no conjunto %c: ",p);
    scanf("%d",&n);
    //Insere o elemento na ultima posi��o do conjunto
    conjunto[qnt]=n;
}
int remover(int conjunto[100],int qnt,char p){

    //Fun��o que le e remove um elemento de um conjunto
    int i=0,n=0;
    printf("\nDigite o elemento que deseja remover do conjunto %c: ",p);//Entrada do elemento que ser� removido do conjunto
    scanf("%d",&n);
    //Processo de remo��o do elemento
    for(i=0;i<qnt;i++){
        if ( qnt==0)
            break;
        if(conjunto[i]==n){
            qnt=qnt-1;
            while(i<qnt){
                conjunto[i]=conjunto[i+1];
                i++;
            }
            break;
        }
    }
    //Impress�o do conjunto
    printf("\n%c = ",p);
    imprimir(conjunto,qnt);
    return qnt;

}
int pertence(int conjunto[100],int qnt,char p){
    //Fun��o que verifica se um elemento pertence � um conjunto
    int n=0,i;
    //Leitura do elemento que ser� avaliado
    printf("\nDigite o elemento que deseja verificar se pertence ao conjunto %c: ",p);
    scanf("%d",&n);
    //Processo de avalia��o
    for(i=0;i<qnt;i++){
        if(conjunto[i]==n){
            printf("\nO elemento %d pertence � %c!\n",n,p);
            return 0;
        }
    }
    printf("\nO elemento %d n�o pertence � %c!\n",n,p);
    return 0;
}

int subconjunto(int conjunto1[100],int conjunto2[100],int qnt1,int qnt2,char lel,char lal){
    //Fun��o que verifica se um conjunto B � subconjunto de um conjunto A
    int i1,i2;
    //Repetidores que verificam se o conjunto B pertence � A
    for(i1=0;i1<qnt1;i1++){
        for(i2=0;i2<qnt2;i2++){
            if (conjunto1[i1]==conjunto2[i2])
                break;
            else if((i2+1==qnt2) && (conjunto1[i1]!=conjunto2[i2+1]) ){
                printf("\n%c n�o � subconjunto de %c\n!",lel,lal);
                return 0;
            }
        }

    }
    printf("\n%c � subconjunto de %c\n!",lel,lal);

}

void uniao(int conjunto1[100],int conjunto2[100],int qnt1,int qnt2,char lel,char lal){
    //Fun��o que realiza a uni�o de um conjunto A e um conjunto B
    int conjunto3[200],qnt3=0,i1,i2,i3=0;
    if (qnt1>=qnt2){
    //O conjunto resultante ja � preenchido com os elementos do conjunto com maior tamanho
        for(i3=0;i3<qnt1;i3++){
            conjunto3[i3]=conjunto1[i3];
        }
    //Bastando apenas colocar apenas os elementos que est�o no menor tamanho no maior
        for(i2=0;i2<qnt2;i2++){
            for(i3=0;i3<qnt1;i3++){
                if(i3+1==qnt1){
                    if(conjunto2[i2]==conjunto3[i3+1])
                        break;
                    conjunto3[qnt1]=conjunto2[i2];
                    qnt1++;
                    break;
                }
                if(conjunto2[i2]==conjunto3[i3]){
                    break;
                }
            }
        }
        qnt3=qnt1;
    }
    else if (qnt2>qnt1){
        //O conjunto resultante ja � preenchido com os elementos do conjunto com maior tamanho
        for(i3=0;i3<qnt2;i3++){
            conjunto3[i3]=conjunto2[i3];
        }
        //Bastando apenas colocar apenas os elementos que est�o no menor tamanho no maior
        for(i1=0;i1<qnt1;i1++){
            for(i3=0;i3<qnt2;i3++){
                if(i3+1==qnt2){
                    if(conjunto1[i1]==conjunto3[i3+1])
                        break;
                    conjunto3[qnt2]=conjunto1[i1];
                    qnt2++;
                    break;
                }
                if(conjunto1[i1]==conjunto3[i3]){
                    break;
                }
            }
        }
        qnt3=qnt2;
    }
    //Impress�o do conjunto resultante
    printf("A uni�o entre %c e %c �: ",lel,lal);
    imprimir(conjunto3,qnt3);
}

void intersecao(int conjunto1[100],int conjunto2[100],int qnt1,int qnt2,char lal,char lel){
    //Fun��o que realiza a interse��o entre um conjunto A e um conjunto B
    int conjunto3[100],qnt3=0,i1,i2,i3=0;

    //O conjunto resultante receber� apenas os elementos que pertencem � A e B
    for(i1=0;i1<qnt1;i1++){
        for(i2=0;i2<qnt2;i2++){
            if(conjunto1[i1]==conjunto2[i2]){
                conjunto3[i3]=conjunto1[i1];
                i3++;
                qnt3++;
                break;
            }
        }
    }
    //Impress�o do conjunto resultante
    printf("\nA interse��o entre %c e %c �: ",lal,lel);
    imprimir(conjunto3,qnt3);

}

void subtracao(int conjunto1[100],int conjunto2[100],int qnt1,int qnt2,char lal, char lel){
    //Fun��o que realiza a opera��o A - B
    int conjunto3[100],qnt3=0,i1,i2,i3=0;
    //Realiza a compara��o entre os elementos de A e B
    for(i1=0;i1<qnt1;i1++){
        for(i2=0;i2<qnt2;i2++){
            if(conjunto1[i1]==conjunto2[i2])
                break;
            else if((conjunto1[i1]!=conjunto2[i2]) && (i2+1==qnt2)){
                //Caso um elemento n perten�a � A e n�o perten�a � B, ele entra no conjunto resultante
                conjunto3[i3]=conjunto1[i1];
                i3++;
                qnt3++;
                break;
            }
        }
    }
    if (qnt2==0){
        qnt3=qnt1;
        for(i3=0;i3<qnt3;i3++){
            conjunto3[i3]=conjunto1[i3];
        }
    }
    //Impress�o do conjunto resultante
    printf("%c - %c = ",lal,lel);
    imprimir(conjunto3,qnt3);
}
void produto_cartesiano(int conjunto1[100],int conjunto2[100],int qnt1,int qnt2,char lal,char lel){
    int c1,c2;
    printf("\n%c x %c = ",lal,lel);
    if (qnt1==0 || qnt2==0)
        printf("Vazio\n");

    else{
        //Realiza a Opera��o do produto cartesiano
        for(c1=0;c1<qnt1;c1++){
            for(c2=0;c2<qnt2;c2++){
                if (c2==0 && c1==0)
                    printf("{ (%d,%d) , ",conjunto1[c1],conjunto2[c2]);
                else if ((c2+1==qnt2) && (c1+1==qnt1)){
                    printf("(%d,%d) }\n",conjunto1[c1],conjunto2[c2]);
                    break;
                }
                else
                    printf("(%d,%d) , ",conjunto1[c1],conjunto2[c2]);
            }
        }
    }
}
int main(){
    //Fun��o menu, atr�ves dela todas as opera�oes s�o realizadas
    setlocale(LC_ALL, "Portuguese");//Comando necessario para usar a acentua��o e caracteres especificos da lingua portuguesa
    int conjunto1[100],conjunto2[100],conjunto3[100],qnt1=0,qnt2=0,qnt3=0,i1,i2,i3,o=0,ind,elementos;
    char r='S',p='N',batata='L',legume='T',nada;

    //Intrudu��o dos conjuntos
    printf("\nA: ");
    imprimir(conjunto1,qnt1);
    printf("\n\nB: ");
    imprimir(conjunto2,qnt2);
    printf("\n\nC: ");
    imprimir(conjunto3,qnt3);
    printf("\n");


    //Repetidor para continuar fazendo opera��es
    while(r=='S' || r=='s'){
        printf("_______________________________________________________________\n");
        printf("| C�digo |                     Opera��o                        |\n");
        printf("|--------|-----------------------------------------------------|\n");
        printf("|   01   |  Inserir um elemento em um conjunto                 |\n");
        printf("|   02   |  Remover um elemento de um conjunto                 |\n");
        printf("|   03   |  Verificar se um elemento pertence � um conjunto    |\n");
        printf("|   04   |  Verificar se um conjunto � subconjunto de outro    |\n");
        printf("|   05   |  Realizar a uni�o de dois conjuntos                 |\n");
        printf("|   06   |  Realizar a interse��o entre dois conjuntos         |\n");
        printf("|   07   |  Realizar a difer�nca entre dois conjuntos          |\n");
        printf("|   08   |  Realizar o produto cartesiano entre dois conjuntos |\n");
        printf("|   09   |  Imprimir os elementos de um conjunto               |\n");
        printf("|   10   |  Sair                                               |\n");
        printf("|________|_____________________________________________________|\n\n");

        printf("\nDigite o c�digo correspondente a opera��o que deseja realizar: ");
        scanf("%d",&o);
        //Switch case para o menu de op��es
        switch(o){
        case(1):
            while((p!='A') && (p!='a') && (p!='B') && (p!='b') && (p!='C') && (p!='c')){
                printf("\nCom qual dos conjuntos deseja realizar a opera��o ? ");
                scanf(" %c",&p);
                printf("\n");
                if (p=='A' || p=='a'){
                    printf("Quantos elementos deseja inserir no conjunto? ");
                    scanf("%d",&elementos);
                    for(ind=0;ind<elementos;ind++){
                        if (qnt1>100)
                            break;
                        inserir(conjunto1,qnt1,'A');
                        qnt1=qnt1+1;
                    }
                    //Impress�o do conjunto
                    printf("\nA = ");
                    imprimir(conjunto1,qnt1);
                }
                else if ((p=='B') || (p=='b')){
                    printf("Quantos elementos deseja inserir no conjunto? ");
                    scanf("%d",&elementos);
                    for(ind=0;ind<elementos;ind++){
                        if (qnt2>100)
                            break;
                        inserir(conjunto2,qnt2,'B');
                        qnt2=qnt2+1;
                    }
                    //Impress�o do conjunto
                    printf("\nB= ");
                    imprimir(conjunto2,qnt2);
                }
                else if ((p=='C') || (p=='c')){
                    printf("Quantos elementos deseja inserir no conjunto? ");
                    scanf("%d",&elementos);
                    for(ind=0;ind<elementos;ind++){
                        if (qnt3>100)
                            break;
                        inserir(conjunto3,qnt3,'C');
                        qnt3=qnt3+1;
                    }
                    //Impress�o do conjunto
                    printf("\nC = ");
                    imprimir(conjunto3,qnt3);
                }
                else
                    printf("\nConjunto inv�lido!\n");
            }
            break;
        case(2):
            while((p!='A') && (p!='a') && (p!='B') && (p!='b') && (p!='C') && (p!='c')){
                printf("\nCom qual dos conjuntos deseja realizar a opera��o ? ");
                scanf(" %c",&p);
                printf("\n");
                if (p=='A' || p=='a'){
                    qnt1=remover(conjunto1,qnt1,'A');
                }
                else if ((p=='B') || (p=='b')){
                    qnt2=remover(conjunto2,qnt2,'B');
                }
                else if ((p=='C') || (p=='c')){
                    qnt3=remover(conjunto3,qnt3,'C');
                }
                else
                    printf("\nConjunto inv�lido!\n");
            }
            break;
        case(3):
            while((p!='A') && (p!='a') && (p!='B') && (p!='b') && (p!='C') && (p!='c')){
                printf("\nCom qual dos conjuntos deseja realizar a opera��o ? ");
                scanf(" %c",&p);
                printf("\n");
                if (p=='A' || p=='a')
                    pertence(conjunto1,qnt1,'A');
                else if ((p=='B') || (p=='b'))
                    pertence(conjunto2,qnt2,'B');
                else if ((p=='C') || (p=='c'))
                    pertence(conjunto3,qnt3,'C');
                else
                    printf("\nConjunto inv�lido!\n");
            }
            break;
        case(4):
            printf("Digite a ordem na qual deseja fazer a opera��o, ex: (A s B) :");
            scanf(" %c %c %c",&batata,&nada,&legume);
            printf("\n");
            if((batata=='C' || batata=='c') && (legume=='A' || legume=='a')){
                subconjunto(conjunto3,conjunto1,qnt3,qnt1,'C','A');
            }
            else if((batata=='C' || batata=='c') && (legume=='B' || legume=='b')){
                subconjunto(conjunto3,conjunto2,qnt3,qnt2,'C','B');
            }
            else if((batata=='B' || batata=='b') && (legume=='A' || legume=='a')){
                subconjunto(conjunto2,conjunto1,qnt2,qnt1,'B','A');
            }
            if((batata=='A' || batata=='a') && (legume=='C' || legume=='c')){
                subconjunto(conjunto1,conjunto3,qnt1,qnt3,'A','C');
            }
            else if((batata=='B' || batata=='b') && (legume=='C' || legume=='c')){
                subconjunto(conjunto2,conjunto3,qnt2,qnt3,'B','C');
            }
            else if((batata=='A' || batata=='a') && (legume=='B' || legume=='b')){
                subconjunto(conjunto1,conjunto2,qnt1,qnt2,'A','B');
            }
            else{
                printf("Conjuntos inv�lidos!\n");
            }
            break;
        case(5):
            printf("Digite a ordem na qual deseja fazer a opera��o, ex: A U B :");
            scanf(" %c %c %c",&batata,&nada,&legume);
            printf("\n");
            if((batata=='C' || batata=='c') && (legume=='A' || legume=='a') || (batata=='A' || batata=='a') && (legume=='C' || legume=='c')){
                uniao(conjunto3,conjunto1,qnt3,qnt1,'C','A');
            }
            else if((batata=='C' || batata=='c') && (legume=='B' || legume=='b') || (batata=='B' || batata=='b') && (legume=='C' || legume=='c')){
                uniao(conjunto3,conjunto2,qnt3,qnt2,'C','B');
            }
            else if((batata=='B' || batata=='b') && (legume=='A' || legume=='a') || (batata=='A' || batata=='a') && (legume=='B' || legume=='b')){
                uniao(conjunto2,conjunto1,qnt2,qnt1,'B','A');
            }
            else{
                printf("Conjuntos inv�lidos!\n");
            }
            break;
        case(6):
            printf("Digite a ordem na qual deseja fazer a opera��o, ex: A n B :");
            scanf(" %c %c %c",&batata,&nada,&legume);
            printf("\n");
            if((batata=='C' || batata=='c') && (legume=='A' || legume=='a') || (batata=='A' || batata=='a') && (legume=='C' || legume=='c')){
                intersecao(conjunto3,conjunto1,qnt3,qnt1,'C','A');
            }
            else if((batata=='C' || batata=='c') && (legume=='B' || legume=='b') || (batata=='B' || batata=='b') && (legume=='C' || legume=='c')){
                intersecao(conjunto3,conjunto2,qnt3,qnt2,'C','B');
            }
            else if((batata=='B' || batata=='b') && (legume=='A' || legume=='a') || (batata=='A' || batata=='a') && (legume=='B' || legume=='b')){
                intersecao(conjunto2,conjunto1,qnt2,qnt1,'B','A');
            }
            else{
                printf("Conjuntos inv�lidos!\n");
            }
            break;
        case(7):
            printf("Digite a ordem na qual deseja fazer a opera��o, ex: A - B :");
            scanf(" %c %c %c",&batata,&nada,&legume);
            printf("\n");
            if((batata=='C' || batata=='c') && (legume=='A' || legume=='a')){
                subtracao(conjunto3,conjunto1,qnt3,qnt1,'C','A');
            }
            else if((batata=='C' || batata=='c') && (legume=='B' || legume=='b')){
                subtracao(conjunto3,conjunto2,qnt3,qnt2,'C','B');
            }
            else if((batata=='B' || batata=='b') && (legume=='A' || legume=='a')){
                subtracao(conjunto2,conjunto1,qnt2,qnt1,'B','A');
            }
            else if((batata=='A' || batata=='a') && (legume=='C' || legume=='c')){
                subtracao(conjunto1,conjunto3,qnt1,qnt3,'A','C');
            }
            else if((batata=='B' || batata=='b') && (legume=='C' || legume=='c')){
                subtracao(conjunto2,conjunto3,qnt2,qnt3,'B','C');
            }
            else if((batata=='A' || batata=='a') && (legume=='B' || legume=='b')){
                subtracao(conjunto1,conjunto2,qnt1,qnt2,'A','B');
            }
            else{
                printf("Conjuntos inv�lidos!\n");
            }
            break;
        case(8):
            printf("Digite a ordem na qual deseja fazer a opera��o, ex: A x B :");
            scanf(" %c %c %c",&batata,&nada,&legume);
            printf("\n");
            if((batata=='C' || batata=='c') && (legume=='A' || legume=='a')){
                produto_cartesiano(conjunto3,conjunto1,qnt3,qnt1,'C','A');
            }
            else if((batata=='C' || batata=='c') && (legume=='B' || legume=='b')){
                produto_cartesiano(conjunto3,conjunto2,qnt3,qnt2,'C','B');
            }
            else if((batata=='B' || batata=='b') && (legume=='A' || legume=='a')){
                produto_cartesiano(conjunto2,conjunto1,qnt2,qnt1,'B','A');
            }
            else if((batata=='A' || batata=='a') && (legume=='C' || legume=='c')){
                produto_cartesiano(conjunto1,conjunto3,qnt1,qnt3,'A','C');
            }
            else if((batata=='B' || batata=='b') && (legume=='C' || legume=='c')){
                produto_cartesiano(conjunto2,conjunto3,qnt2,qnt3,'B','c');
            }
            else if((batata=='A' || batata=='a') && (legume=='B' || legume=='b')){
                produto_cartesiano(conjunto1,conjunto2,qnt1,qnt2,'A','B');
            }
            else{
                printf("Conjuntos inv�lidos!\n");
            }
            break;

        case(9):
            printf("Digite qual conjunto deve ser impresso: ");
            scanf(" %c",&legume);
            printf("\n");
            if (legume=='A' || legume=='a'){
                printf("\n\nConjunto A: ");
                imprimir(conjunto1,qnt1);
                printf("\n");
            }
            else if (legume=='B' || legume=='b'){
                printf("\n\nConjunto B: ");
                imprimir(conjunto2,qnt2);
                printf("\n");
            }
            else if (legume=='C' || legume=='c'){
                printf("\n\nConjunto C: ");
                imprimir(conjunto3,qnt3);
                printf("\n");
            }
            else{
                printf("Conjunto Inv�lido!\n");
            }
            break;
        case(10):
            return 0;
        default:
            printf("\nOpera��o inv�lida!\n\n");
            break;
        }
        printf("\n\nDeseja realizar outra opera��o ?(S/N): ");
        scanf(" %c",&r);
        if ((r=='S') || (r=='s')){
            system("cls");
            printf("\n\nA: ");
            imprimir(conjunto1,qnt1);
            printf("\n\nB: ");
            imprimir(conjunto2,qnt2);
            printf("\n\nC: ");
            imprimir(conjunto3,qnt3);
            printf("\n\n");
            p='N';
        }
        else
            return 0;
    }
}

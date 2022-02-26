//Grupo: Uarlley, Christian, João Vitor e Lucas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para os onibus de uma determinada linha
typedef struct onibus{
    char horario[6];
    int mapa[4][10];
    int poltronas;
}onibus;

//Struct para as reservas
typedef struct reserva{
    int id;
    char line[100];
    char hour[6];
    int pi,pj;
    int busao;
}reserva;

//Struct para as linhas de onibus
typedef struct linhas{
    char lines[100];
    onibus *v;
    int qnt;
}linhas;

//Função para imprimir em negrito
void bold(int status) {
 static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
 printf("%s", seq[!!status]);
}

//Função que verifica as entradas
int verificaentrada(char entrada[9]){
    int i;
    for(i=0;i<strlen(entrada);i++){
        if (entrada[i]<'0' || entrada[i]>'9'){
            return 1;
        }
    }
    return 0;
}
//Impressão dos horarios
void horarios(linhas *vl,int cl){
    int i,j;
    printf(" _____________________________________________\n");
    printf("| Horarios disponíveis | Assentos Disponiveis |\n");
    printf("|——————————————————————|——————————————————————|\n");
    for(i=0;i<vl[cl].qnt;i++){
        if(vl[cl].v[i].poltronas!=0) printf("|        %s         |          %d          |\n",vl[cl].v[i].horario,vl[cl].v[i].poltronas);

    }
    printf("|______________________|______________________|\n");
}

//Função que imprime as linhas ja criadas
void imprimelinhas(linhas *vl,int k){
    int i,j;
    bold(1);
    printf("\nLinha(s) :          \n");
    printf(" _______________________\n");
    for(i=0;i<k;i++){
        printf("|%s",vl[i].lines);
        for(j=0;j<(23-strlen(vl[i].lines));j++) printf(" ");
        printf("|\n");
    }
    printf(" ———————————————————————\n");
    bold(0);
    return;
}

//Impressão do onibus
void map(linhas *vl,int l1,int bus){
    int i=0,j,k=0,l=0;
    printf("\n\n");
    for(j=1;j<=4;j++){
        if((i+1)%2!=0) printf(" ————————————————————————————————————————————————————————\n");
        for(i=j;i<=40;i+=4){
            if (i==1 || i==2 || i==3 || i==4) printf("| ");
            if(vl[l1].v[bus].mapa[k][l]==0){
                if (i>16 && i<21) printf("[%02d]   |   ",i);
                else printf("[%02d] ",i);
            }
            else{
                if (i>16 && i<21) printf("[**]   |   ");
                else printf("[**] ");
            }
            l++;
        }
        printf("\n");
        k++;
        l=0;
    }
    printf(" ————————————————————————————————————————————————————————\n");
}

//Função que imprime as reservas
void imprimereserva(reserva *vr,int r){
    int i,j,identif;
    char ident[9];
    char op;
    loop4:while(1){
        printf("Digite a identificação da reserva: ");
        scanf("%s",ident);
        if (verificaentrada(ident)==0){
            identif=atoi(ident);
            goto loop5;
        }
        else if (verificaentrada(ident)==1){
            printf("Entrada inválida, tente novamente.\n");
            goto loop4;
        }
        getchar();
        if (r==0){
            printf("Não há reservas!\n");
            return;
        }
        loop5:for(i=0;i<r;i++){
            if(i+1==r && vr[i].id!=identif){
                printf("Reserva inexistente!\nDeseja tentar novamente? ");
                getchar();
                scanf("%c",&op);
                getchar();
                setbuf(stdin,NULL);
                if(op=='s' || op=='S') goto loop4;
                else return;

            }
            else if (vr[i].id==identif){
                bold(1);
                printf("\n%d° Reserva: ",i+1);
                printf("\nIdentificação: %d",vr[i].id);
                printf("\nAssento: %d",vr[i].pi + 1 + 4*vr[i].pj);
                printf("\nlinha: %s",vr[i].line);
                printf("\nHorario: %s",vr[i].hour);
                printf("\n");
                bold(0);
                getchar();
                return;
            }
        }
    }
}

//Funcão de criação de linhas
linhas * C_linha(linhas *v1,int cl,int *total,int *salvo){
    int n,i,j,k,f;
    char enter,line[100],tex[9];
    if (cl==0) v1 = (linhas *)malloc(1*sizeof(linhas));
    else  v1=(linhas *)realloc(v1,(cl+1)*sizeof(linhas));
    //Definindo a linha
    loop3:while(1){
        printf("Digite o nome da linha: ");
        fgets(line,100,stdin);
        line[strlen(line)-1]=0;
        for(f=0;f<cl;f++){
            if (strcmp(v1[f].lines,line)==0){
                printf("Essa linha ja existe, tente novamente.\n");
                goto loop3;
            }
        }
        break;
    }
    strcpy(v1[cl].lines,line);
    //Criando o vetor de onibus
    loop6:while(1){
        printf("Digite a quantidade de onibus na linha: ");
        scanf("%s",tex);
        if (verificaentrada(tex)==0){
            n=atoi(tex);
            getchar();
            goto caso1;
        }
        else if (verificaentrada(tex)==1){
            printf("Entrada inválida, tente novamente.\n");
            goto loop6;
        }
        caso1:if(n>0){
            v1[cl].qnt=n;
            break;
        }
        else printf("Quantidade inválida, tente novamente.\n");
    }
    *total+=n;
    char texto[100];
    if (cl==0) v1[cl].v = (onibus *)malloc(n*sizeof(onibus));
    else v1[cl].v = (onibus *)realloc(v1[cl].v,*total*sizeof(onibus));
    for(i=0;i<n;i++){
        loop2:while(1){
            printf("\nDigite o horário do %d° onibus no formato HH:MM: ",i+1);
            fgets(texto,100,stdin);
            texto[strlen(texto)-1]=0;
            if(strlen(texto)!=5){
                printf("Formato inválido, tente novamente\n");
                goto loop2;
            }
            for(f=0;f<i;f++){
                if (strcmp(v1[cl].v[f].horario,texto)==0){
                    printf("Ja existe um ônibus neste horário, tente novamente\n");
                    goto loop2;
                }
            }
            strcpy(v1[cl].v[i].horario,texto);
            if(texto[0]>'2' || texto[0]<'0' || (texto[0]=='2' && texto[1]>'3')  || texto[3]>'5' || texto[3]<'0' || texto[2]!=':'){
                printf("Formato inválido, tente novamente\n");
            }
            else break;
        }
        v1[cl].v[i].poltronas=40;
        for(j=0;j<4;j++){
            for(k=0;k<10;k++){
                v1[cl].v[i].mapa[j][k] = 0;
            }
        }

    }
    imprimelinhas(v1,cl+1);
    printf("\nDigite enter para continuar...");
    *salvo = 0;
    getchar();
    return v1;
}

//Função para criação de reservas
reserva *C_reserva(linhas *v1,reserva *v2,int *r,int cl,int *idnt,int *salvo){
    int i,n,assento,j,k,l,l1;
    char enter,lin[100],op,texto[6],tex[9];
    if(*r==0) v2=(reserva *)malloc((*r+1)*sizeof(reserva));
    else v2 = (reserva *)realloc(v2,(*r+1)*sizeof(reserva));
    inicio:while(1){
        printf("\n%d° Reserva: ",*r+1);
        printf("\n\nDigite em qual linha deseja fazer a reserva: ");
        fgets(lin,100,stdin);
        lin[strlen(lin)-1]=0;
        for(l1=0;l1<cl;l1++){
            if (l1+1==cl && (strcmp(lin,v1[l1].lines)!=0)){
                printf("\nLinha inválida!\n");
                printf("\nDeseja tentar realizar a reserva novamente? ");
                scanf("%c",&op);
                getchar();
                setbuf(stdin,NULL);
                if (op=='s' || op=='S') goto inicio;
                else return v2;
            }
            else if (strcmp(lin,v1[l1].lines)==0){
                horarios(v1,l1);
                strcpy(v2[*r].line,lin);
                v2[*r].id = *idnt;
                cont:printf("\nDigite o horario da reserva: ");
                fgets(v2[*r].hour,6,stdin);
                break;
            }
        }
        for(i=0;i<v1[l1].qnt;i++){
            if ((i+1==v1[l1].qnt) && (strcmp(v2[*r].hour,v1[l1].v[i].horario)!=0)){
                getchar();
                printf("Horario invalido!\n");
                printf("\nDeseja tentar realizar a reserva novamente? ");
                scanf("%c",&op);
                getchar();
                setbuf(stdin,NULL);
                if (op=='s' || op=='S') goto cont;
                else return v2;
            }
            else if (strcmp(v2[*r].hour,v1[l1].v[i].horario)==0){
                volta:while(1){
                    map(v1,l1,i);
                    printf("\nQual dos assentos deseja reservar: ");
                    scanf("%s",tex);
                    if (verificaentrada(tex)==0){
                        assento=atoi(tex);
                        getchar();
                    }
                    else if (verificaentrada(tex)==1){
                        system("clear");
                        printf("\nEntrada inválida, tente novamente.\n");
                        goto volta;
                    }
                    if (assento>40 || assento==0){
                            system("clear");
                            printf("\nEntrada inválida, tente novamente.\n");
                            goto volta;
                    }
                    for(k=1;k<=4;k++){
                        for(l=0;l<10;l++){
                            if(assento==(l*4 +k)){
                                if(v1[l1].v[i].mapa[k-1][l]==0){
                                    printf("\nReserva realizada com sucesso!\n");
                                    bold(1);printf("\n _____________________________");
                                    printf("\n|Identificação da reserva: %d|\n",v2[*r].id);
                                    printf("———————————————————————————————\n");bold(0);
                                    v1[l1].v[i].mapa[k-1][l]=1;
                                    v2[*r].pi=k-1;
                                    v2[*r].pj=l;
                                    v2[*r].busao = i;
                                    v1[l1].v[i].poltronas--;
                                    *salvo =0;
                                    *idnt+=1;
                                    *r+=1;
                                    return v2;
                                }
                                else{
                                    printf("\n\nEste assento ja esta reservado, escolha outro.");
                                  goto volta;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


//Função de exclusão de reserva
reserva * excluir(linhas *vl,reserva *vr,int *r,int cl,int *salvo){
    int i,j,k,l,f;
    int identifi;
    char op,enter,tex[9];
    lal:while(1){
        printf("Digite a identificação da reserva que deseja excluir: ");
        scanf("%s",tex);
        if (verificaentrada(tex)==0){
            identifi=atoi(tex);
            getchar();
        }
        else if (verificaentrada(tex)==1){
            printf("\nEntrada inválida, tente novamente.\n");
            goto lal;
        }
        for(i=0;i<*r;i++){
            if (i+1==*r && vr[i].id!=identifi){
                printf("Identificação nao encontrada, deseja tentar novamente? ");
                scanf("%c",&op);
                getchar();
                setbuf(stdin,NULL);
                if(op=='s' || op=='S') goto lal;
                else return vr;
            }
            else if(vr[i].id==identifi){
                for(f=0;f<cl;f++){
                    if (strcmp(vr[i].line,vl[f].lines)==0){
                        vl[f].v[vr[i].busao].mapa[vr[i].pi][vr[i].pj]=0;
                        vl[f].v[vr[i].busao].poltronas++;
                        if(*r==1){
                            vr = (reserva *)realloc(vr,(*r-1)*sizeof(reserva));
                            *r-=1;
                            *salvo =0;
                            printf("\nReserva excluida\nPressione enter para continuar...");
                            getchar();
                            return vr;
                        }
                        for(l=i;l<*r-1;l++){
                            strcpy(vr[l].hour,vr[l+1].hour);
                            vr[l].id = vr[l+1].id;
                            strcpy(vr[l].line,vr[l+1].line);
                            vr[l].pi=vr[l+1].pi;
                            vr[l].pj=vr[l+1].pj;
                            vr[l].busao=vr[l+1].busao;
                        }
                        vr = (reserva *)realloc(vr,(*r-1)*sizeof(reserva));
                        printf("\nReserva excluida\nPressione enter para continuar...");
                        getchar();
                        *salvo=0;
                        *r-=1;
                        return vr;
                    }
                }
            }
        }
    }
}

//Funções que imprimem o menu de opções
void menu1(){
    printf("           SISTEMA DE RESERVAS \n");
    printf(" ______________________________________\n");
    printf("|  Código  |         Operação          |\n");
    printf("|——————————|———————————————————————————|\n");
    printf("|    01    |      Criar uma Linha      |\n");
    printf("|    02    |      Carregar Arquivo     |\n");
    printf("|    03    |     Fazer uma Reserva     |\n");
    printf("|    04    |    Excluir uma Reserva    |\n");
    printf("|    05    |    Procurar uma reserva   |\n");
    printf("|    06    | Mostrar mapa de um ônibus |\n");
    printf("|    07    |     Salvar alterações     |\n");
    printf("|    08    |           Sair            |\n");
    printf(" ——————————————————————————————————————\n");
}
void menu2(){
    printf("           SISTEMA DE RESERVAS \n");
    printf(" ______________________________________\n");
    printf("|  Código  |         Operação          |\n");
    printf("|——————————|———————————————————————————|\n");
    printf("|    01    |      Criar uma Linha      |\n");
    printf("|    02    |      Carregar Arquivo     |\n");
    printf("|    03    |     Fazer uma Reserva     |\n");
    printf("|    04    |    Excluir uma Reserva    |\n");
    printf("|    05    |    Procurar uma reserva   |\n");
    printf("|    06    | Mostrar mapa de um ônibus |\n");
    printf("|    07    |           Sair            |\n");
    printf(" ——————————————————————————————————————\n");
}

//Função principal do programa
int main(){
    int cl=0,i,j,r=0,k,op1,total=0,salvo=1;
    int idnt=100,hora,min;
    int aberturas=0;
    char op,enter,lcomp[100],texto[6],tex[9],arqname[50];
    FILE *arquivo=NULL;
    linhas *vl;
    reserva *vr;
    loop1:while(1){
        setbuf(stdin,NULL);
        printf("\n");
        system("clear");
        if (aberturas==0) menu2();
        else menu1();
        printf("\nDigite o código correspondente à operação que deseja realizar: ");
        scanf("%s",tex);
        if (verificaentrada(tex)==0){
            op1=atoi(tex);
            getchar();
        }
        else{
            printf("Entrada inválida!\n");
            printf("Pressione enter para continuar...");
            getchar();
            getchar();
            goto loop1;
            
        }
        if (op1==1){
            vl = C_linha(vl,cl,&total,&salvo);
            cl++;
            goto loop1;
        }
        else if (op1==2){
            printf("Digite o nome do arquivo: ");
            scanf("%s",arqname);
            arquivo = fopen(arqname,"rb");
            if(arquivo == NULL){
                printf("Arquivo inexiste, um com o mesmo nome foi criado.\nPressione enter para continuar...");
                arquivo = fopen(arqname,"wb");
                aberturas=1;
                fclose(arquivo);
                getchar();
                getchar();
                goto loop1;
            }
            fread(&cl,sizeof(int),1,arquivo);
            fread(&r,sizeof(int),1,arquivo);
            vl = (linhas *)calloc(cl,sizeof(linhas));
            vr = (reserva *)calloc(r,sizeof(reserva));
            fread(vl,sizeof(linhas),cl,arquivo);
            for(i=0;i<cl;i++){
                vl[i].v = (onibus *)calloc(vl[i].qnt,sizeof(onibus));
            }
            for(i=0;i<cl;i++){
                fread(vl[i].v,sizeof(onibus),vl[i].qnt,arquivo);
            }
            fread(vr,sizeof(reserva),r,arquivo);
            fclose(arquivo);
            printf("O arquivo foi carregado com sucesso.\nPressione enter para continuar...");
            aberturas=1;
            idnt = 100+r;
            getchar();
            getchar();
            goto loop1;

        }
        else if(op1==3){
            while(1){
                if (cl==0){
                    printf("Crie uma linha primeiro!");
                    printf("\nPressione enter para continuar...");
                    getchar();
                    goto loop1;
                }
                system("clear");
                imprimelinhas(vl,cl);
                vr = C_reserva(vl,vr,&r,cl,&idnt,&salvo);
                printf("\nDeseja fazer outra reserva? ");
                scanf("%c",&op);
                getchar();
                if(op!='s' && op!='S'){
                    setbuf(stdin,NULL);
                    goto loop1;
                }
                else{
                    setbuf(stdin,NULL);
                }
            }
        }
        else if(op1==4){
            fflush(stdin);
            if (r==0){
                printf("Não há reservas!\nPressione enter para continuar...");
                getchar();
                goto loop1;
            }
            if (cl==0){
                printf("Não há linhas!\nPressione enter para continuar...");
                getchar();
                goto loop1;
            }
            while(1){
                excluir(vl,vr,&r,cl,&salvo);
                goto loop1;
            }
        }
        else if(op1==5){
            if (r==0){
                printf("Não há reservas!\nPressione enter para continuar...");
                getchar();
                goto loop1;
            }
            imprimereserva(vr,r);
            printf("\nPressione enter para continuar...");
            getchar();
        }
        else if(op1==6){
            if (cl==0){
                printf("Não há linhas!\nPressione enter para continuar...");
                getchar();
                goto loop1;
            }
            imprimelinhas(vl,cl);
            printf("Digite a linha do ônibus: ");
            fgets(lcomp,100,stdin);
            lcomp[strlen(lcomp)-1]=0;
            for(k=0;k<cl;k++){
                if(k+1==cl && strcmp(lcomp,vl[k].lines)!=0){
                    printf("Linha inexistente\n");
                    printf("\nPressione enter para continuar...");
                    getchar();
                    break;
                }
                else if(strcmp(lcomp,vl[k].lines)==0){
                    horarios(vl,k);
                    printf("\nDigite o horário do ônibus no formato HH:MM: ");
                    fgets(texto,6,stdin);
                    for(i=0;i<vl[k].qnt;i++){
                        if(i+1==vl[k].qnt && strcmp(vl[k].v[i].horario,texto)!=0){
                            printf("Horário inválido!");
                            printf("\nPressione enter para continuar...");
                            getchar();
                            getchar();
                            goto loop1;
                        }
                        else if(strcmp(vl[k].v[i].horario,texto)==0){
                            map(vl,k,i);
                            printf("\nPressione enter para continuar...");
                            getchar();
                            getchar();
                            goto loop1;
                        }
                    }
                }
            }
        }
        else if (op1==7){
            if(aberturas==0){
                if (salvo==0){
                    printf("Deseja mesmo sair sem salvar as informações? ");
                    scanf("%c",&op);
                    getchar();
                    setbuf(stdin,NULL);
                    if (op!='S' && op!='s'){
                        setbuf(stdin,NULL);
                        printf("\nDigite o nome do arquivo: ");
                        scanf("%s",arqname);
                        arquivo = fopen(arqname,"wb");
                        if (arquivo!=NULL){
                            fwrite(&cl,sizeof(int),1,arquivo);
                            fwrite(&r,sizeof(int),1,arquivo);
                            fwrite(vl,sizeof(linhas),cl,arquivo);
                            for(i=0;i<cl;i++){
                                fwrite(vl[i].v,sizeof(onibus),vl[i].qnt,arquivo);
                            }
                            fwrite(vr,sizeof(reserva),r,arquivo);
                            fclose(arquivo);
                            printf("Alterações salvas com sucesso!\nPressione enter para continuar...");
                            getchar();
                            getchar();
                        }
                    }
                    else{
                        printf("As alterações não puderam ser salvas.\nPressione enter para continuar...");
                        getchar();
                    }
                }
                if (cl>0) free(vl);
                if (r>0) free(vr);
                return 0;
            }
            arquivo = fopen(arqname,"wb");
            if (arquivo!=NULL){
                fwrite(&cl,sizeof(int),1,arquivo);
                fwrite(&r,sizeof(int),1,arquivo);
                fwrite(vl,sizeof(linhas),cl,arquivo);
                for(i=0;i<cl;i++){
                    fwrite(vl[i].v,sizeof(onibus),vl[i].qnt,arquivo);
                }
                fwrite(vr,sizeof(reserva),r,arquivo);
                fclose(arquivo);
                printf("Alterações salvas com sucesso!\nPressione enter para continuar...");
                getchar();
                salvo=1;
                goto loop1;
            }
            else{
                printf("Não foi possivel salvar as alterações.\nPressione enter para continuar...");
                getchar();
            }
        }
        else if(op1==8){
            if (aberturas>0){
                if(salvo==0){
                    printf("Deseja mesmo sair sem salvar as alterações? ");
                    scanf("%c",&op);
                    getchar();
                    setbuf(stdin,NULL);
                    if (op!='s' && op!='S'){
                        arquivo = fopen(arqname,"wb");
                        if (arquivo!=NULL){
                            fwrite(&cl,sizeof(int),1,arquivo);
                            fwrite(&r,sizeof(int),1,arquivo);
                            fwrite(vl,sizeof(linhas),cl,arquivo);
                            for(i=0;i<cl;i++){
                                fwrite(vl[i].v,sizeof(onibus),vl[i].qnt,arquivo);
                            }
                            fwrite(vr,sizeof(reserva),r,arquivo);
                            fclose(arquivo);
                            printf("Alterações salvas com sucesso!\nPressione enter para continuar...");
                            getchar();
                        }
                    }
                }
                if (cl>0) free(vl);
                if (r>0) free(vr);
                return 0;
            }
            else{
                printf("Operação inválida\nPressione enter para continuar...");
                getchar();
                goto loop1;
            }
        }
        else if (op1>8){
            printf("Operação inválida\nPressione enter para continuar...");
            getchar();
            goto loop1;
        }
        else{
            getchar();
            goto loop1;
        }
    }
}

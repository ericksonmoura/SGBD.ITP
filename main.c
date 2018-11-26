#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>

void addResistro(){
    /*char table[21];

    printf("Nome da tabela: ");
    fgets(table,21,stdin);
    fflush(stdin);
    table[strlen(table)-1]='\0';
    system("cls");*/





}



void tituloEidioma(){
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("Projeto ITP");
}


void novaTable(){
    char tabela[30];
    char key[30];
    int n, contador;

    printf(" Nome: ");
    fgets(tabela,30,stdin);
    system("cls");
    printf(" primary key: ");
    fgets(key,30,stdin);
    system("cls");

    printf("quantas colunas: ");
    scanf("%d",&n);
    fflush(stdin);
    system("cls");

    tabela[strlen(tabela)/sizeof(char) -1]= '\0';
    key[strlen(key)/sizeof(char) -1]= '\0';

    FILE *metaDados = fopen("registros/meta.txt","w");
    char *bufer;
    bufer = malloc((strlen(tabela)+strlen(key)+4)*sizeof(char));
    strcpy(bufer,tabela);
    strcat(bufer,":");
    strcat(bufer,key);
    strcat(bufer,";");


    char buffer[2]={'$'};
    strcat(buffer,bufer);
    free(bufer);
    strcat(buffer,"\n{\n");

    fprintf(metaDados,"%s",buffer);


while (contador <= n){
        int x;
        char tipo[2];
        char nome[30];
        system("cls");
        printf("Escolha o tipo de dado:\n");
        printf("(1)INT\n");
        printf("(2)FLOAT\n");
        printf("(3)DOUBLE\n");
        printf("(4)CHAR\n");
        printf("(5)STRING\n");
        scanf("%d",&x);
        fflush(stdin);

        switch(x){
        case 1 :
            tipo [0]= 'I';
            tipo [1]= '\0';
            break;
        case 2 :
            tipo [0] = 'F';
            tipo [1]= '\0';
            break;
        case 3 :
            tipo [0]= 'D';
            tipo [1]= '\0';
            break;
        case 4 :
            tipo [0]= 'C';
            tipo [1]= '\0';
            break;
        case 5 :
            tipo [0]= 'S';
            tipo [1]= '\0';
            break;
        default:
            printf("opção invalida");
            Sleep(1);
            system("cls");
        }
        system("cls");
        printf("nome da coluna: ");
        fgets(nome,30,stdin);
        nome[(strlen(nome)/sizeof(char))-1] = '\0';
        strcat(tipo,":");
        strcat(tipo,nome);
        strcat(tipo,";\n");

        fprintf(metaDados,tipo);
        contador++;
}



        fprintf(metaDados,"%s","}\n\n");
        fclose(metaDados);


        //criando o .txt para a tabela
        char tab[]="registros/";
        strcat(tabela,".txt");
        strcat(tab,tabela);
        FILE *nova = fopen(tab,"w");
        fclose(nova);



}

int calc_tables(){
    FILE *arq;
    arq = fopen("registros/meta.txt","r");
    int quantTables=0;
    char caracter;

     if(arq!=NULL){
        while((caracter=fgetc(arq))!= EOF){
            if(caracter=='$'){
                quantTables++;
            }

        }
    }

    fclose(arq);
    return quantTables;
}

char **showTables(){
    FILE *arq;
    arq = fopen("registros/meta.txt","r");
    int i=0,quantTables=0, p=0,k=0,y=0;
    char caracter, arquivo[1000];

     if(arq!=NULL){
        while((caracter=fgetc(arq))!= EOF){
            arquivo[i]=caracter;
            i++;
            if(caracter=='$'){
                quantTables++;
            }

        }
    }

    char **vetor = malloc(quantTables*sizeof(char*));

    for (i = 0; i < quantTables; ++i) {
        vetor[i] = (char *)malloc(20+1);
    }

    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='$'){
            p=1;//após o $
            k=0;//para pegar as char

            char tabela_da_vez[21];
                while(arquivo[i+p]!=':'){
                tabela_da_vez[k] = arquivo[p+i];
                    p++;
                    k++;
                }
                tabela_da_vez[k]='\0';

                strcpy(vetor[y],tabela_da_vez);
                y++;

            }

        }




    return vetor;
    fclose(arq);


}

void criarDiretorios(){
    //criando pasta para guardar tabelas
    CreateDirectory("registros",NULL);
    //meta dados
    FILE *arc = fopen("registros/meta.txt","w");
    fclose(arc);


}

BOOL verifica_diretorio(LPCTSTR diretorio){

  DWORD dir = GetFileAttributes(diretorio);
  return (dir != INVALID_FILE_ATTRIBUTES &&
         (dir & FILE_ATTRIBUTE_DIRECTORY));
}

void pesquisarTable(){
char nome_t[30];
char nome_tab[30], nome_coluna[30], tipo[2];
char nome_pk[30];
char valor_pesquisa[30];
int numerador = 1, escolha, escolha1;
char separador_coluna[2] = {'}'};

printf("Em qual tabela deseja pesquisar?");
fgets(nome_t,30,stdin);
//strcpy(nome_t,".txt");
FILE *arq = fopen("meta/registros.txt", "r");
if(arq == NULL){
   printf("Erro, nao foi possivel abrir a tabela\n");
   //menu();
}
else{
    while(fscanf(arq,"\n") != EOF){
    fscanf(arq,"$%s:%s;\n", &nome_tab,&nome_pk);
    if(strcmp(nome_t,nome_tab) == 0){
            char coluna_atual[30];
            fgets(coluna_atual, 30, arq);
            if(coluna_atual == "{\n"){

            }

    }

    printf("Informe o tipo de variavel a ser pesquisado na tabela: \n");
    printf("(1)INT\n");
    printf("(2)FLOAT\n");
    printf("(3)DOUBLE\n");
    printf("(4)CHAR\n");
    printf("(5)STRING\n");

    scanf("%d", escolha);
    switch(escolha){
        case 1 :

            break;
        case 2 :

            break;
        case 3 :

            break;
        case 4 :

            break;
        case 5 :

            break;
        case 6 :

            break;
        default:
            printf("opção invalida");
            Sleep(1);
            system("cls");


        printf("Escolha a operacao:\n");
        printf("(1) Valores maiores que o informado\n");
        printf("(2) Valores maiores ou iguais o informado\n");
        printf("(3) Valores iguais o informado\n");
        printf("(4) Valores menores que o informado\n");
        printf("(5) Valores menores ou iguais o informado\n");
        printf("(6) Valores aproximados ao informado\n");


    scanf("%d", escolha1);
    switch(escolha1){
        case 1 :

            break;
        case 2 :

            break;
        case 3 :

            break;
        case 4 :

            break;
        case 5 :

            break;
        case 6 :

            break;
        default:
            printf("opção invalida");
            Sleep(1);
            system("cls");





    }

}
    }


}
}

void menu(){
    int n;

        system("cls");
        printf("  *******************************\n");
        printf(" *         SGBD-ITP            *\n");
        printf("*******************************\n");
        printf("\n");
        printf("Escolha uma opção:\n");
        printf("(1)Criar um tabela\n");
        printf("(2)Listar todas as tabelas\n");
        printf("(3)Criar uma nova linha na tabela\n");
        printf("(4)Listar todos os dados de uma tabela\n");
        printf("(7)Apagar uma tabela\n");

        scanf("%d",&n);
        fflush(stdin);
        switch(n){
            case 1:
                system("cls");
                novaTable();
            break;
            case 2:
                system("cls");
                int i;
                char **v=showTables();
                for(i=0;i<calc_tables();i++){
                    printf("%s\n",v[i]);
                }

                break;
            case 3:
                system("cls");
                addResistro();
                break;
            case 7:
                apagarTable();
                break;
            case 0:
                n=0;
            default:
                printf("Opção inválida\n");
        }


}

int apagarTable(){
    system("cls");
    char tab[31],**tabelas = showTables();
    int i;

    printf("Tabelas existentes: \n");

    for(i=0;i<calc_tables();i++){
        printf("%s\n",tabelas[i]);
    }

    printf("\n\nQual tabela deseja apagar?\n");
    fgets(tab,30,stdin);
    fflush(stdin);
    tab[strlen(tab)-1]='\0';


    //add o restante do diretorio
    char ss[]="registros/";
    strcat(ss,tab);
    strcat(ss,".txt");

    if(DeleteFileA(ss)!=0){
        printf("FEITO!\n");

    }else{
        printf("Tabela não existe\n");
    }
}

int removerTableMeta(char tab[]){
    FILE *arq;
    arq = fopen("registros/meta.txt","r");
    int i=0,quantTables=0, p=0,k=0,y=0;
    char caracter, arquivo[1000];

    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='$'){
            p=1;//após o $
            k=0;//para pegar as char

            char tabela_da_vez[21];
                while(arquivo[i+p]!=':'){
                tabela_da_vez[k] = arquivo[p+i];
                    p++;
                    k++;
                }
                tabela_da_vez[k]='\0';

                tabela_da_vez;
                y++;

            }

        }

}
int main()
{
menu();



}



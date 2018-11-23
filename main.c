#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void addTupla(){
    /*char table[21];

    printf("Nome da tabela: ");
    fgets(table,21,stdin);
    fflush(stdin);
    table[strlen(table)-1]='\0';
    system("cls");*/





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
        scanf("%d",&n);
        fflush(stdin);
        switch(n){
            case 1:
                system("cls");
                novaTable();
            break;
            case 2:
                system("cls");

                break;
            case 3:
                system("cls");
                addTupla();
                break;
           /* case 4:
                deleteTable();
                break;
            case 0:
                n=0;
           */ default:
                printf("Opção inválida\n");
        }


}

void tituloEidioma(){
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("Projeto ITP");
}


void novaTable(){
    char *ponteiro;
    char tabela[30];
    char key[30];
    int n;

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

    FILE *metaDados = fopen("meta.txt","a+");
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
        fgets(nome,"%s",stdin);
        nome[(strlen(nome)/sizeof(char))-1] = '\0';
        strcat(tipo,":");
        strcat(tipo,nome);
        strcat(tipo,";\n");

        fprintf(metaDados,tipo);




        fprintf(metaDados,"%s","}\n\n");
        fclose(metaDados);


        //criando o .txt para a tabela
        strcat(tabela,".txt");
        FILE * tab = fopen(tabela,"w");
        if(tab!=NULL){
            fprintf(tab,tabela);
        }else{
            printf("ERROR");
        }

        fclose(tab);



}

void showTables (char **vetor){
    FILE *arq;
    arq = fopen("meta.txt","r");
    int i=0,quantTables,aux=0, p=0,k=0;
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

    vetor = malloc(quantTables * sizeof(char));
    int l=0;
    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='$'){
            p=1;
            k=0;
            char tabela_da_vez[21];
            while(arquivo[i+p]!=':'){
                tabela_da_vez[k] = arquivo[p+i];
                p++;
                k++;
            }
            tabela_da_vez[k]='\0';
            strcpy(vetor[l],tabela_da_vez);
            l++;

        }

    }

    fclose(arq);

}

void criarDiretorios(){
    FILE *arc = fopen("meta.txt","w");
    fclose(arc);
}

void consultarTable (){

char nome_tabela[30];
char chave_p[30];
printf("Qual tabela deseja realizar a pesquisa?");
fgets(nome_tabela, 30, stdin);
fgets(chave_p, 30, stdin);
FILE *arq = fopen ("meta.txt", "r");

if(fscanf(arq,"$%s:%s;/n", &nome_tabela, &chave_p) != NULL){


        }
    }


}


int main()
{
    tituloEidioma();
    menu();



    return 0;
}

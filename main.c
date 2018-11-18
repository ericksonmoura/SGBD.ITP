#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
void menu(){
    int n;

        system("cls"); // apaga tudo que ja foi escrito
        printf("\t\t\t\t\t\tITP 2018.2\t\t\t\t\t\n");
    printf("\t\t\t\t\tBanco de dados relacional em C\t\t\t\t\t\n");
    printf("\t\t\t###############################################################\n \t\t\t###############################################################\n \t\t\t###############################################################\n");
    printf("\n");
    printf("\t\t\t\t\tMenu do SGBD: \n");
    printf("\t\t\t\t\t(1). Criar tabela \n");
    printf("\t\t\t\t\t(2). Listar todas as tabelas \n");
    printf("\t\t\t\t\t(3). Criar uma nova linha na tabela \n");
    printf("\t\t\t\t\t(4). Listar todos os dados de uma tabela \n");
    printf("\t\t\t\t\t(5). Pesquisar valor em uma tabela \n");
    printf("\t\t\t\t\t(6). Apagar valor de uma tabela \n");
    printf("\t\t\t\t\t(7). Apagar uma tabela \n");
    printf("\n");
    printf("\t\t\t###############################################################\n \t\t\t###############################################################\n \t\t\t###############################################################\n");
        scanf("%d",&n);
        fflush(stdin); // 'Limpa' o buffer
        switch(n){
            case 1:
                novaTabela();
            break;
            /*case 2:
                showTable();
                break;
            case 3:
                showTables();
                break;
            case 4:
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


void novaTabela(){
    char *ponteiro;
    char tabela[30];
    char key[30];
    int num_colunas;
    char nome_coluna[30];
    char tipo_coluna[10];
    int cont, aux_tipo = 0;

    printf(" Nome: ");
    fgets(tabela,30,stdin);
    system("cls");
    printf(" primary key: ");
    fgets(key,30,stdin);
    system("cls");

    printf("quantas colunas: ");
    scanf("%d",&num_colunas);
    fflush(stdin);
    system("cls");
    }

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

char tipoVariavel(){

        int x;
        char tipo[5];
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
            std
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




    fprintf(metaDados,"%s","}\n");
    fclose(metaDados);

}


void showTables(){

}
void deleteTable(){

}
void showTable(){

}
void criarDiretorios(){
    FILE *arc = fopen("meta.txt","w");
    fclose(arc);
}

int main()
{

    tituloEidioma();
    criarDiretorios();
    menu();

    return 0;
}

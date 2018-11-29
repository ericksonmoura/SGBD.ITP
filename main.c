#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>

void tituloEidioma(){
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("Projeto ITP");
}
// 1)*
void novaTable(){
    FILE *metaDados = fopen("registros/meta.txt","a+");
    // Cria o arquivo registrps/meta.txt
    if(metaDados!=NULL){
        //return 1;
    }
    char *bufer,tabela[30], key[30];

    printf(" Nome: ");
    fgets(tabela,30,stdin);
    system("cls");
    printf(" primary key: ");
    fgets(key,30,stdin);
    system("cls");
    // Solicita nome da Coluna e chave primaria da Tabela a ser criada

    tabela[strlen(tabela)/sizeof(char) -1]= '\0';
    key[strlen(key)/sizeof(char) -1]= '\0';
    // Aloca dinamicamente o nome da tabela e chave primaria

    char buffer[strlen(tabela)]; // Cria a variavel 'Buffer' com o mesmo tamanho da tabela
    fprintf(metaDados,"%s","$");
    strcpy(buffer,tabela);
    strcat(buffer,":");
    strcat(buffer,key);
    strcat(buffer,";\n");
    fprintf(metaDados,"%s",buffer);
    fclose(metaDados);
    // Copia os dados: Nome da tabela, chave primaria e separadores e escreve no Buffer, que escreve, ao final, no arquivo 'registros/meta.txt'

    char arq_tab[]="registros/";
    strcat(arq_tab,tabela);
    strcat(arq_tab,".txt");

    FILE *tab = fopen(arq_tab,"w");
    if(tab!=NULL){
        fprintf(tab,"%s",buffer); // Escreve o nome da tabela e a chave primaria dessa tabela no novo arquivo criado para armazenar as colunas da tabela
     fprintf(tab,"%s","{\n");
        int f=0;
        do{
            int x;
            char *tipo = malloc(sizeof(char)*2);
            char *nome = malloc(sizeof(char)*31);

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
                    Sleep(5);
                    system("cls");
            }
            system("cls");
            printf("nome da coluna: ");
            fgets(nome,30,stdin);
            nome[(strlen(nome)/sizeof(char))-1] = '\0';
            strcat(tipo,":");
            strcat(tipo,nome);
            strcat(tipo,";\n");
            fprintf(tab,"%s",tipo);
            free(tipo);
            free(nome);

            printf("quer add outra coluna? SIM(1) ou NÃo(2)?\n");
            fflush(stdin);
            scanf("%d",&f);
            fflush(stdin);
        }while(f==1);
            fprintf(tab,"%s","}\n");

// Cria um laço(While), baseado na quantidade de colunas informadas pelo usuário, para ler e armazenar o(s) nome(s) e o tipo(s) da(s) coluna(s) no arquivo

            fclose(tab);


    }else{
        fclose(tab);
        //return 1;
    }



}

void pesquisarTable(){
char nome_pesquisa[30];
printf("Em qual tabela deseja pesquisar?");
showTables();

fgets(nome_pesquisa,30,stdin);

 char arq_tab[]="registros/";
    strcat(arq_tab,nome_pesquisa);
    strcat(arq_tab,".txt");

 arq_tab[strlen(arq_tab)/sizeof(char) -1]= '\0';

 FILE *arq = fopen(arq_tab, "r");

 if(arq == NULL)
   printf("Erro, nao foi possivel abrir a tabela\n");

 else if{
 char nome_coluna[30];
 printf("Em qual coluna deseja pesquisar?")
 // função de listar colunas();
 fgets(nome_coluna,30,stdin);
 nome_coluna[strlen(nome_coluna)/sizeof(char) -1]= '\0';

 }


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
    // Verifica a quantidade de tabelas registradas até o momento no arquivo 'registros/Meta.txt'
    return quantTables;
}
//2)
char **showTables(){
    FILE *arq;
    arq = fopen("registros/meta.txt","r");
    int i=0,quantTables=0, p=0,k=0,y=0;
    char caracter, arquivo[1000];

    //lendo todo o arquivo
     if(arq!=NULL){
        while((caracter=fgetc(arq))!= EOF){
            arquivo[i]=caracter;
            i++;
            if(caracter=='$'){
                quantTables++;
            }
        }
    }

    //alocando o vetor de acordo com a quantidade de tabelas
    char **vetor = malloc(quantTables*sizeof(char*));
    for (i = 0; i < quantTables; ++i) {
        vetor[i] = (char *)malloc(30+1);
    }

    //buscando por tabelas atraves do identificador
    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='$'){
            p=1;//após o $
            k=0;//para pegar as char

            char tabela_da_vez[31];
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

int strComparar(char str1[],char str2[]){
    if(strlen(str1)!=strlen(str2)){
       return 1;
    }else{
        int i;
        for(i=0;i<strlen(str1);i++){
            if(str1[i]!=str2[i]){
            return 1;
            }
        }
    }
 // Verifica se duas 'strings' são iguais
    return 0;
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

                break;
            case 7:
                apagarTable();
                break;
            case 0:
                exit(1);
            default:
                printf("Opção inválida\n");
                Sleep(3);
                menu();
        }


}
//7)
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
        printf("Essa tabela não existe\n");
    }
}

void showAttribute(char tabela[31]){
    char caracter, arquivo[1000];
    int i=0,j,k;
    //completando o diretório do arquivo;
    char arq_tab[]="registros/";
    strcat(arq_tab,tabela);
    strcat(arq_tab,".txt");
    FILE *arq = fopen(arq_tab,"a+");

    //lendo todo o arquivo e salvando em uma string
    if(arquivo!=NULL){
        while((caracter=fgetc(arq))!= EOF){
        arquivo[i]=caracter;
        i++;
        }
    }

    int quantAtributos=0;

    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='{'){
            i++;
           while(arquivo[i]!='}'){
                if(arquivo[i]==':'){


                }
            i++;
           }
        }
    }

    //alocando o vetor de acordo com a quantidade de atributos
    char **atributos = malloc(quantAtributos*sizeof(char*));
    char **tipos = malloc(quantAtributos * sizeof(char*));


    for (i = 0; i < quantAtributos; ++i) {
        atributos[i] = (char *)malloc(30+1+1+1+1);
    }
    for (i = 0; i < quantAtributos; ++i) {
        tipos[i] = (char *)malloc(2);
    }

    j=0;
    k=0;
    int p=0;

    //buscando por atributos atraves dos identificadores dos tipos de dados

    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='{'){
            while(arquivo[i]!='}'){
                i++;
                if(arquivo[i]=='I' || arquivo[i]=='D' || arquivo[i]=='F' || arquivo[i]=='C' || arquivo[i]=='S'){
                    char tip[2];
                    char atri[31];

                    tip[0] = arquivo[i];
                    tip[1]= '\0';
                    strcpy(tipos[j],tip);
                    j++;
                    i=i+2;
                    while(arquivo[i]!=';'){
                        atri[p]=arquivo[i];
                        i++;
                        p++;
                    }
                    atri[p]='\0';

                    strcpy(atributos[k],atri);
                    k++;
                }
                i++;
            }
        }
    }
}

int main(){
    tituloEidioma();
    menu();


    return 0;
}



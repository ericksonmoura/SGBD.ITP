#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>
#include "funcoes/funcoes.h"

void tituloEidioma(){
    setlocale(LC_ALL, "Portuguese");
    SetConsoleTitle("Projeto ITP");
}

void novaTable(){
    FILE *metaDados = fopen("registros/meta.txt","a+");
    if(metaDados!=NULL){

        char tabela[30], key[30];

        //lendo nome e chave da tabela;
        printf(" Nome: ");
        fgets(tabela,30,stdin);
        system("cls");
        printf(" primary key: ");
        fgets(key,30,stdin);
        system("cls");

        //delimitando o fim de string
        tabela[strlen(tabela)/sizeof(char) -1]= '\0';
        key[strlen(key)/sizeof(char) -1]= '\0';

        //---prepara a formatação do conteudo que vai ser salvo no arquivo dos meta dados, e escreve;
        char buffer[strlen(tabela)];
        fprintf(metaDados,"%s","$");
        strcpy(buffer,tabela);
        strcat(buffer,":");
        strcat(buffer,key);
        strcat(buffer,";\n");
        fprintf(metaDados,"%s",buffer);
        fclose(metaDados);

        //--- Cria o arquivo da tabela, onde ficaram os registros;
        char arq_tab[]="registros/";
        strcat(arq_tab,tabela);
        strcat(arq_tab,".txt");
        FILE *tab = fopen(arq_tab,"w");

        //---Cria o arquivo para as chaves primarias
        gerarKeys_txt(tabela);

        //escreve o nome, chave, e atributos no inicio do arquivo;
        if(tab!=NULL){
            fprintf(tab,"%s",buffer);
            fprintf(tab,"%s","{\n");
            int f=0;

            //---Adicionando atributos
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
                //formata e escreve noarquivo o atributo;
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

                fprintf(tab,"%s","}\n");//delimita o fim do campo deatributos
                system("cls");
                printf("FEITO!!!");
                fclose(tab);
        }else{
        fclose(tab);
        }
    }else{
        printf("ERRO;");
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
                addResistro();
                break;
            case 7:
                apagarTable();
                break;
            case 4:
                exibir();
            case 0:
                exit(1);
            default:
                printf("Opção inválida\n");
                restart();
        }

        restart();

}

int apagarTable(){
    limparTela();
    char tab[31],**tabelas = showTables();
    int i;

    printf("Tabelas existentes: \n");

    for(i=0;i<calc_tables();i++){
        printf("%s\n",tabelas[i]);
    }

    printf("\n\nQual tabela deseja apagar?\n");
    fgets(tab,30,stdin);
    fflush(stdin);
    limparTela();

    tab[strlen(tab)-1]='\0';

    //add o restante do diretorio
    char buffer[31];
    strcpy(buffer,tab);
    char ss[]="registros/";
    strcat(buffer,".txt");
    strcat(ss,buffer);



    if(DeleteFileA(ss)!=0){
        if(apagarKeys(tab)){

            printf("FEITO!!!");
        }
    }else{

        printf("Essa tabela não existe\n");

    }
}
void limparTela(){
    system("cls");
}
int apagarKeys(char tabela[]){
    char buf[31];
    strcpy(buf,tabela);

    char pk[]="registros/";
    strcat(pk,buf);
    strcat(pk,"_keys.txt");

    if( DeleteFileA(pk)!=0){
        return 1;
    }else{
        return 0;
    }
}

int verificarTabela(char tabela[]){
    char **tab = showTables();
    int i;
    for(i=0;i<calc_tables();i++){
        if(strComparar(tabela,tab[i]) == 0 ){
            return 1;
        }else{
            return 0;
        }
    }
}

void addResistro(){
    char **tabelasExistentes;
    char caracter;
    char arquivo[1000];
    tabelasExistentes=showTables();
    int i;
    char tabela_escolhida[31];
    int quantAtributos=0;

    printf("Lista de tabelas disponíveis:\n");
    for(i=0;i<calc_tables();i++){
        printf("<%s>\n",tabelasExistentes[i]);
    }

    printf("\nQual você quer? \n");
    fgets(tabela_escolhida,30,stdin);
    fflush(stdin);
    tabela_escolhida[strlen(tabela_escolhida)-1]='\0';

    char buffer_nomeTabela[31];
    strcpy(buffer_nomeTabela,tabela_escolhida);

    //se verifica se a tabela existe e lçer todo o seu conteudo
    if(verificarTabela(tabela_escolhida)){


        char buffer[]="registros/";
        strcat(buffer,buffer_nomeTabela);
        strcat(buffer,".txt");
        FILE *txtTabela = fopen(buffer,"r");

        if(txtTabela!=NULL){
            i=0;
            //le todo o arquivo
            while((caracter=fgetc(txtTabela))!= EOF){
            arquivo[i]=caracter;
            i++;
            }
            fclose(txtTabela);
        }else{
            printf("TABELA NAO Existe\n");
            restart();
        }
    }
    //================================================

    //descobrindo a quantidade de atributos da tabela
    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='{'){
            i++;
           while(arquivo[i]!='}'){
                if(arquivo[i]==':'){
                    quantAtributos++;
                }
            i++;
           }
        }
    }

    //=======================================================

    //Alocando vetores para guardar os atributos da tabela
    char **atributos = malloc(quantAtributos*sizeof(char*));
    for (i = 0; i < quantAtributos; ++i) {
        atributos[i] = (char *)malloc(30+1);
    }
    char *tipos = malloc((quantAtributos+1) * sizeof(char));
    //buscando por atributos atraves dos identificadores dos tipos de dados

    int p=0,k=0,j=0;
    for(i=0;i<strlen(arquivo);i++){
        if(arquivo[i]=='{'){
            while(arquivo[i]!='}'){
                if((arquivo[i]=='I' || arquivo[i]=='D' ||
                   arquivo[i]=='F' || arquivo[i]=='C' ||
                   arquivo[i]=='S') && arquivo[i-1]=='\n'){
                   tipos[k]=arquivo[i];
                   k++;
                   char buffer[31];
                   i=i+2;
                    while(arquivo[i]!=';'){
                        buffer[p]=arquivo[i];
                        i++;
                        p++;
                    }
                    buffer[p]='\0';
                    p=0;
                   strcpy(atributos[j],buffer);
                   j++;
                }
                i++;
            }
            tipos[k]='\0';
        }
    }
    //=================================================================



        int u, t = strlen(tipos);
        char buf[31];
        strcpy(buf,tabela_escolhida);
        //---carrega a tabela
        char direct[]="registros/";
        strcat(direct,buf);
        strcat(direct,".txt");
        FILE *txtTab = fopen(direct,"a+");


        char buf2[31];//para preservar , manter intacta a variável com o nome da tabela;
        strcpy(buf2,tabela_escolhida);

        if(txtTab!=NULL && (verificarTabela(buf2)==1)){
            system("cls");
            printf("CHAVE: ");
            int pk;
            scanf("%d",&pk);
            fflush(stdin);

            if(/*verifica_key(tabela,pk)==0*/1){
                fprintf(txtTab, "%d|", pk);

                for(u=0;u<t;u++){
                    printf("%s :", atributos[u]);
                    if(tipos[u]=='I'){
                        int x;
                        scanf("%d",&x);
                        fflush(stdin);
                        fprintf(txtTab,"%d|",x);
                    }else if(tipos[u]=='S'){
                        char str[31];
                        fgets(str,31,stdin);
                        str[strlen(str)-1]='\0';
                        fflush(stdin);
                        fprintf(txtTab,"%s|",str);
                    }else if(tipos[u]=='D'){
                        double d;
                        scanf("%lf",&d);
                        fflush(stdin);
                        fprintf(txtTab,"%lf|",d);
                    }else if(tipos[u]=='F'){
                        float f;
                        scanf("%f",&f);
                        fflush(stdin);
                        fprintf(txtTab,"%f|",f);
                    }else if(tipos[u]=='C'){
                        char c;
                        scanf("%c",&c);
                        fflush(stdin);
                        fprintf(txtTab,"%c|",c);
                    }
                }
                fprintf(txtTab,"%s","\n");
                fclose(txtTab);
                printf("FEITO!!!");
                addInKey(tabela_escolhida,pk);
                //restart();
            }else{
                printf("Chave primária já existente\n");
                restart();
            }

        }else{
            printf("ERROR no canal do arquivo\n");
            restart();
        }
}


void addInKey(char tab[],int key){
    char tabela[31];
    strcpy(tabela,tab);

    char dir[] = "registros/";
    strcat(dir,tabela);
    strcat(dir,"_keys.txt");

    printf("%s",dir);

    FILE *keysTXT = fopen(dir,"a+");
    fprintf(keysTXT,"%d\n",key);
    fclose(keysTXT);
}

void gerarKeys_txt(char tab[]){
    char tabela[31];
    strcpy(tabela,tab);

    char dir[] = "registros/";
    strcat(dir,tabela);
    strcat(dir,"_keys.txt");

    FILE *keysTXT = fopen(dir,"w");
    fclose(keysTXT);
}

int removeKey(char tab[],int key){
    //---carrega as chaves da tabela
    char caracter, arquivo[1000];
    char diretorio[]="registros/";
    strcat(diretorio,tab);
    strcat(diretorio,"_keys.txt");
    FILE *keys =fopen(diretorio,"r");
    int pk=0,aux=0;

    if(keys!=NULL){
        while((caracter=fgetc(keys))!= EOF){
            if(caracter=='\n'){
                fseek(keys,1,1);
                fscanf(keys,"%d\n",&pk);
                if(pk==key){
                    fprintf(keys,"%s","   /n");
                }
            }
        }
    }
}

int Verificakey(char tab[],int k){
    char tabela[31];
    strcpy(tabela,tab);
    int v=0;
    char *p;

    char dir[] = "registros/";
    strcat(dir,tabela);
    strcat(dir,"_keys.txt");
    FILE *keys=fopen(dir,"r");
    while(fgets(p,10,keys)){
        fscanf(keys,"%d\n",&v);
        if(v==k);
        return 1;
    }
    return 0;

}

void restart(){
    Sleep(2500);
    system("cls");
    menu();
}
void exibir(){
    char caracter , arquivo[1000], tabela_escolhida[31],**tabelasExistentes=showTables();
    int i=0,quantAtributos=0;
    FILE* Tabel;
    printf("Lista de tabelas disponíveis:\n");
    for(i=0;i<calc_tables();i++){
        printf("<%s>\n",tabelasExistentes[i]);
    }

    printf("\nQual você quer? \n");
    fgets(tabela_escolhida,30,stdin);
    fflush(stdin);
    tabela_escolhida[strlen(tabela_escolhida)-1]='\0';

    // se verifica se a tabela existe,ler todo o seu conteudo, e calcula a quantidae de colunas;
    char dir[]="registros/";
    strcat(dir,tabela_escolhida);
    strcat(dir,".txt");
    Tabel = fopen(dir,"r");

    if(Tabel!=NULL){
        i=0;
        //---le todo o arquivo
        while((caracter=fgetc(Tabel))!= EOF){
            arquivo[i]=caracter;
            i++;
        }
        arquivo[i+1]='\0';
        fclose(Tabel);
        //*************************************************


        //---descobrindo a quantidade de atributos da tabela
        for(i=0;i<strlen(arquivo);i++){
            if(arquivo[i]=='{'){
                i++;
                while(arquivo[i]!='}'){
                    if(arquivo[i]==':'){
                        quantAtributos++;
                    }
                    i++;
                }
            }
        }
        //*************************************************


        //---imprimindo os atributos atraves dos identificadores dos tipos de dados
        int p=0;
        for(i=0;i<strlen(arquivo);i++){
            if(arquivo[i]=='{'){
                while(arquivo[i]!='}'){
                    if((arquivo[i]=='I' || arquivo[i]=='D' || arquivo[i]=='F' || arquivo[i]=='C' || arquivo[i]=='S') && arquivo[i-1]=='\n'){
                        char buffer[31];
                        i=i+2;
                        while(arquivo[i]!=';'){
                            buffer[p]=arquivo[i];
                            i++;
                            p++;
                        }
                        buffer[p]='\0';
                        p=0;
                        printf("%s|",buffer);
                    }
                    i++;
                }
                printf("\n");
            }
        }
        //**********************************************************************************************************************************

        //---Imprimindo as tuplas da tabela, tabulando a partir dos identificador "|";
        FILE * tata = fopen(dir,"r");
        int k=0;
        for(i=0;i<strlen(arquivo);i++){
            if(arquivo[i]=='}'){
                k=i;
            }
        }
        k=k+5;
        if(tata!=NULL){
            fseek(tata,k+1,0);
            char c;
            while((c = fgetc(tata)) != EOF){
                printf("%c",c);
            }
        }


        //********************************************************************************


    }else{
        fclose(Tabel);
        printf("Tabela não existe\n");
        restart();
    }
}




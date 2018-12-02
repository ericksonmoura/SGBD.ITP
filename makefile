#Makefile do projeto SGBD ITP

all:
	@echo "Compilando o main.c"
	@gcc main.c funcoes/funcoes.c -o executavel
	@echo "Para executar, digite \"make run\""

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

void IincVet(int vet[],int x){
	int i;
	for(i = 0 ; i < x ; i++) {
		vet[i]=0;
	}
}

void CincVet(char vet[],int x){
	int i;
	for(i = 0 ; i < x ; i++) {
		vet[i]=0;
	}
}

void linha(int x) {//gera uma linha.
	int i;
	printf("\n");
	for(i = 1 ; i < x ; i++) {
		printf("-");
	}
	printf("\n");
}

int BancoDeNumero(char num) {//numeros sendo convertidos en caracteres
	switch(num) {
		case '0': return 0;
			break;
		case '1': return 1;
			break;
		case '2': return 2;
			break;
		case '3': return 3;
			break;
		case '4': return 4;
			break;
		case '5': return 5;
			break;
		case '6': return 6;
			break;
		case '7': return 7;
			break;
		case '8': return 8;
			break;
		case '9': return 9;
			break;
		case 'a':
		case 'A': return 10;
			break;
		case 'b': 
		case 'B': return 11;
			break;
		case 'c':
		case 'C': return 12;
			break;
		case 'd':
		case 'D': return 13;
			break;
		case 'e':
		case 'E': return 14;
			break;
		case 'f':
		case 'F': return 15;
			break;
	}	
}

char BancoDeCaracter(int num) {//numeros sendo convertidos em caracteres
	switch(num) {
		case 0: return '0';
			break;
		case 1: return '1';
			break;
		case 2: return '2';
			break;
		case 3: return '3';
			break;
		case 4: return '4';
			break;
		case 5: return '5';
			break;
		case 6: return '6';
			break;
		case 7: return '7';
			break;
		case 8: return '8';
			break;
		case 9: return '9';
			break;
		case 10: return 'A';
			break;
		case 11: return 'B';
			break;
		case 12: return 'C';
			break;
		case 13: return 'D';
			break;
		case 14: return 'E';
			break;
		case 15: return 'F';
			break;
	}	
}

int ConvIntEmNum(char num[],int base) {//convertendo um vetor de string em vetor de inteiro.
	int expoente,i,maxI,soma=0,numero;
	
	maxI=strlen(num);
	
	expoente=maxI-1;
	
	for(i = 0 ; i < maxI ; i++) {
		numero=BancoDeNumero(num[i]);
		soma+=numero*(pow(base,expoente));
		expoente--;
	}
	
	return soma;
}

int conversor(int num,int base, int numero[]) {
	int i=0,resto;
	
	while(num) {
		resto = num % base;
		num /= base;
		numero[i]= resto;
		i++;
	}
	return i;
}

void Impressao(int base,int maxI, int numero[]) {
	int i=0;
	
	linha(33);
	printf("\nNumero na base %i: ",base);
	for(i = 0 ; i < maxI ; i++) {
		if( i < maxI - 1 )
			printf("%c",BancoDeCaracter(numero[i]));
		else
			printf("%c\n",BancoDeCaracter(numero[i]));
	}
	linha(33);
}

void calculoConversor(char num[],int baseDoNumeroConvert,int baseDoNumero) {
	int maxI,i,numeroI,numero[40],respostaIvert[40];
	
	//Inicializando variaves
	IincVet(numero,40);
	IincVet(respostaIvert,40);
	
	//converte a string em um numero inteiro
	numeroI=ConvIntEmNum(num,baseDoNumero);
	
	//conta do conversor armazena quantas possiçoes usou.
	maxI=conversor(numeroI,baseDoNumeroConvert,respostaIvert);
	
	//inverter resposta
	for(i = 0 ; i < maxI ; i++)
		 numero[i]=respostaIvert[maxI-i-1];
	
	//Impreção
	Impressao(baseDoNumeroConvert,maxI,numero);
	
	system("Pause");
}

int testeBase(char num[],int base) {//teste base
	int i,maxI,numero;
	
	maxI=strlen(num);
	
	if(base <= 1)
		return 1;
	
	for(i = 0 ; i < maxI ; i++) {
		numero=BancoDeNumero(num[i]);
		if(numero >= base)
			return 1;
	}
	return 0;
}

int main() {
	int baseDoNumero,baseDoNumeroConvert;
	char numero[20];
	
	system("title Conversor de Base");
	
	CincVet(numero,20);
	
	setlocale(LC_ALL,"");
	
	linha(90);
	printf("Conversor de qualquer base menor ou igual a 16 para qualquer base menor ou igual a 16.");
	linha(90);
	
	printf("Digite o numero ");
	scanf("%s",numero);
	
	do {
		printf("\nDigite a sua base ");
		scanf("%i",&baseDoNumero);
		if(testeBase(numero,baseDoNumero))
			printf("A base não pode ser um numero menor que algum numero do numero escrito a cima ou menor ou igual a 1.\n");
	}while(testeBase(numero,baseDoNumero));
	
	printf("\nDigite a base para converção ");
	scanf("%i",&baseDoNumeroConvert);
	
	calculoConversor(numero,baseDoNumeroConvert,baseDoNumero);
}

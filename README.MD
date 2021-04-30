# Conversor de base

bem a converção de base e um conceito mátematico onde podemos ver por meio dessa função que recebe um certo numero para tentar entender melhor esta função vamos tentar conveter um numero:

` O numero 14 na base 10 vamos convertelo para a base 3`

Pegamos o numero e dividimos pela sua base que queremos converter 14/3 da resto 1 e quociente 4 eu irei repetir este processo ate que o com o quociente ate que de 0.(Obrigatorimente o numero a ser convetido precisa estar na base 10 antes de passar para a próxima)

1° processo 14/3 = resto 1 e quociente 4
2° processo 4/3 = resto 1 e quociente 1
3° processo 1/3 = resto 2 e quociente 0

E pegando o resto da ordem em que sao apresentados temos o numero 14 na base 10 para a base 3 para _112_


```c
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
```

## Algumas resalvas sobre o funcionamento do programa

bem primeiro a entrada precisa ser um Float por conta de algumas entradas poderem ser _A, B_ que não são numeros para o sistema entao precisamos fazer alguma coisa para trasformar essas letras em numeros que o programa ententa para isso fazemos o seguinte fazemos um tratamento da entrada para conveter para numero e armazenar um arry que a representatividade do valor dele nao sera divida no seguinte sentido `vetorChar[1]= A` então sabemos que A e igual a 10 que sao dois algorismos e eu posso botar na posição `vetorInt[1]=10` podendo depois fazer o processo inverso para apresentar esses dados para o usuario.

segue o codigo que faz esta parte no codigo:

```c
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
```

Agora o nosso problema pricipal e como represntar isso as desenas e os milhares de cada um deses valores que ate agora os dados estao tipo `vetorInt[0]=12` `vetorInt[1]=4` `vetorInt[2]=14` isso realmente nao signifca nada apenas que precisamos somar todos os valores e trazer para a base em questão que neste caso e 16 na posição maxima do vetor menos um e ir decrementando ate acabar o arry.

`vetorInt[0]=12`
`vetorInt[1]=4`
`vetorInt[2]=14`

`soma += vetorInt[0]*(pow(16,2));`
`soma += vetorInt[1]*(pow(16,1));`
`soma += vetorInt[2]*(pow(16,0));`


```c
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
```

bem usar esta soma para efetuar e usar na função que falamos acima por ja deixarmos preparado na base 10 e conseguirmos converter para qualquer base desejada caso queria converter para uma base maior de 16 basta almentar o banco de `switch` acrecetando as outras representatividades

```c
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
```

obrigado por ler até aqui e pela atenção espero que tenha te ajudado este repositorio
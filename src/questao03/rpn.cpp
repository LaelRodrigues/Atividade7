/**
 * @file	rpn.cpp
 * @brief	codigo fonte com a implementacao da funcao que  
 * 			calcula o valor de um derminada expressao
 *			escrita na notacao polonesa inversa 
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	07/06/2017
 * @date	07/06/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <stack>
using std::stack;

#include <cstdlib>
using std::atoi;
using std::exit;

#include <cstring>

#include "rpn.h"


/**
 * @brief Funcao que calcula o valor de um determinada 
 *		  expressao escrita na notacao polonesa inversa
 * @param tam quantidade de argumentos da expressao
 * @param argumentos elementos que compoem a expressao
 * @return o valor do calculo da expressao
 */
int calcValorExpressao(int tam, char **argumentos) {
	
	stack <int> pilha;

	int operador1;
	int operador2;
	int cont;

	const char *num[] = {"0","1","2","3","4","5","6","7","8","9"};

	for(int i = 1; i < tam; i++) {
		
		cont = 0;
		if(strcmp(argumentos[i], "+") == 0) {
			operador2 = pilha.top();
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 + operador2);
		}
		else if(strcmp(argumentos[i], "-") == 0) {
			operador2 = pilha.top();
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 - operador2);
		}
		else if(strcmp(argumentos[i], ".") == 0) {
			operador2 = pilha.top();
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 * operador2);
		}
		else if(strcmp(argumentos[i], "/") == 0) {
			operador2 = pilha.top ();
			if(operador2 == 0) {
				cout << "Erro: na expressao existe uma divisao por 0(nao e possivel dividir por 0)." << endl;
				exit(1);
			}
			pilha.pop();
			operador1 = pilha.top();
			pilha.pop();
			pilha.push(operador1 / operador2);
		}
		else {
			for(int j = 0; j < 10; j++) {
				if(strcmp(argumentos[i], num[j]) == 0) {
					pilha.push(atoi(argumentos[i]));
					cont++;
					break;
				}
			}
			if(cont != 1) {
				cout << "paramentro(s) digitados sao invalido(s)." << endl;
				exit(1);
			}
		}
	}

	return pilha.top();
}

/**
 * @file	primos.h
 * @brief	Implementacao de funcoes que realizam operacoes
 *			em relacao a valores primos presentes em um conteiner
 * @author	Lael Rodrigues (laelrodrigues7@gmail.com)
 * @since	08/06/2017
 * @date	08/06/2017
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::atoi;

#include <algorithm>
using std::find_if;

#ifndef SEQPRIMOS_H
#define SEQPRIMOS_H


/**
 * @brief Funcao para determinar se um numero é primo
 * @param numero Valor verificado
 * @return True se numero for primo e false caso contrario
 */
bool primo(int numero) {

	int cont = 0;

	for(int i = 2; i < numero; i++) {
		if (numero % i == 0) {
			cont++;
		}	
	}
	if(cont == 0) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief Funcao que insere em um container valores de 
 *		  1 a N(onde N = tam) e imprime todos os valores 
 *		  primos presentes no container
 * @param tam Tamanho do container
 * @param container Conteiner que armazenar os valores
 */
template <typename TContainer>
void sequenciaPrimos(int tam, TContainer& container){

	for(int i = 1; i <= tam; i++) {
		container.push_back(i);
	}

	int cont = 1;
	cout << "Numeros primos [1-50]: ";
	auto it = container.begin();
	for(auto i = container.begin(); i != container.end(); ++i) {
		
		it = find_if(i, container.end(), primo);
		if(primo(cont)) {
			cout << *it << " ";
		}	
		cont++;
	}
	cout << endl;
}

#endif
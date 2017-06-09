/**
 * @file	imprime.h
 * @brief	implementacao da funcao para imprimir elementos 
 *			de um container  
 * @author	LaelRodrigues (laelrodrigues7@gmail.com)
 * @since	06/06/2017
 * @date	08/06/2017
 */	

#ifndef IMPRIME_H
#define IMPRIME_H

#include <iostream>
using std::cout;
using std::endl;

/**
 * @brief funcao que imprime elementos de um container
 * @param collection container que tera os elementos impressos
 * @param label vetor de caracteres 
 * @param separator caractere para separacao dos elementos
 */ 
template<typename TContainer>
void print_elementos(const TContainer& collection, const char* label="",
	const char separator=' '){

	cout << label;
	for(auto it = collection.begin(); it != collection.end(); ++it){
		cout << *it << separator;
	}
	cout << endl;
}

#endif
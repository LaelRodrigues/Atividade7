/**
 * @file	intervalo.h
 * @brief	implementacao da funcao que realiza operacoes para 
 *			encontrar o elemento do intervalo cujo valor é o mais  
 *			proximo da media do intervalo.
 * @author	LaelRodrigues (laelrodrigues7@gmail.com)
 * @since	05/06/2017
 * @date	05/06/2017
 */	

#include <typeinfo> 

#ifndef INTERVALO_H
#define INTERVALO_H

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

/**
 * @brief funcao que encontra o elemento do intervalo cujo
 *		  valor é o mais o proximo da media do intervalo
 * @param first iterador para o primeiro elemento do container
 * @param last iterador para uma posicao apos o ultimo elemento
 * @return iterador para o elemento mais proximo da media do intervalo
 */ 
template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last){

	auto soma = 0;
	int cont = 0;

	for(auto it = first; it != last; ++it) {
		soma += *it;
		cont++;
	}

	auto media = soma/cont;

	auto it = first;
	auto elemento = it;

	auto prox = abs(*it - media);
	it+1;
	for(int i = 0; i < cont-1; ++i, ++it){
		
		if(abs(*it - media) < prox){
			prox = abs(*it - media);
			elemento = it;
		}		
	}

	return elemento;
}

#endif
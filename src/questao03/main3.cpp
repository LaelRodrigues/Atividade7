/**
 * @file	main3.cpp
 * @brief	Codigo fonte de teste da funcao que calcula o
 *			valor de uma determinada expressao escrita na 
 *			notacao polonesa inversa
 *			presente no aquivo imprime.h
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	08/06/2017
 * @date	08/06/2017
 */


#include <iostream>
using std::cout;
using std::endl;

#include "rpn.h"

/** @brief Funcao principal */
int main(int argc, char* argv[]) {

	if(argc < 2){
		cout << "Erro: a expressao nao foi digitada." << endl;
		return EXIT_FAILURE;
	}

	int result = calcValorExpressao(argc, argv);
	cout << "O valor resultante da expressao e: " << result << endl;
	return EXIT_SUCCESS;


	return 0;
}
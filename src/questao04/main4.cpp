/**
 * @file	main4.cpp
 * @brief	Codigo fonte de teste da funcaos realizam 
 *			operacoes referente a valores primos contidos
 *			em um container
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	08/06/2017
 * @date	08/06/2017
 */

#include <list>
using std::list;

#include "primos.h"

/** @brief Funcao principal */
int main(int argc, char* argv[]) {

	if (argc < 2){
		cout << "Erro: nao foram digitados os paramentros necessarios." << endl;
		return EXIT_FAILURE;
	}

	int valor = atoi(argv[1]);
	list<int> vetor;
	sequenciaPrimos(valor, vetor);
	return EXIT_SUCCESS;

   
	return 0;
} 	

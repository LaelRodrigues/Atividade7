/**
 * @file	main2.cpp
 * @brief	Codigo fonte de teste da funcao print_elementos
 *			presente no aquivo imprime.h
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	07/06/2017
 * @date	08/06/2017
 */

#include <set>
using std::set;

#include "imprime.h"

/** @brief Funcao principal */
int main() {
	
	set<int> numeros;
	numeros.insert(3);
	numeros.insert(1);
	numeros.insert(4);
	numeros.insert(1);
	numeros.insert(2);
	numeros.insert(5);

	print_elementos(numeros, "Set: ");
	print_elementos(numeros, "CSV Set: ", ';');

	return 0;
}
/**
 * @file	main.cpp
 * @brief	Codigo fonte principal de teste da funcao
 *			closest2mean presente no arquivo intervalo.h
 * @author	LaelRodrigues (laelRodrigues7@gmail.com)
 * @since	06/06/2017
 * @date	06/06/2017
 */


#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "intervalo.h"

/** @brief Funcao principal */
int main() {
	vector<float> v { 1, 2, 3, 30, 40, 50 };
	auto result = closest2mean(v.begin(), v.end());
	cout << "O valor do elemento mais proximo da media do intervalo e: " << (*result) << endl;
	return 0;
}
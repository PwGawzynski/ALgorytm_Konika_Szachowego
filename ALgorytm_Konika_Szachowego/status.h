#ifndef DEBUG
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#endif // DEBUG

/**
 * \brief Funkcja sprawdza czy wartość "test" została zainicjalizowana. 
 *
 * \param[in] description opis.
 * \param[in] test wartość do sprawdzenia.
 * \return Zwraca true jeżeli dana wartość działa poprawnie.
 * 
 */

bool must_init(bool test,const char* description) {
	if (test) { return true; }
	else {
		printf("Cannot inicialize or value fault \n DESCRIPTION: %s", description);
		system("pause");
		exit(1);
	}
}
#include <iostream>
#include "SimpleReversePolishCalculator.h"

/*
    Existe un tipo de notacion conocida como notación polaca inversa,
cuya ventaja es que realiza operaciones compuestas sin necesidad de utilizar parentesis.

Por ejemplo la siguiente operación infijo:
  (4 + 2) * (7 - 5)
Se expresaria en notación polaca inversa de la siguiente forma:
  4 2 + 7 5 - *

    Como se observa en notación polaca inversa se coloca primero los 2 numeros seguidos
por la operación, conservando la precedencia.

Ejemplo:
  (4 - 2) * 10

En notación polaca inversa se expresaria:
  4 2 - 10 *

    Diseñar y escribir una función que recepcione una expresión en notación polaca
inversa que se denominara:

  simple_reverse_polish_calculator

    Esta función recibira como parametro una expresión arítmetica en notación polaca del
tipo Texto y mostrara el resultado de la expresion.
*/

int main() {
    std::cout << "The first result is: ";
    simple_reverse_polish_calculator("5 2 - 10 *");  // Equivalente a (5 - 2) * 10
    std::cout << "The second result is: ";
    simple_reverse_polish_calculator("10 0 /");      // Equivalente a 10 / 0
    std::cout << "The third result is: ";
    simple_reverse_polish_calculator("10 5 ^");      // Equivalente a 10 ^ 5, No existe la operación ^
    std::cout << "The fourth result is: ";
    simple_reverse_polish_calculator("10.5 5 / 3.5 2 * +");      // Equivalente a (10.5 / 5) + (3.5 * 2)
    return 0;
}
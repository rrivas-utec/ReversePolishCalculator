//
// Created by ruben on 9/1/19.
//

#ifndef POLISH_NOTATION_SIMPLEREVERSEPOLISHCALCULATOR_H
#define POLISH_NOTATION_SIMPLEREVERSEPOLISHCALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

// Tipos Genericos
enum class TermType
{
    Number = '0',
    Sum = '+',
    Rest = '-',
    Multiplication = '*',
    Division = '/',
    Empty = '\0'
};

typedef double Number;
typedef std::string Text;
typedef char Character;
typedef void Void;
typedef std::pair<TermType, Text> Token;
typedef std::vector<double> Stack;

// Funciones
Token get_token(Text&);     // Retorna los token de una expresion
Void push(Stack&, Number);  // Push en un Stack
Number pop(Stack&);         // Pop de un Stack
Void simple_reverse_polish_calculator(Text); // Funcion Solicitada

#endif //POLISH_NOTATION_SIMPLEREVERSEPOLISHCALCULATOR_H

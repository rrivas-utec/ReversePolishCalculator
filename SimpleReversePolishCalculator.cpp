//
// Created by ruben on 9/1/19.
//

#include "SimpleReversePolishCalculator.h"

Void push(Stack& s, Number n) {
    s.push_back(n);
}

Number pop(Stack& s) {
    auto result = s.back();
    s.pop_back();
    return result;
}

Token get_token(Text& expr) {
    Text term = Text();
    size_t i = 0;
    Text rest;

    // Limpiando de posibles espacios iniciales
    if (isblank(expr[i]))
        while (isblank(expr[++i]));

    // Evaluando si expresion queda vacia
    if (i >= expr.size()) {
        return {TermType::Empty, term};
    }

    // Evaluando si termino no es numerico
    if (!isdigit(expr[i]) && expr[i] != '.') {
        char c = expr[i++];
        while (i < expr.size())
            rest += expr[i++];
        expr = rest;
        return {TermType(c), term};
    }

    // Evaluando si termino es numerico
    if (isdigit(expr[i]))
        while (isdigit(expr[i]))
            term += expr[i++];

    if (expr[i] == '.') {
        term += expr[i++];
        while (isdigit(expr[i]))
            term += expr[i++];
    }

    // Actualizando expresion con resto
    while (i < expr.size())
        rest += expr[i++];
    expr = rest;

    // Retornando token numerico
    return {TermType::Number, term};
}

Void simple_reverse_polish_calculator(Text expression) {

    // Variables requeridas
    Token token;
    Number oper2;
    Stack stack;

    // Recorriendo expresiones
    while ((token = get_token(expression)).first != TermType::Empty) {
        switch (token.first) {

            // Push numero en stack
            case TermType::Number:
                push(stack, stod(token.second));
                break;

                // Pop 2 numeros y Push Suma de los 2 numeros
            case TermType::Sum:
                push(stack, pop(stack) + pop(stack));
                break;

                // Pop 2 numeros y Push Multiplication de los 2 numeros
            case TermType::Multiplication:
                push(stack, pop(stack) * pop(stack));
                break;

                // Pop 2 numeros y Push Resta de los 2 numeros
            case TermType::Rest:
                push(stack, -pop(stack) + pop(stack));
                break;

                // Pop 2 numeros y Push Division si segundo numero no es CERO
            case TermType::Division:
                oper2 = pop(stack);
                if (oper2 != 0)
                    push(stack, pop(stack) / oper2);
                else {
                    std::cout << "Error: Division by Zero\n";
                    return;
                }
                break;

                // Si tipo de termino es desconocido envia mensaje
            default:
                std::cout << "Error: Unknown command: " << char(token.first) << std::endl;
                return;
        }
    }
    // Mostrando resultado
    std::cout << pop(stack) << std::endl;
}
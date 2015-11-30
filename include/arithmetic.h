#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"

bool Check_the_brackets ( char *s); // проверка корректности скобок

bool Check_of_operatoins_and_operands( char *s); //проверка корректности использования знаков операций и переменных

int Type( char a); // тип 

int Priority ( char a); // приоритет

bool Are_used_variables (char *s); // функция, проверяющая, использовались ли переменные

void Assigment_of_lines ( char *s, char* s1); // замена переменных их значениями 

void Assigning_values_to_variables (char* s); // приравнивание двух строк

double Calculation ( char *s); // вычисления

void ToPostfix(char *s, char**& post);

double Calc(char** post);

void Free(char**& post, int n);

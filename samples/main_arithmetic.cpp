//переменные, унарный минус
#include "arithmetic.h"
#include <cstring>
#include <iostream>
using namespace std;

int main()
{	
	char string[256];
	char** post;
	double result;
	setlocale(LC_ALL, "Russian");
	cout << "Введите выражение, которое хотите вычислить(не более 256 знаков)."
    << endl;
	cout << "Обращаю внимание на то, что в качестве переменных можно использовать только латинские буквы."
	<< endl;
	cout << "Для разделения целой и дробной части используйте запятую."
	 << endl;
	 gets_s(string);
	cout << endl; 
	while(( Check_the_brackets( string ) == false ) || ( Check_of_operatoins_and_operands( string ) == false ))
	{
		cout << "Вы ввели некорректное выражение. Пожалуйста, проверьте правильность и введите выражение снова"
		<< endl;
		gets_s(string);
		cout << endl << endl;
	}
	if( Are_used_variables(string) == true )
	{
		char string1[256];
		Assigment_of_lines( string, string1 );
		Assigning_values_to_variables (string);
		result = Calculation (string);
		cout << string1 << " = " << result 
		<< endl << endl;
		int i = 0;
		cout << "Хотите ли Вы повторить вычисления с другими значениями переменных?"
		<< endl;
		cout << "1.Да   2.Нет"
		<< endl << endl;
		cin >> i;
		cout << endl;
		if (i == 1)
		{
			char string2[256];
			Assigning_values_to_variables(string1);///
			Assigment_of_lines( string1, string2 );
			result = Calculation (string1);
			cout << string1 << " = " << result
			<< endl<< endl;
		}
	}
	else
	{
		//result = Calculation(string);
		ToPostfix(string, post);
		result = Calc(post);
		cout << string << " = " << result
		<< endl;
		Free(post, strlen(string));
	}
	system("pause");
}
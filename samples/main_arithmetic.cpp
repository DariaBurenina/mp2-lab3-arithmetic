//����������, ������� �����
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
	cout << "������� ���������, ������� ������ ���������(�� ����� 256 ������)."
    << endl;
	cout << "������� �������� �� ��, ��� � �������� ���������� ����� ������������ ������ ��������� �����."
	<< endl;
	cout << "��� ���������� ����� � ������� ����� ����������� �������."
	 << endl;
	 gets_s(string);
	cout << endl; 
	while(( Check_the_brackets( string ) == false ) || ( Check_of_operatoins_and_operands( string ) == false ))
	{
		cout << "�� ����� ������������ ���������. ����������, ��������� ������������ � ������� ��������� �����"
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
		cout << "������ �� �� ��������� ���������� � ������� ���������� ����������?"
		<< endl;
		cout << "1.��   2.���"
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
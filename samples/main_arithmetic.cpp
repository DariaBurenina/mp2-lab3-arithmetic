#include "arithmetic.h"
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	char str[256];
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������, ������� ������ ���������"
    << endl;
    gets_s(str);
	/*cout << str
    << endl;*/
	system("pause");
}
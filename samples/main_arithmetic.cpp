#include "arithmetic.h"
#include <cstring>
#include <iostream>
using namespace std;

int main()
{	
	char string[256];
	char post[256];
	setlocale(LC_ALL, "Russian");
	cout << "Введите выражение, которое хотите вычислить(не более 256 знаков)"
    << endl;
    gets_s(string);

	while(( Check_the_brackets( string ) == false ) || ( Check_of_operatoins_and_operands( string ) == false ))
	{
	cout << "Вы ввели некорректное выражение. Пожалуйста, проверьте правильность и введите выражение снова"
    << endl;
	gets_s(string);
	}
	Peverse_Polish_notation (string, post);
	int j = 0;
	while(post[j] != '\0')
	{
		cout << post[j];
		j++;
	}
	//cout << string
	 //<< endl;














	//char post[20];
	//char part[20];
	////int type[20];
	//char str[] = "(a+b*7)*3-2";
	//char st[] = "ab+4-5*6*6";

	//int k = 0;
	//setlocale(LC_ALL, "Russian");
	/*cout << "Введите выражение, которое хотите вычислить"
    << endl;*/
    //gets_s(str);
	//cout << str
 //   << endl;
	////Разбиение
	//Partition(str, part, k);
	//int i = 0;
	//while(part[i] != '\0')
	//{
	//	cout << part[i];
	//	i++;
	//}
	//cout << str
 //   << endl;
  /*  int p = Type('3');
		cout << p
			<< endl;*/
	////Польская запись
	//Peverse_Polish_notation (str, post);
	//int j = 0;
	//while(post[j] != '\0')
	//{
	//	cout << post[j];
	//	j++;
	//}
	//int q = 0;
	//if(Check_of_operatoins_and_operands(st) == false)
	//	q = 1;
	//cout << q
	//		<< endl;

	system("pause");
}
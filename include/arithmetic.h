#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"



void Partition ( char *s)
{
	char variables[] = "qwertyuiopasdfghjklzxcvbnm";
	char signs[] = "()+*-/";
	//char figures[] = "1234567890";
	char type1[256]; // тип1: переменные
	char type2[256]; // тип2: операции
	//char type3[256];// тип3: цыфры
	int k1 = 0;
	int k2 = 0;
	//int k3 = 0;
	for( int i = 0; i < strlen(s); i++)
		for( int j = 0; j < strlen(variables); j++)
		{
			if( s[i] == variables[j] )
			{
				type1[k1] = s[i];
				k1++;
			}
		}
	for( int i = 0; i < strlen(s); i++)
		for( int j = 0; j < strlen(signs); j++)
		{
			if( s[i] == signs[j] )
			{
				type2[k2] = s[i];
				k2++;
			}
		}
		//return *type1,*type2;
}


bool Check_the_brackets ( char *s)
{
	bool temp;
	Stack<int> st(strlen(s));
	for ( int i = 0; i < strlen(s); i++)
	{
		if( s[i] == '(' )
					st.Push('(');
			if( s[i] == ')' )
				if (st.Top > -1)
					st.Get();
				else 
				{
					temp = false;
					return temp;
				}
	}
	temp = st.IsEmpty();
	return temp;

}

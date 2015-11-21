#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"


char Partition_into_variables( char *s)
{
	char variables[] = "qwertyuiopasdfghjklzxcvbnm";
	char type1[256]; // тип1: переменные
	int k1 = 0;
	for( int i = 0; i < strlen(s); i++)
		for( int j = 0; j < strlen(variables); j++)
		{
			if( s[i] == variables[j] )
			{
				type1[k1] = s[i];
				k1++;
			}
		}
		return *type1;
}

char Partition_into_signs( char *s)
{
	char signs[] = "()+*-/";
	char type2[256]; // тип2: операции
	int k2 = 0;
	for( int i = 0; i < strlen(s); i++)
		for( int j = 0; j < strlen(signs); j++)
		{
			if( s[i] == signs[j] )
			{
				type2[k2] = s[i];
				k2++;
			}
		}
	return *type2;
}

char Partition_into_figures( char *s)
{
	char figures[] = "1234567890";
	char type3[256]; // тип3: цифры
	int k3 = 0;
	for( int i = 0; i < strlen(s); i++)
		for( int j = 0; j < strlen(figures); j++)
		{
			//while( s[i] = figures[j]
			if( s[i] == figures[j] )
			{
				type3[k3] = s[i];
				k3++;
			}
		}
	return *type3;
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
//char Partition (char *s)
//{
//	char part[256];
//	//char a;
//	 char type1 = Partition_into_variables(s); // type1
//	Partition_into_figures(s);  // type2
//	Partition_into_signs(s);  // type3
//	for (int i = 0; i < strlen(s); i++)
//	{
//		for(int j = 0; j < 256; j++)
//			if( s[i] == type1[j] )
//				part[i] = type1[j];
//	}
//}

bool Check_of_operatoins_and_operands( char *s)
{
	char variables[] = "qwertyuiopasdfghjklzxcvbnm";
	char signs[] = "+*-/";
	char figures[] = "1234567890";
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка ab  
		for( int j = 0; j < strlen(variables); j++)
			if( s[i] == variables[j] ) 
				for( int k = 0; k < strlen(variables); k++)
					if ( s[i + 1] == variables[k] )
						return false;
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка +*  
		for( int j = 0; j < strlen(signs); j++)
			if( s[i] == signs[j] ) 
				for( int k = 0; k < strlen(signs); k++)
					if ( s[i + 1] == signs[k] )
						return false;
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка a+
		for( int j = 0; j < strlen(variables); j++)
			if( s[i] == variables[j] ) 
				for( int k = 0; k < strlen(signs); k++)
					if(( s[i + 1] == signs[k] ) && ( s[i + 2] == '\0'))
								return false; 
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка 1+
		for( int j = 0; j < strlen(figures); j++)
			if( s[i] == figures[j] ) 
				for( int k = 0; k < strlen(signs); k++)
					if(( s[i + 1] == signs[k] ) && ( s[i + 2] == '\0'))
								return false; 
	return true;
}


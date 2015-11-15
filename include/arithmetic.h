#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"



void Partition ( char *s)
{
	char variables[] = "qwertyuiopasdfghjklzxcvbnm";
	//char signs[] = "()+*-/";
	char type1[256];
	int k = 0;
	for( int i = 0; i < strlen(s); i++)
		for( int j = 0; j < strlen(variables); j++)
			if( s[i] == variables[j] )
			{
				type1[k] = s[i];
				k++;
			}
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

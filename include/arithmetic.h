#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"

char Partition (char *s)
{
	char variables[] = "qwertyuiopasdfghjklzxcvbnm";
	char signs[] = "()+*-/";
	char figures[] = "1234567890";
	char part[256];
	int k = 0;
	int r;
	
	for( int i = 0; i < strlen(s); i++)
	{
		for( int j = 0; j < strlen(variables); j++)
			if( s[i] == variables[j] )
			{	
				part[k] = s[i];
				k++;
			}
		for( int j = 0; j < strlen(signs); j++)
			if( s[i] == signs[j] )
			{
				part[k] = s[i];
				k++;
			}
		for( int j = 0; j < strlen(figures); j++)
			if( s[i] == figures[j] )
			{
				/*for (int k = 0; k < strlen(figures); k++)
					if ( s[i +1] == figures[k] )
					{
						r1 = atoi(&figures[j]);
						r2 = atoi(&figures[k]);
						r = 10*r1 + r2;
						part[k1] = (char)r;
						type[k2] = 3;
						k1++;
						k2++;
					}
					*/
						part[k] = s[i];
						k++;					
			}
	}	
	return *part;
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

char Peverse_Polish_notation ( char *s)
{
	char flag1, flag2;
	Stack<char> st(256);
	char temp[256]; // постфиксная запись
	int prioritet[256];
	int n, ind;
	n = 0;
	char part = Partition(s);
	for(int i = 0; i < 256; i++)
	{
		prioritet[i] = 0;
		if((part[i] == '(')||(part[i] == ')'))
			prioritet[i] = 1;
		if((part[i] == '+') || (part[i] == '-'))
			prioritet[i] = 2;
		if((part[i] == '*')||(part[i] == '/'))
			prioritet[i] = 3;
	}

	for( int i = 0; i < 256; i++)
	{
		if (prioritet[i] == 0)
		{
			temp[n] = part[i];
			n++;
		}
	
		if (( prioritet[i] == 2) || ( prioritet[i] == 3))
		{
			if ( st.IsEmpty() == true )
				st.Push( part[i] );
			else
			{
				flag1 = st.Get();
				st.Push( flag1 );
				for (int w = 0; w < 256; w++)
					if (part[w] == flag1)
						ind = w;
				do
				{
					temp[n] = st.Get();
					n++;
					flag1 = st.Get(); 
				}
				while( prioritet[i] <= prioritet[ind] ); 
				st.Push( part [i]);
			}
		}
		if( part[i] == '(' )
			st.Push('(');
		if( part[i] == ')' )
		{
			flag2 = st.Get();
			do 
			{
				temp[n] = flag2;
				n++;
				flag2 = st.Get();
			}
			while ( flag2 != '(');
		}
	}
return *temp;
}
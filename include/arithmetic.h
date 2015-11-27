#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"

void Partition (char *s, char *part , int k1)
{
	char signs[] = "()+*-/";
	k1 = 0;
	for( int i = 0; i < strlen(s); i++)
	{
		if( isalpha(s[i]) )
		{	
			//strncpy( part[k1], s + i, 1 ); 
			part[k1] = s[i];
			k1++;
		}
		for( int j = 0; j < strlen(signs); j++)
			if( s[i] == signs[j] )
			{
				//strncpy( part[k1], s + i, 1 );
				part[k1]= s[i];
				k1++;
			}
		if( isdigit(s[i]) )
		{
			//	int m = 0;
			//if( (s[i + 1] != '\0') && ((s[i + 1] == '.') || ( isdigit(s[i + 1] ))))
			//	while( (s[i + 1] != '\0') && ((s[i + 1] == '.') || ( isdigit(s[i + 1] ))))
			//{
			//	//strncpy( part[k1], s + i, 1);
			//	part[k1]/*[m]*/ = s[i];
			//	i++;
			//	m++;
			//	}
			//}
			//else 
				part[k1] = s[i];
				k1++;
		}
			//int pos = i + 1;
			//while ( (pos < strlen(s)) && (isdigit(s[pos])) || (s[pos] == '.') )
			//	pos++;
			//strncpy( part[k1], s + i, pos - i );
			//i = pos - 1;
			//type[k2] = 3;
			//k2++;
			//k1++;
	}
part[k1] = '\0';
}

int Type( char a)
{
	char signs[] = "()+*-/";
	int temp = 0;
	if( isalpha(a) )
		temp = 1;
	for( int j = 0; j < strlen(signs); j++)
			if( a == signs[j] )
			{
				temp = 3;
				break;
			}
	if( isdigit(a) )
		temp = 2;
	return temp;
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
	char signs[] = "+*-/";
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка ab  
			if( isalpha(s[i]) ) 
					if ( isalpha(s[i + 1]) )
						return false;
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка +*  
		for( int j = 0; j < strlen(signs); j++)
			if( s[i] == signs[j] ) 
				for( int k = 0; k < strlen(signs); k++)
					if ( s[i + 1] == signs[k] )
						return false;
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка a+
			if( isalpha(s[i]) ) 
				for( int k = 0; k < strlen(signs); k++)
					if(( s[i + 1] == signs[k] ) && ( s[i + 2] == '\0'))
								return false; 
	for ( int i = 0; i < strlen(s) - 1 ; i++) // проверка 1+
			if( isdigit(s[i]) ) 
				for( int k = 0; k < strlen(signs); k++)
					if(( s[i + 1] == signs[k] ) && ( s[i + 2] == '\0'))
								return false; 
	return true;
}

int Prioritet ( char a)
{
	int temp = 0;
	if ((a == '+')||(a == '-'))
		temp = 1;
	if ((a == '*')||(a == '/'))
		temp = 2;
	return temp;
}


void Peverse_Polish_notation ( char *s, char *post)
{
	Stack<char> st(256);
	//post  постфиксная запись
	int j, k;
	k = 0;
	j = 0;
	char part[256];
	Partition(s, part, k);

	for( int i = 0; i < 256; i++)
	{
		if (( Type(part[i]) == 1 ) ||(Type(part[i]) == 2))
		{
			post[j] = part[i];
			j++;
		}
	
		if (( Type(part[i]) == 3 )&&(Prioritet(part[i]) != 0))
			//if((type[i] !='(') && (type[i] !=')'))
		{
			if ( st.IsEmpty() == true )
				st.Push( part[i]);
			else
			{
				char flag1 = st.Get();
				st.Push( flag1 );				
				while ((!st.IsEmpty() && (Prioritet(part[i]) <= Prioritet(flag1))))
				{
					post[j] = st.Get();
					j++;
					if (st.IsEmpty() == false)
					{
						flag1 = st.Get(); 
						st.Push( flag1 );
					}					
				}
				st.Push( part[i]);
			}	
		}
		if( part[i] == '(' )
			st.Push('(');
		if( part[i] == ')' )
		{
			char flag2 = st.Get();
			while ( flag2 != '(')
			{
				post[j] = flag2;
				j++;
				flag2 = st.Get();
			}
		}
	}
	if (!st.IsEmpty())
		while (!st.IsEmpty())
		{
			post[j] = st.Get();
			j++;
		}
		post[j] = '\0';
}

//void V(char *s/*, char *post*/)
//{
//	char post[256];
//	Peverse_Polish_notation( s, post);
//	int i = 0;
//	while (post[i] != '\0')
//	{
//
//	}
//}

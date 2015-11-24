#include <string.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include "stack.h"

void Partition (char *s, char **part, int *type )
{
	char signs[] = "()+*-/";
	//int type[256];
	//char part[256][5];
	int k1 = 0;
	int k2 = 0;
	int r, r1, r2;	
	for( int i = 0; i < strlen(s); i++)
	{
		if( isalpha(s[i]) )
		{	
			strncpy( part[k1], s + i, 1 );
			k1++;
			type[k2] = 1;
			k2++;
		}
		for( int j = 0; j < strlen(signs); j++)
			if( s[i] == signs[j] )
			{
				//part[k][0] = s[i];
				strncpy( part[k1], s + i, 1 );
				k1++;
				type[k2] = 3;
				k2++;
			}
		if( isdigit(s[i]) )
		{
			int pos = i + 1;
			while ( (pos < strlen(s)) && (isdigit(s[pos])) || (s[pos] == '.') )
				pos++;
			strncpy( part[k1], s + i, pos - i );
			i = pos - 1;
			type[k2] = 3;
			k2++;
		}
			//if ( isdigit(s[i + 1]))
			//{
			//	r1 = atoi(&s[i]);
			//	r2 = atoi(&s[i + 1]);
			//	/*part[k][0] =*/ itoa(r1, *part, 10);
			//	/*part[k][1] =*/ (char)r2;
			//	k++;	
			//}
			//else	
			//{
			//	part[k][0] = s[i];
			//	k++;
			//}
	}	
	//part[k][0] = '\0';
	//return **part;
}


//bool Check_the_brackets ( char *s) //+++
//{
//	bool temp;
//	Stack<int> st(strlen(s));
//	for ( int i = 0; i < strlen(s); i++)
//	{
//		if( s[i] == '(' )
//					st.Push('(');
//			if( s[i] == ')' )
//				if (st.Top > -1)
//					st.Get();
//				else 
//				{
//					temp = false;
//					return temp;
//				}
//	}
//	temp = st.IsEmpty();
//	return temp;
//
//}

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

//int Type( char *s) //----
//{
//	char signs[] = "+*-/";
//	int type[256];
//	int i = 0;
//	char part[256][5];
//	/*part =*/ Partition(s, part);
//	while ( part[i][0] != '/0')
//	{
//		if( isalpha(s[i]) )
//		{
//			type[i] = 1;
//			i++;
//		} 
//		if( isdigit(s[i]) ) 
//		{
//			type[i] = 1;
//			i++;
//		}
//		for( int j = 0; j < strlen(signs); j++)
//			if( part[i][0] == signs[j] )
//			{
//				type[i] = 3;
//				i++;
//			}
//	}
//	return *type;
//
//}

int Prioritet ( char a)
{
	int prioritet[256];
	int i = 0;
	int type[256];
	int temp;
	//char part[256][5];
	//вызвать функцию разбиения и типа
	//Partition(s, part);
	/*while ( part[i][0] != '/0')
	{
		if ( type[i] == 3)
		{
			if(( part[i][0] == '+' ) || ( part[i][0] == '-' ))
			{
				prioritet[i] = 1;
			}
			if(( part[i][0] == '*' ) || ( part[i][0] == '/' ))
			{
				prioritet[i] = 2;
			}
		}
		i++;
	}*/
	if ((a == '+')||(a == '-'))
		temp = 1;
	if ((a == '*')||(a == '/'))
		temp = 2;
	return temp;
}


char Peverse_Polish_notation ( char *s)
{
	char flag1, flag2;
	Stack<char> st(256);
	char post[256]; // постфиксная запись
	int j, ind;
	j = 0;
	char part[256][5];
	int type[256];
	int prioritet[256];
	Partition(s, part, type);
	Prioritet (part);
	//вызвать фуекцию Разбиение
	//вызвать функцию Тип
	for( int i = 0; i < strlen(part); i++)
	{
		if (( type[i] == 1 ) ||(type[i] == 2))
		{
			post[j] = part[i];
			j++;
		}
	
		if ( type[i] == 3 )
		{
			if ( st.IsEmpty() == true )
				st.Push( part[i] );
			else
			{
				flag1 = st.Get();
				st.Push( flag1 );

				// 3 стр не нужны. Заменить на функцию, кот. по символу '+', '-' и т.д. возвращает его приоритет
				// либо класть в стек позицию, а не символ
				for (int w = 0; w < i; w++)
					if (flag1 == part[w])
						ind = w;
				while (prioritet[i] <= prioritet[ind] ) // !st.IsEmpty() && (prioritet[i] <= prioritet[ind] )  
					// извлечение из стека flag1 внутрь цикла
				{
					post[n] = st.Get();
					n++;
					if (st.IsEmpty() == false)
					{
						flag1 = st.Get(); 
						st.Push( flag1 );
						for (int w = 0; w < i; w++)
							if (flag1 == post[w])
								ind = w;
					}
					else 
						prioritet[ind] = prioritet[ind] - 4;
					
				}
				st.Push( post [i]);
			}
				
				
		}
	
		if( part[i] == '(' )
			st.Push('(');
		if( part[i] == ')' )
		{
			flag2 = st.Get();
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
return *post;
}
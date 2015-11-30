#include "arithmetic.h"
#include <string.h>
#include <memory.h>
#include <cstring>
#include <iostream>

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
	if (( s[0] == '*') || ( s[0] == '+') || ( s[0] == '/') )// проверка: знаки *, +, / в начале строки 
		return false;
	return true;
}

int Type( char a)
{
	char signs[] = "()+*-/";
	int temp = 0;
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

int Priority ( char a)
{
	setlocale(LC_ALL, "Russian");
	int temp = 0;
	if ((a == '+')||(a == '-'))
		temp = 1;
	if ((a == '*')||(a == '/'))
		temp = 2;
	return temp;
}

bool Are_used_variables (char *s)
{
	bool temp = false;
	for ( int i = 0; i < strlen(s); i++)
		if( isalpha(s[i]) )
		{
			temp = true;
			break;
		}
		return temp;
}

void Assigment_of_lines ( char *s, char* s1)
{
	int i = 0;
	//strcpy(s1, s); - это эквивалент того, что ниже
	while ( s[i] != '\0')
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
}

void Assigning_values_to_variables (char* s)
{
	for ( int i = 0; i < strlen(s); i++)
	{
		if( isalpha(s[i]) )
		{
			char c;
			cout << "¬ведите значение переменной " << s[i] 
			<< endl;
			cout  << "ќбращаю внимание на то, что переменной может присваиватьс€ только цифра от 0 до 10";//!!!!!
			cout << endl;
			cin >> c;
			s[i] = c;
			cout << endl;
		}
	}
}

void ToPostfix(char *s, char**& post)
{
	Stack<char> st(50);
	int j, ind, k;
	j = 0;
	double result;

	post = new char* [strlen(s)];
	for (int i = 0; i < strlen(s); i++)
		post[i] = new char [15];

	for( int i = 0; i < strlen(s); i++)
	{
		if(Type(s[i]) == 2)
		{
			if (( s[i+1] != '\0' ) && (( s[i+1] == ',' ) || ( Type(s[i+1]) == 2 )) )
			{
				int pos = i + 1;
				while (( pos < strlen(s)) && ((isdigit( s[pos] ))) || ( s[pos] == ',' ))
					pos++;
				strncpy (post[j], s + i, pos - i);
				post[j][pos - i] = '\0';
				i = pos - 1;
				j++;
			}
			else
			{
				post[j][0] = s[i];
				post[j][1] = '\0';
				j++;
			}
		}
		if (( Type(s[i]) == 3 )&&(Priority(s[i]) != 0))
		{
			if ( st.IsEmpty() == true )
				st.Push( s[i] );
			else
			{
				char flag1 = st.Get();
				st.Push( flag1 );				
				while ((!st.IsEmpty() && (Priority(s[i]) <= Priority(flag1))))
				{
					post[j][0] = st.Get();
					post[j][1] = '\0';
					j++;
					if (st.IsEmpty() == false)
					{
						flag1 = st.Get(); 
						st.Push( flag1 );
					}					
				}
				st.Push( s[i]);
			}	
		}
		if( s[i] == '(' )
			st.Push('(');
		if( s[i] == ')' )
		{
			char flag2 = st.Get();
			while ( flag2 != '(')
			{
				post[j][0] = flag2;
				post[j][1] = '\0';
				j++;
				flag2 = st.Get();
			}
		}
	}
	if (!st.IsEmpty())
		while (!st.IsEmpty())
		{
			char flag3;
			post[j][0] = st.Get();
			post[j][1] = '\0';
			j++;
		}
		post[j][0] = '\0';

}

double Calc(char** post)
{
	double result;
	Stack<double> stack_for_computing(50);
	int l = 0;
	while ( post[l][0] != '\0')
	{	
		if ( Type(post[l][0]) == 2 ) 
			if (( post[l][1] != '\0' ) && (( post[l][1] == ',' ) || ( Type(post[l][1]) == 2 )) )
			{
				int s = 0;
				while ( post[l][s] != '\0')
				{
					if (post[l][s] != ',')
						s++;
					else 
					{
						double x = atof (post[l]);
						stack_for_computing.Push( x );
						break;
					}
				}
				if ( s == strlen(post[l]))
				{
					int r = 0;
					while ( post[l][r] != '\0')
						r++;
					post[l][r+1] = ',';
					post[l][r+2] = '0';
					post[l][r+3] = '\0';
					int x = atof (post[l]);
					stack_for_computing.Push( x );
				}
			}
			else
			{
				post[l][1] = ',';
				post[l][2] = '0';
				post[l][3] = '\0';
				int x = atof (post[l]);
				stack_for_computing.Push( x );
			}
			if ( Type(post[l][0]) == 3 )
			{
				double temp2 = stack_for_computing.Get();
				double temp1 = stack_for_computing.Get();
				double res;
				switch ( post[l][0] )
				{
				case '+' : res = temp1 + temp2; break;
				case '-' : res = temp1 - temp2; break;
				case '*' : res = temp1 * temp2; break;
				case '/' : res = temp1 / temp2; break;
				}
				stack_for_computing.Push( res );
			}
			l++;
	}
	result = stack_for_computing.Get();
	return result;
}

void Free(char**& post, int n)
{
	for (int i = 0; i < n; i++)
		delete[] post[i];
	delete [] post;
}


double Calculation (char *s)
{
	Stack<char> st(50);
	int j, ind, k;
	j = 0;
	char** post;
	double result;

	post = new char* [strlen(s)];
	for (int i = 0; i < strlen(s); i++)
		post[i] = new char [15];
	ToPostfix(s, post);

	for( int i = 0; i < strlen(s); i++)
	{
		if(Type(s[i]) == 2)
		{
			if (( s[i+1] != '\0' ) && (( s[i+1] == ',' ) || ( Type(s[i+1]) == 2 )) )
			{
				int pos = i + 1;
				while (( pos < strlen(s)) && ((isdigit( s[pos] ))) || ( s[pos] == ',' ))
					pos++;
				strncpy (post[j], s + i, pos - i);
				post[j][pos - i] = '\0';
				i = pos - 1;
				j++;
			}
			else
			{
				post[j][0] = s[i];
				post[j][1] = '\0';
				j++;
			}
		}
		if (( Type(s[i]) == 3 )&&(Priority(s[i]) != 0))
		{
			if ( st.IsEmpty() == true )
				st.Push( s[i] );
			else
			{
				char flag1 = st.Get();
				st.Push( flag1 );				
				while ((!st.IsEmpty() && (Priority(s[i]) <= Priority(flag1))))
				{
					post[j][0] = st.Get();
					post[j][1] = '\0';
					j++;
					if (st.IsEmpty() == false)
					{
						flag1 = st.Get(); 
						st.Push( flag1 );
					}					
				}
				st.Push( s[i]);
			}	
		}
		if( s[i] == '(' )
			st.Push('(');
		if( s[i] == ')' )
		{
			char flag2 = st.Get();
			while ( flag2 != '(')
			{
				post[j][0] = flag2;
				post[j][1] = '\0';
				j++;
				flag2 = st.Get();
			}
		}
	}
	if (!st.IsEmpty())
		while (!st.IsEmpty())
		{
			char flag3;
			post[j][0] = st.Get();
			post[j][1] = '\0';
			j++;
		}
		post[j][0] = '\0';

		Stack<double> stack_for_computing(50);
		int l = 0;
		while ( post[l][0] != '\0')
		{	
			if ( Type(post[l][0]) == 2 ) 
				if (( post[l][1] != '\0' ) && (( post[l][1] == ',' ) || ( Type(post[l][1]) == 2 )) )
				{
					int s = 0;
					while ( post[l][s] != '\0')
					{
						if (post[l][s] != ',')
							s++;
						else 
						{
							double x = atof (post[l]);
							stack_for_computing.Push( x );
							break;
						}
					}
					if ( s == strlen(post[l]))
					{
						int r = 0;
						while ( post[l][r] != '\0')
							r++;
						post[l][r+1] = ',';
						post[l][r+2] = '0';
						post[l][r+3] = '\0';
						int x = atof (post[l]);
						stack_for_computing.Push( x );
					}
				}
				else
				{
					post[l][1] = ',';
					post[l][2] = '0';
					post[l][3] = '\0';
					int x = atof (post[l]);
					stack_for_computing.Push( x );
				}
				if ( Type(post[l][0]) == 3 )
				{
					double temp2 = stack_for_computing.Get();
					double temp1 = stack_for_computing.Get();
					double res;
					switch ( post[l][0] )
					{
					case '+' : res = temp1 + temp2; break;
					case '-' : res = temp1 - temp2; break;
					case '*' : res = temp1 * temp2; break;
					case '/' : res = temp1 / temp2; break;
					}
					stack_for_computing.Push( res );
				}
				l++;
		}
		result = stack_for_computing.Get();
		return result;
}

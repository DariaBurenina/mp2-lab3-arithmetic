#include <gtest.h>
#include "arithmetic.h"


TEST(Arithmetic, can_do_partition)
{
	char variables[] = "qwertyuiopasdfghjklzxcvbnm";
	char signs[] = "()+*-/";
	char temp[] = "a+b*c-7+t";
	char type1[256];
	char type2[256];
	int k1 = 0;
	int k2 = 0;
	for( int i = 0; i < strlen(temp); i++)
		for( int j = 0; j < strlen(variables); j++)
			if( temp[i] == variables[j] )
			{
				type1[k1] = temp[i];
				k1++;
			}
	for( int i = 0; i < strlen(temp); i++)
		for( int j = 0; j < strlen(signs); j++)
		{
			if( temp[i] == signs[j] )
			{
				type2[k2] = temp[i];
				k2++;
			}
		}
	ASSERT_NO_THROW(Partition (temp));
	EXPECT_EQ(type1[0], 'a');
	EXPECT_EQ(type1[1], 'b');
	EXPECT_EQ(type1[2], 'c');
	EXPECT_EQ(type1[3], 't');
	EXPECT_EQ(type2[0], '+');
	EXPECT_EQ(type2[1], '*');
	EXPECT_EQ(type2[2], '-');
	EXPECT_EQ(type2[3], '+');
}


TEST(Arithmetic, can_check_the_brackets)
{
	char temp1[] = "(5+4)*9";
	char temp2[] = "(5+4)*9)";
	char temp3[] = "(5+4)*9(";
	char temp4[] = ")(5+4)*9(";
	ASSERT_NO_THROW( Check_the_brackets(temp1) );
	EXPECT_EQ(true, Check_the_brackets(temp1));
	EXPECT_EQ(false, Check_the_brackets(temp2));
	EXPECT_EQ(false, Check_the_brackets(temp3));
	EXPECT_EQ(false, Check_the_brackets(temp4));
}


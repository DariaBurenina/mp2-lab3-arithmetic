#include <gtest.h>
#include "arithmetic.h"


TEST(Arithmetic, can_do_partition_)
{
	char temp[] = "a+b*c-7+t";
	ASSERT_NO_THROW(Partition (temp));
}


TEST(Arithmetic, can_check_the_brackets)
{
	char temp1[] = "(5+4)*9";
	ASSERT_NO_THROW( Check_the_brackets(temp1) );
}

TEST(Arithmetic, return_true_if_brackets_are_entered_correctly)
{
	char temp1[] = "(5+4)*9";
	EXPECT_EQ(true, Check_the_brackets(temp1));
}

TEST(Arithmetic, return_false_if_brackets_are_entered_incorrectly_closing_brackets_are_more)
{
	char temp2[] = "(5+4)*9)";
	EXPECT_EQ(false, Check_the_brackets(temp2));
}

TEST(Arithmetic, return_false_if_brackets_are_entered_incorrectly_opening_brackets_are_more)
{
	char temp3[] = "(5+4)*9(";
	EXPECT_EQ(false, Check_the_brackets(temp3));
}

TEST(Arithmetic, return_false_if_brackets_are_entered_incorrectly_the_first_bracket_is_closing)
{

	char temp4[] = ")(5+4)*9(";
	EXPECT_EQ(false, Check_the_brackets(temp4));
}

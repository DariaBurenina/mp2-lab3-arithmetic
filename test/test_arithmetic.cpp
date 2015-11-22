#include <gtest.h>
#include "arithmetic.h"
#include <iosream.h>
#include <stdio.h>
#include <stdlib.h>



TEST(Arithmetic, can_do_partition)
{
	char temp[] = "a+b*c-7+t";
	ASSERT_NO_THROW(Partition (temp));
}


TEST(Arithmetic, can_check_the_brackets)
{
	char temp[] = "(5+4)*9";
	ASSERT_NO_THROW( Check_the_brackets(temp) );
}

TEST(Arithmetic, return_true_if_brackets_are_entered_correctly)
{
	char temp[] = "(5+4)*9";
	EXPECT_EQ(true, Check_the_brackets(temp));
}

TEST(Arithmetic, return_false_if_brackets_are_entered_incorrectly_closing_brackets_are_more)
{
	char temp[] = "(5+4)*9)";
	EXPECT_EQ(false, Check_the_brackets(temp));
}

TEST(Arithmetic, return_false_if_brackets_are_entered_incorrectly_opening_brackets_are_more)
{
	char temp[] = "(5+4)*9(";
	EXPECT_EQ(false, Check_the_brackets(temp));
}

TEST(Arithmetic, return_false_if_brackets_are_entered_incorrectly_the_first_bracket_is_closing)
{

	char temp[] = ")(5+4)*9(";
	EXPECT_EQ(false, Check_the_brackets(temp));
}

TEST(Arithmetic, can_check_of_operatoins_and_operands)
{
	char temp[] = "(5+4)*9";
	ASSERT_NO_THROW( Check_of_operatoins_and_operands(temp) );
}

TEST(Arithmetic, return_false_if_two_operands_in_a_row)
{
	char temp[] = "(5+4)*9*ab";
	EXPECT_EQ(false, Check_of_operatoins_and_operands(temp));
}

TEST(Arithmetic, return_false_if_two_signs_in_a_row)
{
	char temp[] = "(5+4)*9*a+*";
	EXPECT_EQ(false, Check_of_operatoins_and_operands(temp));
}

TEST(Arithmetic, return_false_if_at_the_end_of_expression_is_an_sign_after_operand)
{
	char temp[] = "(5+4)*9*a+";
	EXPECT_EQ(false, Check_of_operatoins_and_operands(temp));
}

TEST(Arithmetic, return_false_if_at_the_end_of_expression_is_an_sign_after_figure)
{
	char temp[] = "(5+4)*9*1+";
	EXPECT_EQ(false, Check_of_operatoins_and_operands(temp));
}

TEST(Arithmetic, can_check_of_operatoins_and_operandsdqf)
{
	char temp[] = "(5+4)*9*a+1";
	EXPECT_EQ(true, Check_of_operatoins_and_operands(temp));
}



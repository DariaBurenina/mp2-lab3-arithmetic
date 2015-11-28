#include <gtest.h>
#include "arithmetic.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

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

TEST(Arithmetic, return_true_if_expression_is_correct)
{
	char temp[] = "(5+4)*9*a+1";
	EXPECT_EQ(true, Check_of_operatoins_and_operands(temp));
}

TEST(Arithmetic, can_get_type)
{
	char temp[] = "9+8";
	ASSERT_NO_THROW( Type(temp[1]) );
}

TEST(Arithmetic, type_of_sign_is_three)
{
	EXPECT_EQ(3, Type('-'));
}

TEST(Arithmetic, type_of_figure_is_two)
{
	EXPECT_EQ(2, Type('6'));
}

TEST(Arithmetic, can_get_priority_of_operations)
{
	ASSERT_NO_THROW( Priority('/') );
}

TEST(Arithmetic, priority_of_operation_of_addition_is_one)
{
	EXPECT_EQ(1, Priority('+'));
}

TEST(Arithmetic, priority_of_operation_of_subtraction_is_one)
{
	EXPECT_EQ(1, Priority('-'));
}

TEST(Arithmetic, priority_of_operation_of_multiplication_is_two)
{
	EXPECT_EQ(2, Priority('*'));
}

TEST(Arithmetic, priority_of_operation_of_compartition_is_two)
{
	EXPECT_EQ(2, Priority('/'));
}

TEST(Arithmetic, can_check_were_used_variables)
{
	char temp[] = "(5+4)*9*a";
	ASSERT_NO_THROW( Are_used_variables(temp) );
}

TEST(Arithmetic, return_true_if_variables_were_used)
{
	char temp[] = "(5+4)*9*a";
	EXPECT_EQ(true, Are_used_variables(temp));
}

TEST(Arithmetic, return_false_if_variables_were_not_used)
{
	char temp[] = "(5+4)*9";
	EXPECT_EQ(false, Are_used_variables(temp));
}


TEST(Arithmetic, can_assigment_of_lines)
{
	char temp[] = "(5+4)*9*a";
	char temp2[20];
	ASSERT_NO_THROW( Assigment_of_lines(temp, temp2));
}

TEST(Arithmetic, after_assigment_lines_are_equal)
{
	char temp[] = "(5+4)";
	char temp2[20];
	Assigment_of_lines(temp, temp2);
	EXPECT_EQ(temp[0], temp2[0]);
	EXPECT_EQ(temp[1], temp2[1]);
	EXPECT_EQ(temp[2], temp2[2]);
	EXPECT_EQ(temp[3], temp2[3]);
	EXPECT_EQ(temp[4], temp2[4]);
	EXPECT_EQ(temp[5], temp2[5]);
}

TEST(Arithmetic, can_evaluate_the_expression)
{
	char temp[] = "(5+4)*9";
	ASSERT_NO_THROW( Calculation(temp));
}

TEST(Arithmetic, can_evaluate_the_expression_with_two_digit_numbers)
{
	char temp[] = "(57+4)*89";
	double result;
	result = Calculation(temp);
	EXPECT_EQ(result, 5429);
}

TEST(Arithmetic, can_evaluate_the_expression_with_rational_numbers)
{
	char temp[] = "7,5+7,5";
	double result;
	result = Calculation(temp);
	EXPECT_EQ(result, 15);
}
//#include "stack.h"
//#include <gtest.h>
//
//
//
//TEST(Stack, can_create_stack_with_positive_size)
//{
//  ASSERT_NO_THROW(Stack<int> a(3));
//}
//
//
//TEST(Stack, throws_when_create_stack_with_negative_size)
//{
//  ASSERT_ANY_THROW(Stack<int> a(-3));
//}
//
//
//TEST(Stack, new_stack_is_empty)
//{
//  Stack<int> a(100);
//  EXPECT_EQ(true, a.IsEmpty());
//}
//
//TEST(Stack, can_get_index_of_first_element)
//{
//  Stack<int> a(100);
//  a.Top = 6;
//  EXPECT_EQ(6, a.Top);
//}
//
//TEST(Stack, can_get_size_of_stack)
//{
//  Stack<int> a(100);
//  EXPECT_EQ(100, a.N);
//}
//
//TEST(Stack, can_push_element)
//{
//	Stack<int> a(9);
//	ASSERT_NO_THROW( a.Push(3));
//}
//
//
//TEST(Stack, can_copy)
//{
//	const int k = 4;
//	Stack<int> a(k);
//	for (int i = 0; i < k; i++)
//		a.Push(i);
//	ASSERT_NO_THROW ( Stack<int> b(a) );
//
//}
//
//TEST(Stack, can_get_element)
//{
//	Stack<int> a(9);
//	for (int i = 0; i < 9; i++)
//		a.Push(i);
//	ASSERT_NO_THROW ( a.Get() );
//}
//
//TEST(Stack, if_get_element_it_will_be_delete)
//{
//	Stack<int> a(9);
//	for (int i = 0; i < 9; i++)
//		a.Push(i);
//	 EXPECT_EQ( a.Get(), 8 );
//	 EXPECT_EQ( a.Get(), 7 );
//}
//
//TEST(Stack, element_is_removed_when_getting_it)
//{
//	int temp1, temp2;
//	Stack<int> a(9);
//	for (int i = 0; i < 9; i++)
//		a.Push(i);
//	temp1 = a.Top;
//	a.Get();
//	temp2 = a.Top;
//	EXPECT_EQ( temp1, temp2 + 1);
//}
//
//TEST(Stack, index_of_first_element_is_increased_when_push_the_element )
//{
//	int temp1, temp2;
//	Stack<int> a(9);
//	for (int i = 0; i < 6; i++)
//		a.Push(i);
//	temp1 = a.Top;
//	a.Push(4);
//	temp2 = a.Top;
//	EXPECT_EQ( temp1 + 1, temp2);
//}
//
//
//TEST(Stack, return_true_when_stack_is_full)
//{
//	Stack<int> a(10);
//	for (int i = 0; i < a.N; i++)
//		a.Push(i);
//	EXPECT_EQ(true, a.IsFull());
//}
//
//TEST(Stack, when_copy_two_stacks_length_and_index_of_first_element_of_stacks_are_equal)
//{
//	const int k = 4;
//	Stack<int> a(k);
//	for (int i = 0; i < k; i++)
//		a.Push(i);
//	Stack<int> b(a);
//	EXPECT_EQ(a.Top, b.Top);
//	EXPECT_EQ(a.N, b.N);
//}
//
//
//

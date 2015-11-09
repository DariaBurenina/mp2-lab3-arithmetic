#ifndef __STACK_H___
#define __STACK_H___

#include <iostream>
#include <memory>
using namespace std;


class Stack 
{
	public:
		int *st;
		int N;  //  ������ ��������� ����
		int Top;  //  ������ ������� ��������

		
		Stack(int Max);
		Stack(const Stack &s);
		void Push(int x);  // �������� �������
		int Get();  //  ��������� ������� � ���������
		bool IsEmpty();  //  �������� �������
		bool IsFull();  //  �������� �������
		~Stack();  //  ����������
		friend ostream& operator<<(ostream &os, const Stack &s);
};		
#endif

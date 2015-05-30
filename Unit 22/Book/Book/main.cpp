#include <iostream>
#include <string>
#include <assert.h>
#include "book.h"

using namespace std;

void test_book_class();

int main()
{
	test_book_class();
	system("pause");
	return 0;
}

void test_book_class()
{
	Book book = Book("Malcolm Gladwell", "The Tipping Point", 256);
	book.SetRefNumber("4239JBF23S");
	book.PrintDetails();

}
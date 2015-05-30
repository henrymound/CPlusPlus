#include <iostream>
#include <algorithm>
#include <sstream>
#include "book.h"

Book::Book(string book_author, string book_title, int pages) :
m_Author(book_author), m_Title(book_title), m_Pages(pages){
	m_RefNumber = "";
}
Book::~Book(void){
}

//Accessor Methods
string Book::GetAuthor(){
	return m_Author;
}
string Book::GetTitle(){
	return m_Title;
}
string Book::GetRefNumber(){
	return m_RefNumber;
}
int Book::GetPageCount(){
	return m_Pages;
}

//Void Methods
void Book::PrintAuthor(){
	cout << GetAuthor();
}
void Book::PrintTitle(){
	cout << GetTitle();
}
void Book::PrintDetails(){
	cout << "Title:            " << GetTitle() << "\n";
	cout << "Author:           " << GetAuthor() << "\n";
	cout << "Pages:            " << GetPageCount() << "\n";
	if (GetRefNumber().size() > 0)
		cout << "Reference Number: " << GetRefNumber() << "\n";
	else
		cout << "Reference Number: ZZZ\n";
}

//Mutator Methods
void Book::SetRefNumber(string refNumber){
	m_RefNumber = refNumber;
}



#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;
/** @brief A class that maintains information on a book.

	This might form part of a larger application such
	as a library system, for instance.
	@author (Insert your name here.)
	@date (Insert today's date here.)
	*/

class Book
{
public:
    /** Book constructor. Initializes author and title.
        */
	Book(string book_author, string book_title, int pages);
    /** Default destructor.
        */
	~Book(void);

	//Accessor Methods
	string GetAuthor();
	string GetTitle();
	string GetRefNumber();
	int GetPageCount();

	//Void Methods
	void PrintAuthor();
	void PrintTitle();
	void PrintDetails();

	//Mutator Methods
	void SetRefNumber(string refNumber);

private:
	string m_Author; /**<book's author*/
	string m_Title;  /**<book's title*/
	string m_RefNumber; /**book's reference number*/
	int m_Pages; /**book's page count*/
};
#endif


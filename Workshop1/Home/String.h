/*= ================================================================ =
	Name: Olena Onopriyenko
	File : String.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/13/2019
	Workshop: Workshop1 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/

#ifndef SDDS_STRING_H
#define SDDS_STRING_H
#include <iostream>
#include<cstring>

namespace sdds {
	// declaration of global veriable that can be avaliable for all translation units
	extern unsigned int g_maxSize;

	class String {
		char *Cstring;// C-style null terminated string of any length
	public:
		String(const char*);
		void display(std::ostream&);
	};
	std::ostream& operator << (std::ostream& os, String&);
}

#endif // !SDDS_STRING_H


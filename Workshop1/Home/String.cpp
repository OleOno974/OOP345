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
#define _CRT_SECURE_NO_WARNINGS

#include "String.h"

namespace sdds {

	unsigned int g_maxSize = 3u;

	String::String(const char *cstr) //recieves an unmodifiable reference to a c-style string 
	{
		if (cstr != nullptr) //checking existance of cstr 
		{
			Cstring = new char[g_maxSize];
			//copying characters from cstr to str 
			strncpy(Cstring, cstr, (g_maxSize));
			Cstring[g_maxSize] = 0;
		}
		else if (cstr[0] == '\0') //if the cstr string is empty 
		{
			Cstring = nullptr;
		}
			
		
    }
	// receive object and inserts the string stored in the instance variable.
	void String::display(std::ostream& os) {

		os << Cstring;
	};

	//inserts the saved string into the left operand
	std::ostream& operator << (std::ostream& os, String & cstr) {

		static int count = 1;
		os << count << ": ";
		count++;//operator counts how many times it has been called 

		cstr.display(os);

		return os;

	};


}

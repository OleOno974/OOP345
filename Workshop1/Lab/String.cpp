/*= ================================================================ =
	Name: Olena Onopriyenko
	File : String.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/13/2019
	Workshop: Workshop1 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/

#include "String.h"


namespace sdds {

	 unsigned int g_maxSize = 3u;
	
	//receives the address of the C-style string and copies the string at that address into an instance variable.
	String::String(const char* cstr) {

		if (cstr == nullptr) 
			Cstring[0] = '\0';
		else
			strncpy_s(Cstring, cstr, g_maxSize);
		Cstring[3] = '\0';
	};
	// receive object and inserts the string stored in the instance variable.
	void String::display(std::ostream& os)  {

		os << Cstring;
	};
	//inserts the saved string into the left operand
	std::ostream& operator << (std::ostream& os,  String & cstr) {

		static int count = 1;
		os << count << ": ";
		count++;//operator counts how many times it has been called 

		cstr.display(os);

		return os;

	};

}

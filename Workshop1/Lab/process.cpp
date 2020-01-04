/*= ================================================================ =
	Name: Olena Onopriyenko
	File : process.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/13/2019
	Workshop: Workshop1 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/
#include <iostream>
#include "String.h"

namespace sdds
{
	void process(const char* str)
	{
		String a = String(str);
		std::cout << a << std::endl;
	}
}

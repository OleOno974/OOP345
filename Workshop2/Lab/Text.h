/*= ================================================================ =
	Name: Olena Onopriyenko
	File : Text.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/20/2019
	Workshop: Workshop2 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/
#ifndef TEXT_H
#define TEXT_H

#include<string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
namespace sdds {

	
		class Text {
			unsigned int lineNumber;
			string* lineContent;

		public:
			//default constructor: It set the safe statement 
			Text();
			//Constructor with a string parameter: 
			//the parameter is file name. it reads data from file and save every lines in the string.
			Text(char* fileName);
			//Copy Constructor: 
			//It copies a Text parameter to "this" Text object. 
			Text(const Text& text);
			Text& operator=(const Text& text);

			Text(const Text&& text);

			Text& operator = (Text&& text);
			//Destructor: 
			//Deallocate the lineCounten variable.
			~Text();
			//this function returns the number of line the object stores.
			size_t size() const;
		};
}
#endif//! TEXT_H

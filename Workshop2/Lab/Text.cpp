/*= ================================================================ =
	Name: Olena Onopriyenko
	File : Text.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/20/2019
	Workshop: Workshop2 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/
#define _CRT_SECURE_NO_WARNINGS

#include"Text.h"

namespace sdds
{
	//default constructor: It set the safe statement 
	Text::Text() : lineNumber(0), lineContent(nullptr)
	{}
	//Constructor with a string parameter: 
	//the parameter is file name. it reads data from file and save every lines in the strring. 
	Text::Text(char* fileName) 
	{
		fstream file(fileName, ios::in);
		if (file.is_open())
		{
			
			string line;
			while (getline(file, line, ' '))//read the file
			{

				lineNumber++;//count numdre of line
			}
			file.clear();
			file.seekp(0);
			lineContent = new string[lineNumber--];
			file.seekg(0, file.beg);
			for (size_t i = 0; i < lineNumber; i++)
			{
				getline(file, lineContent[i]);// reread and insert into array
				

			}
			file.close();
		}
		else {
			cerr << "Fail to open '" << fileName << "'\n";
			exit(1);
		}
	}
	//Copy Constructor: 
	//It copies a Text parameter to "this" Text object. 
	Text::Text(const Text& text)
	{
		*this = text;
	}
	//Copy Assingment: 
		//It copies a Text parameter to a Text object, and return the reference of it. 
	Text& Text::operator=(const Text& text)
	{
		if (this != &text)
		{
			delete[] lineContent;
			lineNumber = text.lineNumber;
			lineContent = new string[lineNumber];
			for (size_t i = 0; i < lineNumber; i++)
			lineContent[i] = text.lineContent[i];
		}
		return *this;
	}
	//Move Constructor, move the text parametr to this text object
		Text ::Text(const Text&& text) {

			lineContent = nullptr;
			*this = move(text);
		};

		Text& Text:: operator=(Text&& text)  {

			if (this != &text) {
				// Deallocate the memory for the current object
				delete[] lineContent;
				lineNumber = text.lineNumber;
				lineContent = text.lineContent;
				text.lineContent = nullptr;
				text.lineNumber = 0;
			}
			return *this;
		};

	//Destructor: 
		//Deallocate the lineContent variable. 
	Text::~Text()
	{
		delete[] lineContent;
	}
	//this function returns the number of line the object stores. 
	size_t Text::size() const
	{
		return lineNumber;
	}
}

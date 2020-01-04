/*= ================================================================ =
	Name: Olena Onopriyenko
	File : TimedEvents.cpp
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/20/2019
	Workshop: Workshop2 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/
#define _CRT_SECURE_NO_WARNINGS

#include "TimedEvents.h"
using namespace std;

namespace sdds {
	//constructor; called when Timekeeper object created
	TimedEvents::TimedEvents()
	{
		static int numberOfObjectsCreated = 0;
		numOfRecords = 0;
		record->messageString = nullptr;
		record->unitsOfTime = nullptr;
		numberOfObjectsCreated++;
	}

	//starts stopwatch
	void TimedEvents::startClock()
	{
		startTime = chrono::steady_clock::now();
	}

	//stops stopwatch
	void TimedEvents::stopClock()
	{
		endTime = chrono::steady_clock::now();
	}

	//sets values of execution times and number of records created
	void TimedEvents::recordEvent(const char* incomingStr)
	{
		static int counter = 0;
		const char* unitTime = "nanoseconds";
		record[counter].messageString = incomingStr;
		record[counter].unitsOfTime = unitTime;
		auto returnTime = record->durationTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
		record[counter].durationTime = ((endTime - startTime));
		counter++;
		numOfRecords++;
	}
	
	//prints execution times
	
	std::ostream & operator<<(std::ostream & out, TimedEvents & t)
	{
		cout << "--------------------------";
		out << "\nExecution Times:" << std::endl;
		cout << "--------------------------\n";
		for (int index = 0; index < t.numOfRecords; index++)
		{
		   cout.setf(ios::left); cout.width(20);cout<< t.record[index].messageString;
			cout << " ";
			cout.unsetf(ios::left);
			cout.width(12); cout.setf(ios::right);
			cout << t.record[index].durationTime.count() ; 
			cout << " ";
			cout.unsetf(ios::right);
			cout << t.record[index].unitsOfTime;
			cout << "\n";
			
		}
		cout << "--------------------------\n";
		return out;
	}
}

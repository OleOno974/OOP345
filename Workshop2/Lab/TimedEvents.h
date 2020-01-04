/*= ================================================================ =
	Name: Olena Onopriyenko
	File : TimedEvents.h
	Email : oonopriyenko@myseneca.ca
	Student Number : 124605163
	Course Code : OOP345
	Date : 9/20/2019
	Workshop: Workshop2 / Lab
	I confirm that the content of this file is created by me,
	with the exception of the parts provided to me by my professor.
	==================================================================*/

#ifndef TIMEDEVENT_H
#define TIMEDEVENT_H

#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds {


	const int maxNumOfRecords = 7;
	class TimedEvents
	{
		int numOfRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct
		{
			const char* messageString;
			const char* unitsOfTime;
			std::chrono::steady_clock::duration durationTime;
		} record[maxNumOfRecords];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* incomingStr);
		friend std::ostream& operator<<(std::ostream& out, TimedEvents& t);
			
		
	};
	

}


#endif // !TIMEDEVENT_H

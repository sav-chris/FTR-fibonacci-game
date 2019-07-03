#include "program.hpp"
#include <chrono>
#include <thread>
#include "console.hpp"
#include <iostream>

using namespace std::this_thread;
using namespace std::chrono;

void FTR::Program::printUpdate()
{
	while (this->state == FTR::State::run)
	{
		sleep_for(seconds(this->frequency));

		if (this->state == FTR::State::run)
		{
			FTR::Console::printDataTable(this->dataTable);
		}
	}
}

bool FTR::Program::IsSquare(int x)
{
	int s = static_cast<int>(sqrt(x));
	return (s*s == x);
}

int FTR::Program::getFrequency()
{
	return frequency;
}

FTR::State FTR::Program::getState()
{
	return state;
}

FTR::Program::Program(int frequency, int firstNumber) 
	: frequency(frequency), 
	state(FTR::State::pause)
{
	if (frequency <= 0)
	{
		throw std::exception("invalid frequency");
	}

	dataTable = 
	{
		{firstNumber, 1}
	};
}

void FTR::Program::run()
{
	//get choice 
	std::thread choiceThread([=]() { this->getChoice(); });

	//print info periodically
	std::thread updateThread([=]() { this->printUpdate(); });

    choiceThread.join();
	updateThread.join();
}

void FTR::Program::getChoice() 
{
	FTR::State state = FTR::Console::getStateChoice();
	this->state = state;
}

void FTR::Program::newEntry()
{
	int val = FTR::Console::requestValueWithMessage("Please enter the new number:");

	addValue(val);

	this->state = FTR::State::run;
}

void FTR::Program::addValue(int val)
{
	if (IsFibonacci(val) && val <= 1000)
	{
		FTR::Console::showMessage("FIB!");
	}

	if (this->dataTable.count(val))
	{
		std::map<int, int>::iterator it = this->dataTable.find(val);
		it->second = it->second + 1;
	}
	else
	{
		dataTable.insert(std::make_pair(val, 1));
	}
}

void FTR::Program::quit()
{
	FTR::Console::showMessage("See you next time!");
	exit(1);
}

void FTR::Program::runMain()
{
	this->state = FTR::State::run;

	while (true)
	{
		FTR::State state = this->getState();

		switch (state)
		{
		case FTR::State::newEntry:
			this->newEntry();
			break;
		case FTR::State::pause:
			this->pause();
			break;
		case FTR::State::run:
			this->run();
			break;
		case FTR::State::quit:
			this->quit();
			break;
		}
	}
}

// One could compute this with a recursive function but it is much simpler to just use 
// this interesting result https://www.fq.math.ca/Scanned/10-4/advanced10-4.pdf at the 
// end of page 417
bool FTR::Program::IsFibonacci(int x)
{
	return IsSquare(5 * x * x + 4) || IsSquare(5 * x * x - 4);
}

void FTR::Program::pause()
{
	this->state = FTR::Console::getStateChoice();
}




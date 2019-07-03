#include "console.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int FTR::Console::requestValueWithMessage(string message)
{
	int period = 0;
	while (!(period > 0))
	{
		std::cout << message << std::endl;

		std::string str;
		std::getline(std::cin, str);
		try
		{
			period = std::stoi(str);
		}
		catch (exception )
		{
			period = 0;
		}
	}

	return period;
}

int FTR::Console::requestOutputPeriod()
{
	return requestValueWithMessage("Please enter the output period:");
}

int FTR::Console::requestFirstNumber()
{
	return requestValueWithMessage("Please enter the first number:");
}

void FTR::Console::printDataTable(std::map<int, int> dataTable)
{
	using pair = std::pair<int, int>;
	std::vector<pair> vec;

	std::copy
	(
		dataTable.begin(),
		dataTable.end(),
		std::back_inserter<std::vector<pair>>(vec)
	);

	std::sort
	(
		vec.begin(),
		vec.end(),
		[](std::pair<int, int> a, std::pair<int, int> b)
	    {
		    bool res = a.second > b.second;

			if (a.second == b.second)
			{
				res = a.first < b.first;
			}
			return res;
	    }
	);

	std::string msg = "";
	for (auto const& x : vec)
	{
		msg = msg + std::to_string(x.first) + ":" + std::to_string(x.second) + ", " ;
	}

	msg.pop_back();
	msg.pop_back();
	std::cout << msg << std::endl;
}

FTR::State FTR::Console::getStateChoice()
{
	while(true)
	{
		std::string str;
		std::getline(std::cin, str);
		if (str == "N")
		{
			return FTR::State::newEntry;
		}
		if (str == "Q")
		{
			return FTR::State::quit;
		}
		if (str == "P")
		{
			return FTR::State::pause;
		}
		if (str == "R")
		{
			return FTR::State::run;
		}
	}
	
	throw std::exception("No state found");
}

void FTR::Console::showMessage(std::string msg)
{
	std::cout << msg << std::endl;
}



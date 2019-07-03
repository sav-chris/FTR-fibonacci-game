#pragma once
#include <string>
#include <map>
#include "program.hpp"


namespace FTR 
{
	namespace Console
	{
		int requestValueWithMessage(std::string message);
		int requestOutputPeriod();
		int requestFirstNumber();
		void printDataTable(std::map<int, int> dataTable);

		FTR::State getStateChoice();

		void showMessage(std::string msg);
	}
}
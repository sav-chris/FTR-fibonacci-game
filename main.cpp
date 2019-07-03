#include <string>
#include <iostream>
#include <thread>

#include "console.hpp"
#include "program.hpp"


using namespace std;

int main()
{
	int period = FTR::Console::requestOutputPeriod();
	int firstNo = FTR::Console::requestFirstNumber();

	if (FTR::Program::IsFibonacci(firstNo) && firstNo <= 1000)
	{
		FTR::Console::showMessage("FIB!");
	}

	FTR::Program program(period, firstNo);

	program.runMain();

}


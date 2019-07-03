#pragma once
#include <map>

namespace FTR
{
	enum State
	{
		run,
		quit,
		pause, 
		newEntry
	};

	class Program
	{
	private:
		int frequency;
		std::map<int, int> dataTable;
		FTR::State state;
		void printUpdate();
		static bool IsSquare(int x);
	public:
		int getFrequency();
		FTR::State getState();

		Program(int frequency, int firstNumber);

		void getChoice();
		void addValue(int val);

		void run();
		void newEntry();
		void quit();
		void pause();
		void runMain();

		static bool IsFibonacci(int x);
	};
}


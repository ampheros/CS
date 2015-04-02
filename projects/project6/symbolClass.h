#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "stringM.h"

using namespace std;

class symbol{
	public:
		symbol();
		~symbol();
		symbol(const symbol &);
		//functions for value
		void setValue(int);
		int getValue();
		
		//functions for bonus
		void setBonus(bool);
		bool getBonus();
		
		//functions for name
		void nameinit(int);
		void nameInput(char *a);
		char *getName();

		//print function
		void print();
	private:
		char *name;
		int value;
		bool bonus;
};

class reel{
	public:
		~reel(); //destructor
		reel(); //default constructor
		reel(const reel &); //copy contructor
		int getPay(); //return payline stop number
		void print(); //print all stop from reel
		void printStop(int); //print specific stop from reel
		void spin(); //output a random symbol from each of the reels and output the total value
		void setReel(symbol *s); //generate a random reel config
	private:
		symbol *strobe;
		int payline;
};

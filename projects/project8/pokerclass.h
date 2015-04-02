#include <string>
#include <iostream>
#include <fstream>
#include "stringM.h"
#include <ctime>
#include <cstdlib>

using namespace std;
class player;
class card{
	public:
		card();
		card(const card&);
		~card();
		card& operator=(const card&);
		bool operator <=(const card&);
		bool operator >=(const card&);
				
		friend bool operator > (card &c1, card &c2);
		friend bool operator < (card &c1, card &c2);
		friend ostream& operator<<(ostream&, card&);
		friend ifstream& operator>>(ifstream&, card&);
		friend class player;

		int getValue () const;
		char *getSuit() const;
		char *getRank() const;
		char *getLocation() const;
		void printCard();
		void suitInit(int );
		void rankInit(int );
		void locationInit(int);
		void suitInput(char *a);
		void rankInput(char *a);
		void locationInput(char *a);
		
				
	private:
		char *suit;
		char *rank;
		char *location;
		int value;

};

class player{
	public:
		player();
		~player();
		friend ostream& operator<<(ostream&, player&);
		friend ifstream& operator>>(ifstream&, player&);
		friend class card;
		char *getfName() const;
		char *getlName() const;
		float getBet() const;
//		ostream printHand();		
		card getHand(int) const;
		void fnameInput(char *a);
		void lnameInput(char *a);
		void print();
		
	private:
		char* fname;
		char* lname;
		card *hand;
		float bet;
};

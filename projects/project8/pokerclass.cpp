#include "pokerclass.h"

card::card(){
	suit = NULL;
	rank = NULL;
	location = NULL;
	value = 0;		
}

card::card(const card &c){
	int l = stringLength( c.suit);
	int lh = stringLength(c.rank);
	int ll = stringLength(c.location);
	suit = new char [l+1];
	rank = new char [lh +1];
	location = new char [ll + 1];
}

card::~card(){
	delete [] suit;
	delete [] rank;
	suit = NULL;
	rank = NULL;
	value = 0;
}

int card::getValue() const{
	return value;
}
char* card::getRank() const{
	return rank;
}

char* card::getSuit() const{
	return suit;
}

char *card::getLocation() const{
	return location;
}
card& card::operator=(const card &c){
	if(this != &c){
		suit = c.suit;
		rank = c.rank;
		location = c.location;
	}
	return *this;
}

bool card::operator<=(const card &c){
	bool stat;
	if(value <= c.value)
		stat = true;
	else
		stat = false;
	return stat;
}
bool card::operator>=(const card &c){
	bool stat;
	if(value >= c.value)
		stat = true;
	else
		stat = false;
	return stat;
}

bool operator>(const card &c1, const card &c2){
	if(c1.getValue() > c2.getValue())
		return true;
	else
		return false;

}
bool operator<(const card &c1, const card &c2){
	int bb = c1.getValue();
	int bv = c2.getValue();
	if(bb < bv )
		return true;
	else
		return false;

}

void card::printCard(){
	cout << suit << " " << rank << " " << location << " " << value;	
}

void card::suitInit(int l){
	suit = new char[l+1];
}
void card::rankInit(int l){
	rank= new char[l+1];
}
void card::locationInit(int l){
	location = new char[l+1];
}
void card::suitInput(char *a){
	stringCopy(suit, a);
}
void card::rankInput(char *a){
	stringCopy(rank, a);
}
void card::locationInput(char *a){
	stringCopy(location, a);
}
ostream& operator<<(ostream &output, const card &c){
	output << c.getSuit() << " " << c.getRank() << " "
		<< c.getLocation() << " " << c.getValue();
	return output;		
}

ifstream &operator>>(ifstream &input, card &c){
	char *a = new char [14];
	char *b = new char[14];
	input >> a >> b;
	int ls = stringLength( a );
	c.suitInit(ls);
	int lr = stringLength( b );
	c.rankInit(lr);
	c.suitInput(a);
	c.rankInput(b);
	char cl[20] = "unshuffled";
	c.locationInit(20);
	c.locationInput(cl);

	char two[] = "two";
	char three[] = "three";
	char four[] = "four";
	char five[] = "five";
	char six[] = "six";
	char seven[] = "seven";
	char eight[] = "eight";
	char nine[] = "nine";
	char ten[] = "ten";
	char jack[] = "jack";
	char queen[] = "queen";
	char king[] = "king";
	char ace[] = "ace";


	if(stringCompare(c.getRank(), two) == true)
		c.value = 2;
	if(stringCompare(c.getRank(), three) == true)
		c.value = 3;
	if(stringCompare(c.getRank(), four) == true)
		c.value = 4;
	if(stringCompare(c.getRank(), five) == true)
		c.value = 5;
	if(stringCompare(c.getRank(), six) == true)
		c.value = 6;
	if(stringCompare(c.getRank(), seven) == true)
		c.value = 7;
	if(stringCompare(c.getRank(), eight) == true)
		c.value = 8;
	if(stringCompare(c.getRank(), nine) == true)
		c.value = 9;
	if(stringCompare(c.getRank(), ten) == true)
		c.value = 10;
	if(stringCompare(c.getRank(), jack) == true)
		c.value = 11;
	if(stringCompare(c.getRank(), queen) == true)
		c.value = 12;
	if(stringCompare(c.getRank(), king) == true)
		c.value = 13;
	if(stringCompare(c.getRank(), ace) == true)
		c.value = 14;
}

player::player(){
	hand = new card[5];
	char first[] = "first";
	char last[] = "last";
	fnameInput(first);
	lnameInput(last);
	bet = 0;
}

player::~player(){
	delete [] hand;
	hand = NULL;
	delete [] fname;
	delete [] lname;
	bet = 0;
}

char* player::getfName() const{
	return fname;
}
char* player::getlName() const{
	return lname;
}

float player::getBet() const{
	return bet;
}
card player::getHand(int i) const{
	return hand[i];
}
void player::fnameInput(char *a){
	fname = new char[stringLength(a) +1];
	stringCopy(fname, a);
}

void player::lnameInput(char *a){
	lname = new char[ stringLength(a) +1];
	stringCopy(lname, a);
}
void player::print(){
	cout << fname << " " << lname << endl;
	cout << "Bet: " << bet << endl;
	if(hand[0].getValue() != 0){
		for(int i=0; i<5; i++){
			hand[i].printCard();
			cout << endl;
		}
	}
}
/*
ostream player::printHand(){
	ostream output;
	output << c.getfName() << " " << endl;
	for(int i=0; i<5; i++){
		output << hand[i].getSuit() << " " << hand[i].getRank() << " "
		<< hand[i].getLocation() << " " << hand[i].getValue() << endl;
	}
	output << c.getBet();
	return output
}
*/
ostream& operator<<(ostream &output, const player &c){
	output << c.getfName() << " " << c.getlName() << endl;
	for(int i=0; i<5; i++){
		output << c.getHand(i).getSuit() << " " << c.getHand(i).getRank() << " "
		<< c.getHand(i).getLocation() << " " << c.getHand(i).getValue() << endl;
	}
	output << c.getBet();
	return output;		
}

ifstream &operator>>(ifstream &input, player &p){
	char *a = new char[14];
	char *b = new char[14];
	input >> a >> b;
	p.fnameInput(a);
	p.lnameInput(b);
	return input;
}
	

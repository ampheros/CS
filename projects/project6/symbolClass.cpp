#include "symbolClass.h"

//constructor
symbol::symbol(){
	name = NULL;
	value = 0;
	bonus = false;
}

//copy constructor
symbol::symbol(const symbol &s){
	//allocate exact memory needed and copy the name over
	int l = stringLength( s.name ); 
	name = new char[l+1];
	stringCopy(name, s.name );
	
	//copy s values
	value = s.value;
	bonus = s.bonus; 
}

//destructor
symbol::~symbol(){
	delete [] name;
	name = NULL;
	value = 0;
	bonus = false;
}

//set the value
void symbol::setValue(int a){
	value = a;
}

//get the value
int symbol::getValue(){
	return value;
}

//set the bonus
void symbol::setBonus(bool a){
	bonus = a; 
}

//get the bonus
bool symbol::getBonus(){
	return bonus;
}

//allocate the memory for name by the amount "l"
void symbol::nameinit(int l){
	name = new char[l];
}

//copy a string to name
void symbol::nameInput(char *a){
	stringCopy(name, a);
}

//get the address of the first element in the name array
char* symbol::getName(){
	return name;
}

//print out the data for this element
void symbol::print(){
	cout << name << ", " << value << ", ";
	if(bonus == 0)
		cout << "false";
	else
		cout << "true";
}

//////***Reel Functions***///////

//destructor
reel::~reel(){
	delete [] strobe;
	strobe = NULL;
	payline = 0;
}

//default constructor
reel::reel(){
	payline = 0;
	strobe = new symbol[10];
}

//copy constructor
reel::reel(const reel &r){
	strobe = new symbol[10]; //allocate space for 10 stops
	symbol *sptr = r.strobe; //make a pointer to the symbol array within the reel

	//copy the date for the 10 stops
	for(int i=0; i<10; i++){
	strobe[i].setValue( sptr[i].getValue() ); //set the symbol value using the get value function
	strobe[i].setBonus( sptr[i].getBonus() ); //set the bonus value

	//allocate exact memory for name and copy
	strobe[i].nameinit( stringLength( sptr[i].getName() ) + 1); 
	strobe[i].nameInput( sptr[i].getName() );
	}
}

void reel::print(){
	//print out each stop in the reel
	for(int i=0; i < 10; i++){
		strobe[i].print();
		cout << endl;
	}		
	cout << endl;
}

void reel::spin(){
	int p = rand()%10; //generate a random stop number 
	payline = strobe[p].getValue(); //assign the payline to to that stop number

	//allocate the memory for the char to hold symbol name & copy it
	char *sname = new char[ stringLength( strobe[p].getName() ) + 1];	
	stringCopy(sname, strobe[p].getName() );
	cout << sname << ", "; //output only symbol name

	//deallocate temp char array	
	delete [] sname;
	sname = NULL;
}

void reel::setReel(symbol *s){
	int p; //int to hold random number
	for(int i =0; i<10; i++){
		p = rand()%6; //generate random num
	
		//input the randomly chosen symbol data into reel stop
		strobe[i].nameinit( stringLength(s[p].getName() )+1 );
		strobe[i].nameInput( s[p].getName() );
		strobe[i].setValue( s[p].getValue() );
		strobe[i].setBonus( s[p].getBonus() );
	}		
}

void reel::printStop(int y){
	//print chosen stop within reel
	strobe[y].print();
}

//return payline
int reel::getPay(){
	return payline;
}

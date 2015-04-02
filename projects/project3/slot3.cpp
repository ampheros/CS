#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct symbol{
	char name[10];
	int value;
	bool bonus;
};

struct reel {
	symbol s[10];
};

//sting copy function
void strcpy(char *a, char*b);
//string compare function
int strcomp(char *a, char *b);

//input symbols file into array function
void sInput(char *fptr, symbol *blur, char *a, int c); 

//generate a random configuration
void configGeneration(symbol *blur, reel *r);

//print the current configuration
void printConfig(reel *r);

//pick a stop and reel and output the data
void pick(reel *r);

int main(){
	//declare symbol struct and a pointer pointing to it
	symbol cat[6];
	symbol *blur = cat;
	
	//declare reel struct and pointer
	reel liq[3];
	reel *r = liq;

	//array and pointer to hold chosen filename
	char filename[20]; 
	char *fptr = filename;
	
	//arrays & pointers to hold data while it is stored into struct
	char a1[10];
	char *a = a1;
	char b1[10];
	char *b = b1;
	int c;  
	
	//used to hold chosen menu option
	int u;	
	
	srand(time(NULL));


	//start menu	
	do{
		cout << "Slot Machine Simulator" << endl;
		cout << ":::::::::::::::::::::::::::::::::::::::::" << endl;
		cout << " 1. Read in symbols file" << endl;
		cout << " 2. Generate Configuration" << endl;
		cout << " 3. Print config to screen" << endl;
		cout << " 4. Pick a Stop an Reel" << endl;
		cout << " 0. Exit" << endl;
		cout << ":::::::::::::::::::::::::::::::::::::::::" << endl;
		cout << "Enter your selection: ";
		cin >> u;
		cout << endl;
		
		switch(u){
			case 1:
				r = liq;
				blur = cat;
				sInput(fptr, blur, a, c);
				break;
			case 2:
				r = liq;
				blur = cat;
				configGeneration(blur, r);
				break;
			case 3:
				r = liq;
				blur = cat;
				printConfig(r);
				break;
			case 4:
				r= liq;
				blur = cat;
				pick(r);
				break;
		}
	}while (u !=0 );	
	
	cout << "Goodbye" << endl;
return 0;
}

void pick(reel *r){
	reel *r1 = r;
	//will translate user input to correct array element
	int reelS;
	int stop;

	int i =0;
	int j =0;
	
	//point to symbol struct within reel struct
	symbol *sPtr = (*r).s;
	
	//input chosen reel/stop 
	cout << "Pick a Reel (1-3): ";
	cin >> reelS;
	cout << "Pick a Stop (1-10): ";			
	cin >> stop;
	cout << endl;
	
	int reelz = reelS ;
	int stopz = stop ;
		
	//move pointer to specified location
	for(i=0; i< reelS; i++)
		r++;
	for(j=0; j< stop; j++)
		sPtr++;

	//output the chosen symbol with data
	cout << "Symbol: " << (*sPtr).name << endl;
	cout << "Value: " << (*sPtr).value << endl;
	if((*sPtr).bonus == 0)
		cout << "Bonus: False" << endl;
	else
		cout << "Bonus: True" << endl;
	cout << endl;
	
	//reset real back to base address
	r = r1;
	
}

void printConfig(reel *r){
	//point to symbol struct with reel
	symbol *sPtr = (*r).s;
	//make a copy of reel
	reel *originalR = r;
	
	char *namePtr = (*sPtr).name;
	
	//print out the symbols data for each reel
	for(int e = 0; e < 3; e++){
		cout << "Reel " << (e+1) << ":: " <<  endl;
		for(int i=0; i< 10; i++){
			cout << "Symbol: " << (*sPtr).name 
			<< " -- Value: " << (*sPtr).value << " --  "; 
		
			//check for bonus value true or false
			if((*sPtr).bonus == 0)
				cout << "Bonus: False" << endl;			
			else
				cout << "Bonus: True" << endl;
			sPtr++;
		}
		r++;
		cout << endl;
	}	
	r = originalR; //reset reel back to base address
	
}

void configGeneration(symbol *blur, reel *r){
	int p; //used to hold random number		
	int k=0; //while loop variable
	symbol *oBlur = blur; //copy of original symbol struct address
	symbol *sPtr = (*r).s; // point to symbol struct within reel
	char *namePtr = (*sPtr).name; // point to char array within symbol struct

	//loop through each reel
	for(int i=0; i< 4; i++){
		//loop through each stop and generate random number which will input the corresponding
		//symbol struct element into the designated reel array position
		for(int j =0; j< 10; j++){
			p = rand()%6;
			while(k<p){	
				blur++;
				k++;
			}				
			k =0;
			strcpy((*sPtr).name, (*blur).name);
			(*sPtr).value = (*blur).value;
			(*sPtr).bonus = (*blur).bonus;
			blur = oBlur; //reset symbol pointer so it can be used again in the next iteration
			sPtr++; // increase to the next stop #
		}
		sPtr = (*r).s; //reset stop back to original for the next reel
		r++;
	}
}

void sInput(char *fptr, symbol *blur, char *a, int c){ 
	symbol *oBlur = blur;
	
	//input filename and open that file
	cout << "Input filename: ";
	cin >> fptr;
	
	fstream afile;
	afile.open(fptr);

	//copy data from every line in file to a, c and then to symbol struct
	while(afile >> a >> c){
		strcpy( (*blur).name, a);	
		(*blur).value = c;
		if(c == 0)
			(*blur).bonus = false;
		else
			(*blur).bonus = true;
		blur++;
	} 
	blur = oBlur;	
	
}

void strcpy(char *a, char*b){
	char *a1 = a;
	char *b1 = b;
	while(*b != '\0'){
		*a = *b;
		a++;
		b++;
	} 
	*a = '\0';
	a = a1;
	b = b1;
}

int strcomp(char *a, char *b){
	while(*a == *b){
		if(*a == '\0' || *b == '\0')
			break;
		a++;
		b++;
	}
	
	if(*a == '\0' && *b == '\0')
		return 1;
	else
		return 0;
}	

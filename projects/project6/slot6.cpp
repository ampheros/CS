#include "symbolClass.h"

void sInput(symbol *masterReel); //input symbols from file
void configGenerate(symbol *masterReel, reel *trips); //generate random config
void printConfig(reel *trips); //output the config to screen
void chooseStopReel(reel *trips); //output chosen stop and reel data
void spin(reel *trips); //pick 3 random stops from each reel

int main(){
	symbol *masterReel = new symbol[6]; //array from symbol data
	reel *trips = new reel[3]; //array for reels
	int u; //menu selection int
	
	srand(time(NULL)); //seed random number generator
	
	do{
        	  cout << "Slot Machine Simulator" << endl;
                  cout << ":::::::::::::::::::::::::::::::::::::::::" << endl;
                  cout << " 1. Read in symbols file" << endl;
                  cout << " 2. Generate Configuration" << endl;
                  cout << " 3. Print config to screen" << endl;
                  cout << " 4. Pick a Stop an Reel" << endl;
		  cout << " 5. Spin the Reels" << endl;
                  cout << " 0. Exit" << endl;
                  cout << ":::::::::::::::::::::::::::::::::::::::::" << endl;
                  cout << "Enter your selection: ";
                  cin >> u;
                  cout << endl;
	
		switch(u){
			case 1:
				sInput(masterReel);
				break;
			case 2:
				configGenerate(masterReel, trips);
				break;
			case 3:
				printConfig(trips);
				break;
			case 4:
				chooseStopReel(trips);
				break;
			case 5:
				spin(trips);
				break;
		}	
	}while( u !=0 );
	
	delete [] masterReel; //deallocate the symbol data array
	delete [] trips; //deallocate the reel array

return 0;
}

void sInput(symbol *masterReel){
	int c; //temp int to hold int from symbol file
	char *a = new char[20]; //temp char array to hold filename and symbol name
	symbol *reelhome = masterReel; //homepointer for reel array
	char *ahome = a; //homepointer for temp char array

	cout << "Input Filename: ";
	cin >> a;
	
	fstream afile;
	afile.open(a);
	
	a = ahome;
        delete [] a;
        a = new char[10];	
	
	//read in each line from the file
	while(afile >> a >>c){
		int l = stringLength(a);
		(*masterReel).nameinit(l+1); //allocate the same amount of characters as "a" + null into the symbol array
                (*masterReel).nameInput(a); //copy a into symbol name array
                (*masterReel).setValue(c); //copy symbol file value to the array                

                if(c == 0) //check for bonus value
                        (*masterReel).setBonus(false);
                else        
                        (*masterReel).setBonus(true);
                            
                masterReel++; //increment to next symbol
        }           
            
        afile.close();
        masterReel = reelhome; //reset symbol array

	
	
	//deallocate the memory used for temp char array
        a = ahome;
        delete [] a;
        a = '\0';
}


void configGenerate(symbol *masterReel, reel *trips){
	//run the config generator from the reel class for each of the 3 reels
	for(int i = 0; i<3; i++){
		trips[i].setReel( masterReel ); 
	}	
}

void printConfig(reel *trips){
	//run the print function from the reel class 3 times
	for(int i =0; i<3; i++){
		cout << "######### Reel " << i+1
		<< " #########" << endl;

		trips[i].print();
	}
}
void chooseStopReel(reel *trips){
	//ints to hold user input
	int wStop;
	int wReel;

	cout << "Choose a stop (1-10): ";
	cin >> wStop;
	cout << "Chosse a reel (1-3): ";
	cin >> wReel;
	cout << endl;
	
	//offset by -1 to account for arrays starting at 0	
	//run the print stop function from the reel class
	trips[wReel-1].printStop(wStop -1);
	cout << endl << endl;
}

void spin(reel *trips){
	int totalPay = 0; //int to hold the sum of payline values
	
	//pick a random stop from each reel using the getPay function from the reel class
	for(int i =0; i<3; i++){
		trips[i].spin();
		totalPay += trips[i].getPay(); //add the current value to the total
	}
	//output the total value
	cout << endl << "Total: ";
	cout << totalPay << endl;
}



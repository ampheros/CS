#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct slotmachine{
	char symbol [10];
	int bvalue;
	bool bonus;	
};

//used to read in symbols file to array
void sInput(int &i, slotmachine ace[], char a[], int b);

//print the array that is holding the symbols file data
void printAce(slotmachine ace[]);

//generate a random config
void configGeneration(slotmachine ace[], slotmachine delica[10][3] );

//print the current slotmachine configuration
void printDelica(slotmachine delica[10][3]);

//output the current configuration to a user specified file
void delicaToFile(char fileName[20], slotmachine delica[10][3]);

//string comparison function
int strcomp(char a[], char b[]);

//read in a configuration from a specific file
void readInFile(char fileName[], slotmachine delica[10][3], slotmachine ace[], char a[], char x[], char h[]);

//output a single symbol and corresponding value chosen by user
void Draw(slotmachine ace[], slotmachine delica[10][3], int reel, int stop);

//spinning reels simulation
void rPull(slotmachine delica[10][3]);

int main(){
	int i =0;
	int b;
	int u;
	int reel;
	int stop;
	char a[10];
	char x[10];
	char h[10];
	char fileName[20];
	slotmachine ace[6];
	slotmachine delica[10][3];
	srand(time(NULL));

	sInput(i, ace, a, b);

//program menu uses #'s to select option
    do {
        cout << "  Slot Machine Simulator" << endl;
        cout << "  ============================ " << endl;
        cout << "  1.  Generate New Config"<< endl;
        cout << "  2.  Read in Existing Config"<< endl;
        cout << "  3.  Print Config to Screen" << endl;
        cout << "  4.  Print Config to File " << endl;
        cout << "  5.  Pick a Number " << endl;
	cout << "  6.  Spin " << endl;
        cout << "  0.  Exit " << endl;
        cout << "  Enter your selection: ";
        cin >> u;
        cout << "  ============================ " << endl;

        switch (u)
        {
            case 1:
             	configGeneration(ace, delica);
            	break;	
            
            case 2:
            	readInFile(fileName, delica, ace, a, x, h);	
            	break;	
            
            case 3: 
            	printDelica(delica);
            	break;

            case 4:
            	delicaToFile(fileName, delica);
            	break;
            
            case 5:
            	Draw(ace, delica, reel, stop);  
            	break;
	    case 6:
	        rPull(delica);
		break;
        }

    }while (u != 0 );

	cout << "GoodBye" << endl;
return 0;
}

void sInput(int &i, slotmachine ace[], char a[], int b){
	//open the symbols file
	fstream afile;
	afile.open("symbols");

	//read all lines of the file
	while(afile >> a >> b){
		//copy string from place holder to symbol array 
		for(int e= 0; e< 10; e++){
			ace[i].symbol[e] = a[e];
			ace[i].bvalue = b;  // assign correct bonus value

			if(ace[i].bvalue == 0)
				ace[i].bonus = false;  //check if bonus value = 0
		}

		i++;
	}
	afile.close();
}

//print symbols file array (used for testing)
void printAce(slotmachine ace[]){
	for(int i=0; i<6; i++){
		cout << ace[i].symbol << " " << ace[i].bvalue << endl;
	}

}

void configGeneration(slotmachine ace[], slotmachine delica[10][3]){
	int r;
	//loops through all elements of 2-d slotmachine array
	for(int i=0; i< 10; i++){
		for(int j=0; j<3; j++){
			r = rand()%6;  // pick a random #

			//copy string from random symbol element to the slotmachines symbol element
			for(int k =0; k< 10; k++){
				delica[i][j].symbol[k] = ace[r].symbol[k];
				delica[i][j].bvalue = ace[r].bvalue;  //assing correct bonus value
					if(delica[i][j].bvalue == 0)
						delica[i][j].bonus = false; //check for bonus value
			}	
		}
	}

	cout << "Config Generated" << endl << endl;
}

void printDelica(slotmachine delica[10][3]){
        cout << "Current Config: " << endl << endl;
	//loop to print current symbols in delica array
	for(int i=0; i<10; i++){
		cout << delica[i][0].symbol << " "
		<< delica[i][1].symbol << " " 
		<< delica[i][2].symbol << endl;
	}
        cout << endl;
}

void delicaToFile(char fileName[20], slotmachine delica[10][3]){
	//ask for filename
       	cout << "Enter Filename: ";
       	cin >> fileName;

	ofstream ofile;
	ofile.open(fileName);

	//output symbols to specified file		
	for(int i=0; i<10; i++){
		ofile << delica[i][0].symbol << " "
		<< delica[i][1].symbol << " " 
		<< delica[i][2].symbol << endl;
	}

	ofile.close();
}

void readInFile(char fileName[], slotmachine delica[10][3], slotmachine ace[], char a[], char x[], char h[]){
	int q =0;
	
	//ask user for filename
        cout << "Enter Filename: ";
        cin >> fileName;
	
	
	fstream afile;
	afile.open(fileName);
		//input characters on every line in file
		while(afile >> a >> x >> h){
			//copy string from placeholders to config array
			for(int e=0; e< 10; e++){
				delica[q][0].symbol[e] = a[e];
				delica[q][1].symbol[e] = x[e];
				delica[q][2].symbol[e] = h[e];
			}
			
			//assign the correct bonus value
			for(int l=0; l< 3; l++){
				for(int i=0; i< 6; i++){
					int f = strcomp(delica[q][l].symbol, ace[i].symbol);
					if(f == 1){
						delica[q][l].bvalue = ace[i].bvalue;
					}
				}
				//check for bonus value
				if(delica[q][l].bvalue == 0)
					delica[q][l].bonus = false;
			}	
			q++;
		}		
	afile.close();

	cout << "Config Generated" << endl << endl;
}

void Draw(slotmachine ace[], slotmachine delica[10][3], int reel, int stop){
	//ask user for real and stop # and input them into a variable
	cout << "Enter Reel # (1-3); ";
	cin >> reel;
	cout << "Enter Stop # (1-10): ";	
	cin >> stop;
	cout << endl;

	// translate user input to corresponding array element	
	int reelz = reel - 1;
	int stopz = stop -1;
	
	cout << "Symbol: " << delica[stopz][reelz].symbol << endl;
	cout << "Bonus Value : " << delica[stopz][reelz].bvalue << endl;
}

void rPull(slotmachine delica[10][3]){
	int tBonus=0; // total bonus value
	cout << ":::   ";

	//pick a random stop from each reel and print
	for(int i=0; i< 3; i++){
		int r = rand()%10; 
		cout << delica[r][i].symbol << " - ";
		tBonus += delica[r][i].bvalue; // add bonus values as they are chosen
	}	
	cout << "   :::";
	cout << endl << "Total Bonus: " << tBonus; // output total bonus value
	cout << endl << endl;
}

//compare string b to string a
int strcomp(char a[], char b[]){
     int c = 0;
 
   while( a[c] == b[c] )
   {
      if( a[c] == '\0' || b[c] == '\0' )
         break;
      c++;
   }
   if( a[c] == '\0' && b[c] == '\0' )
      return 1;
   else
      return 0;
}

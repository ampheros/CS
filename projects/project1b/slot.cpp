

        /***************************************************************/

        /* PROGRAM: Slot Machine Project 1b                                                                  */

        /*                                                                                       */

        /* AUTHOR: Eduardo Nava                                                                      */

        /*                                                                                       */

        /* DATE: 2/3/15                                                                    */

        /*                                                                                      */

        /* REVISIONS:                                                                   */

        /*                                                                                      */

        /* PURPOSE: slot machine simulation                                                                   */

        /*                                                                                      */



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//input symbols into array
void sInput(int &i, char symVal[][2][10], char a[], char b[]);

//generate random config
void configGeneration(char symVal[7][2][10], char ace[10][3][10], char a[10], char b[10], char c[10]);

// print config
void printAce(char ace[10][3][10]);

//read config from file
void Xinput(char ace[10][3][10], char trance[20], char a[], char b[], char c[]);

//output config to file
void AceToFile(char ace[10][3][10], char trance[20]);

//print symbol and bonus value
void Kash(char ace[][3][10], char symVal[][2][10], int reel, int stop);

//compare strings for equality
int strcomp(char a[], char b[]);

int main(){
    //char a,b,c will act as place holders for strings until they are copied to the "ace" array
	char a[10];
	char b[10];
	char c[10];

	char symVal[7][2][10]; //array to hold the symbols and bonus values
	char ace[10][3][10];  // array to hold the current symbol layout
	char trance [20]; // char used to hold filename from cin
	
    //varaibles for various loops
    int i = 0;
	int u;
	int q = 0;
    
    // will hold the reel and stop #'s chosen by user
	int reel;
	int stop;

	srand(time(NULL));

    //read in symbol array
	sInput(i, symVal, a, b);


	//print menu and listen for switch to execute menu option
	do {
        cout << "  Slot Machine Simulator" << endl;
        cout << "  ============================ " << endl;
        cout << "  1.  Generate New Config"<< endl;
        cout << "  2.  Read in Existing Config"<< endl;
        cout << "  3.  Print Config to Screen" << endl;
        cout << "  4.  Print Config to File " << endl;
        cout << "  5.  Pick a Number " << endl;
        cout << "  0.  Exit " << endl;
        cout << "  Enter your selection: ";
        cin >> u;
        cout << "  ============================ " << endl;

        switch (u)
        {
            case 1:
              configGeneration(symVal, ace, a, b, c);
				      cout << "Config Generated" << endl << endl;
            	break;	
            
            case 2:
            	cout << "Enter Filename: ";
            	cin >> trance;
            	Xinput(ace, trance, a, b, c);
            	cout << "Config Generated" << endl << endl;
            	break;	
            
            case 3: 
            	cout << "Current Config: " << endl;
            	printAce(ace);
            	cout << endl;
            	break;

            case 4:
            	cout << "Enter Filename: ";
            	cin >> trance;
            	AceToFile(ace, trance);
            	break;
            
            case 5:
            	cout << "Enter Reel # (0-2): ";
            	cin >> reel;
            	cout << "Enter Stop # (0-9): ";
            	cin >> stop;
              cout << "  ============================ " << endl;
              Kash(ace, symVal, reel, stop);
            	break;
        }

    }while (u != 0 );
	

	cout << "Goodbye" << endl;

return 0;
}

//function that will read in the symbols and bonus value into an array
void sInput(int &i, char symVal[][2][10], char a[], char b[]){
	fstream afile;
	afile.open("symbols");

	while(afile >> a >> b){
		for(int e=0; e < 10; e++){
			symVal[i][0][e] = a[e];
                        symVal[i][1][e] = b[e];
		}
		i++;
	}
	
    afile.close();
}

//generates a random config
void configGeneration(char symVal[7][2][10], char ace[10][3][10], char a[10], char b[10], char c[10]){
	int r;
	int q = 0;
	
	ofstream ofile;
	ofile.open("dconfig");

    //double loop to generate 3 symbols per line
    //every time the loop is a run a random number is generated and is used a pick out a random string from the symbol array
	for (int i = 0; i < 10; i++){
		for(int j = 0; j < 3; j++){
			r = rand()%6;
			ofile << symVal[r][0] << " " ; 

		}
		ofile << endl;
	}
	
    // write the config to the default "dconfig" file
	fstream afile;
				afile.open("dconfig");
        		while(afile >> a >> b >> c){
             		for(int e=0; e < 10; e++){
                    	ace[q][0][e] = a[e];
                    	ace[q][1][e] = b[e];
                    	ace[q][2][e] = c[e];
                  }
                  q++;
          }
          afile.close();
	
}

//prints out the current config
void printAce(char ace[10][3][10]){
	for(int k =0; k<=9; k++){
        cout << ace[k][0] << " " << ace[k][1] << " " << ace[k][2] << endl;
    }
}

//function that will open a config from a file and use it as the current config
void Xinput(char ace[10][3][10], char trance[20], char a[10], char b[10], char c[10]){
	int q = 0;
	fstream afile;
	afile.open(trance);
        //while there are lines in the file, read in the three strings to a,b,c
        while(afile >> a >> b >> c){
            for(int e=0; e < 10; e++){
               	ace[q][0][e] = a[e];
                ace[q][1][e] = b[e];
                ace[q][2][e] = c[e];
            }
                  q++;
        }
    afile.close();

}

//function to Save current config to a file chosen by user
void AceToFile(char ace[10][3][10], char trance[20]){
	ofstream ofile;
	ofile.open(trance);
		for(int k =0; k<=9; k++){
        	ofile << ace[k][0] << " " << ace[k][1] << " " << ace[k][2] << endl;
        
    	}	
	ofile.close();
}

//function to print out desired symbol and corresponding bonus value
void Kash(char ace[10][3][10], char symVal[7][2][10], int reel, int stop){
        
        //compare the chosen symbol with with every string from the the Symval array
        // and print if there is a match
		for(int i = 0; i < 6; i++){
            int f = strcomp(ace[stop][reel], symVal[i][0]);
			if(f == 1){
				cout << "Symbol: " << ace[stop][reel] << endl;
                cout << "Bonus Value: " << symVal[i][1] << endl << endl;
            }
		}
}


//String compare function
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
#include <iostream>
#include <fstream>

using namespace std;

//A function that will take in an array and print it out to a file using a predefined file name
void Xoutput(int &i, char ace[10][3][20], char trance[20]);

//This function will open the "symbols" and read in the elements into an array
void Xinput(int &i, char ace[10][3][20], char a[20], char b[20], char c[20] );

int main () {
//initialization of variables
	char ace[10][3][20];
	char trance[20];
	char a[20];
	char b[20];
	char c[20];
	int i = 0;
	int j = 0;
	int e = 0;

//read in file
	Xinput(i, ace, a, b, c);

//print out the contents of ace which contains the symbols
	for(int k =0; k<=9; k++){
		for(int y=0; y<= 2; y++){
				cout << ace[k][y] << endl;
		}
	}

//ask user for output file name and store it in "trance"
	cout << "Enter ouput filename: ";
	cin >> trance;	
	cout << trance << endl;

//print ace into the new file
	Xoutput(i, ace, trance);	
	return 0;
}

/* the function will take in the i by reference in order to have it keep increasing in value
	a,b,c will be used as placeholders to make sure the file reads in correctly
	the ace array is where the symbols will be stored*/
void Xinput(int &i, char ace[10][3][20], char a[20], char b[20], char c[20] ){
fstream afile;
	afile.open("symbols");
	
	//run while the file can still read a line, 
	while(afile >> a >> b >> c){
		for(int e = 0; e < 20; e++){
			ace[i][0][e] = a[e]; 
			ace[i][1][e] = b[e]; 
			ace[i][2][e] = c[e];
		}
		
		//copy the next line
		i++;
	}
	
	afile.close();
}


// take in i by reference, ace to print, and trance as the user definded ouput file
void Xoutput(int &i, char ace[10][3][20], char trance[20]){

	ofstream ofile;
	ofile.open( trance);

	//copy ace to the new file
	for(i=0; i<10; i++){
		ofile << ace[i][0] << " " << ace[i][1] << " " << ace[i][2] << endl;
	}	
	ofile.close();

}

#include "pokerclass.h"
void cInput(card*);
void pInput(player*, int);
void shuffleDeck(card*);
void deal(card*, player*);
void printShuffled(card*);
void printUnshuffled(card*);
void printRemaining(card*);
void printPlayerInfo(player*, int);


int main(){
	card *deck = new card[52];
	int numplayers = 3;
	player *pl = new player[numplayers];
	cInput(deck);
	printUnshuffled(deck);
	pInput(pl, numplayers);
	for (int i=0; i<3; i++){
		pl[i].print();
	}
}

void cInput(card* deck){
	char *a = new char[29];
	cout << "Input Filname: ";
	cin >> a;
	ifstream afile;
	afile.open(a);
	
		for(int i=0; i<52; i++){
			afile >> deck[i];
		}
	afile.close();
	
	
}
void pInput(player *pl, int numplayers){
	char *a = new char [15];
	cout << "Input filename: ";
	cin >> a;
	ifstream afile;
	afile.open(a);
		for(int i=0; i<numplayers; i++)
			afile >> pl[i];
	afile.close();
}
void shuffleDeck(card*){

}
void deal(card*, player*){

}
void printShuffled(card*){

}
void printUnshuffled(card* deck){
	for(int i=0; i< 52; i++){
		deck[i].printCard();
		cout << endl;
	}

}
void printRemaining(card*){

}
void printPlayerInfo(player* pl, int numplayers){
	for(int i=0; i<numplayers; i++){
		pl[i].print();
	}

}



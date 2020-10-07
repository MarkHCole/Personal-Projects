// Random Number Generation Program using a Dice based system
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int DiceRoller(string);
int Character(string);
int Rules(string);

int main() {

	string Func;
	int quit=0;

	while (quit !=1) {
		cout << "What do you want to do?" << endl 
			<< "1) Dice " << endl 
			<< "2) Character" << endl 
			<< "3) Rules" << endl 
			<< "Enter any other character to quit" << endl;
		cin >> Func;

		if (Func == "1") {
			if (DiceRoller("-1")) {
				return 0;
			}
		}

		else if (Func == "2") {
			if (Character("-1")) {
				return 0;
			}
		}

		else if (Func == "3") {
			if (Rules("-1")) {
				return 0;
			}
		}

		else {
			return 0;
		}
	}
}

int DiceRoller(string Func) {
	int Dice = 0;      //Number of Dice
	int Size = 0;      //Size of Dice
	int Roll = 0;      //Individual Dice Rolled
	int Total = 0;     //Total to be output
	int Counter = 0;   //Counts number of rolls
	int OrigDice = 0;  //Used for final user output
	
	srand(time(NULL));

	while (Dice > -1) {
	
		if (Dice == 0) {
			if (Total != 0) {
				cout << "The total of " << OrigDice << "d" << Size << " is: " << Total << endl<<endl<<endl;
				Total = 0;
			}
		
			cout << "Input Number of Dice or any negative number to stop rolling dice." << endl;
			cin >> Dice;

			while (Dice == 0) {
				cout << "Your commitment to crashing this program is admirable, but please input a positive number of dice, or a negative number to stop rolling dice." << endl;
				cin >> Dice;
			}

			if (Dice < 0) {
				cout << "What do you want to do?" << endl 
					<< "1) Main Menu" << endl 
					<< "Enter any other character to quit" << endl;
				cin >> Func;
				if (Func == "1"){
					return 0;
				}
				else {
					return -1;
				}
			}
			OrigDice = Dice;

			cout << "Input Size of Dice" << endl;
			cin >> Size;
			while (Size < 1) {
				cout << "Error in processing dice size.  Please input a positive integer." << endl;
					cin >> Size;
			}
		}
		
		Counter++;
		Roll = rand() % Size + 1;
		cout << "Roll " << Counter << ": " << Roll << endl;
		Total = Total + Roll;
		Dice--;
	}
}

int Character(string Func) {
	string NAME, LANG, WEAP, ARMR;
	int LVL, STR, STRM, DEX, DEXM, CON, CONM, INT, INTM, WIS, WISM, CHA, CHAM, HP, AC, INIT, SPD, PROF, HITD, SAVEDC, SPELLATK;
	bool STRS, DEXS, CONS, INTS, WISS, CHAS, ACRO, ANHA, ARCA, ATHL, DECE, HIST, INSI, INTI, INVE, MEDI, NATU, PERC, PERF, PERS, RELI, SLOH, STEA, SURV;
	

	ofstream myfile;
	myfile.open("Char.txt");
	
	
	
	
	
	myfile << "Test.";








	myfile.close();
	return 0;

}

int Rules(string Func) {

	return 0;

}
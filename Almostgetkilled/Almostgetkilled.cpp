// Almostgetkilled.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
	char in;
	int i, j;
	bool Gameover = false;
	int mapx=20,mapy=40;
	int hprin1 = 3, hprin2 = 4, hprin3 = 5;
	int paddlex1 = 17,paddlex2 = 23,paddley1=3,paddley2=15;
	//i bawah | j samping

	while (!Gameover) {
		if (_kbhit()) {
			in = _getch();
			if (in == 'w') {
				cout << "W";
			}
			else if (in == 'a') {
				cout << "A";
			}
			else if (in == 's') {
				cout << "S";
			}
			else if (in == 'd') {
				cout << "D";
			}
			else {
				cout << " ";
			}
		}
		for (i = 1; i <= mapx; i++) {
			for (j = 1; j <= mapy; j++) {
				if (i == 1 || j == 1 || i == mapx || j == mapy) {
					cout << "#";
				}
				else {
					cout << " ";
				}
				
			}
			cout << "\n";
		}
		
		cout << "Hp Rintangan1 : " << hprin1 << endl;
		cout << "Hp Rintangan2 : " << hprin2 << endl;
		cout << "Hp Rintangan3 : " << hprin3 << endl;
		Sleep(800);
		system("CLS");


	}
}

/*Objek 1
for (i=1;i<=2;i++){
		cout << "1";
		for (j=1;j<=3;j++){
			cout << "1";
		}
		cout << "\n";
	}
*/
/*Objek 2
	int row,colom,space;
	for (row=1;row<=3;row++){
		for(space=1;space<=3-row;space++){
			cout << " ";
		}
		for(colom=1;colom<=(2*row)-1;colom++){
			cout << "2";
		}
		cout << "\n";
	}
	for (row=2;row>=1;row--){
		for(space=1;space<=3-row;space++){
			cout << " ";
		}
		for(colom=1;colom<=(2*row)-1;colom++){
			cout << "2";
		}
		cout << "\n";
	}
*/
/*Objek 3

*/
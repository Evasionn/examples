/*
Melihþah AKIN	Cankaya UNIVERSITY
*/

#include <stdlib.h>
#include <iostream>
#include <time.h>
#define Max 50000
using namespace std;
int step = 1;


bool checkRoom(int N, int M, int ** Room) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Room[i][j] == 0) return true;
		}
	}
	return false;
}
void printFinalRoom(int N, int M, int ** Room, int process = 0) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (process == 1) {
				cout << Room[i][j] << " ";
			}
			else {
				if (Room[i][j]> 0) cout << 1 << " ";
				else cout << 0 << " ";
			}

		}
		cout << endl;
	}

}

void simRandomWalk(int xBug, int yBug, int N, int M, int *** Room) {
	time_t t;
	srand((unsigned)time(&t));
	int xWalk, yWalk;


	while (checkRoom(N, M, *Room)) {
		if (step > Max) break;
		while (1) {
			xWalk = -1 + rand() % 3;
			if (xWalk + xBug >= 0 && xWalk + xBug < N) break;
		}
		while (1) {
			yWalk = -1 + rand() % 3;
			if (yWalk + yBug >= 0 && yWalk + yBug < M) break;
		}

		xBug += xWalk; yBug += yWalk;

		(*Room)[xBug][yBug]++;
		step++;

	}

}
void main() {
	time_t t;
	srand((unsigned)time(&t));
	int N, M, xBug, yBug;
	int ** Room;

	do {
		cout << "N: "; cin >> N;
		cout << "M: "; cin >> M;
	} while (N < 2 || N > 40 || M < 2 || M > 20);
	Room = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++) {
		Room[i] = (int *)calloc(M, sizeof(int));
	}
	xBug = rand() % N; // INITIAL X CORDINATE OF THE BUG
	yBug = rand() % M; // INITIAL Y CORDINATE OF THE BUG

	simRandomWalk(xBug, yBug, N, M, &Room);


	cout << endl
		<< "THIS TABLE SHOWS IF TILES WERE TOUCHED OR NOT! "
		<< endl << endl;
	printFinalRoom(N, M, Room);

	cout << endl
		<< "-------------------------------------------------" << endl
		<< "THIS TABLE SHOWS THE NUMBER OF TIMES EACH TILE ON THE FLOOR WAS TOUCHED!"
		<< endl << endl;
	printFinalRoom(N, M, Room, 1);

	if (step > Max) cout << endl
		<< "-------------------------------------------------" << endl
		<< "THE BUG COULD NOT REACH THE ASPIRIN BEFORE THE MAX # OF STEP";

	free(Room);
	cin >> N;


}
// MELIHSAH AKIN Cankaya University
#include <stdlib.h>
#include <stdio.h>
#define n 8

typedef struct {
	int x;
	int y;
} Point;
typedef struct {
	Point cor[n];
	int last;
}qStack;


void intStack(qStack * s) {
	s->last = -1;
}

int isFull(qStack * s) {
	return s->last == n - 1 ? 1 : 0;
}
int isEmpty(qStack * s) {
	return s->last == -1 ? 1 : 0;
}
Point pop(qStack * s) {
	if (isEmpty(s)) {
		printf("There is no queen on the board.");
		exit(0);
	}
	Point p = s->cor[s->last];
	(s->last)--;
	return p;
	
}
void push(qStack * s, Point p) {
	if (isFull(s)) {
		printf("# of queens has already been reached the max.");
		exit(0);
	}
	(s->last)++;
	s->cor[s->last].x = p.x;
	s->cor[s->last].y = p.y;
}
void intBoard(int board[][n]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = 0;
		}
	}
}
int isAttacked(int board[][n], int i, int j) {
	// checking horizantal
	int tempx=0, tempy=j;
	while (tempx < n) {
		if (tempx == i) tempx++;
		if (tempx >= n) break;
		if (board[tempx][tempy] == 1) return 1;
		tempx++;

	}
	// checking vertical
	tempx = i; tempy = 0;
	while (tempy < n) {
		if (tempy == j) tempy++;
		if (tempy >= n) break;
		if (board[tempx][tempy] == 1) return 1;
		tempy++;
	}
	// checking diagonal from top-left to bottom-right
	tempx = i; tempy = j;
	while (tempx > -1 && tempy > -1) {
		tempx--; tempy--;
	}
	tempx++; tempy++;
	while (tempx < n && tempy < n) {
		if (tempx == i && tempy == j) {
			tempx++; tempy++;
		}
		if (board[tempx][tempy] == 1) return 1;
		tempx++;
		tempy++;
	}
	//checking diagonal from top-right to bottom-left
	tempx = i; tempy = j;
	while (tempx > -1 && tempy < n) {
		tempx--; tempy++;
	}
	tempx++; tempy--;
	while (tempx < n && tempy > -1) {
		if (tempx == i && tempy == j) {
			tempx++; tempy--;
		}
		if (board[tempx][tempy] == 1) return 1;
		tempx++;
		tempy--;
	}
	return 0;
}
int checkBoard(int board[][n]) {
	for (int i=0; i < n; i++) {
		for (int j=0; j < n; j++) {
			if (board[i][j] == 1) {
				if (isAttacked(board, i, j)) return 0;
			}
		}
	}
	return 1;
}
void printBoard(int board[][n]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d  ", board[i][j]);
		}
		printf("\n");
	}

	printf("\n Each of 1s show the location of queens. \n Each of 0s Show the empty squares.\n");

}
void solve(int board[][n]) {
	int count = 0;
	qStack move;
	Point cord = { 0,0 };
	intStack(&move);
	
	while (count < n) {
		if (cord.x >= n) {
			cord=pop(&move);
			board[cord.y][cord.x] = 0;
			count--;
			cord.x++;
		}
		else if (cord.y >= n) break;
		if(cord.x<n) {
			board[cord.y][cord.x] = 1;
			if (checkBoard(board)) {
				push(&move, cord);
				cord.y++;
				cord.x = 0;
				count++;
			}
			else {
				board[cord.y][cord.x] = 0;
				cord.x++;
			}
		}
	}
}
int main() {
	int board[n][n];
	intBoard(board);

solve(board);

printBoard(board);

	system("pause");
	
}
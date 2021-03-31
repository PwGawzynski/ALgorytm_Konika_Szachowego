#ifndef DEBUG
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#endif // DEBUG

typedef unsigned int** pp_chessboard;
typedef unsigned int* p_chessboard;

bool must_init(bool test,const char* description) {
	if (test) { return true; }
	printf("Cannot inicialize or value fault \n DESCRIPTION: %s",  description);
	exit(1);
}

void init_by_0(pp_chessboard chessBoard, int* size_x, int* size_y) {
	for (int i = 0; i < (*size_y); i++) {
		for (int j = 0; j < (*size_x); j++) {
			chessBoard[i][j] = 0;
		}
	}
}

void print_board(pp_chessboard chessBoard, int* size_x, int* size_y) {
	for (int i = 0; i < (*size_y); i++) {
		for (int j = 0; j < (*size_x); j++) {
			printf("%d\t", chessBoard[i][j]);
		}
		printf("\n");
	}
}

p_chessboard alocate_for_one(int* size_x) {
	p_chessboard new_chessBoard = (p_chessboard)malloc(sizeof(unsigned int) * (*size_x));
	must_init(new_chessBoard, "Tab of values");
	return new_chessBoard;
}

pp_chessboard init_chessBoard(int* size_x, int* size_y) {
	pp_chessboard m_chessBoard = (pp_chessboard)malloc(sizeof(pp_chessboard) * (*size_y));
	must_init(m_chessBoard, "Tab of pointers to each line");
	for (int i = 0; i < (*size_y); i++) {
		m_chessBoard[i] = alocate_for_one(size_x);
	}
	init_by_0(m_chessBoard, size_x, size_y);
	print_board(m_chessBoard, size_x, size_y);
	return m_chessBoard;

}

pp_chessboard getdata(int* size_x, int* size_y, int* position_x, int* position_y) {
	printf(" Podaj rozmiar szachownicy X : \n");
	scanf("%d", size_x);
	printf(" Podaj rozmiar szachownicy Y : \n");
	scanf("%d", size_y);
	system("cls");
	printf(" Podaj pozycje poczatkowa skoczka X : \n");
	scanf("%d", position_x);
	printf(" Podaj pozycje poczatkowa skoczka Y : \n");
	scanf("%d", position_y);
	system("cls");
	return init_chessBoard(size_x, size_y);
}

// ___POSIBLE MOVES____ //
int moves[8][2] = {
  { -2,  1 }, { -1,  2 }, {  1,  2 }, {  2,  1 },
  {  2, -1 }, {  1, -2 }, { -1, -2 }, { -2, -1 }
};

int valid(int* x, int* y, pp_chessboard chessBoard, int* size_x, int* size_y) // wybranie najbardziej optymalnego skoku bior¹c pod uwage co bedzie po tym skoku
{
    return
       ( (*x) >= 0) && ((*x) < (*size_y))&& // sprawdza czy nie wychodzi poza szachownice 
       ( (*y) >= 0 )&& ((*y) < (*size_x))&& 
        chessBoard[(*y)][(*x)] == 0; // sprawdza czy ta pozycja nie zostala wczesniej odwiedzona
}

int compar(const void* a, const void* b)
{
	return ((int*)a)[0] - ((int*)b)[0];
}

bool solve_knight_problem(pp_chessboard chessBoard, int* position_x, int* position_y, int* size_x, int* size_y, int* current) {
	
	
	chessBoard[(*position_y)][(*position_x)] = (*current);
	if ((*current) ==( (*size_x) * (*size_y))) //warunek ^^
		return 1;

	/* Gather valid moves and count their "loneliness". */
	int i, j, valids[8][3];
	for (i = 0; i < 8; i++) // wyznacza najkrotsza droge aby nie bylo mozliwosci
	{
		valids[i][0] = 0; //koordynaty skokow do tego miejsca co mozna skoczyc  // 0 -flaga
		valids[i][1] = (*position_x) + moves[i][0]; //koordynaty pozycji kolejnego skoku
		valids[i][2] = (*position_y) + moves[i][1];
		if (valid(&valids[i][1], &valids[i][2],chessBoard, (size_x), (size_y)))
			for (j = 0; j < 8; j++)
				if (valid((valids[i][1] + moves[j][0]? &valids[i][1]: &valids[i][1]),
					(valids[i][2] + moves[j][1]? &valids[i][2]: &valids[i][2]), chessBoard, (size_x), (size_y)))
					valids[i][0]++;
	}

	/* Sort and try each one. */
	qsort(&valids[0][0], 8, 3 * sizeof(int), &compar);
	for (i = 0; i < 8; i++)
		if (valid((&valids[i][1]), (&valids[i][2]), chessBoard, (size_x), (size_y)) && solve_knight_problem(chessBoard, (&valids[i][1]),(&valids[i][2]), (size_x), (size_y), (*current+=1)?current:0 ))
			return 1;

	/* Dead end: back off. */
	chessBoard[(*position_y)][(*position_x)] = 0;
	return 0;
}

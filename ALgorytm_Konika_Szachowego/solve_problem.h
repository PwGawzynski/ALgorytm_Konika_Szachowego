
// ___POSIBLE MOVES____ //
int moves[8][2] = {
  { -2,  1 }, { -1,  2 }, {  1,  2 }, {  2,  1 },
  {  2, -1 }, {  1, -2 }, { -1, -2 }, { -2, -1 }
};

int valid(int x, int y, pp_chessboard chessBoard, int* size_x, int* size_y) // wybranie najbardziej optymalnego skoku biorąc pod uwage co bedzie po tym skoku
{
	return
		(x) >= 0 && (x) < (*size_y) && // sprawdza czy nie wychodzi poza szachownice 
		(y) >= 0 && (y) < (*size_x) &&
		chessBoard[(y)][(x)] == 0; // sprawdza czy ta pozycja nie zostala wczesniej odwiedzona
}

int compar(const void* a, const void* b)
{
	return ((int*)a)[0] - ((int*)b)[0];
}

bool solve_knight_problem(pp_chessboard chessBoard, int* position_x, int* position_y, int* size_x, int* size_y, int* current) {


	chessBoard[(*position_y)][(*position_x)] = (*current);
	if ((*current) == ((*size_x) * (*size_y))) //warunek kończący rekurencje
		return 1;

	/* Gather valid moves and count their "loneliness". */
	int i, j, valids[8][3];
	for (i = 0; i < 8; i++) // wyznacza najkrotsza droge aby nie bylo mozliwosci
	{
		valids[i][0] = 0; //koordynaty skokow do tego miejsca co mozna skoczyc  // 0 -flaga
		valids[i][1] = (*position_x) + moves[i][0]; //koordynaty pozycji kolejnego skoku
		valids[i][2] = (*position_y) + moves[i][1];
		if (valid(valids[i][1], valids[i][2], chessBoard, (size_x), (size_y)))
			for (j = 0; j < 8; j++)
				if (valid(valids[i][1] + moves[j][0],
					valids[i][2] + moves[j][1], chessBoard, (size_x), (size_y)))
					valids[i][0]++;
	}

	/* Sort and try each one. */
	qsort(&valids[0][0], 8, 3 * sizeof(int), &compar);
	for (i = 0; i < 8; i++)
		if (valid(valids[i][1], valids[i][2], chessBoard, (size_x), (size_y)) && solve_knight_problem(chessBoard, (&valids[i][1]), (&valids[i][2]), (size_x), (size_y), (*current += 1) ? current : 0))
			return 1;

	/* Dead end: back off. */
	chessBoard[(*position_y)][(*position_x)] = 0;
	return 0;
}

/* Possible moves */
int moves[8][2] = {
 { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 },
 { 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 }
};

int check(int x, int y, pp_chessboard chessBoard, int* size_x, int* size_y) 
{
	return 
	(x) >= 0 && (x) < (*size_y) && 
	(y) >= 0 && (y) < (*size_x) &&
	chessBoard[(y)][(x)] == 0; 
}

int compare(const void* a, const void* b)
{
	return ((int*)a)[0] - ((int*)b)[0];
}

/* Solve problem*/
bool solve_knight_problem(pp_chessboard chessBoard, int* position_x, int* position_y, int* size_x, int* size_y, int* current)
{
	chessBoard[(*position_y)][(*position_x)] = (*current);
	if ((*current) == ((*size_x) * (*size_y))) return 1;

	int i, j, step[8][3];
	for (i = 0; i < 8; i++)
	{
		step[i][0] = 0; 
		step[i][1] = (*position_x) + moves[i][0]; 
		step[i][2] = (*position_y) + moves[i][1];
		if (check(step[i][1], step[i][2], chessBoard, (size_x), (size_y)))
		{ 
			for (j = 0; j < 8; j++)
			{
				if (check(step[i][1] + moves[j][0],
					step[i][2] + moves[j][1], chessBoard, (size_x), (size_y)))
					step[i][0]++;
			}
		}
	}
	qsort(&step[0][0], 8, 3 * sizeof(int), &compare);
	for (i = 0; i < 8; i++)
	{
		if (check(step[i][1], step[i][2], chessBoard, (size_x), (size_y)) && 
			solve_knight_problem(chessBoard, (&step[i][1]), (&step[i][2]), 
					(size_x), (size_y), (*current += 1) ? current : 0))
		return 1;
	}
	chessBoard[(*position_y)][(*position_x)] = 0;
	return 0;
}
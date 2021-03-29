#include "initStructures.h"

int main() {

	int size_x, size_y;
	int position_x, position_y, current=1;
	pp_chessboard chessBoard;
	chessBoard=getdata(&size_x, &size_y, &position_x, &position_y);
	solve_knight_problem(chessBoard, &position_x, &position_y, &size_x, &size_y, current);
	printf("\n\n\n");
	print_board(chessBoard, &size_x, &size_y);
	return 0;
}

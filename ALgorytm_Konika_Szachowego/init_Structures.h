typedef unsigned int** pp_chessboard;
typedef unsigned int* p_chessboard;

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
	//print_board(m_chessBoard, size_x, size_y);
	return m_chessBoard;

}

pp_chessboard getdata(int* size_x, int* size_y) {

	return init_chessBoard(size_x, size_y);
}


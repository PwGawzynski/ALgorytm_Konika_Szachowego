/* W³asny typ wskaŸnika/ podwójnego wskaŸnika na stukturê */
typedef unsigned int** pp_chessboard;
typedef unsigned int* p_chessboard;

/**
 * \brief Funckja wype³nia macierz zerami.
 *
 *	Ta funkcja wype³nia macierz zerami aby oznaczyæ pola nie odwiedzone 
 * 
 * \@param chessBoard macierz odwzoruj¹ca szachownicê.
 * \@param size_x wymiar poziomy szachownicy.
 * \@param size_y wymiar pionowy szachownicy.
 */
void init_by_0(pp_chessboard chessBoard, int* size_x, int* size_y) {
	for (int i = 0; i < (*size_y); i++) {
		for (int j = 0; j < (*size_x); j++) {
			chessBoard[i][j] = 0;
		}
	}
}

/**
 * \brief Funckja wyœwietla rozwi¹zan¹ szachownicê w konsoli.
 *
 *	Ta funkcja ko¿ystaj¹c z wype³nionej macierzy wypisuje j¹ w konsoli
 *	
 * \@param chessBoard macierz odwzoruj¹ca szachownicê.
 * \@param size_x wymiar poziomy szachownicy.
 * \@param size_y wymiar pionowy szachownicy.
 */
void print_board(pp_chessboard chessBoard, int* size_x, int* size_y) {
	for (int i = 0; i < (*size_y); i++) {
		for (int j = 0; j < (*size_x); j++) {
			printf("%d\t", chessBoard[i][j]);
		}
		printf("\n");
	}
}

/**
 * \brief Funkcja alokuje pamiêæ dla pojedynczego wiersza szachownicy.
 *
 *	Alokuje pamiêæ przez funkcje malloc.
 *	
 * \@param size_x wymiar poziomy szachownicy.
 * \return  adres pamiêci zaalokowanej dla wiersza.
 */
p_chessboard alocate_for_one(int* size_x) {
	p_chessboard new_chessBoard = (p_chessboard)malloc(sizeof(unsigned int) * (*size_x));
	must_init(new_chessBoard, "Tab of values");
	return new_chessBoard;
}

/**
 * \brief Funkcja tworzy macierz szachownicy.
 *
 *	Alokuje pamiêæ przez funkcje malloc.
 *	Nastêpnie wywo³uje funkcje wype³niaj¹c¹ zerami.
 *
 * \@param size_x wymiar poziomy szachownicy.
 * \@param size_y wymiar pionowy szachownicy. 
 * \@return  adres zaalokowanej pamiêci dla macierzy.
 */
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


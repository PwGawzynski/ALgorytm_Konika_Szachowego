/**
 * \brief Funckja odwzorująca macierz szachownicy na wersję graficzną.
 *
 * \param[in] resolution_x rozdzielczość pozioma okna programu.
 * \param[in] resolution_y rozdzielczość pionowa okna programu.
 * \param[in] FPS ilość klatek na sekundę.
 * \param[in] chessBoard macierz odwzorująca szachownicę.
 * \param[in] size_x rozmiar poziomy szachownicy.
 * \param[in] size_y rozmiar pionowy szachownicy.
 * \param[in] position_x koordynat poziomy początkowej pozycji skoczka.
 * \param[in] position_y koordynat pionowy początkowej pozycji skoczka.
 * \param[in] impossible sprawdza czy można rozwiązać problem.
*/
void draw_solution(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** bg,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS,
	int* size_x, int* size_y, int* position_x, int* position_y, 
	pp_chessboard chessboard, int impossible)
{
	*resolution_y = 1080;
	*resolution_x = 1080;
	al_resize_display(*display,*resolution_x, *resolution_y);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	int one_ractangle_x = ((*resolution_x) / (*size_x));
	int one_ractangle_y = ((*resolution_y) / (*size_y));
	*font=al_load_font("spotify_circular.ttf", 50, 1);
	int ractangle_font_x;
	int ractangle_font_y;
	char* alfanumerical_int = malloc(sizeof(char) * 10);
	int iter_i = 0;
	int iter_j = 0;
	
		for (int i = 0; i < ((*size_y) * one_ractangle_y); i += one_ractangle_x)
		{
			for (int j = 0; j < ((*size_x) * one_ractangle_x); j += one_ractangle_y)
			{
				ractangle_font_x = (i + one_ractangle_x / 2);
				ractangle_font_y = (j + one_ractangle_y / 2);
				itoa((chessboard[iter_i][iter_j]), alfanumerical_int, 10);
				if (iter_i % 2 == 0) {
					if (iter_j % 2 == 0)
					{
						al_draw_filled_rectangle(i, j, i + one_ractangle_x, j + one_ractangle_y,
							al_map_rgb(222, 189, 146));
						al_draw_text(*font, al_map_rgb(0, 0, 0),
							ractangle_font_x, ractangle_font_y - 30, ALLEGRO_ALIGN_CENTER, alfanumerical_int);
					}
					else
					{
						al_draw_filled_rectangle(i, j, i + one_ractangle_x, j + one_ractangle_y,
							al_map_rgb(106, 75, 53));
						al_draw_text(*font, al_map_rgb(255, 255, 255),
							ractangle_font_x, ractangle_font_y - 30, ALLEGRO_ALIGN_CENTER, alfanumerical_int);
					}
				}
				else {
					if (iter_j % 2 == 0)
					{
						al_draw_filled_rectangle(i, j, i + one_ractangle_x, j + one_ractangle_y,
							al_map_rgb(106, 75, 53));
						al_draw_text(*font, al_map_rgb(255, 255, 255),
							ractangle_font_x, ractangle_font_y - 30, ALLEGRO_ALIGN_CENTER, alfanumerical_int);
					}
					else
					{
						al_draw_filled_rectangle(i, j, i + one_ractangle_x, j + one_ractangle_y,
							al_map_rgb(222, 189, 146));
						al_draw_text(*font, al_map_rgb(0, 0, 0),
							ractangle_font_x, ractangle_font_y - 30, ALLEGRO_ALIGN_CENTER, alfanumerical_int);
					}
				}

				iter_j++;
			}
			iter_i++;
			iter_j = 0;
		}
	if(impossible||(*size_x < 5)&&(*size_y < 5) && (*size_x !=1 ) && (*size_y !=1))
	{
		al_destroy_font(*font);
		*font = al_load_font("spotify_circular.ttf", 120, 1);
		al_draw_text(*font, al_map_rgb(252, 44, 3),
			*resolution_x/2,(*resolution_y/2)-80, ALLEGRO_ALIGN_CENTER, "IMPOSSIBLE");
	}
	al_flip_display();
	ALLEGRO_EVENT event;
	bool done=false;
	while(1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if(done)break;
	}
}

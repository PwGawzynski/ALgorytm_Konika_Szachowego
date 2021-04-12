void draw_solution(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display,
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** bg,
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS,
	int* size_x, int* size_y, int* position_x, int* position_y, 
	pp_chessboard chessboard)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	int one_ractangle_x = ((*resolution_x) / (*size_x));
	int one_ractangle_y = ((*resolution_y) / (*size_y));
	
	for(int i=0;i<((*size_y)*one_ractangle_y);i+=one_ractangle_x)
	{
		for (int j=0; j<((*size_x)*one_ractangle_x);j+=one_ractangle_y)
		{
			al_draw_rectangle(i, j, i + one_ractangle_x, j + one_ractangle_y,
				al_map_rgb(255, 255, 255), 1);
		}
	}
	al_flip_display();
	al_rest(5);
}

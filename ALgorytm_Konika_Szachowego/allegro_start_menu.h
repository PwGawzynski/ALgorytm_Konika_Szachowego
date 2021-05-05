

bool check_event_click(unsigned int* mouse_x, unsigned int* mouse_y, int *values, 
	int* size_x, int* size_y, int* position_x, int* position_y)
{
	if (((*mouse_x >= 654) && (*mouse_x <= 1264)) && ((*mouse_y >= 903) && (*mouse_y <= 992))) 
	{
		*size_x = values[0];
		*size_y = values[1];
		*position_x = values[2];
		*position_y = values[3];
		return true;
	}
}

bool can_i(int* values)
{
	int i = 0;
	for(;i<2;i++)
	{
		if (values[i] > 12) return false;
	}
	if (values[0] != values[1])return false;
	for (; i < 5; i++)
	{
		if (values[i] > 11) return false;
	}
	return true;
}

bool listener(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, 
	ALLEGRO_BITMAP** bg, ALLEGRO_FONT** font, unsigned int* resolution_x, 
	unsigned int* resolution_y, const float* FPS,
	int *size_x, int*size_y, int* position_x, int* position_y)
{
	ALLEGRO_EVENT event;
	bool done = false;
	bool redraw = false;
	int unichar;
	int iterator=0;
	int values[4];
	int font_position_y[] = { 400, 482, 664, 746 };
	ALLEGRO_USTR *input = al_ustr_new("");
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	ALLEGRO_FONT* font_menu = al_load_font("spotify_circular.ttf", 50, 1);
	unsigned int mouse_x, mouse_y, mouse_click;
	while (1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			if (iterator == 4 && can_i(values)) 
			{
				return check_event_click(&mouse_x, &mouse_y, values, 
					size_x, size_y, position_x, position_y);	
			}
			break;
		case ALLEGRO_EVENT_KEY_CHAR:
			unichar = event.keyboard.unichar;
			if(unichar>=48&&unichar<=57)
			{
				al_ustr_append_chr(input, unichar);
				
			}
			else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
			{
				
				al_draw_text(font_menu,color,
					*resolution_x/2,font_position_y[iterator],
					ALLEGRO_ALIGN_CENTER, al_cstr(input));
				al_flip_display();
				if(iterator<=3)values[iterator] = atoi(al_cstr(input));
				input = al_ustr_new("");
				iterator++;
				if(iterator==5)
				{
					al_draw_bitmap(*bg, 0, 0, 0);
					al_flip_display();
					iterator = 0;
				}
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;

	}
	al_destroy_font(font_menu);
}



bool init_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, 
	ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** bg, 
	unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS,
	int *size_x,int*size_y,int* position_x,int* position_y)
{
	al_draw_bitmap(*bg, 0, 0, 0);
	al_flip_display();
	listener(timer, display, queue, bg, font, resolution_x, 
		resolution_y, FPS,size_x,size_y,position_x,position_y);
}
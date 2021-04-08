
bool check_event_click(unsigned int* mouse_x, unsigned int* mouse_y)
{   
	//Solve button
	if (((*mouse_x >= 654) && (*mouse_x <= 1264)) && ((*mouse_y >= 903) && (*mouse_y <= 992))) {
		
		printf("nmrinmri");
		return true;
	}
}

const int listener(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_BITMAP** bg, unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	ALLEGRO_EVENT event;
	bool done = false;
	bool redraw = false;
	int check_returned;
	unsigned int mouse_x, mouse_y, mouse_click;
	while (1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			must_init(check_event_click(&mouse_x, &mouse_y), "check position");
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;

	}
}

bool init_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** bg, unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	al_draw_bitmap(*bg, 0, 0, 0);
	al_flip_display();
	listener(timer, display, queue, bg, resolution_x, resolution_y, FPS);

}
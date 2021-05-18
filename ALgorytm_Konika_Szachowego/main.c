#include "status.h"
#include "init_Structures.h"
#include "solve_problem.h"
#include "allegro_handler.h"
#include "allegro_start_menu.h"
#include "draw_solution.h"

/* FPS & rozmiar okna */
const float FPS = 30.0;
unsigned int resolution_x = 1920;
unsigned int resolution_y = 1080;

int main() {
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_BITMAP* background = NULL;
	int impossible = 0;
	int size_x, size_y;
	int position_x, position_y, current = 1;
	allegro_game_init(&timer, &display, &queue, &font, &background, &resolution_x, &resolution_y, &FPS);
	init_menu(&timer, &display, &queue, &font, &background, 
		&resolution_x, &resolution_y, &FPS,&size_x,&size_y,&position_x,&position_y);
	pp_chessboard chessBoard;
	chessBoard = init_chessBoard(&size_x, &size_y);
	if (solve_knight_problem(chessBoard, &position_x, &position_y, &size_x, &size_y, &current)) {
		printf("\n\n\n");
	}
	else impossible = 1;

	draw_solution(&timer, &display, &queue, &font, &background,
		&resolution_x, &resolution_y, &FPS, &size_x, &size_y, &position_x, &position_y, chessBoard, impossible);

	al_destroy_font(font);
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	return 0;
}

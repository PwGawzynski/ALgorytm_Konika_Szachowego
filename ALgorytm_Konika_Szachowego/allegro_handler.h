#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

/**
 * \brief Funcja inicjalizuje niezbêdne wskaŸniki i elementy biblioteki allegro.
 *
 *  W tej funkcji nastêpuje kolejno, inicjalizacja addon allegro, nastêpnie inicjalizowane s¹ wskaŸniki,
 *  nastêpnie  ustawiane s¹ w³aœciwoœci okna wyswietlacza, ustwiane s¹ w³asnoœci grafiki, i kolejki eventów.
 *
 * \@param resolution_x rozdzielczoœæ pozioma okna programu.
 * \@param resolution_y rozdzielczoœæ pionowa okna programu. 
 * \@param FPS iloœæ klatek na sekundê.
* \@param timer podwójny wskaŸnik na timer biblioteki allegro.
 * \@param display podwójny wskaŸnik na display biblioteki allegro.
 * \@param queue podwójny wskaŸnik na kolejkê biblioteki allegro.
 * \@param bg podwójny wskaŸnik na t³o biblioteki allegro.
 * \@param font podwójny wskaŸnik na font biblioteki allegro.
 * \@param resolution_x  wskaŸnik na szerokoœæ ekranu.
 * \@param resolution_y  wskaŸnik na wysokoœæ ekranu.
 *
 */
void allegro_game_init(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, 
    ALLEGRO_BITMAP** bg, unsigned int* resolution_x, unsigned int* resolution_y, float* FPS) {
    
   /* Dodatki Allegro */
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    must_init(al_install_mouse(), "mouse");
    must_init(al_init_image_addon(), "bg_image");

   /* Inicjalizacja wskaŸników */
    *timer = al_create_timer(1 / *FPS);
    must_init(*timer, "timer");
    *queue = al_create_event_queue();
    must_init(*queue, "queue");
    *display = al_create_display(*resolution_x, *resolution_y);
    must_init(*display, "display");
    *font = al_create_builtin_font();
    must_init(*font, "font");
    *bg = al_load_bitmap("MENU.jpg");
    must_init(*bg, "bg_pointer");

    al_init_font_addon();              
    al_init_ttf_addon();
	
   /* Ustawienia okna */
    al_set_window_position(*display, 0, 0);
    al_set_window_title(*display, "THE KNIGHT'S TOUR PROBLEM");

    /* Ustawienia grafiki */
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    /* Ustawienia eventów */
    al_register_event_source(*queue, al_get_keyboard_event_source());
    al_register_event_source(*queue, al_get_display_event_source(*display));
    al_register_event_source(*queue, al_get_timer_event_source(*timer));
    al_register_event_source(*queue, al_get_mouse_event_source());
}

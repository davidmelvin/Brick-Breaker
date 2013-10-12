/*
 * Vivek Jain, David Melvin, Roland Fong
 * 9/21/13
 * Brick Breaker C++ OOP Project
 */

#include "Include.h"

/*
*****IMPORTANT! PLEASE READ*****
The include folder, lib files, and bin files that came with your allegro download 
(VERSION 5.0.9 for me, 5.0.10 for Vivek) should be placed within the regular C++ 
include file, lib folder, and bin folder respectively.  Ask Roland if you need help.

Be sure that you are creating a separate VS project and linking it with this one by right clicking Source Files (or Header Files)
and then Add > Existing and find the ones in git.  Similarly, when creating new files, put them in the github folder

Before opening your project be sure to sync in git. When you sync, be sure to save first!
*/

using namespace std;

int main()
{
	/*****INITIALIZE ALLEGRO*****/
	if(!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL,
			"Failed to initialize Allegro!", NULL, NULL);
		return -1;
	}

	ALLEGRO_DISPLAY *display = NULL;
	display = al_create_display(WIDTH, HEIGHT);

	/*****INITIALIZE MAIN WINDOW*****/
	if(!display)
	{
		al_show_native_message_box(NULL, NULL, NULL,
			"Failed to initialize display!", NULL, NULL);
		return -1;
	}
	al_set_window_title(display, "Reverse Engineering");

	/*****ADD ONS AND INPUT INITIALIZATION*****/
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon(); //may not need this...
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();


	/*****VARIABLE DECLARATIONS*****/
	int FPS = 60;// frame rate per second
	bool done = false;//if true, game ends
	bool draw = true;
	bool redraw = true;//used in double buffering game (avoid flickering)
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	Brick brTest(0, 0, "img/brickTest.png");

	event_queue = al_create_event_queue();

	al_clear_to_color(al_map_rgb(0, 0, 0));

	timer = al_create_timer(1.0 / FPS);

	/*****REGISTER EVENT SOURCES*****/
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);//must be placed directly before while loop

	/*****MAIN LOOP*****/
	while(!done)
	{
		/*****EVENT HANDLING*****/
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			if(al_show_native_message_box(display, "Exit",
				"Are you sure you want to exit?", NULL,
				NULL, ALLEGRO_MESSAGEBOX_YES_NO) == 1)
			{
				done = true;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)//i.e. in new frame, redraw everything
		{
			redraw = true;
		}
		/*****DRAWING*****/
		if(draw && redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
			//DRAWING CODE HERE
			brTest.draw();
			al_flip_display();//transfers drawing code to screen
			al_clear_to_color(al_map_rgb(0,0,0));//resets screen color (may not be necessary)
			//Note that previously drawn figures will still be on the screen; al_clear_to_color is used to delete them.
		}


	}

	/*****POINTER DESTROYERS; VERY IMPORTANT TO AVOID MEMORY LEAKS*****/
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
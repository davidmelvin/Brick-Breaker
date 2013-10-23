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
	if(!al_init_image_addon())
		cout << "Could not install image addon" << endl;
	else
		cout << "Installed image addon" << endl;

	if(!al_install_keyboard())
		cout << "Could not install keyboard" << endl;
	else
		cout << "Installed keyboard" << endl;

	if(!al_install_mouse())
		cout << "Could not install mouse" << endl;
	else
		cout << "Installed mouse" << endl;


	/*****VARIABLE DECLARATIONS*****/
	bool done = false;//if true, game ends
	bool draw = true;
	bool redraw = true;//used in double buffering game (avoid flickering)
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
<<<<<<< HEAD
	Brick brTest(0, 0, "img/brickTest.png");
	Paddle paddle1("img/paddle.png", WIDTH / 2 - 150 / 2, HEIGHT - 20, 150, 15);
	Ball ball1 ("img/ball1.png", WIDTH / 2, HEIGHT - 35, 15, 15);
	Ball ballTest("img/ball1.png", 585, 100, 15, 15);
	ballTest.setAngle(PI/4);
	ballTest.setVelocity(2);
	
=======

>>>>>>> 3061617e20fbb27517eccddff82ad2831719ba1e
	enum KEYS {KEY_RIGHT, KEY_LEFT};
	bool keyPress[2] = {false, false};

	RegBrick brTest(0, 0, "img/brickTest.png");
	Paddle paddle1("img/paddle.png", WIDTH / 2 - 150 / 2, HEIGHT - 20, 150, 15);
	
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
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_RIGHT:
				cout << "Pressed Right Key" << endl;
				keyPress[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				cout << "Pressed Left Key" << endl;
				keyPress[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				cout << "Escaped" << endl;
				return 0;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_RIGHT:
				cout << "Released Right Key" << endl;
				keyPress[KEY_RIGHT] = false;
				//ballTest.move();
				break;
			case ALLEGRO_KEY_LEFT:
				cout << "Released Left Key" << endl;
				keyPress[KEY_LEFT] = false;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)//i.e. in new frame, redraw everything
		{
			if(keyPress[KEY_RIGHT] == true)
			{
				paddle1.move(ALLEGRO_KEY_RIGHT, 5);
			}
			else if(keyPress[KEY_LEFT] == true)
			{
				paddle1.move(ALLEGRO_KEY_LEFT, 5);
			}
			redraw = true;
		}
		/*****DRAWING*****/
		if(draw && redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
			//DRAWING CODE HERE
			paddle1.draw();
			brTest.draw();
			ball1.draw();
			ballTest.draw();
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
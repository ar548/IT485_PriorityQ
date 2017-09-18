#include <SDL.h>
#include "gf2d_graphics.h"
#include "gf2d_sprite.h"
#include "simple_logger.h"
#include "PriorityQ.h"

int main(int argc, char * argv[])
{
	/*for testing of Alex Rosen's project only*/
	PriorityQueue *pq = pq_new(6*sizeof(char));

    /*variable declarations*/
    int done = 0;
    const Uint8 * keys;
    Sprite *sprite;
    
    int mx,my;
    float mf = 0;
    Sprite *mouse;
    Vector4D mouseColor = {255,100,255,200};
    
    /*program initializtion*/
    init_logger("gf2d.log");
    slog("---==== BEGIN ====---");
    gf2d_graphics_initialize(
        "gf2d",
        1200,
        720,
        1200,
        720,
        vector4d(0,0,0,255),
        0);
    gf2d_graphics_set_frame_delay(16);
    gf2d_sprite_init(1024);
    SDL_ShowCursor(SDL_DISABLE);
    
	/*for testing of Alex Rosen's project only*/
	pq_insert(pq, (void*)"three", 3);
	print_priotities(pq);
	pq_insert(pq, (void*)"one  ", 1);
	print_priotities(pq);
	pq_insert(pq, (void*)"three", 3);
	print_priotities(pq);
	pq_insert(pq, (void*)"seven", 7);
	print_priotities(pq);
	pq_insert(pq, (void*)"four ", 4);
	print_priotities(pq);
	pq_insert(pq, (void*)"five ", 5);
	print_priotities(pq);

	slog("str 1: %s", pq_delete_max(pq));
	slog("str 2: %s", pq_delete_max(pq));
	slog("str 3: %s", pq_delete_max(pq));
	slog("str 4: %s", pq_delete_max(pq));
	slog("str 5: %s", pq_delete_max(pq));
	slog("str 6: %s", pq_delete_max(pq));

	pq_insert(pq, (void*)"three", 3);
	pq_insert(pq, (void*)"one  ", 1);
	pq_insert(pq, (void*)"three", 3);
	pq_insert(pq, (void*)"seven", 7);
	pq_insert(pq, (void*)"four ", 4);
	pq_insert(pq, (void*)"five ", 5);

	slog("str 1: %s", pq_delete_min(pq));
	slog("str 2: %s", pq_delete_min(pq));
	slog("str 3: %s", pq_delete_min(pq));
	slog("str 4: %s", pq_delete_min(pq));
	slog("str 5: %s", pq_delete_min(pq));
	slog("str 6: %s", pq_delete_min(pq));

    /*demo setup*/
    sprite = gf2d_sprite_load_image("images/backgrounds/bg_flat.png");
    mouse = gf2d_sprite_load_all("images/pointer.png",32,32,16);
    /*main game loop*/
    while(!done)
    {
        SDL_PumpEvents();   // update SDL's internal event structures
        keys = SDL_GetKeyboardState(NULL); // get the keyboard state for this frame
        /*update things here*/
        SDL_GetMouseState(&mx,&my);
        mf+=0.1;
        if (mf >= 16.0)mf = 0;
        
        
        gf2d_graphics_clear_screen();// clears drawing buffers
        // all drawing should happen betweem clear_screen and next_frame
            //backgrounds drawn first
            gf2d_sprite_draw_image(sprite,vector2d(0,0));
            
            //UI elements last
            gf2d_sprite_draw(
                mouse,
                vector2d(mx,my),
                NULL,
                NULL,
                NULL,
                NULL,
                &mouseColor,
                (int)mf);
        gf2d_grahics_next_frame();// render current draw frame and skip to the next frame
        
        if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
        //slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
    }
    slog("---==== END ====---");
    return 0;
}
/*eol@eof*/

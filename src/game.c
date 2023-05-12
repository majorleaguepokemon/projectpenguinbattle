#include <SDL.h>
#include "simple_logger.h"

#include "gf2d_graphics.h"
#include "gf2d_sprite.h"

#include "gfc_audio.h"

int main(int argc, char * argv[])
{
    /*variable declarations*/
    int done = 0;
    const Uint8 * keys;
    
    int mx,my;
    float mf = 0;
    Sprite *f, *b, *fs, *bs;
    
    /*program initializtion*/
    init_logger("gf2d.log",0);
    slog("---==== BEGIN ====---");
    gf2d_graphics_initialize(
        "Project Penguin Battle",
        1200,
        720,
        1200,
        720,
        vector4d(0,0,0,255),
        0);
    gf2d_graphics_set_frame_delay(16);
    gf2d_sprite_init(1024);
    SDL_ShowCursor(SDL_DISABLE);
    
    /*demo setup*/
    f = gf2d_sprite_load_image("images/sprites/front/bulbasaur.png");
    fs = gf2d_sprite_load_image("images/sprites/front-shiny/bulbasaur.png");
    b = gf2d_sprite_load_image("images/sprites/back/bulbasaur.png");
    bs = gf2d_sprite_load_image("images/sprites/back-shiny/bulbasaur.png");
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
            gf2d_sprite_draw_image(f,vector2d(100,100));
            gf2d_sprite_draw_image(fs,vector2d(300,100));
            gf2d_sprite_draw_image(b,vector2d(500,100));
            gf2d_sprite_draw_image(bs,vector2d(700,100));
            
            //UI elements last

        gf2d_graphics_next_frame();// render current draw frame and skip to the next frame
        
        if (keys[SDL_SCANCODE_ESCAPE])done = 1; // exit condition
        //slog("Rendering at %f FPS",gf2d_graphics_get_frames_per_second());
    }
    slog("---==== END ====---");
    return 0;
}
/*eol@eof*/

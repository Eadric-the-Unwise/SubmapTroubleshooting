#include <gb/gb.h>
#include "macros.h"

Variables bkg;

void main()
{
    DISPLAY_OFF;
    SHOW_BKG;
    init_submap();

    DISPLAY_ON;

    while (TRUE)
    {
        bkg.joy = joypad();
        // Add above loop (beginning of else-if loop, effectively)
        if (bkg.joy & J_SELECT)
        {
            init_submap();
        }
        else if (bkg.joy & J_START)
        {
            init_house();
        }
        if (bkg.indoor)
        {
            if (bkg.joy & J_UP)
            {
                if (bkg.camera_y)
                {
                    bkg.camera_y--;
                    bkg.redraw = TRUE;
                }
            }
            if (bkg.joy & J_DOWN)
            {
                if (bkg.camera_y < bkg.camera_max_y)
                {
                    bkg.camera_y++;
                    bkg.redraw = TRUE;
                }
            }
        }

        else if (bkg.sliding)
        {
            // If the camera and slide is inside the map, slide, otherwise cancel slide
            if (!(bkg.camera_x + bkg.slide_x < 0 || bkg.camera_x + bkg.slide_x > bkg.camera_max_x ||
                  bkg.camera_y + bkg.slide_y < 0 || bkg.camera_y + bkg.slide_y > bkg.camera_max_y))
            {
                bkg.camera_x += bkg.slide_x; // Move as much as slide in X direction
                bkg.camera_y += bkg.slide_y; // " " in Y direction
                bkg.redraw = TRUE;           // Flag for redraw
            }
            else
                bkg.sliding = FALSE;

            // If camera is at the end of the slide, stop sliding
            if (bkg.camera_x % 160 == 0 && bkg.camera_y % 144 == 0)
                bkg.sliding = FALSE;
        }
        // make sure else if before all other inputs
        else if (bkg.joy & J_LEFT)
        {
            // Realistically this would be gated by an edge-check and valid-edge check
            // (this would replace camera_x++/-- or camera_y++/--)
            bkg.slide_x = -2; // How much to move in the X direction
            bkg.slide_y = 0;  // How much to move in the Y direction
            bkg.sliding = 1;  // Initiate slide
        }
        else if (bkg.joy & J_RIGHT)
        {
            bkg.slide_x = 2;
            bkg.slide_y = 0;
            bkg.sliding = 1;
        }
        else if (bkg.joy & J_UP)
        {
            bkg.slide_x = 0;
            bkg.slide_y = -2;
            bkg.sliding = 1;
            if (bkg.indoor)
            {
                if (bkg.camera_y)
                {
                    bkg.camera_y--;
                    bkg.redraw = TRUE;
                }
            }
        }
        else if (bkg.joy & J_DOWN)
        {
            bkg.slide_x = 0;
            bkg.slide_y = 2;
            bkg.sliding = 1;
            if (bkg.indoor)
            {
                if (bkg.camera_y)
                {
                    bkg.camera_y++;
                    bkg.redraw = TRUE;
                }
            }
        }

        if (bkg.redraw)
        {
            wait_vbl_done();
            set_camera();
            bkg.redraw = FALSE;
        }
        else
            wait_vbl_done();
    }
}
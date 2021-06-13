#include <gb/gb.h>

#include "bigmap_map.h"
#include "bigmap_tiles.h"
#include "bigmap_map.h"
#include "bkg_apartment_scroll_map.h"
#include "bkg_apartment_scroll_tiles.h"
#include "bkg_submap_map.h"
#include "bkg_submap_tiles.h"

UINT16 camera_max_y;
UINT16 camera_max_x;

#define MIN(A, B) ((A) < (B) ? (A) : (B))

UBYTE joy;
UBYTE indoor;
UBYTE sliding = 0;
INT8 slide_x = 0;
INT8 slide_y = 0;

// current and old positions of the camera in pixels
WORD camera_x, camera_y, old_camera_x, old_camera_y;
// current and old position of the map in tiles
UBYTE map_pos_x, map_pos_y, old_map_pos_x, old_map_pos_y;
// redraw flag, indicates that camera position was changed
UBYTE redraw;

//below PROVIDED BY TOXA IN DISCORD //
UINT8 level_map_width;
UINT8 level_map_height;
const UINT8 *level_map_data;
inline void set_level(UINT8 map_width, UINT8 map_height, const UINT8 *map_data)
{
    level_map_width = map_width;
    level_map_height = map_height;
    level_map_data = map_data;
    camera_max_y = (map_height - 18) * 8;
    camera_max_x = (map_width - 20) * 8;
}

void set_camera()
{
    // update hardware scroll position
    SCY_REG = camera_y;
    SCX_REG = camera_x;
    // up or down
    map_pos_y = (UBYTE)(camera_y >> 3u);
    if (map_pos_y != old_map_pos_y)
    {
        if (camera_y < old_camera_y)
        {
            set_bkg_submap(map_pos_x, map_pos_y, MIN(21u, level_map_width - map_pos_x), 1, level_map_data, level_map_width);
        }
        else
        {
            if ((level_map_height - 18u) > map_pos_y)
                set_bkg_submap(map_pos_x, map_pos_y + 18u, MIN(21u, level_map_width - map_pos_x), 1, level_map_data, level_map_width);
        }
        old_map_pos_y = map_pos_y;
    }
    // left or right
    map_pos_x = (UBYTE)(camera_x >> 3u);
    if (map_pos_x != old_map_pos_x)
    {
        if (camera_x < old_camera_x)
        {
            set_bkg_submap(map_pos_x, map_pos_y, 1, MIN(19u, level_map_height - map_pos_y), level_map_data, level_map_width);
        }
        else
        {
            if ((level_map_width - 20u) > map_pos_x)
                set_bkg_submap(map_pos_x + 20u, map_pos_y, 1, MIN(19u, level_map_height - map_pos_y), level_map_data, level_map_width);
        }
        old_map_pos_x = map_pos_x;
    }
    // set old camera position to current camera position
    old_camera_x = camera_x, old_camera_y = camera_y;
}

void init_map()
{
    HIDE_BKG;
    camera_x = 0x1E;
    camera_y = 0x02;
    old_camera_x = camera_x;
    old_camera_y = camera_y;
    map_pos_x = (UBYTE)(camera_x >> 3u);
    map_pos_y = (UBYTE)(camera_y >> 3u);

    set_bkg_data(0, 241u, bigmap_tiles);
    old_map_pos_x = old_map_pos_y = 255;
    camera_max_y = (bigmap_mapHeight - 18) * 8;
    camera_max_x = (bigmap_mapWidth - 20) * 8;
    set_bkg_submap(map_pos_x, map_pos_y, 20, 18, bigmap_map, bigmap_mapWidth);
    set_level(bigmap_mapWidth, bigmap_mapHeight, bigmap_map);

    redraw = FALSE;
    indoor = 0;

    SCX_REG = camera_x;
    SCY_REG = camera_y;
    SHOW_BKG;
}

void init_house()
{
    HIDE_BKG;
    camera_x = camera_y = 0;
    old_camera_x = camera_x;
    old_camera_y = camera_y;
    map_pos_x = (UBYTE)(camera_x >> 3u);
    map_pos_y = (UBYTE)(camera_y >> 3u);

    set_bkg_data(0, BKG_APARTMENT_SCROLL_TILE_COUNT, bkg_apartment_scroll_tiles);
    old_map_pos_x = old_map_pos_y = 255;
    camera_max_y = (BKG_APARTMENT_SCROLL_MAP_HEIGHT - 18) * 8;
    camera_max_x = (BKG_APARTMENT_SCROLL_MAP_WIDTH - 20) * 8;
    set_bkg_submap(map_pos_x, map_pos_y, 20, 18, bkg_apartment_scroll_map, BKG_APARTMENT_SCROLL_MAP_WIDTH);
    set_level(BKG_APARTMENT_SCROLL_MAP_WIDTH, BKG_APARTMENT_SCROLL_MAP_HEIGHT, bkg_apartment_scroll_map);

    old_camera_x = camera_x;
    old_camera_y = camera_y;

    redraw = FALSE;
    indoor = 1;

    SCX_REG = camera_x;
    SCY_REG = camera_y;
    SHOW_BKG;
}

void init_submap()
{
    HIDE_BKG;
    camera_x = 160;
    camera_y = 144;
    old_camera_x = camera_x;
    old_camera_y = camera_y;
    map_pos_x = (UBYTE)(camera_x >> 3u);
    map_pos_y = (UBYTE)(camera_y >> 3u);

    set_bkg_data(0, BKG_SUBMAP_TILE_COUNT, bkg_submap_tiles);
    old_map_pos_x = old_map_pos_y = 255;
    camera_max_y = (BKG_SUBMAP_MAP_HEIGHT - 18) * 8;
    camera_max_x = (BKG_SUBMAP_MAP_WIDTH - 20) * 8;
    set_bkg_submap(map_pos_x, map_pos_y, 20, 18, bkg_submap_map, BKG_SUBMAP_MAP_WIDTH);
    set_level(BKG_SUBMAP_MAP_WIDTH, BKG_SUBMAP_MAP_HEIGHT, bkg_submap_map);

    old_camera_x = camera_x;
    old_camera_y = camera_y;

    redraw = FALSE;
    indoor = 0;

    SCX_REG = camera_x;
    SCY_REG = camera_y;
    SHOW_BKG;
}

void main()
{
    DISPLAY_OFF;
    SHOW_BKG;
    init_submap();

    DISPLAY_ON;

    while (TRUE)
    {
        joy = joypad();
        // Add above loop (beginning of else-if loop, effectively)
        if (joy & J_SELECT)
        {
            init_submap();
        }
        else if (joy & J_START)
        {
            init_house();
        }
        if (indoor)
        {
            if (joy & J_UP)
            {
                if (camera_y)
                {
                    camera_y--;
                    redraw = TRUE;
                }
            }
            if (joy & J_DOWN)
            {
                if (camera_y < camera_max_y)
                {
                    camera_y++;
                    redraw = TRUE;
                }
            }
        }

        else if (sliding)
        {
            // If the camera and slide is inside the map, slide, otherwise cancel slide
            if (!(camera_x + slide_x < 0 || camera_x + slide_x > camera_max_x ||
                  camera_y + slide_y < 0 || camera_y + slide_y > camera_max_y))
            {
                camera_x += slide_x; // Move as much as slide in X direction
                camera_y += slide_y; // " " in Y direction
                redraw = TRUE;       // Flag for redraw
            }
            else
                sliding = FALSE;

            // If camera is at the end of the slide, stop sliding
            if (camera_x % 160 == 0 && camera_y % 144 == 0)
                sliding = FALSE;
        }
        // make sure else if before all other inputs
        else if (joy & J_LEFT)
        {
            // Realistically this would be gated by an edge-check and valid-edge check
            // (this would replace camera_x++/-- or camera_y++/--)
            slide_x = -2; // How much to move in the X direction
            slide_y = 0;  // How much to move in the Y direction
            sliding = 1;  // Initiate slide
        }
        else if (joy & J_RIGHT)
        {
            slide_x = 2;
            slide_y = 0;
            sliding = 1;
        }
        else if (joy & J_UP)
        {
            slide_x = 0;
            slide_y = -2;
            sliding = 1;
            if (indoor)
            {
                if (camera_y)
                {
                    camera_y--;
                    redraw = TRUE;
                }
            }
        }
        else if (joy & J_DOWN)
        {
            slide_x = 0;
            slide_y = 2;
            sliding = 1;
            if (indoor)
            {
                if (camera_y)
                {
                    camera_y++;
                    redraw = TRUE;
                }
            }
        }

        // // up or down
        // if (joy & J_UP)
        // {
        //     if (camera_y)
        //     {
        //         camera_y--;
        //         redraw = TRUE;
        //     }
        // }
        // else if (joy & J_DOWN)
        // {
        //     if (camera_y < camera_max_y)
        //     {
        //         camera_y++;
        //         redraw = TRUE;
        //     }
        // }
        // // left or right
        // if (joy & J_LEFT)
        // {
        //     if (indoor == 0)
        //     {
        //         if (camera_x)
        //         {
        //             camera_x--;
        //             redraw = TRUE;
        //         }
        //     }

        // }
        // else if (joy & J_RIGHT)
        // {
        //     if (indoor == 0)
        //     {
        //         if (camera_x < camera_max_x)
        //         {
        //             camera_x++;
        //             redraw = TRUE;
        //         }
        //     }
        // }
        if (redraw)
        {
            wait_vbl_done();
            set_camera();
            redraw = FALSE;
        }
        else
            wait_vbl_done();
    }
}
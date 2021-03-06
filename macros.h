#ifndef __MACROS_H__
//prevents the includes from being called twice
#define __MACROS_H__

#include <gb/gb.h>
#include <stdio.h>
#include "maps/submap/submap.h"
#include "maps/house/house.h"
#include "maps/house/cellar/cellar.h"
#include "maps/house/cellar/cellar_lvl2/cellar_lvl2.h"

#define MIN(A, B) ((A) < (B) ? (A) : (B))
//##joins the __bank and 'A' variable name together
#define __BANK_PREFIX(A) __bank_##A
#define BANK(A) (UBYTE) & (__BANK_PREFIX(A))
// #define __SIZE_PREFIX(A) __size_##A
// #define SIZE(A) (UWORD) & (__SIZE_PREFIX(A))
// #define OFFSET(A) (void *)&(A)

enum Cam
{
    vertical_cam,
    horizontal_cam,
    platforming_cam,
    scroll_cam
};

typedef struct Variables
{
    UINT16 camera_max_y;
    UINT16 camera_max_x;
    UBYTE joy;

    UBYTE sliding;
    INT8 slide_x;
    INT8 slide_y;
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
    enum Cam camera_style;

    UINT8 level_map_bank;

} Variables;

void set_camera();

inline void set_level(UINT8, UINT8, const UINT8 *, UINT8 bank);
void set_bkg_data_nonbanked(UINT8 first_tile, UINT8 nb_tiles, const UINT8 *tile_data, UINT8 bank);
void set_bkg_submap_nonbanked(UINT8 x, UINT8 y, UINT8 w, UINT8 h, const UINT8 *map_data, UINT8 map_w, UINT8 bank);

#endif
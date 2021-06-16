#ifndef __MACROS_H__ //prevents the includes from being called twice
#define __MACROS_H__

#include <gb/gb.h>
#include "maps/submap/submap.h"
#include "maps/house/house.h"
#include "maps/house/cellar/cellar.h"

#define MIN(A, B) ((A) < (B) ? (A) : (B))

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

} Variables;

void set_camera();

inline void set_level(UINT8, UINT8, const UINT8 *);

#endif
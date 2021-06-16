#include "submap.h"
#include "../../macros.h"

extern UINT16 camera_max_y;
extern UINT16 camera_max_x;
extern UBYTE joy;
extern UBYTE indoor;
extern UBYTE sliding;
extern INT8 slide_x;
extern INT8 slide_y;
// current and old positions of the camera in pixels
extern WORD camera_x, camera_y, old_camera_x, old_camera_y;
// current and old position of the map in tiles
extern UBYTE map_pos_x, map_pos_y, old_map_pos_x, old_map_pos_y;
// redraw flag, indicates that camera position was changed
extern UBYTE redraw;
//below PROVIDED BY TOXA IN DISCORD //
extern UINT8 level_map_width;
extern UINT8 level_map_height;
extern const UINT8 *level_map_data;

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
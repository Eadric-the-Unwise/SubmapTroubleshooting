#include "house.h"
#include "../../macros.h"

extern Variables bkg;

void init_house()
{
    HIDE_BKG;
    bkg.camera_x = bkg.camera_y = 0;
    bkg.old_camera_x = bkg.camera_x;
    bkg.old_camera_y = bkg.camera_y;
    bkg.map_pos_x = (UBYTE)(bkg.camera_x >> 3u);
    bkg.map_pos_y = (UBYTE)(bkg.camera_y >> 3u);

    set_bkg_data(0, BKG_APARTMENT_SCROLL_TILE_COUNT, bkg_apartment_scroll_tiles);
    bkg.old_map_pos_x = bkg.old_map_pos_y = 255;
    bkg.camera_max_y = (BKG_APARTMENT_SCROLL_MAP_HEIGHT - 18) * 8;
    bkg.camera_max_x = (BKG_APARTMENT_SCROLL_MAP_WIDTH - 20) * 8;
    set_bkg_submap(bkg.map_pos_x, bkg.map_pos_y, 20, 18, bkg_apartment_scroll_map, BKG_APARTMENT_SCROLL_MAP_WIDTH);
    set_level(BKG_APARTMENT_SCROLL_MAP_WIDTH, BKG_APARTMENT_SCROLL_MAP_HEIGHT, bkg_apartment_scroll_map);

    bkg.old_camera_x = bkg.camera_x;
    bkg.old_camera_y = bkg.camera_y;

    bkg.redraw = FALSE;

    bkg.camera_style = vertical_cam;

    SCX_REG = bkg.camera_x;
    SCY_REG = bkg.camera_y;
    SHOW_BKG;
}

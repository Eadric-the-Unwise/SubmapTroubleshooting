#include "house.h"
#include "../../macros.h"

extern const void __bank_house_map;
extern const void __bank_house_tiles;
extern Variables bkg;

void init_house()
{
    HIDE_BKG;
    bkg.camera_x = bkg.camera_y = 0;
    bkg.old_camera_x = bkg.camera_x;
    bkg.old_camera_y = bkg.camera_y;
    bkg.map_pos_x = (UBYTE)(bkg.camera_x >> 3u);
    bkg.map_pos_y = (UBYTE)(bkg.camera_y >> 3u);

    set_bkg_data_nonbanked(0, HOUSE_TILE_COUNT, HOUSE_TILE_DATA, (UINT8)&__bank_house_tiles);
    bkg.old_map_pos_x = bkg.old_map_pos_y = 255;
    bkg.camera_max_y = (HOUSE_MAP_HEIGHT - 18) * 8;
    bkg.camera_max_x = (HOUSE_MAP_WIDTH - 20) * 8;
    set_bkg_submap_nonbanked(bkg.map_pos_x, bkg.map_pos_y, 20, 18, HOUSE_MAP_DATA, HOUSE_MAP_WIDTH, (UINT8)&__bank_house_map);
    set_level(HOUSE_MAP_WIDTH, HOUSE_MAP_HEIGHT, HOUSE_MAP_DATA, (UINT8)&__bank_house_map);

    bkg.old_camera_x = bkg.camera_x;
    bkg.old_camera_y = bkg.camera_y;

    bkg.redraw = FALSE;

    bkg.camera_style = vertical_cam;

    SCX_REG = bkg.camera_x;
    SCY_REG = bkg.camera_y;
    SHOW_BKG;
}

#ifndef __MACROS_H__ //prevents the includes from being called twice
#define __MACROS_H__

#include <gb/gb.h>
#include "bigmap_map.h"
#include "bigmap_tiles.h"
#include "bigmap_map.h"
#include "bkg_apartment_scroll_map.h"
#include "bkg_apartment_scroll_tiles.h"
#include "maps/submap/submap.h"

#define MIN(A, B) ((A) < (B) ? (A) : (B))

void set_camera();

inline void set_level(UINT8, UINT8, const UINT8 *);

#endif
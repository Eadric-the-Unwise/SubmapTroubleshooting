REM Automatically generated from Makefile
del large_map.gb


@REM C:\c_code\gbdk\bin\lcc.exe -autobank -Wb-ext=.rel -Wb-v -Wl-yt0x1B -Wl-yo256 -Wl-ya4 -o large_map.gb large_map.c^
@REM  macros.c^
@REM  bigmap_map.c bigmap_tiles.c^
@REM   maps\house\house_map.c maps\house\house_tiles.c maps\house\house.c^
@REM    maps\submap\bkg_submap_map.c maps\submap\bkg_submap_tiles.c maps\submap\submap.c^
@REM     maps\house\cellar\cellar_map.c maps\house\cellar\cellar_tiles.c maps\house\cellar\cellar.c^
@REM      maps\house\cellar\cellar_lvl2\cellar_lvl2_map.c maps\house\cellar\cellar_lvl2\cellar_lvl2_tiles.c maps\house\cellar\cellar_lvl2\cellar_lvl2.c  



C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m  -c -o large_map.o large_map.c

C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\submap\submap.o maps\submap\submap.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\submap\submap_tiles.o maps\submap\submap_tiles.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\submap\submap_map.o maps\submap\submap_map.c

C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\house.o maps\house\house.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\house_tiles.o maps\house\house_tiles.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\house_map.o maps\house\house_map.c

C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\cellar\cellar.o maps\house\cellar\cellar.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\cellar\cellar_tiles.o maps\house\cellar\cellar_tiles.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\cellar\cellar_map.o maps\house\cellar\cellar_map.c

C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\cellar\cellar_lvl2\cellar_lvl2.o maps\house\cellar\cellar_lvl2\cellar_lvl2.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\cellar\cellar_lvl2\cellar_lvl2_tiles.o maps\house\cellar\cellar_lvl2\cellar_lvl2_tiles.c
C:\c_code\gbdk\bin\lcc.exe -Wa-l -Wl-m -c -o maps\house\cellar\cellar_lvl2\cellar_lvl2_map.o maps\house\cellar\cellar_lvl2\cellar_lvl2_map.c

C:\c_code\gbdk\bin\lcc.exe -autobank -Wb-ext=.rel -Wb-v -Wl-yt0x1B -Wl-yo256 -Wl-ya4 -o large_map.gb^
 maps\submap\submap.o maps\submap\submap_tiles.o maps\submap\submap_map.o^
  maps\house\house.o maps\house\house_map.o maps\house\house_tiles.o^
   maps\house\cellar\cellar.o maps\house\cellar\cellar_map.o maps\house\cellar\cellar_tiles.o^
    maps\house\cellar\cellar_lvl2\cellar_lvl2.o maps\house\cellar\cellar_lvl2\cellar_lvl2_tiles.o maps\house\cellar\cellar_lvl2\cellar_lvl2_map.o^
  

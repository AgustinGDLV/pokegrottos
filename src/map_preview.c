#include "global.h"
#include "map_preview.h"

static const u8 sMtMoonName[] = _("Cave"); 
static const u16 sMtMoonMapPreviewPalette[] = INCBIN_U16("graphics/map_preview/mt_moon/tiles.gbapal");
static const u32 sMtMoonMapPreviewTiles[] = INCBIN_U32("graphics/map_preview/mt_moon/tiles.4bpp.lz");
static const u32 sMtMoonMapPreviewTilemap[] = INCBIN_U32("graphics/map_preview/mt_moon/tilemap.bin.lz");

static const u8 sIcePathName[] = _("Ice Path"); 
static const u16 sIcePathMapPreviewPalette[] = INCBIN_U16("graphics/map_preview/ice_path/tiles.gbapal");
static const u32 sIcePathMapPreviewTiles[] = INCBIN_U32("graphics/map_preview/ice_path/tiles.4bpp.lz");
static const u32 sIcePathMapPreviewTilemap[] = INCBIN_U32("graphics/map_preview/ice_path/tilemap.bin.lz");

static const u8 sMtEmberName[] = _("Volcano"); 
static const u16 sMtEmberMapPreviewPalette[] = INCBIN_U16("graphics/map_preview/mt_ember/tiles.gbapal");
static const u32 sMtEmberMapPreviewTiles[] = INCBIN_U32("graphics/map_preview/mt_ember/tiles.4bpp.lz");
static const u32 sMtEmberMapPreviewTilemap[] = INCBIN_U32("graphics/map_preview/mt_ember/tilemap.bin.lz");

static const u8 sPowerPlantName[] = _("Power Plant");
static const u16 sPowerPlantMapPreviewPalette[] = INCBIN_U16("graphics/map_preview/power_plant/tiles.gbapal");
static const u32 sPowerPlantMapPreviewTiles[] = INCBIN_U32("graphics/map_preview/power_plant/tiles.4bpp.lz");
static const u32 sPowerPlantMapPreviewTilemap[] = INCBIN_U32("graphics/map_preview/power_plant/tilemap.bin.lz");

const struct MapPreview gMapPreviewData[PREVIEW_COUNT] =
{
    [PREVIEW_MT_MOON] = {
        .name = sMtMoonName,
        .palette = sMtMoonMapPreviewPalette,
        .tiles = sMtMoonMapPreviewTiles,
        .map = sMtMoonMapPreviewTilemap,
    },
    [PREVIEW_ICE_PATH] = {
        .name = sIcePathName,
        .palette = sIcePathMapPreviewPalette,
        .tiles = sIcePathMapPreviewTiles,
        .map = sIcePathMapPreviewTilemap,
    },
    [PREVIEW_MT_EMBER] = {
        .name = sMtEmberName,
        .palette = sMtEmberMapPreviewPalette,
        .tiles = sMtEmberMapPreviewTiles,
        .map = sMtEmberMapPreviewTilemap,
    },
    [PREVIEW_POWER_PLANT] = {
        .name = sPowerPlantName,
        .palette = sPowerPlantMapPreviewPalette,
        .tiles = sPowerPlantMapPreviewTiles,
        .map = sPowerPlantMapPreviewTilemap,
    },
};

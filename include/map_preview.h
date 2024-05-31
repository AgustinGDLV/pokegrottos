#ifndef GUARD_MAP_PREVIEW_H
#define GUARD_MAP_PREVIEW_H

enum {
    PREVIEW_MT_MOON,
    PREVIEW_ICE_PATH,
    PREVIEW_MT_EMBER,
    PREVIEW_POWER_PLANT,
    PREVIEW_COUNT,
};

struct MapPreview {
    const u8 * name;
    const u16 * palette;
    const u32 * tiles;
    const u32 * map;
};

extern const struct MapPreview gMapPreviewData[PREVIEW_COUNT];

#endif

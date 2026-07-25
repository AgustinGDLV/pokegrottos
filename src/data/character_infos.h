#include "graphics/mugshots.h"

const struct CharacterInfo gCharacterInfos[CHARACTERS_COUNT] = {

    [CHAR_SWIMMER] = {
        .name = COMPOUND_STRING("Swimmer"),
        .starters = {SPECIES_SLOWPOKE, SPECIES_KRABBY, SPECIES_WINGULL},
        .graphicsId = OBJ_EVENT_GFX_SWIMMER_M,
    },
    [CHAR_HIKER] = {
        .name = COMPOUND_STRING("Hiker"),
        .starters = {SPECIES_DIGLETT, SPECIES_ROGGENROLA, SPECIES_WHISMUR},
        .graphicsId = OBJ_EVENT_GFX_HIKER,
    },
    [CHAR_BUG_CATCHER] = {
        .name = COMPOUND_STRING("Bug Catcher"),
        .starters = {SPECIES_CATERPIE, SPECIES_KRICKETOT, SPECIES_LEDYBA},
        .graphicsId = OBJ_EVENT_GFX_BUG_CATCHER,
    },
    [CHAR_BREEDER] = {
        .name = COMPOUND_STRING("Breeder"),
        .starters = {SPECIES_MAREEP, SPECIES_SWINUB, SPECIES_BUDEW},
        .graphicsId = OBJ_EVENT_GFX_BREEDER,
    },
};

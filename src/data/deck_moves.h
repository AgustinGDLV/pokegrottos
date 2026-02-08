const struct DeckMoveInfo gDeckMovesInfo[MOVES_COUNT] =
{
    [MOVE_TACKLE] =
    {
        .name = COMPOUND_STRING("TACKLE"),
        .description = COMPOUND_STRING("Damages one opponent."),
        .power = 40,
        .target = TARGET_SINGLE_OPPONENT,
        .effect = DECK_EFFECT_HIT,
    },

    [MOVE_VINE_WHIP] =
    {
        .name = COMPOUND_STRING("VINE WHIP"),
        .description = COMPOUND_STRING("Damages one opponent."),
        .power = 60,
        .target = TARGET_SINGLE_OPPONENT,
        .effect = DECK_EFFECT_HIT,
    },

    [MOVE_HELPING_HAND] =
    {
        .name = COMPOUND_STRING("HELPING HAND"),
        .description = COMPOUND_STRING("Powers up right ally."),
        .power = 0,
        .target = TARGET_RIGHT_ALLY,
        .effect = DECK_EFFECT_POWER_UP,
    },

    [MOVE_SURF] =
    {
        .name = COMPOUND_STRING("SURF"),
        .description = COMPOUND_STRING("Damages all opponents."),
        .power = 60,
        .target = TARGET_ALL_OPPONENTS,
        .effect = DECK_EFFECT_HIT,
    },

    [MOVE_EARTHQUAKE] =
    {
        .name = COMPOUND_STRING("EARTHQUAKE"),
        .description = COMPOUND_STRING("Damages all opponents."),
        .power = 60,
        .target = TARGET_LEFT_ALLY | TARGET_RIGHT_ALLY | TARGET_ALL_OPPONENTS,
        .effect = DECK_EFFECT_HIT,
    },

    [MOVE_CRABHAMMER] =
    {
        .name = COMPOUND_STRING("CRABHAMMER"),
        .description = COMPOUND_STRING("Damages one opponent."),
        .power = 80,
        .target = TARGET_SINGLE_OPPONENT,
        .effect = DECK_EFFECT_HIT,
    },
};

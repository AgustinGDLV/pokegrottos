#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

#include "window.h"

void CB2_InitMainMenu(void);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);
void DrawMainMenuWindowBorder(const struct WindowTemplate *, u16);
void CreateDialogueWindowBorder(u8, u8, u8, u8, u8, u8);

#endif // GUARD_MAIN_MENU_H

/*
*   This file is part of Universal-Core-Example
*   Copyright (C) 2020 SuperSaiyajinStackie
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

// Screens.


#include "mainMenu.hpp"
#include "gameManagement.hpp"
#include "titleManagement.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include "gamecard.hpp"
#include "nand.hpp"
#include "sdmenuv2.hpp"



#include "msg.hpp"


#include <unistd.h>
#include <iostream>

extern bool touching(touchPosition touch, Structs::ButtonPos button);
extern bool exiting;




void MainMenu::Draw(void) const {
	
	GFX::DrawTop();
	GFX::DrawBetteryTop();
	
	Gui::DrawStringCentered(0, 2, 0.8f, WHITE, "D7-Menu", 400);




	



	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/
	


	
	


	GFX::DrawBottom();
	
	for (int i = 0; i < (int)this->MMButtons.size(); i++) {
		if (this->Selection == i) {
			Gui::Draw_Rect(this->MMButtons[i].x, this->MMButtons[i].y, this->MMButtons[i].w, this->MMButtons[i].h, C2D_Color32(0, 170, 170, 255));
		} else {
			Gui::Draw_Rect(this->MMButtons[i].x, this->MMButtons[i].y, this->MMButtons[i].w, this->MMButtons[i].h, C2D_Color32(0, 170, 100, 255));
		}
	}
	Gui::DrawStringCentered(0, MMButtons[0].y+10, 0.6f, WHITE, "SDCard");
	Gui::DrawStringCentered(0, MMButtons[1].y+10, 0.6f, WHITE, "GameCard");
	Gui::DrawStringCentered(0, MMButtons[2].y+10, 0.6f, WHITE, "???");


	Gui::DrawString(37, 214, 0.8f, WHITE, "Hold \uE046 to show controols!");
	// Draw Buttons. ;P

	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect

}


void MainMenu::Logic(u32 hDown, u32 hHeld, touchPosition touch) {



	if (hDown & KEY_START) {
		fadecolor = 0;
		fadeout = true;
		exiting = true;
	}
	if (hHeld & KEY_SELECT){
		GFX::DrawTopSP();
		Gui::DrawString(1, 30, 0.8f, WHITE, "\uE000: Start");
		Gui::DrawString(1, 60, 0.8f, WHITE, "\uE07B / \uE07C: Navigate");
		Gui::DrawString(1, 90, 0.8f, WHITE, "Press \uE045 to exit!");
		GFX::DrawBottomSP();
	}
	if (hDown & KEY_A) {
		if (this->Selection == 0) {
			Gui::setScreen(std::make_unique<SDMenu>(), true, false);
		} else if (this->Selection == 1) {
			Gui::setScreen(std::make_unique<gamecard>(), true, false);
		} else if (this->Selection == 2) {
                   
                        
                }
     
	}

	// Touch the button to enter example screen.
	if (hDown & KEY_TOUCH) {
		if (touching(touch, this->MMButtons[0])) {
			Gui::setScreen(std::make_unique<SDMenu>(), true, false);
		} else if (touching(touch, this->MMButtons[1])) {
			Gui::setScreen(std::make_unique<gamecard>(), true, false);
		} else if (touching(touch, this->MMButtons[2])) {
        
                }
	}
     //   if (hDown & KEY_L) {
      //  Screenshot_Capture();
      //  }
	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->MMButtons.size() - 1)	this->Selection++;
	}

	// Press Up to go one entry up.
	if (hDown & KEY_UP) {
		if (this->Selection > 0)	this->Selection--;
	}
	

	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	
}

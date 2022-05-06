
#include "sdmenuv2.hpp"
#include "mainMenu.hpp"
#include  "utils.hpp"


#define BOXES 15

//extern bool touching(touchPosition touch, Structs::ButtonPos button);
//extern bool exiting;

SDMenu::SDMenu() {
	
	maxTitles = (int)TitleManager::sdtitles.size();
}

void SDMenu::Draw(void) const {
	RenderD7::OnScreen(Top);
	RenderD7::DrawRect(0, 0, 400, 240, COOLWHITE);
	RenderD7::DrawRect(0, 0, 400, 30, COOLDARK);
	//RenderD7::DrawText(0, 2 , 0.8f, BLACK, timeStr());
	RenderD7::DrawTextCentered(0, 2, 0.8f, COOLWHITE, "D7-Menu -> SDMenu", 400);
    RenderD7::DrawRect(10, 50, 380, 100, C2D_Color32(130, 130, 130, 140));
	RenderD7::DrawRect(6, 46, 388, 108, C2D_Color32(180, 180, 180, 150));
	RenderD7::DrawTextCentered(0, 75, 0.7f, BLACK, TitleManager::sdtitles[Selection]->name());
	RenderD7::DrawTextCentered(0, 105, 0.7f, BLACK, TitleManager::sdtitles[Selection]->author());
	
    


	//if (fadealpha > 0) RenderD7::DrawRect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
	RenderD7::OnScreen(Bottom);
	RenderD7::DrawRect(0, 0, 320, 240, COOLWHITE);
	RenderD7::DrawRect(0, 0, 320, 30, COOLDARK);
	RenderD7::DrawText(2, 3, 0.8f, COOLWHITE, "Title: " + std::to_string(Selection + 1) + "/ " + std::to_string(maxTitles));
	//RenderD7::DrawText(3-RenderD7::GetStringWidth(0.8f, "Titles: " + std::to_string(Selection + 1) + " / " + std::to_string(maxTitles)), 3-RenderD7::GetStringHeight(0.8f, "Titles: " + std::to_string(Selection + 1) + " / " + std::to_string(maxTitles)), 0.8f, BLACK, "Titles: " + std::to_string(Selection + 1) + " / " + std::to_string(maxTitles));
	
	for(int i=0;i<BOXES && i<maxTitles;i++) {
		if(screenPos + i == Selection) {
			RenderD7::DrawRect(mainButtons[i].x-2, mainButtons[i].y-2, 52, 52, BLUE);
			C2D_DrawImageAt(TitleManager::sdtitles[screenPos+i]->icon(), mainButtons[i].x+0, mainButtons[i].y+0, 0.5f);
		}
	
		
		
		C2D_DrawImageAt(TitleManager::sdtitles[screenPos+i]->icon(), mainButtons[i].x+0, mainButtons[i].y+0, 0.5f); 
		// Installed Title Icon.
	}

	
	RenderD7::DrawText(37, 214, 0.8f, BLACK, "Hold \uE046 to show controols!");
		
		// Installed Title Icon.



	//if (fadealpha > 0) RenderD7::DrawRect(0, 0, 320, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
}


void SDMenu::Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) {
	// Press Start to exit the app.
	if (hDown & KEY_START) {
		/*fadecolor = 0;
		fadeout = true;
		exiting = true;*/
		RenderD7::ExitApp();
	}

	if (hHeld & KEY_SELECT) {

		
		RenderD7::OnScreen(Top);
		RenderD7::DrawText(1, 30, 0.8f, BLACK, "\uE000: Start");
		RenderD7::DrawText(1, 60, 0.8f, BLACK, "\uE006: Navigate");
		
		
		RenderD7::DrawText(1, 90, 0.8f, BLACK, "Press \uE002 to go to MainMenu");

		RenderD7::DrawText(1, 120, 0.8f, BLACK, "Press \uE045 to exit!");
        


    }
	if (hDown & KEY_X){
         
        RenderD7::Scene::Load(std::make_unique<MainMenu>());
	}

	// Press <A> on a Button to enter example screen.
	

        if (hDown & KEY_A) {
			if (!TitleManager::sdtitles.empty()) {
				u8 param[0x300];
				u8 hmac[0x20];
				memset(param, 0, sizeof(param));
				memset(hmac, 0, sizeof(hmac));
				APT_PrepareToDoApplicationJump(0, TitleManager::sdtitles[Selection]->ID(), MEDIATYPE_SD);
				APT_DoApplicationJump(param, sizeof(param), hmac);
			}
		}

	// Touch the button to enter example screen.
	

	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->maxTitles - 5)	this->Selection+= 5;
	}
        if (hDown & KEY_RIGHT) {
		if (this->Selection < (int)this->maxTitles - 1)	this->Selection++;
	}
        if (hDown & KEY_LEFT) {
		if (this->Selection > 0)	this->Selection--;
	}
	

	// Press Up to go one entry up.
	if (hDown & KEY_UP) {
		if (this->Selection > 4)	this->Selection-= 5;
	}
	if (hDown & KEY_R) {
		if (this->Selection < (int)this->maxTitles -8) this->Selection += 8;
	}
	if (hDown & KEY_L) {
		if (this->Selection > 7)     this->Selection -=8;
	}
		if(Selection < screenPos) {
		screenPos = Selection;
	} 
	if (Selection > screenPos + BOXES - 1) {
		screenPos = Selection - BOXES + 1;
	}
}
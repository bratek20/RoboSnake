/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
#include "s3e.h"
#include "Iw2D.h"
#include "Scene.h"
#include "MenuScene.h"
#include "memory"

#define FRAME_TIME (30.0f / 1000.0f)

//skopiowane z readme
//Sterowanie: Naciskaj¹c ekran (lewy przycisk myszy) i trzymaj¹c sprawiamy, ¿e Snake bêdzie pod¹zaæ w tym kierunku
//Gra ma domyslna rozdzielczosc 320x480.
//Aby Snake porusza³ siê ze sta³a prêdkoœci¹ trzeba zadbaæ aby ekran by³ zeskalowany w³aœnie w takich proporcjach!
int main()
{
	
    Iw2DInit();

	std::unique_ptr<Scene>currentScene(new MenuScene);
	
	while (!s3eDeviceCheckQuitRequest())
    {
		uint64 new_time = s3eTimerGetMs(); // wszystko co po angielsku skopiowowane z przykladowego projektu z jakiegos tutorialu

        s3ePointerUpdate();
		currentScene->update();

		if (currentScene->whatNextScene())// istnieje nastepna Scene, zmieniamy scene np menu -> gra
			currentScene = std::unique_ptr<Scene>(currentScene->whatNextScene()); //smart pointer dba o usuniecie wczesniejszej sceny

		Iw2DSurfaceClear(0);

		currentScene->draw();
        
		Iw2DSurfaceShow();
		
		int yield = (int)(FRAME_TIME * 1000 - (s3eTimerGetMs() - new_time));
		if (yield < 0)
			yield = 0;
		s3eDeviceYield(yield);
    }

	
	delete &Assets::instance();
	currentScene.reset();

	Iw2DTerminate();
    
    return 0;
}

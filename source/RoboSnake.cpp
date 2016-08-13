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
#include "Scena.h"
#include "ScenaMenu.h"
#include "memory"

#define FRAME_TIME (30.0f / 1000.0f)

int main()
{
	
    Iw2DInit();

	std::unique_ptr<Scena>aktualnaScena(new ScenaMenu);
	
	while (!s3eDeviceCheckQuitRequest())
    {
		uint64 new_time = s3eTimerGetMs(); // wszystko co po angielsku skopiowowane z przykladowego projektu z jakiegos tutorialu

        s3ePointerUpdate();
		aktualnaScena->uaktualnij();

		if (aktualnaScena->jakaNastepnaScena())// istnieje nastepna scena, zmieniamy scene np menu -> gra
			aktualnaScena = std::unique_ptr<Scena>(aktualnaScena->jakaNastepnaScena()); //smart pointer dba o usuniecie wczesniejszej sceny

		Iw2DSurfaceClear(0);

		aktualnaScena->rysuj();
        
		Iw2DSurfaceShow();
		
		int yield = (int)(FRAME_TIME * 1000 - (s3eTimerGetMs() - new_time));
		if (yield < 0)
			yield = 0;
		s3eDeviceYield(yield);
    }

	
	delete &Zasoby::instancja();
	aktualnaScena.reset();

	Iw2DTerminate();
    
    return 0;
}

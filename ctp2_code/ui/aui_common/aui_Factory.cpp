/// \file aui_Factory.cpp
/// \brief Factory for native aui_* Instance creation
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : Factory for native aui_* Instance creation
// Id           : $Id$
//
//----------------------------------------------------------------------------
//
// Disclaimer
//
// THIS FILE IS NOT GENERATED OR SUPPORTED BY ACTIVISION.
//
// This material has been developed at apolyton.net by the Apolyton CtP2
// Source Code Project. Contact the authors at ctp2source@apolyton.net.
//
//----------------------------------------------------------------------------
//
// Compiler flags
//
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
//----------------------------------------------------------------------------

#include "c3.h"
#include "aui_Factory.h"

#include "aui_directsurface.h"
#include "aui_directmouse.h"
#include "aui_directkeyboard.h"

#include "aui_sdlsurface.h"
#include "aui_sdlmouse.h"
#include "aui_sdlkeyboard.h"

#include "c3ui.h"   // C3UI

extern C3UI *   g_c3ui;

aui_Surface *
aui_Factory::new_Surface(AUI_ERRCODE &retval,
                         const sint32 &width,
                         const sint32 &height,
                         void *data,
                         const BOOL &isPrimary,
                         const BOOL &useVideoMemory,
                         const BOOL &takeOwnership
                        )
{
	aui_SDLSurface *surface = 0;

	surface = new aui_SDLSurface(&retval, width, height, g_c3ui->BitsPerPixel(), g_c3ui->DD(),
	                             isPrimary, useVideoMemory, takeOwnership);

	Assert( AUI_NEWOK(surface, retval) );

	return surface;
}

aui_Mouse *
aui_Factory::new_Mouse(AUI_ERRCODE  &retval,
                       const MBCHAR *ldlBlock,
                       const BOOL   &useExclusiveMode
                      )
{
	aui_SDLMouse *mouse = new aui_SDLMouse(&retval, ldlBlock, useExclusiveMode);

	Assert( AUI_NEWOK(mouse, retval) );

	return mouse;
}

aui_Keyboard *
aui_Factory::new_Keyboard(AUI_ERRCODE &retval)
{

	aui_SDLKeyboard *keyboard = new aui_SDLKeyboard(&retval);

	Assert( AUI_NEWOK(keyboard, retval) );

	return keyboard;
}

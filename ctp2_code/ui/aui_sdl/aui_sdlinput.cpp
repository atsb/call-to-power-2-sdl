#include "ctp2_config.h"
#include "c3.h"

#include "aui_sdlinput.h"

aui_SDLInput::aui_SDLInput(AUI_ERRCODE *retval, BOOL useExclusiveMode)
{
}

aui_SDLInput::~aui_SDLInput()
{
}

AUI_ERRCODE aui_SDLInput::InitCommon(BOOL useExclusiveMode)
{
	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLInput::Acquire()
{
	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLInput::Unacquire()
{
	return AUI_ERRCODE_OK;
}

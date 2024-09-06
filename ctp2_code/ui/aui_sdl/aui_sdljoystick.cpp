#include "ctp2_config.h"
#include "c3.h"

#include "aui_sdljoystick.h"

aui_SDLJoystick::aui_SDLJoystick(AUI_ERRCODE *retval,
                                 uint32 lMin,
                                 uint32 lMax)
{
	m_lMin = lMin;
	m_lMax = lMax;
}

aui_SDLJoystick::~aui_SDLJoystick()
{
}

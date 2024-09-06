//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : Music
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
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - Standardised min/max usage.
//
//----------------------------------------------------------------------------

#include "c3.h"

#include "aui_music.h"


aui_Music::aui_Music() :
m_first_track(-1),
m_last_track(-1),
m_ntracks(-1),
m_ctrack(-1),
m_volume(0xff),
m_pause(FALSE)
{
}

aui_Music::~aui_Music()
{
	m_first_track = -1;
	m_last_track = -1;
	m_ntracks = -1;
	m_ctrack = -1;
	m_volume = 0xff;
	m_pause = FALSE;
}

AUI_MUSIC_ERRCODE
aui_Music::SetVolume( uint8 volume )
{
	m_volume = volume;
	return AUI_MUSIC_ERRCODE_OK;
}

//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : General declarations
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
// _DEBUGTOOLS
// - Provides debug tools (leak reporter, asserts, ...)
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// None
//
//----------------------------------------------------------------------------

#include "c3.h"

#ifdef _MSC_VER
#pragma hdrstop
#endif

#ifndef _WIN32
#include <unistd.h>
#include <time.h>

uint32_t GetTickCount64(void) {
    struct timespec ts;
    unsigned theTick = 0U;
    clock_gettime( CLOCK_REALTIME, &ts );
    theTick  = ts.tv_nsec / 1000000;
    theTick += ts.tv_sec * 1000;
    return theTick;
}
#endif


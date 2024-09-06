//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  :
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
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - added linux specific code
//
//----------------------------------------------------------------------------
#include "c3.h"
#include "netconsole.h"
#include "c3cmdline.h"
#if defined(WIN32)
#include <winsock.h>
#elif defined(LINUX)
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#endif
#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

static int s_winsockInitialized = 0;

#define k_MAX_SOCK_READ 2048

NetConsole *g_netConsole = NULL;

void netconsole_Initialize()
{
	if(!g_netConsole)
		g_netConsole = new NetConsole(9999);
}

void netconsole_Cleanup()
{
	if(g_netConsole) {
		delete g_netConsole;
		g_netConsole = NULL;
	}
}
#if defined(WIN32)
static void initWinsock()
{

}

static void cleanupWinsock()
{

}
#endif

NetConsole::NetConsole(uint16 port)
{

}

NetConsole::~NetConsole()
{
	
}

void NetConsole::Idle()
{

}

void NetConsole::Print(const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	Print(fmt, vl);
	va_end(vl);
}

void NetConsole::Print(const char *fmt, va_list vl)
{

}

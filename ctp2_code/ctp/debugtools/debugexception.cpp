#include "c3.h"
#include "debugexception.h"

#ifdef _DEBUG

#include "debugassert.h"
#include "debugcallstack.h"
#include "breakpoint.h"
#include "log.h"

#if defined(WIN32)
#include <windows.h>
#endif

struct DebugException
{
	DebugAssertClientFunction DebugException_Enter;
};

static DebugException debug_exception = {0};

void DebugException_Open (DebugExceptionClientFunction function_enter)
{
	debug_exception.DebugException_Enter = function_enter;
}

void DebugException_Close (void)
{
}

void DebugException_Execute (DebugExceptionClientFunction function_monitored)
{

}
#endif

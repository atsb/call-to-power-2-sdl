#ifdef HAVE_PRAGMA_ONCE
#pragma once
#endif

#ifndef BREAKPOINT_H
#define BREAKPOINT_H

#ifdef _DEBUG

#ifdef __cplusplus
extern "C" {
#endif

#include <csignal>
#define Breakpoint()  std::raise(SIGINT);

#ifdef __cplusplus
}
#endif

#endif // _DEBUG

#endif // BREAKPOINT_H

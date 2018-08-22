#define VC_EXTRALEAN		

#include <afxwin.h>     
#include <afxext.h>     

#ifndef CPING_NO_WINSOCK2
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <winsock.h>
#endif

#include <afxpriv.h>
#include <afxtempl.h>
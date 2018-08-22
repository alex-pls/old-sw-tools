

#ifdef __BUILDING_THE_DLL

#define __EXPORT_TYPE __export
	#else
	#define __EXPORT_TYPE __import
	#endif

#ifndef _MYDLL_H
#define _MYDLL_H


extern "C" SysInfo* __declspec(dllexport) WINAPI YourFunctionNumberOne();

SysInfo LocalOS;

#endif




#ifdef __BUILDING_THE_DLL

#define __EXPORT_TYPE __export
	#else
	#define __EXPORT_TYPE __import
	#endif

#ifndef _MYDLL_H
#define _MYDLL_H

// __declspec(dllexport)void f(void);
//void __EXPORT_TYPE SayHello();

HINSTANCE MyInstance;



extern "C" void __declspec(dllexport) WINAPI YourFunctionNumberOne();

class __declspec(dllexport) YourClassNumberOne
{ 
 private: 
	 int MemberOne; 
 public: 
	 static int MemberTwo; 
         int FunctionGetMemberOne (); 
}; 




extern "C" void __declspec(dllexport) WINAPI InitializeSocket();

#endif


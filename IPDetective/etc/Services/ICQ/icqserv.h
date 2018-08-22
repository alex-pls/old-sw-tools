

#ifndef _MYDLL_H
#define _MYDLL_H

//extern "C" __declspec(dllimport)
//        void


extern "C" void __declspec(dllexport) WINAPI YourFunctionNumberOne();

class __declspec(dllexport) YourClassNumberOne 
{ 
 private: 
	 int MemberOne; 
 public: 
	 static int MemberTwo; 
         int FunctionGetMemberOne (); 
}; 




#endif


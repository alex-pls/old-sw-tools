// IPCTraceMacros.h: include file IPCTraceMacros.
//

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#if (defined _DEBUG || defined _IPCRELEASETRACE)
#define IPCTRACE(message)                                       \
{                                                               \
	HWND hReceiver = ::FindWindow(NULL, _T("IPCTrace"));          \
	if (hReceiver)                                                \
	{                                                             \
		COPYDATASTRUCT cds;                                         \
		ZeroMemory(&cds, sizeof(COPYDATASTRUCT));                   \
		cds.dwData = 0x00031337;                                    \
		cds.cbData = _tcslen(message) + sizeof(TCHAR);              \
		cds.lpData = message;                                       \
		::SendMessage(hReceiver, WM_COPYDATA, NULL, (LPARAM) &cds); \
	}                                                             \
}
#else // defined _DEBUG || defined _IPCRELEASETRACE
#define IPCTRACE (void(0))
#endif // !_DEBUG
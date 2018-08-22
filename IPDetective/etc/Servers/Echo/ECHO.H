
#include "wsa_xtra.h"
#include <windows.h>
#include <windowsx.h>
//#include <ver.h>
#include <winsock.h>
//#include "resource.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <dos.h>
#include <direct.h>
#include "winsockx.h"

/*-------------- global data -------------*/
char szAppName[] = "as_echo";

SOCKET hLstnSock=INVALID_SOCKET; /* Listening socket */
SOCKADDR_IN stLclName;           /* Local address and port number */
char szHostName[MAXHOSTNAME]={0};/* Local host name */
int  iActiveConns;               /* Number of active connections */
long lByteCount;                 /* Total bytes read */
int  iTotalConns;                /* Connections closed so far */

typedef struct stConnData {
  SOCKET hSock;                  /* Connection socket */
  SOCKADDR_IN stRmtName;         /* Remote host address & port */
  LONG lStartTime;               /* Time of connect */
  BOOL bReadPending;             /* Deferred read flag */
  int  iBytesRcvd;               /* Data currently buffered */             
  int  iBytesSent;               /* Data sent from buffer */
  long lByteCount;               /* Total bytes received */
  char achIOBuf  [INPUT_SIZE];   /* Network I/O data buffer */
  struct stConnData FAR*lpstNext;/* Pointer to next record */
} CONNDATA, *PCONNDATA, FAR *LPCONNDATA;
LPCONNDATA lpstSockHead = 0;     /* Head of the list */

class EchoSocket
 {
protected:
    LPCONNDATA lpstSock;             /* Work Pointer */
    WORD WSAEvent, WSAErr;
    SOCKADDR_IN stRmtName;
    SOCKET hSock;
//    BOOL bRet = FALSE;
    int nRet, cbRcvd, cbSent;
    HINSTANCE hinstance;

        SOCKET AcceptConn(SOCKET, PSOCKADDR_IN);
        int SendData(SOCKET, LPSTR, int);
        int RecvData(SOCKET, LPSTR, int);
        int CloseConn(SOCKET, LPSTR, int, HWND);
        void DoStats (long, long, LPCONNDATA);
        LPCONNDATA NewConn (SOCKET, PSOCKADDR_IN);
        LPCONNDATA FindConn (SOCKET);
        void RemoveConn (LPCONNDATA);
        bool InitLstnSock(int iLstnPort, PSOCKADDR_IN pstSockName, HWND hWnd, u_int nAsyncMsg);

public:
        EchoSocket(HINSTANCE hinstance);
        ~EchoSocket();
        int AcceptConnections();

 };

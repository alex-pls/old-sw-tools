# Microsoft Visual C++ generated build script - Do not modify

PROJ = AS_ECHO
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = .
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = AS_ECHO.C   
FIRSTCPP =             
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W3 /Zi /AM /Od /D "_DEBUG" /FR /GA /Fd"AS_ECHO.PDB"
CFLAGS_R_WEXE = /nologo /W4 /AL /O1 /D "NDEBUG" /FR /GA 
LFLAGS_D_WEXE = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:61440 /CO /ALIGN:16 /STACK:10240
LFLAGS_R_WEXE = /NOLOGO /ONERROR:NOEXE /NOD /PACKC:61440 /ALIGN:16 /STACK:10240
LIBS_D_WEXE = oldnames libw commdlg shell olecli olesvr mlibcew
LIBS_R_WEXE = oldnames libw commdlg shell olecli olesvr llibcew
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = AS_ECHO.DEF
OBJS_EXT = 
LIBS_EXT = ..\WINSOCKX.LIB ..\WINSOCK.LIB 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = AS_ECHO.SBR

AS_ECHO_DEP = ..\wsa_xtra.h \
	..\winsockx.h


AS_ECHO_RCDEP = as_echo.h \
	as_echo.ico


WINSOCKX_DEP = 

WINSOCK_DEP = 

all:	$(PROJ).EXE $(PROJ).BSC

AS_ECHO.OBJ:	AS_ECHO.C $(AS_ECHO_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c AS_ECHO.C

AS_ECHO.RES:	AS_ECHO.RC $(AS_ECHO_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r AS_ECHO.RC


$(PROJ).EXE::	AS_ECHO.RES

$(PROJ).EXE::	AS_ECHO.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
AS_ECHO.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
..\WINSOCKX.LIB+
..\WINSOCK.LIB+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) AS_ECHO.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	AS_ECHO.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) AS_ECHO.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)
clean: 
       del *.exe
       del *.obj
       del *.res
       del *.pdb
       del *.sbr

$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<

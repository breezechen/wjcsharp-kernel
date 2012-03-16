Console App
TestCon
Console application
[*BEGINPRO*]
[*BEGINDEF*]
[MakeDef]
Menu=0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
1=
2=0,O,$B\dmc.exe -mn -c -p -I"$I" -C -WA -o"$3" -o+space,2
3=5,O,$B\link.exe /NOLOGO /SUBSYSTEM:CONSOLE /EXETYPE:NT "$3"|"$5"
4=0,0,$D\RunStub,5
5=
6=*.obj,O,$B\dmc.exe -mn -c -p -I"$I" -C -WA -o"$3" -o+space,*.c
7=0,0,"$E\OllyDbg",5
[MakeFiles]
0=TestCon.rap
1=TestCon.rc
2=TestCon.c
3=TestCon.obj
4=TestCon.res
5=TestCon.exe
6=TestCon.def
7=TestCon.dll
8=TestCon.txt
9=TestCon.lib
10=TestCon.mak
11=TestCon.cpp
12=TestCon.com
13=TestCon.ocx
14=TestCon.idl
15=TestCon.tlb
[Resource]
[StringTable]
[Accel]
[VerInf]
FV=0.0.0.1
FileVersion=0.0.0.1
PV=0.0.0.1
ProductVersion=0.0.0.1
[Group]
Group=Added files,Assembly,Resources,Misc,Modules
1=2
2=2
3=1
[*ENDDEF*]
[*BEGINTXT*]
TestCon.c
#include <stdio.h>
#include <windows.h>
#include "TestCon.h"
int main(void)
{
static TCHAR szText[]=TEXT("HelloWin");

	printf("%s\n",szText);
	return 0;
}
[*ENDTXT*]
[*BEGINTXT*]
TestCon.h
[*ENDTXT*]
[*ENDPRO*]

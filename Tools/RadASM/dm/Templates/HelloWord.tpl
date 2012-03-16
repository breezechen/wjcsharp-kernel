Console App
Console
A simple "Hello World!" program.
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
0=Console.rap
1=Console.rc
2=Console.c
3=Console.obj
4=Console.res
5=Console.exe
6=Console.def
7=Console.dll
8=Console.txt
9=Console.lib
10=Console.mak
11=Console.cpp
12=Console.com
13=Console.ocx
14=Console.idl
15=Console.tlb
[Resource]
[StringTable]
[Accel]
[Group]
Group=Added files,Assembly,Resources,Misc,Modules
1=2
2=2
3=1
[*ENDDEF*]
[*BEGINTXT*]
Console.c
#include <stdio.h>
int main(void)
{
	printf("Hello World");
	return 0;
}
[*ENDTXT*]
[*BEGINTXT*]
Console.h
[*ENDTXT*]
[*ENDPRO*]

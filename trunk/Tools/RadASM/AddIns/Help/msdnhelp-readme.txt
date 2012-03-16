MsdnHelp v2.0 (msdnhelp.dll) - by Qweerdy

Usage: Just extract everything to the \RadASM\AddIns folder. The source files and other files
       you don't really need are in two separate folders.

This addin is meant as a replacement for the RadASM help function. It allows multiple helpfiles
to be grouped under the help key (F1). RadASM.ini flags can be found at the top of MsdnHelp.asm

 Supporting files:
-----------------------------------------------------------------------------------------------
\RadASM\AddIns\SetPaths.exe	Utility to change the help file paths.

\RadASM\AddIns\help.mdb		Database containing the keywords and paths for the
				various help files. In most cases, it will be easier to use
				one of the replacement databases listed below.

 Optional files:
-----------------------------------------------------------------------------------------------
MsdnOnline.exe			Set this file as the helpfile for windows API functions and it
				will take you to the right MSDN online page when you press F1.
				It may take a while for it to open a browser window because in
				the background it is first loading the search results page.
				Note that this has not been tested as thoroughly as MsdnHelp.

win32.hlp help.mdb		This help.mdb should be used when you use Win32.hlp as your
				main API reference. Don't forget to set the correct path!

Msdn help.mdb			Use this help.mdb when you use MSDN or the PlatSDK as your main
				API reference. 


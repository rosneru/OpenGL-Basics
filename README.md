# How to build in Visual Studio

## Install Visual Studio

Ensure to select the *Desktop Development with C++* workload also.

Can be done after the main Visual Studio installation with the Visual 
Studio installer. There click on *Modify* and select that workload.

## Install OpenGL Headers, Libs etc for target platform

You find the files on [that](https://www.opengl.org/resources/libraries/glut/glut_downloads.php) page.

From there pick the file [glutdlls37beta.zip](https://www.opengl.org/resources/libraries/glut/glutdlls37beta.zip)

The contents of this file must copied to several places of the 
Windows/Visual Studio installation:

Copy **glut.h** file in:

    C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\include\gl

Copy **glut.lib** in:

    C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\lib\64

Copy **glut32.lib** in:

    C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\lib\86

Copy **glut.dll** and **glut32.dll** in:

    C:\Windows\SysWOW64

Copy **glut32.dll** to:

    C:\Windows\System32 


Then you should be able to compile and link the solution with Visual Studio.

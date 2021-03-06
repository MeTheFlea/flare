#Description
This will eventually be a 3D component-based game engine using OpenGL 3.3+.

#Build Instructions
##Prerequisites
- OpenGL 3.3+
- [GLFW 3.1.1](http://www.glfw.org/)
- [Premake 5](https://github.com/premake/premake-core/wiki)

##Building
1. Place the GLFW 3.1.1 libs inside `extern/lib/[Debug/Release]`.
	- There are also precompiled Win32 libs inside `dependencies/win32precompiled.zip`.

2. Run `premake5` with the appropriate action depending on what you want to compile the project with.
	- So for example, running `premake5 vs2012` will generate a Visual Studio 2012 .sln file inside `_project/vs2012` which you can then open and compile as usual. Other options include `gmake` and `vs2013`. Please refer to the [this](https://github.com/premake/premake-core/wiki/Using_Premake) for more build options.

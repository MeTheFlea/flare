solution( "flare" )
	location( "_project/%{_ACTION}" )
	configurations{ "Debug", "OptimisedDebug", "Release" }

project( "flare" )
	kind( "ConsoleApp" )
	language( "C++" )
	targetdir( "bin/%{cfg.buildcfg}" )
	debugdir( "_project/.." )

	files{ "src/**.cpp", "src/**.h", "include/flare/**.h" }
	vpaths{ 
		["*"] = "src",
	}
	vpaths{ 
		["*"] = "include/flare",
	}

	includedirs{ "%{_WORKING_DIR}/extern/include", "include/flare" }


	links{ "glfw3" }
	flags{ "ExtraWarnings" }

	filter{ "system:windows" }
		defines{ "_WINDOWS" }
		links{ "opengl32" }
	filter{ "system:linux" }
		defines{ "_LINUX" }
		links{ "GL", "GLU", "X11", "Xxf86vm", "Xrandr", "pthread", "Xi", "Xinerama", "Xcursor" }
		buildoptions{ "-std=c++11" }

	
	filter{ "configurations:Debug" }
		defines{ "_DEBUG" }
		flags{ "Symbols" }
		debugenvs{ "PATH=%PATH%;extern/dll/Debug" }
		libdirs{ "extern/lib/Debug" }
	filter{ "configurations:Debug", "system:windows" }
		--links{ "glew32d", "assimpd" }


	filter{ "configurations:OptimisedDebug" }
		flags{ "Symbols" }

	filter{ "configurations:OptimisedDebug or Release" }
		defines{ "_NDEBUG" }
		flags{ "OptimizeSpeed" }
		libdirs{ "extern/lib/Release" }
		
	filter{ "configurations:OptimisedDebug or Release", "system:windows" }
		debugenvs{ "PATH=%PATH%;extern/dll/Release" }
		

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


	filter{ "system:windows" }
		defines{ "_WINDOWS" }
	filter{ "system:linux" }
		defines{ "_LINUX" }

	
	filter{ "configurations:Debug" }
		defines{ "_DEBUG" }
		flags{ "Symbols" }
		debugenvs{ "PATH=%PATH%;extern/dll/Debug" }
		libdirs{ "extern/lib/Debug" }
		links{ "glfw3", "opengl32" }
	filter{ "configurations:Debug", "system:windows" }
		--links{ "glew32d", "assimpd" }


	filter{ "configurations:OptimisedDebug" }
		flags{ "Symbols" }

	filter{ "configurations:OptimisedDebug or Release" }
		defines{ "_NDEBUG" }
		flags{ "OptimizeSpeed" }
		libdirs{ "extern/lib/Release" }
		links{ "glfw3", "opengl32" }
	filter{ "configurations:OptimisedDebug or Release", "system:windows" }
		debugenvs{ "PATH=%PATH%;extern/dll/Release" }
		

solution "libini"
    language "C++"

    configurations {"debug", "release"}

    configuration "debug"
        flags "Symbols"

    includedirs "include"

    buildoptions "-std=c++1y"

    project "ini"
        kind "StaticLib"

        files "src/**.cpp"

    project "test"
        kind "ConsoleApp"

        files "tests/main.cpp"

        links "ini"

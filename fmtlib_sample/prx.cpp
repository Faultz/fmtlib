#include <stdio.h>
#include <stdarg.h>

#include "fmt/format.h"

// We need to provide an export to force the expected stub library to be generated
__declspec (dllexport) void dummy()
{
}


extern "C"
{
	int __cdecl module_start(size_t argc, const void* args)
	{
		fmt::print("Hello, World!\n");
		fmt::print("The answer is {}\n", 42);

		// show me a example of usage
		fmt::print("The answer is {0} or {0:x} or {0:b}\n", 42);

		// show me a example of usage

		return 0;
	}

	int __cdecl module_stop(size_t argc, const void* args)
	{
		return 0;
	}
}
#include <stdio.h>
#include <stdarg.h>

#include "fmt/format.h"
#include "fmt/ostream.h"
#include "fmt/printf.h"
#include "fmt/color.h"
#include "fmt/os.h"

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

		// use a file
		auto f = fmt::output_file("/data/test.txt");
		f.print("The answer is {}\n", 42);

		// use a file
		auto f2 = fmt::output_file("/data/test2.txt");
		f2.print("The answer is {0} or {0:x} or {0:b}\n", 42);

		// use color
		fmt::print(fg(fmt::color::pink) | fmt::emphasis::bold, "The answer is {0} or {0:x} or {0:b}\n", 42);

		auto now = std::chrono::system_clock::now();
		fmt::print("Date and time: {}\n", now);
		fmt::print("Time: {:%H:%M}\n", now);

		return 0;
	}

	int __cdecl module_stop(size_t argc, const void* args)
	{
		return 0;
	}
}
// tutorial.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <lua.hpp>

#include <conio.h>

using namespace std;

int main()
{
	lua_State *L;
	L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, "luascript.lua")) {
		cerr << "Something went wrong loading the lua script file <luascript.lua>" << endl;
		cerr << lua_tostring(L, -1) << endl;
		lua_pop(L, 1);
	}

	printf("Press any key to continue\n");
	_getch();
	return 0;
}

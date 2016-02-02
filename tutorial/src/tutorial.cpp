// tutorial.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <lua.hpp>

#include <conio.h>
#include "config.h"

using namespace std;


Config g_config;

int main()
{
	ConfigNode *configRoot = g_config.getRoot();
	configRoot->set("key1", false);
	configRoot->set("key2", 12);
	configRoot->set("key3", 3.1415f);
	configRoot->set("key4", "This is a string");
	configRoot->set("key5", false);
	configRoot->set("key6", new ConfigNode());

	configRoot->set("key1", true);
	configRoot->set("key2", 5150);
	configRoot->set("key3", 9.f);
	configRoot->set("key4", "Here lies Davey Jones!");
	configRoot->set("key5", true);

	lua_State *L;
	L = luaL_newstate();
	luaL_openlibs(L);
	 
	if (luaL_loadfile(L, "scripts\\config.lua")) {
		cerr << "Something went wrong loading the lua script file <luascript.lua>" << endl;
		cerr << lua_tostring(L, -1) << endl;
		lua_pop(L, 1);
	}

	lua_close(L);

	printf("Press any key to continue\n");
	_getch();
	return 0;
}

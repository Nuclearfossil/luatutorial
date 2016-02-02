// tutorial.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <lua.hpp>

#include <conio.h>
#include <map>

using namespace std;

class ConfigNode
{
public:
	ConfigNode() :
		m_nodeType(NODE_UNDEF),
		m_booleanValue(false),
		m_integerValue(0),
		m_floatValue(0.0f),
		m_stringValue(nullptr)
	{}

	ConfigNode(const char* key, bool value) : 
		m_nodeType(NODE_BOOL),
		m_booleanValue(value)
	{}

	ConfigNode(const char* key, int value) : 
		m_nodeType(NODE_INT),
		m_integerValue(value)
	{}

	ConfigNode(const char* key, float value) :
		m_nodeType(NODE_FLOAT),
		m_floatValue(value)
	{}

	ConfigNode(const char* key, const char* value) :
		m_nodeType(NODE_FLOAT)
	{
		size_t length = strlen(value)+1;
		m_stringValue = new char[length];
		strcpy_s(m_stringValue, length, value);
	}

	enum NodeType
	{
		NODE_UNDEF = 0,
		NODE_BOOL,
		NODE_INT,
		NODE_FLOAT,
		NODE_STRING,
		NODE_GROUP,
		NODE_MAX
	};

	NodeType m_nodeType;

	~ConfigNode() 
	{
		for (std::map<const char*, ConfigNode*>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
		{
			delete (*it).second;
		}
		m_nodes.clear();

		delete[] m_stringValue;
	}

	bool m_booleanValue;
	int m_integerValue;
	float m_floatValue;
	char* m_stringValue;

	template<typename T>
	ConfigNode* set(const char* key, T value)
	{
		ConfigNode* result = nullptr;
		std::map<const char*, ConfigNode*>::iterator it = m_nodes.find(key);

		if (it != m_nodes.end())
		{
			result = (*it).second;
			result->set(key, value);
		}
		else
		{
			result = new ConfigNode(key, value);
			m_nodes[key] = result;
		}

		return result;
	}

	ConfigNode* set(const char* key, ConfigNode* value)
	{
		ConfigNode* result = nullptr;
		std::map<const char*, ConfigNode*>::iterator it = m_nodes.find(key);
		if (it != m_nodes.end())
		{
			result = (*it).second;
			result->set(key, value);
		}
		else
		{
			m_nodes[key] = value;
			m_nodes[key]->m_nodeType = NODE_GROUP;
			result = m_nodes[key];			
		}
		return result;
	}
private:
	map<const char*, ConfigNode*> m_nodes;
};

class Config
{
public:
	Config() {}
	~Config() {}

	ConfigNode* getRoot()
	{
		return &m_root;
	}

private:
	ConfigNode m_root;
};

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

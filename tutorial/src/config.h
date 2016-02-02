#pragma once
#include <map>

class ConfigNode
{
public:
	ConfigNode();

	ConfigNode(const char* key, bool value);

	ConfigNode(const char* key, int value);

	ConfigNode(const char* key, float value);

	ConfigNode(const char* key, const char* value);

	~ConfigNode();

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

	ConfigNode* set(const char* key, ConfigNode* value);

private:
	std::map<const char*, ConfigNode*> m_nodes;
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

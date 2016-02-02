#include "config.h"

ConfigNode::ConfigNode() :
	m_nodeType(NODE_UNDEF),
	m_booleanValue(false),
	m_integerValue(0),
	m_floatValue(0.0f),
	m_stringValue(nullptr)
{}

ConfigNode::ConfigNode(const char* key, bool value) :
	m_nodeType(NODE_BOOL),
	m_booleanValue(value)
{}

ConfigNode::ConfigNode(const char* key, int value) :
	m_nodeType(NODE_INT),
	m_integerValue(value)
{}

ConfigNode::ConfigNode(const char* key, float value) :
	m_nodeType(NODE_FLOAT),
	m_floatValue(value)
{}

ConfigNode::ConfigNode(const char* key, const char* value) :
	m_nodeType(NODE_FLOAT)
{
	size_t length = strlen(value) + 1;
	m_stringValue = new char[length];
	strcpy_s(m_stringValue, length, value);
}

ConfigNode::~ConfigNode()
{
	for (std::map<const char*, ConfigNode*>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
	{
		delete (*it).second;
	}
	m_nodes.clear();

	delete[] m_stringValue;
}

ConfigNode* ConfigNode::set(const char* key, ConfigNode* value)
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

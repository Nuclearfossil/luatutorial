#include "config.h"

#if defined(__APPLE_CC__)
#include "string.h"
#endif

unsigned int safe_strcpy(char* dst, size_t length, const char* value)
{
	unsigned int result = 0;
#if defined(__APPLE_CC__)
	result = strlcpy(dst, value, length);
#else
	result = strcpy_s(dst, length, value);
#endif
	return result;	
}

ConfigNode::ConfigNode() :
	m_nodeType(NODE_UNDEF),
	m_booleanValue(false),
	m_integerValue(0),
	m_floatValue(0.0f),
	m_stringValue(nullptr)
{}

ConfigNode::ConfigNode(const char* key, bool value) :
	m_nodeType(NODE_BOOL),
	m_booleanValue(value),
	m_stringValue(nullptr)
{}

ConfigNode::ConfigNode(const char* key, int value) :
	m_nodeType(NODE_INT),
	m_integerValue(value),
	m_stringValue(nullptr)

{}

ConfigNode::ConfigNode(const char* key, float value) :
	m_nodeType(NODE_FLOAT),
	m_floatValue(value),
	m_stringValue(nullptr)

{}

ConfigNode::ConfigNode(const char* key, const char* value) :
	m_nodeType(NODE_FLOAT)
{
	size_t length = strlen(value) + 1;
	m_stringValue = new char[length];
	safe_strcpy(m_stringValue, length, value);
}

ConfigNode::~ConfigNode()
{
	for (std::map<const char*, ConfigNode*>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it)
	{
		delete (*it).second;
	}
	m_nodes.clear();

	delete[] m_stringValue;
	m_stringValue = nullptr;
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

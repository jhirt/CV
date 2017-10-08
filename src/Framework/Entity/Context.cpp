#include "Context.h"

#include <iostream>
#include <QString>

namespace Framework
{
	Context::Context()
	{
		sprintf(m_controller, "default");
		sprintf(m_guid, "00000000-0000-0000-0000-000000000000");
		sprintf(m_prop, "default");
		sprintf(m_value, "default");
	}

	Context::Context(char controller[30], char guid[128], char prop[30], char value[256])
	{
		setController(controller);
		setGuid(guid);
		setProp(prop);
		setValue(value);
	}

	void Context::setController(char controller[30])
	{
		sprintf(m_controller, controller);
	}

	void Context::setGuid(char guid[128])
	{
		sprintf(m_guid, guid);
	}

	void Context::setProp(char prop[30])
	{
		sprintf(m_prop, prop);
	}

	void Context::setValue(char value[256])
	{
		sprintf(m_value, value);
	}

}
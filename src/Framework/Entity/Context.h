#ifndef CONTEXT
#define CONTEXT

namespace Framework
{
	class Context
	{
	public:
		Context();
		Context(char controller[30], char guid[128], char prop[30], char value[30]);

		void setController(char controller[30]);
		void setGuid(char guid[128]);
		void setProp(char prop[30]);
		void setValue(char value[256]);

		char* controller() { return m_controller; }
		char* guid() { return m_guid; }
		char* prop() { return m_prop; }
		char* value() { return m_value; }

	protected:
		char m_controller[30];
		char m_guid[128];
		char m_prop[30];
		char m_value[256];
	};
}
#endif //CONTEXT

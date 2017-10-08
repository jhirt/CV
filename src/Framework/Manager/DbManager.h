#ifndef DB_MANAGER
#define DB_MANAGER

namespace Framework
{
	class DbManager
	{
	public:
		DbManager() {};

	protected:
		virtual bool Connection()=0;
	};
}
#endif //DB_MANAGER

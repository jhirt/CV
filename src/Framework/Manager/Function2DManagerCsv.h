#ifndef FUNCTION_2D_MANAGER_CSV
#define FUNCTION_2D_MANAGER_CSV

#include "..\Entity\Function2D.h"

namespace Framework
{
	class Function2DManagerCsv //: public FunctionManager
	{
	public:
		Function2DManagerCsv();

		void Read(QString path);
		Function2D& F() {return m_function2D;}

	protected:
		Function2D m_function2D;
	};
}
#endif //FUNCTION_2D_MANAGER_CSV

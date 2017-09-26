#ifndef FUNCTION
#define FUNCTION

#include <QtCore\QList>
#include <QtCore\QPointF>

namespace Framework
{
	class Function2D
	{
	public:
		Function2D();
		Function2D(QList<QPointF>);

		void append(QPointF point);

		void clear();
		int size() { return m_functionSamples.size(); }
		double xMin() { return m_xMin; }
		double xMax() { return m_xMax; }
		double yMin() { return m_yMin; }
		double yMax() { return m_yMax; }
		QPointF& operator[](int id);

	protected:
		QList<QPointF> m_functionSamples;
		double m_xMin;
		double m_xMax;
		double m_yMin;
		double m_yMax;
	};
}
#endif //FUNCTION

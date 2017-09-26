#include "Function2D.h"

namespace Framework
{
	Function2D::Function2D()
	{
		m_xMin = 0;
		m_xMax = 0;
		m_yMin = 0;
		m_yMax = 0;
	}

	Function2D::Function2D(QList<QPointF> pointList)
	{
		for (int i = 0; i < pointList.size(); i++)
		{
			m_functionSamples.append(pointList[i]);

			if (pointList[i].x() < m_xMin)
				m_xMin = pointList[i].x();
			if (pointList[i].x() > m_xMax)
				m_xMax = pointList[i].x();

			if (pointList[i].y() < m_yMin)
				m_yMin = pointList[i].y();
			if (pointList[i].y() > m_yMax)
				m_yMax = pointList[i].y();
		}
	}

	void Function2D::append(QPointF point)
	{ 
		m_functionSamples.append(point); 

		if (point.x() < m_xMin)
			m_xMin = point.x();
		if (point.x() > m_xMax)
			m_xMax = point.x();

		if (point.y() < m_yMin)
			m_yMin = point.y();
		if (point.y() > m_yMax)
			m_yMax = point.y();
	}

	void Function2D::clear()
	{
		m_functionSamples.clear();
		m_xMin = 0;
		m_xMax = 0;
		m_yMin = 0;
		m_yMax = 0;
	}

	QPointF& Function2D::operator[](int id)
	{
		if (id >= 0 && id < m_functionSamples.size())
			return m_functionSamples[id];
		else
			throw("Invalid index");
	}
}
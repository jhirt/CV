#include "Function2DManagerCsv.h"

#include <QtCore\QFile>
#include <QtCore\QTextCodec>
#include <QtCore\QRegExp>

namespace Framework
{
	Function2DManagerCsv::Function2DManagerCsv()
	{

	}

	void Function2DManagerCsv::Read(QString path)
	{
		QString fileName = path.mid(path.lastIndexOf("\\"), -1);

		//.csv check ?
		QFile file(path);
		if (!file.exists())
			throw QString("CSV function file doesn't exist, check path: %1").arg(path);

		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			throw QString("Can't open CSV function file %1, check access rights").arg(fileName);

		m_function2D.clear();
		while (!file.atEnd())
		{
			QByteArray dataLine = file.readLine();
			QString line(dataLine);
			//QString line = QTextCodec::codecForMib(1015)->toUnicode(dataLine);

			line.remove("\n");
			QStringList coordinates = line.split(",");
			if (coordinates.size() < 2)
			{
				m_function2D.clear();
				throw QString("CSV file inconsistent, some lines propose less than 2 coordinates");
			}
			else
			{
				//QRegExp rx("^\d+$");
				QRegExp rx("^[0-9]+(.[0-9]+)?$");
				if (rx.exactMatch(coordinates[0]) && rx.exactMatch(coordinates[1]))
				{
					m_function2D.append(QPointF(coordinates[0].toDouble(), coordinates[1].toDouble()));
				}
				else
				{
					m_function2D.clear();
					throw QString("CSV file inconsistent, some lines coordinates are not numerical");
				}
			}
		}
	}
}
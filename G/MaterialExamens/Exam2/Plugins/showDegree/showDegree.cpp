#include "showDegree.h"
#include "glwidget.h"

void ShowDegree::onPluginLoad()
{
    degree = 0;
	vector<Face> faces = scene()->objects()[0].faces();
    int n = faces.size();
    for (int i = 0; i < n; ++i)
    {
        degree += faces[i].numVertices();
    }

    degree /= scene()->objects()[0].vertices().size();
}

void ShowDegree::preFrame()
{
	
}

void ShowDegree::postFrame()
{
  QFont font;
  font.setPixelSize(16);
  painter.begin(glwidget());
  painter.setFont(font);
  int x = 15;
  int y = 40;
  painter.drawText(x, y, QString("%1").arg(degree));
  painter.end();
}

void ShowDegree::onObjectAdd()
{
	
}

bool ShowDegree::drawScene()
{
	return false; // return true only if implemented
}

bool ShowDegree::drawObject(int)
{
	return false; // return true only if implemented
}

bool ShowDegree::paintGL()
{
	return false; // return true only if implemented
}

void ShowDegree::keyPressEvent(QKeyEvent *)
{
	
}

void ShowDegree::mouseMoveEvent(QMouseEvent *)
{
	
}


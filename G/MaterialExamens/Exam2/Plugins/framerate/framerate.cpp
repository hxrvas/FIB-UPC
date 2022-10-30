#include "framerate.h"
#include "glwidget.h"

void Framerate::onPluginLoad()
{
	
}

void Framerate::preFrame()
{
	elapsedTimer.start();
}

void Framerate::postFrame()
{
	cout << (1./elapsedTimer.nsecsElapsed())*1000000000 << endl;
}

void Framerate::onObjectAdd()
{
	
}

bool Framerate::drawScene()
{
	return false; // return true only if implemented
}

bool Framerate::drawObject(int)
{
	return false; // return true only if implemented
}

bool Framerate::paintGL()
{
	return false; // return true only if implemented
}

void Framerate::keyPressEvent(QKeyEvent *)
{
	
}

void Framerate::mouseMoveEvent(QMouseEvent *)
{


}


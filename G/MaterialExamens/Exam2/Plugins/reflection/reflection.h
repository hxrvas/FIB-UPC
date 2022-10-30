#ifndef _REFLECTION_H
#define _REFLECTION_H

#include "plugin.h"
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QElapsedTimer>

class S3_ex6_reflection: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin")
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void drawQuad(const Point& p0, const Point& p1, const Point& p2, const Point& p3);
	 bool paintGL();

  private:
	QOpenGLShaderProgram* program;
    QOpenGLShader* vs;
    QOpenGLShader* fs;
    GLuint textureId;
};

#endif


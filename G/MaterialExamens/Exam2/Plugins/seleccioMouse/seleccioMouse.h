#ifndef _SELECCIOMOUSE_H
#define _SELECCIOMOUSE_H

#include "plugin.h" 
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>

class SeleccioMouse: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:

	 void onPluginLoad();
	 void postFrame();

	 void onObjectAdd();
	 bool drawScene();
	 bool drawObject(int);

	 bool paintGL();

	 void keyPressEvent(QKeyEvent * event);
	 void mouseReleaseEvent(QMouseEvent * e);
  private:
      GLuint VAO_box;
      QOpenGLShaderProgram* program;
      QOpenGLShader* vs;
      QOpenGLShader* fs;
      void encodeID(unsigned int i, GLubyte *color);
      int decodeID(const GLubyte *color);
};

#endif








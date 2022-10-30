#ifndef _SELECCIOOBJECTE_H
#define _SELECCIOOBJECTE_H

#include "plugin.h" 
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>

class SeleccioObjecte: public QObject, public Plugin
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
	 void mouseMoveEvent(QMouseEvent *);
  private:
      GLuint VAO_box;
      QOpenGLShaderProgram* program;
      QOpenGLShader* vs;
      QOpenGLShader* fs;
};

#endif


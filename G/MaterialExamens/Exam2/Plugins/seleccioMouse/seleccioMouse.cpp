#include "seleccioMouse.h"
#include "glwidget.h"

void SeleccioMouse::onPluginLoad()
{
    GLWidget &g = *glwidget();
    g.makeCurrent();

        // Create & bind empty VAO
    g.glGenVertexArrays(1, &VAO_box);
    g.glBindVertexArray(VAO_box);

    // Create VBO with (x,y,z) coordinates
    float coords[] = {
        1, 1, 1,
        0, 1, 1,
        1, 0, 1,
        0, 0, 1,
        1, 0, 0,
        0, 0, 0,
        1, 1, 0,
        0, 1, 0,
        1, 1, 1,
        0, 1, 1,
        0, 1, 1,
        0, 1, 0,
        0, 0, 1,
        0, 0, 0,
        1, 0, 1,
        1, 0, 0,
        1, 1, 1,
        1, 1, 0
    };

    GLuint VBO_coords;
    g.glGenBuffers(1, &VBO_coords);
    g.glBindBuffer(GL_ARRAY_BUFFER, VBO_coords);
    g.glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);
    g.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    g.glEnableVertexAttribArray(0);
    g.glBindVertexArray(0);

    // Carregar shader, compile & link
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile(glwidget()->getPluginPath()+"/../seleccioMouse/seleccioMouse.vert");
    //cout << "vs" << endl;

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile(glwidget()->getPluginPath()+"/../seleccioMouse/seleccioMouse.frag");
    //cout << "fs" << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    if (!program->isLinked()) cout << "Shader link error" << endl;
}

void SeleccioMouse::postFrame()
{

}

void SeleccioMouse::onObjectAdd()
{
	
}

bool SeleccioMouse::drawScene()
{
	return false; // return true only if implemented
}

bool SeleccioMouse::drawObject(int)
{
	return false; // return true only if implemented
}

bool SeleccioMouse::paintGL()
{
	return false; // return true only if implemented
}

void SeleccioMouse::keyPressEvent(QKeyEvent * event)
{

}

void SeleccioMouse::mouseReleaseEvent(QMouseEvent * e)
{
    GLWidget &g = *glwidget();
    g.makeCurrent();

	if ((e->button() == Qt::LeftButton) && (e->modifiers() == (Qt::ShiftModifier)))
    {
        g.glClearColor(1,1,1,1);
        g.glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        program->bind();
        QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
        program->setUniformValue("modelViewProjectionMatrix", MVP);

        // per cada objecte
        for (unsigned int i=0; i<scene()->objects().size(); ++i)
        {
            GLubyte color[4];
            encodeID(i, &color[0]); // trieu la conversió que volgueu
            program->setUniformValue("color", QVector4D(color[0]/255.0,
            color[1]/255., color[2]/255., 1.0));
            drawPlugin()->drawObject(i);
        }
        program->release();
        int x = e->x();
        int y = glwidget()->height() - e->y();
        GLubyte read[4];
        glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, read);
        scene()->setSelectedObject(decodeID(&read[0]));
        cout << scene()->selectedObject() << endl;
    }
    g.update();
}

void SeleccioMouse::encodeID(unsigned int i, GLubyte* color) {
    color[0]=color[1]=color[2]=i;
}

int SeleccioMouse::decodeID(const GLubyte* color) {
  if (color[0]==255) return -1;
  return color[0];
}



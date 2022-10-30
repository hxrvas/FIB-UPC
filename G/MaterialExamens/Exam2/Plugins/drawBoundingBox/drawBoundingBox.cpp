#include "drawBoundingBox.h"
#include "glwidget.h"

void DrawBoundingBox::onPluginLoad()
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
    vs->compileSourceFile(glwidget()->getPluginPath()+"/../drawBoundingBox/drawBoundingBox.vert");
    //cout << "vs" << endl;

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile(glwidget()->getPluginPath()+"/../drawBoundingBox/drawBoundingBox.frag");
    //cout << "fs" << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    if (!program->isLinked()) cout << "Shader link error" << endl;
}

void DrawBoundingBox::postFrame()
{

    GLWidget &g = *glwidget();
    g.makeCurrent();

    // bind shader and define uniforms
    program->bind();
    QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();

    program->setUniformValue("modelViewProjectionMatrix", MVP);

    vector<Object> objects = scene()->objects();

    for (int i = 0; i < objects.size(); ++i) {
        objects[i].computeBoundingBox();
        Point min = objects[i].boundingBox().min();
        Point max = objects[i].boundingBox().max();

        QVector3D translate = QVector3D((max.x()+min.x())/2.0, min.y(), (max.z()+min.z())/2.0);
        program->setUniformValue("translate", translate);

        QVector3D scale = QVector3D((max.x()-min.x()), (max.y()-min.y()), (max.z()-min.z()));
        program->setUniformValue("scale", scale);

        g.glBindVertexArray(VAO_box);
        g.glDrawArrays(GL_TRIANGLE_STRIP, 0, 18);
        g.glBindVertexArray(0);
    }
}

void DrawBoundingBox::onObjectAdd()
{
	
}

bool DrawBoundingBox::drawScene()
{
	return false; // return true only if implemented
}

bool DrawBoundingBox::drawObject(int)
{
	return false; // return true only if implemented
}

bool DrawBoundingBox::paintGL()
{
	return false; // return true only if implemented
}

void DrawBoundingBox::keyPressEvent(QKeyEvent *)
{
	
}

void DrawBoundingBox::mouseMoveEvent(QMouseEvent *)
{
	
}


#include "seleccioObjecte.h"
#include "glwidget.h"

void SeleccioObjecte::onPluginLoad()
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
    vs->compileSourceFile(glwidget()->getPluginPath()+"/../seleccioObjecte/seleccioObjecte.vert");
    //cout << "vs" << endl;

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile(glwidget()->getPluginPath()+"/../seleccioObjecte/seleccioObjecte.frag");
    //cout << "fs" << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    if (!program->isLinked()) cout << "Shader link error" << endl;
}

void SeleccioObjecte::postFrame()
{

    GLWidget &g = *glwidget();
    g.makeCurrent();

    // bind shader and define uniforms
    program->bind();
    QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();

    program->setUniformValue("modelViewProjectionMatrix", MVP);

    vector<Object> objects = scene()->objects();

    int seleccionat = scene()->selectedObject();
    if (seleccionat != -1)  {
        objects[seleccionat].computeBoundingBox();
        Point min = objects[seleccionat].boundingBox().min();
        Point max = objects[seleccionat].boundingBox().max();

        QVector3D translate = QVector3D((max.x()+min.x())/2.0, min.y(), (max.z()+min.z())/2.0);
        program->setUniformValue("translate", translate);

        QVector3D scale = QVector3D((max.x()-min.x()), (max.y()-min.y()), (max.z()-min.z()));
        program->setUniformValue("scale", scale);

        g.glBindVertexArray(VAO_box);
        g.glDrawArrays(GL_LINE_STRIP, 0, 18);
        g.glBindVertexArray(0);
    }´
}

void SeleccioObjecte::onObjectAdd()
{
	
}

bool SeleccioObjecte::drawScene()
{
	return false; // return true only if implemented
}

bool SeleccioObjecte::drawObject(int)
{
	return false; // return true only if implemented
}

bool SeleccioObjecte::paintGL()
{
	return false; // return true only if implemented
}

void SeleccioObjecte::keyPressEvent(QKeyEvent * event)
{
    GLWidget &g = *glwidget();
    g.makeCurrent();

    if (event->key() == Qt::Key_0 ) {
        if (scene()->objects().size() > 0) {
            scene()->setSelectedObject(0);
        }
        else scene()->setSelectedObject(-1);
    }
	else if (event->key() == Qt::Key_1 ) {
                if (scene()->objects().size() > 1) {
            scene()->setSelectedObject(1);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_2 ) {
                if (scene()->objects().size() > 2) {
            scene()->setSelectedObject(2);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_3 ) {
                if (scene()->objects().size() > 3) {
            scene()->setSelectedObject(3);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_4 ) {
                if (scene()->objects().size() > 4) {
            scene()->setSelectedObject(4);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_5 ) {
                if (scene()->objects().size() > 5) {
            scene()->setSelectedObject(5);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_6 ) {
                if (scene()->objects().size() > 6) {
            scene()->setSelectedObject(6);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_7 ) {
                if (scene()->objects().size() > 7) {
            scene()->setSelectedObject(7);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_8 ) {
                if (scene()->objects().size() > 8) {
            scene()->setSelectedObject(8);
        }
        else scene()->setSelectedObject(-1);
    }
    else if (event->key() == Qt::Key_9 ) {
                if (scene()->objects().size() > 9) {
            scene()->setSelectedObject(9);
        }
        else scene()->setSelectedObject(-1);
    }

    g.update();
}

void SeleccioObjecte::mouseMoveEvent(QMouseEvent *)
{
	
}


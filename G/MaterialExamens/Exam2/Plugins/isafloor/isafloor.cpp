#include "isafloor.h"
#include "glwidget.h"

void Isafloor::onPluginLoad()
{
	vector<Face> faces = scene()->objects()[0].faces();
    float totalArea = 0;
    float floorArea = 0;
    for (int i = 0; i < faces.size(); ++i)
    {
        Vector normal = faces[i].normal();
        float area = normal.length()/2.;
        Vector u = Vector(0,0,1);
        float c = Vector::dotProduct(normal.normalized(), u);
        if (c > 0.7) floorArea += area;
        totalArea += area;
    }
    prop = floorArea/totalArea;

        // Carregar shader, compile & link
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile(glwidget()->getPluginPath()+"/../isafloor/isafloor.vert");
    //cout << "vs" << endl;

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile(glwidget()->getPluginPath()+"/../isafloor/isafloor.frag");
    //cout << "fs" << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    if (!program->isLinked()) cout << "Shader link error" << endl;
}

void Isafloor::preFrame()
{
	program->bind();
    QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	QMatrix3x3 MV = camera()->viewMatrix().normalMatrix();
    program->setUniformValue("modelViewProjectionMatrix", MVP);
	program->setUniformValue("normalMatrix", MV);
    program->setUniformValue("lambda", prop);
}

void Isafloor::postFrame()
{
	
}

void Isafloor::onObjectAdd()
{
	
}

bool Isafloor::drawScene()
{
	return false; // return true only if implemented
}

bool Isafloor::drawObject(int)
{
	return false; // return true only if implemented
}

bool Isafloor::paintGL()
{
	return false; // return true only if implemented
}

void Isafloor::keyPressEvent(QKeyEvent *)
{
	
}

void Isafloor::mouseMoveEvent(QMouseEvent *)
{
	
}


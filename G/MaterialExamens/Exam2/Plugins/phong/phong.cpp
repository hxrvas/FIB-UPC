#include "phong.h"
#include "glwidget.h"

void Phong::onPluginLoad()
{
	   // Carregar shader, compile & link
    QString vs_src =
	"#version 330 core\n"

"layout (location = 0) in vec3 vertex;"
"layout (location = 1) in vec3 normal;"
"layout (location = 2) in vec3 color;"

"out vec3 N;"
"out vec3 P;"

"uniform mat4 modelViewProjectionMatrix;"
"uniform mat4 modelViewMatrix;"
"uniform mat3 normalMatrix;"


"void main() {"
  "P=(modelViewMatrix*vec4(vertex.xyz, 1)).xyz;"
  "N=normalize(normalMatrix*normal);"
  "gl_Position = modelViewProjectionMatrix*vec4(vertex, 1);"
"}";
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceCode(vs_src);
    cout << "VS log:" << vs->log().toStdString() << endl;

    QString fs_src =
"#version 330 core\n"

"uniform vec4 lightAmbient;"
"uniform vec4 lightDiffuse;"
"uniform vec4 lightSpecular;"
"uniform vec4 lightPosition;"

"uniform vec4 matAmbient;"
"uniform vec4 matDiffuse;"
"uniform vec4 matSpecular;"
"uniform float matShininess;"

"in vec3 N;"
"in vec3 P;"
"out vec4 fragColor;"

"vec4 light(vec3 N, vec3 V, vec3 L) {"
  "N=normalize(N);"
  "V=normalize(V);"
  "L=normalize(L);"
  "vec3 R=normalize(2*dot(N, L)*N-L);"
  "float NdotL=max(0, dot(N, L));"
  "float RdotV=max(0, dot(R, V));"
  "float ldiff=NdotL;"
  "float lspec=0;"
  "if (NdotL>0) lspec=pow(RdotV, matShininess);"
  "return matAmbient*lightAmbient + matDiffuse*lightDiffuse*ldiff + matSpecular*lightSpecular*lspec;"
"}"

"void main() {"
  "vec3 L=lightPosition.xyz-P;"
  "vec3 V=-P;"
  "fragColor=light(N, V, L);"
"}";

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceCode(fs_src);
    cout << "FS log:" << fs->log().toStdString() << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    cout << "Link log:" << program->log().toStdString() << endl;
}

void Phong::preFrame()
{
    if (program && program->isLinked()) {
	 // bind shader and define uniforms
    program->bind();
    QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	QMatrix4x4 MV = camera()->viewMatrix();
    program->setUniformValue("modelViewProjectionMatrix", MVP);
	program->setUniformValue("modelViewMatrix", MV);
    program->setUniformValue("normalMatrix", camera()->viewMatrix().normalMatrix());
    program->setUniformValue("lightAmbient", QVector4D(Vector(0.1,0.1,0.1),1));
    program->setUniformValue("lightDiffuse", QVector4D(Vector(1,1,1),1));
    program->setUniformValue("lightSpecular", QVector4D(Vector(1,1,1),1));
    program->setUniformValue("lightPosition", QVector4D(0,0,0,1));
    //materialAmbient = Vector(0.8, 0.8, 0.6);
    //materialDiffuse = Vector(0.8, 0.8, 0.6);
    //materialSpecular = Vector(1.0, 1.0, 1.0);
    //materialShininess = 64.0;
    program->setUniformValue("matAmbient", QVector4D(Vector(0.8, 0.8, 0.6),1));
    program->setUniformValue("matDiffuse", QVector4D(Vector(0.8, 0.8, 0.6),1));
    program->setUniformValue("matSpecular", QVector4D(Vector(1.0, 1.0, 1.0),1));
    program->setUniformValue("matShininess", GLfloat(64.0));
    }
}

void Phong::postFrame()
{
	// unbind shader
    program->release();
}

void Phong::onObjectAdd()
{
	
}

bool Phong::drawScene()
{
	return false; // return true only if implemented
}

bool Phong::drawObject(int)
{
	return false; // return true only if implemented
}

bool Phong::paintGL()
{
	return false; // return true only if implemented
}

void Phong::keyPressEvent(QKeyEvent *)
{
	
}

void Phong::mouseMoveEvent(QMouseEvent *)
{
	
}


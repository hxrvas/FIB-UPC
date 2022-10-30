// GLarena, a plugin based platform to teach OpenGL programming
// © Copyright 2012-2018, ViRVIG Research Group, UPC, https://www.virvig.eu
// 
// This file is part of GLarena
//
// GLarena is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "AnimateVertices.h"

void AnimateVertices::onPluginLoad()
{
    // Carregar shader, compile & link 
    QString vs_src =
	"#version 330 core\n"

	"layout (location = 0) in vec3 vertex;"
	"layout (location = 1) in vec3 normal;"
	"layout (location = 2) in vec3 color;"
	"layout (location = 3) in vec2 texCoord;"

	"out vec4 frontColor;"
	"out vec2 vtexCoord;"

	"uniform mat4 modelViewProjectionMatrix;"
	"uniform mat4 modelViewMatrix;"
	
	"uniform float time;"

	"mat3 normalMatrix = mat3(transpose(inverse(modelViewMatrix)));"
	"const float PI = 3.141592;"

	"uniform float amplitude = 0.1;"
	"uniform float freq = 1;"

	"void main()"
	"{"
	    "vec3 N = normalize(normalMatrix * normal);"
	    "frontColor = vec4(1, 1, 1, 1.0) * N.z;"
	    "vtexCoord = texCoord;"
	    "vec3 d = normal * amplitude * sin(2 * PI * freq * time);"
	    "gl_Position = modelViewProjectionMatrix * vec4(vertex+d, 1.0);"
	"}";
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceCode(vs_src);
    cout << "VS log:" << vs->log().toStdString() << endl;

    QString fs_src =
	"#version 330 core\n"

	"in vec4 frontColor;"
	"out vec4 fragColor;"

	"void main()"
	"{"
	    "fragColor = frontColor;"
	"}";

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceCode(fs_src);
    cout << "FS log:" << fs->log().toStdString() << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    cout << "Link log:" << program->log().toStdString() << endl;

	elapsedTimer.start();
  // keep repainting
	/*
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), glwidget(), SLOT(updateGL()));
  timer->start();
	*/
}

void AnimateVertices::preFrame() 
{
    // bind shader and define uniforms
    program->bind();
    QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	QMatrix4x4 MV = camera()->viewMatrix();
    program->setUniformValue("modelViewProjectionMatrix", MVP); 
	program->setUniformValue("modelViewMatrix", MV);
	program->setUniformValue("time", float(elapsedTimer.elapsed()/1000.0f));
}

void AnimateVertices::postFrame() 
{
    // unbind shader
    program->release();
}


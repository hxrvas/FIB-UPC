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

#include "ModelInfo1.h"
#include "glwidget.h"

void ModelInfo1::calculateNumbers()
{
	numObj = scene()->objects().size();	
	
	numVert = 0;
	numPoly = 0;
	int numTri = 0;
	for(int i = 0; i < numObj; ++i)
	{
		vector<Face> facesi = scene()->objects()[i].faces();
		numPoly += facesi.size();
		int numi = facesi.size();
			for (int j = 0; j < numi; ++j)
			{
				if 	(facesi[j].numVertices() == 3) ++numTri;
			}
		numVert +=  scene()->objects()[i].vertices().size();
	}
	percT = (numTri/float(numPoly))*100;
}


void ModelInfo1::onPluginLoad()
{
	calculateNumbers();
}

void ModelInfo1::onObjectAdd()
{
	calculateNumbers();
}

void ModelInfo1::onSceneClear()
{
	calculateNumbers();
}

void ModelInfo1::postFrame() 
{
  QFont font;
  font.setPixelSize(16);
  painter.begin(glwidget());
  painter.setFont(font);
  int x = 15;
  int y = 40;
  painter.drawText(x, y, QString("Num Obj = %1"
				 "  NumVertex = %2" "  NumPoligons = %3" "  PercTriangles = %4").arg(numObj).arg(numVert).arg(numPoly).arg(percT));
  painter.end();
}

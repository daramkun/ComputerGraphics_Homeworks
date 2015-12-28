//
//  MyLigting.h
//  MyGL
//
//  Created by jinjae-yeon on 2014. 12. 2..
//  Copyright (c) 2014년 DARAM WORLD. All rights reserved.
//

#ifndef __MyGL__MyLigting__
#define __MyGL__MyLigting__

#include "MyMatrix.h"

namespace daram {
	enum LightProperty
	{
		LightProperty_Ambient,
		LightProperty_Diffuse,
		LightProperty_Specular,
		LightProperty_Position,
	};
	
	struct Vertex
	{
		Vector3 position;
		Vector3 normal;
	};
	
	void mySetStreamSource ( Vertex * vertices, int length );
	
	void myLightEnable ( int id, bool enable );
	void mySetLight ( int id, LightProperty prop, float * coef );
	
	Vector4 * myLigting ( int id );
}

#endif /* defined(__MyGL__MyLigting__) */

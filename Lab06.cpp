//
//  main.cpp
//  MatrixLib
//
//  Created by 진재연 on 2014. 10. 15..
//  Copyright (c) 2014년 DARAM WORLD. All rights reserved.
//

#include <iostream>
#include "Lab06/MyMatrix.h"
#include "Lab06/MyLigting.h"

int main(int argc, const char * argv[])
{	
	daram::Vertex vertices [ 12 ] = {
		{ daram::Vector3 ( -2.0f, 0.0f, -2.0f ), daram::Vector3 ( 0.0f, 0.707f, -0.707f ) },
		{ daram::Vector3 (  0.0f, 1.0f,  0.0f ), daram::Vector3 ( 0.0f, 0.707f, -0.707f ) },
		{ daram::Vector3 (  2.0f, 0.0f, -2.0f ), daram::Vector3 ( 0.0f, 0.707f, -0.707f ) },
		
		{ daram::Vector3 ( -2.0f, 0.0f,  2.0f ), daram::Vector3 ( -0.707f, 0.707f, 0.0f ) },
		{ daram::Vector3 (  0.0f, 2.0f,  0.0f ), daram::Vector3 ( -0.707f, 0.707f, 0.0f ) },
		{ daram::Vector3 ( -2.0f, 0.0f, -2.0f ), daram::Vector3 ( -0.707f, 0.707f, 0.0f ) },
		
		{ daram::Vector3 ( 2.0f, 0.0f, -2.0f ), daram::Vector3 ( 0.707f, 0.707f, 0.0f ) },
		{ daram::Vector3 ( 0.0f, 2.0f,  0.0f ), daram::Vector3 ( 0.707f, 0.707f, 0.0f ) },
		{ daram::Vector3 ( 2.0f, 0.0f,  2.0f ), daram::Vector3 ( 0.707f, 0.707f, 0.0f ) },
		
		{ daram::Vector3 (  2.0f, 0.0f, 2.0f ), daram::Vector3 ( 0.0f, 0.707f, 0.707f ) },
		{ daram::Vector3 (  0.0f, 2.0f, 0.0f ), daram::Vector3 ( 0.0f, 0.707f, 0.707f ) },
		{ daram::Vector3 ( -2.0f, 0.0f, 2.0f ), daram::Vector3 ( 0.0f, 0.707f, 0.707f ) },
	};
	daram::mySetStreamSource(vertices, 8);
	
	daram::myLightEnable(0, true);
	
	float pos [] = { 12, 5, 0 };
	daram::mySetLight ( 0, daram::LightProperty_Position, pos );
	float amb [] = { 1, 1, 1, 0.6f };
	daram::mySetLight ( 0, daram::LightProperty_Ambient, amb );
	float dif [] = { 1, 1, 1, 1 };
	daram::mySetLight ( 0, daram::LightProperty_Diffuse, dif );
	float spe [] = { 1, 1, 1, 0.3f };
	daram::mySetLight ( 0, daram::LightProperty_Specular, spe );
	
	daram::Vector4 * result = daram::myLigting(0);
	for ( int i = 0; i < 12; ++i )
		printf( "R: %d, G: %d, B: %d, A: %d\n", (int)(result [ i ].x * 255), (int)(result [ i ].y * 255), (int)(result [ i ].z * 255), (int)(result [ i ].w * 255) );
	
    return 0;
}

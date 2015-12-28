//
//  MyLigting.cpp
//  MyGL
//
//  Created by jinjae-yeon on 2014. 12. 2..
//  Copyright (c) 2014년 DARAM WORLD. All rights reserved.
//

#include "MyLigting.h"

#include <cstring>
#include <cmath>

daram::Vector4 arrToVec4 ( float * arr ) { return daram::Vector4 ( arr [ 0 ], arr [ 1 ], arr [ 2 ], arr [ 3 ] ); }
daram::Vector3 arrToVec3 ( float * arr ) { return daram::Vector3 ( arr [ 0 ], arr [ 1 ], arr [ 2 ] ); }
float saturate ( float x ) { return ( x > 0 ) ? ( ( x < 1 ) ? x : 1 ) : 0; }

daram::Vertex vertices [ 16 ];

void daram::mySetStreamSource ( daram::Vertex * _vertices, int length )
{
	memcpy(vertices, _vertices, sizeof(daram::Vertex) * length);
}

struct _Light
{
	bool isEnabled;
	daram::Vector4 ambient;
	daram::Vector4 diffuse;
	daram::Vector4 specular;
	daram::Vector3 position;
} lights [ 8 ];

daram::Vector4 resultColor [ 16 ];

void daram::myLightEnable ( int id, bool enable )
{
	lights [ id ].isEnabled = enable;
}

void daram::mySetLight ( int id, daram::LightProperty prop, float * coef )
{
	_Light * light = &lights [ id ];
	switch (prop) {
		case LightProperty_Ambient: light->ambient = arrToVec4(coef); break;
		case LightProperty_Diffuse: light->diffuse = arrToVec4 ( coef ); break;
		case LightProperty_Specular: light->specular = arrToVec4 ( coef ); break;
		case LightProperty_Position: light->position = arrToVec3(coef); break;
			
		default: break;
	}
}

daram::Vector4 * daram::myLigting ( int id )
{
	if ( !lights [ id ].isEnabled )
		return nullptr;
	
	for ( int i = 0; i < 16; ++i )
	{
		daram::Vector3 viewDir = daram::Vector3( 5, 5, 0 ) - vertices [ i ].position;
		daram::Vector3 lightDir = ( lights [ id ].position - vertices [ i ].position ) / 15;
		float ldDot = lightDir.dot ( lightDir );
		float attenuetion = saturate ( 1.0f - ldDot );
		
		daram::Vector3 n = vertices [ i ].normal.normalize ();
		daram::Vector3 l = lightDir.normalize ();
		daram::Vector3 v = viewDir.normalize ();
		daram::Vector3 h = ( l + v ).normalize ();
		
		float nDotL = saturate ( n.dot ( l ) );
		float nDotH = saturate ( n.dot ( h ) );
		float power = ( nDotL == 0.0f ) ? 0.0f : pow ( nDotH, 1 );
		
		resultColor [ i ] = ( lights [ id ].ambient * attenuetion +
			( lights [ id ].diffuse * nDotL * attenuetion ) +
			( lights [ id ].specular * power * attenuetion ) );
	}
	
	return resultColor;
}
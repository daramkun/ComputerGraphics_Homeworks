//
//  main.cpp
//  MatrixLib
//
//  Created by 진재연 on 2014. 10. 15..
//  Copyright (c) 2014년 DARAM WORLD. All rights reserved.
//

#include <iostream>
#include "Lab04/MyMatrix.h"

int main(int argc, const char * argv[])
{
	daram::mySetMatrixMode ( daram::MatrixMode::MatrixMode_ModelView );
	daram::myLoadIdentity ();
	std::cout << "-- MatrixMode - ModelView, Loaded Identity --" << std::endl;
	daram::showMatrix4x4 ( daram::getTopMatrix () );

	daram::myLookAt ( daram::Vector3 ( 20, 20, 20 ), daram::Vector3 ( 0, 0, 0 ), daram::Vector3 ( 0, 1, 0 ) );
	std::cout << "-- MatrixMode - ModelView, LookAt --" << std::endl;
	daram::showMatrix4x4 ( daram::getTopMatrix () );

	daram::myTranslateX ( 10 );
	daram::myTranslateY ( 20 );
	std::cout << "-- Translate Tx(10), Ty(20) --" << std::endl;
	daram::showMatrix4x4 ( daram::getTopMatrix () );

	daram::myPushMatrix ();
	std::cout << "-- PushMatrix --" << std::endl;
	daram::showMatrix4x4 ( daram::getTopMatrix () );

	daram::myRotateX ( 128 );
	daram::myRotateZ ( 65 );
	std::cout << "-- Rotate Rx(128), Rz(65) --" << std::endl;
	daram::showMatrix4x4 ( daram::getTopMatrix () );

	daram::myRunMatrix ( daram::Vector3 ( 20, 20, 20 ) );
	std::cout << "-- Run Vertex(20, 20, 20) --" << std::endl;
	daram::showVector4 ( daram::getRunnedVertex () );

	daram::myPopMatrix ();
	std::cout << "-- PopMatrix --" << std::endl;
	daram::showMatrix4x4 ( daram::getTopMatrix () );

	daram::myRunMatrix ( daram::Vector3 ( 20, 20, 20 ) );
	std::cout << "-- Run Vertex(20, 20, 20) --" << std::endl;
	daram::showVector4 ( daram::getRunnedVertex () );
    
    return 0;
}

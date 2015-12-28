//
//  MyMatrix.h
//  MatrixLib
//
//  Created by 진재연 on 2014. 10. 15..
//  Copyright (c) 2014년 DARAM WORLD. All rights reserved.
//

#ifndef __MatrixLib__MyMatrix__
#define __MatrixLib__MyMatrix__

namespace daram {
    struct Vector2;
    struct Vector3;
    struct Vector4;
    struct Matrix4x4;
    
    struct Vector2
    {
    public:
        Vector2 ();
        Vector2 ( float x, float y );
        
    public:
        Vector2 operator+ ( Vector2 v );
        Vector2 operator- ( Vector2 v );
        Vector2 operator- ();
        Vector2 operator* ( Vector2 v );
        Vector2 operator/ ( Vector2 v );
        bool operator== ( Vector2 v );
        
    public:
        float length ();
        Vector2 normalize ();
        
    public:
        float dot ( Vector2 v );
        Vector2 cross ( Vector2 v );
        
    public:
        float x, y;
    };
    
    struct Vector3
    {
    public:
        Vector3 ();
        Vector3 ( float x, float y, float z );
        Vector3 ( Vector2 vector, float z );
        
    public:
        Vector3 operator+ ( Vector3 v );
        Vector3 operator- ( Vector3 v );
		Vector3 operator- ( );
		Vector3 operator- ( float v );
        Vector3 operator* ( Vector3 v );
		Vector3 operator* ( float v );
		Vector3 operator/ ( Vector3 v );
		Vector3 operator/ ( float v );
        bool operator== ( Vector3 v );
        
    public:
        float length ();
        Vector3 normalize ();
        
    public:
        float dot ( Vector3 v );
        Vector3 cross ( Vector3 v );
        
    public:
        float x, y, z;
    };
    
    struct Vector4
    {
    public:
        Vector4 ();
        Vector4 ( float x, float y, float z, float w );
        Vector4 ( Vector3 vector, float w );
        
    public:
        Vector4 operator+ ( Vector4 v );
		Vector4 operator- ( Vector4 v );
		Vector4 operator- ( float v );
        Vector4 operator- ( );
		Vector4 operator* ( Vector4 v );
		Vector4 operator* ( float v );
        Vector4 operator* ( Matrix4x4 matrix );
		Vector4 operator/ ( Vector4 v );
		Vector4 operator/ ( float v );
        bool operator== ( Vector4 v );
        
    public:
        float length ();
        Vector4 normalize ();
        
    public:
        float dot ( Vector4 v );
        Vector4 cross ( Vector4 v1, Vector4 v2 );
        
    public:
        float x, y, z, w;
    };
    
    struct Matrix4x4
    {
    public:
        Matrix4x4 ();
        Matrix4x4 ( float m11, float m12, float m13, float m14,
                   float m21, float m22, float m23, float m24,
                   float m31, float m32, float m33, float m34,
                   float m41, float m42, float m43, float m44 );
        Matrix4x4 ( Vector4 & column1, Vector4 & column2, Vector4 & column3, Vector4 & column4 );
        
    public:
        Matrix4x4 operator+ ( Matrix4x4 & v );
        Matrix4x4 operator+ ( float v );
        Matrix4x4 operator- ( Matrix4x4 & v );
        Matrix4x4 operator- ( float v );
        Matrix4x4 operator* ( Matrix4x4 & v );
        Matrix4x4 operator* ( float v );
        Matrix4x4 operator/ ( Matrix4x4 & v );
        Matrix4x4 operator/ ( float v );
        bool operator== ( Matrix4x4 & v );
        
    public:
        Matrix4x4 transpose ();
        Matrix4x4 invert ();
        float determinant ();
        
    public:
        static Matrix4x4 identity ();
        
        static Matrix4x4 translate ( Vector3 & translate );
        static Matrix4x4 scale ( Vector3 & scale );
        
        static Matrix4x4 rotateX ( float r );
        static Matrix4x4 rotateY ( float r );
        static Matrix4x4 rotateZ ( float r );
        
        static Matrix4x4 orthographicOffCenterLH ( float l, float r, float b, float t, float zn, float zf );
        static Matrix4x4 orthographicOffCenterRH ( float l, float r, float b, float t, float zn, float zf );
        static Matrix4x4 perspectiveFieldOfViewLH ( float fov, float aspect, float zn, float zf );
        static Matrix4x4 perspectiveFieldOfViewRH ( float fov, float aspect, float zn, float zf );
        
        static Matrix4x4 lookAtLH ( Vector3 & eye, Vector3 & at, Vector3 & up );
        static Matrix4x4 lookAtRH ( Vector3 & eye, Vector3 & at, Vector3 & up );
        
        static Matrix4x4 rotatePitchYawRoll ( float yaw, float pitch, float roll );
        
    public:
        float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
    };
    
    enum MatrixMode {
        MatrixMode_ModelView,
        MatrixMode_Projection,
    };
    
    void mySetMatrixMode(MatrixMode matrixMode);
    void myLoadIdentity();
    void myPushMatrix();
    void myPopMatrix();
    void myMatrixMul(Matrix4x4 matrix);
    void myRunMatrix(Vector3 vertex);
    
    void myTranslateX(float tx);
    void myTranslateY(float ty);
    void myTranslateZ(float tz);
    
    void myRotateX(float rx);
    void myRotateY(float ry);
    void myRotateZ(float rz);
    
    void myScaleX(float sx);
    void myScaleY(float sy);
    void myScaleZ(float sz);
    
    void myLookAt(Vector3 eye, Vector3 at, Vector3 up);
	
	void myFrustum ( int l, int r, int b, int t, float n, float f );
	void myOrtho ( int l, int r, int b, int t, float n, float f );
    
    Matrix4x4 getTopMatrix();
    Vector4 getRunnedVertex();
    
    void showMatrix4x4(Matrix4x4 matrix);
    void showVector4(Vector4 vector);
}

#endif
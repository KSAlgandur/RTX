#include "Matrix.hpp"

    //пользовательские типы
    typedef Matrix<double, 3, 1> Vector3_col;
    typedef Matrix<double, 1, 3> Vector3_row;


    // static double dot(const Vector3_row& v1, const Vector3_row& v2) // скалярное произведение 
    // {
        
    // return v1[0][0] * v2[0][0] + v1[0][1] * v2[0][1] + v1[0][2] * v2[0][2];
    // }

    // static Vector3_row scale(const Vector3_row& v,double scalar)
    // {   
        
    //  return Vector3_row{{v[0][0] * scalar,v[0][1] * scalar,v[0][2] * scalar}} ;
    
    // }

    

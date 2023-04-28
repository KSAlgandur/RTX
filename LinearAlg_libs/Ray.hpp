#include <iostream>
#include "Mat_types.hpp"
#include <cmath>

class Ray
{
    public:
    
    Ray(const Vector3_row& origin,const Vector3_row& direction);
    Ray(const Vector3_row& origin,float thAngle,float phAngle);
   
    ~Ray() = default;

   const Vector3_row& getOrigin() const { return m_origin; }
   const Vector3_row& getDirection() const { return m_direction; }

    float ray_length();

    private:

        Vector3_row m_origin; // начало
        Vector3_row m_direction; // направление
        //Где typedef Matrix<double, 1, 3> Vector3_row;

};


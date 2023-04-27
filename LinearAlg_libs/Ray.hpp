#include <iostream>
#include "Matrix.hpp"
#include <cmath>

class Ray
{
    public:

    Ray(const Vector3_row& origin,const Vector3_row& direction):m_origin(origin),m_direction(direction){};
    Ray(const Vector3_row& origin,double thAngle,double phAngle):m_origin(origin)
    {
        //Определяем координаты заданной точки с помощью сферических координат  
        double x = std::sin(thAngle) * std::cos(phAngle);
        double y = std::sin(thAngle) * std::sin(phAngle);
        double z = std::cos(thAngle);

        Vector3_row direction{{x,y,z}};
        m_direction = direction;
    }
    ~Ray() = default;

    private:
    Vector3_row m_origin; // начало
    Vector3_row m_direction; // направление
    //Где typedef Matrix<double, 1, 3> Vector3_row;

};


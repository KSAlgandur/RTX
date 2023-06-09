#include "Ray.hpp"



Ray::Ray(const Vector3_row& origin,const Vector3_row& direction):m_origin(origin),m_direction(direction)
{

}

Ray::Ray(const Vector3_row& origin,float thAngle,float phAngle):m_origin(origin)
{
    //Определяем координаты заданной точки с помощью сферических координат  
        float x = std::sin(thAngle) * std::cos(phAngle);
        float y = std::sin(thAngle) * std::sin(phAngle);
        float z = std::cos(thAngle);

        Vector3_row direction{{x,y,z}};
        m_direction = direction;
}

float Ray::ray_length()
{
    float dx = this->m_direction[0][0] - this->m_origin[0][0];
    float dy = this->m_direction[0][1] - this->m_origin[0][1];
    float dz = this->m_direction[0][2] - this->m_origin[0][2];
        
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double Ray::norm(const Vector3_row& v)
{
     return std::sqrt(v[0][0] * v[0][0] + v[0][1] * v[0][1] + v[0][2] * v[0][2]);
}

 double Ray::dot(const Vector3_row& v1,const Vector3_row& v2)
{
    return v1[0][0] * v2[0][0] + v1[0][1] * v2[0][1] + v1[0][2] * v2[0][2];
}
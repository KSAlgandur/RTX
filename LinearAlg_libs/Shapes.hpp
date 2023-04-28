#include "Ray.hpp"

class Shape
{
    public:
    Shape(float x, float y, float z): x_c(x), y_c(y),z_c(z){};
    virtual bool beam_is_intersect(Ray& beam,const Vector3_row& ray_origin,const Vector3_row& ray_direction) const = 0;
    virtual Vector3_row beam_intersection(Ray& beam) const = 0;
    protected:
    float x_c, y_c, z_c;
};

class Sphere : public Shape
{
    public: 
        Sphere(float x, float y, float z, float r): Shape(x,y,z),radius(r)
        {
            Vector3_row C{{x,y,z}}; //Центр сферы
            Center = C;
        }

        bool beam_is_intersect(Ray &beam,const Vector3_row& ray_origin,const Vector3_row& ray_direction)
        {
            Vector3_row L = Center - ray_origin;
            float tca = Vector3_row::dot(L,ray_direction);
            if (tca < 0) return false;
            float d2 = Vector3_row::dot(L,L) - tca * tca;
            if (d2 > radius * radius) return false;
            float thc = sqrtf(radius * radius - d2);
            t1 = tca - thc;
            t2 = tca + thc;
            return true; 

        }

        Vector3_row beam_intersection(Ray &beam)
        {
            const Vector3_row& ray_origin = beam.getOrigin();
            const Vector3_row& ray_direction = beam.getDirection();

            if(beam_is_intersect(beam,ray_origin,ray_direction)) // если true то есть как минимум одно пересечение 
            {
                if(t1 > 0 && t2 > 0) // Выбираем наименьшую (ближайшую)    
                    if(t1 < t2)
                    {
                        return ray_origin + ray_direction * t1;
                    }
                    else
                    {
                        return ray_origin + ray_direction * t2;
                    }
                else if(t1 > 0)
                {
                    return ray_origin + ray_direction * t1;
                }
                else if(t2 > 0)
                {
                   return ray_origin + ray_direction * t2; 
                }
            }
            else {
            // Обе точки отрицательны, пересечения нет
            return Vector3_row(0, 0, 0);
            

        }




    private:
        float radius; 
        Vector3_row Center;
        Vector3_row Intersect;

        float t1 = 0;
        float t2 = 0;
};

// Vector3 intersect_ray_point(const Vector3& origin, const Vector3& direction) const {
//         Vector3 L = center - origin;
//         float tca = L.dot(direction);
//         float d2 = L.dot(L) - tca * tca;
//         if (d2 > radius * radius) {
//             // Луч не пересекает сферу
//             return Vector3(0, 0, 0);
//         }
//         float thc = sqrt(radius * radius - d2);
//         float t0 = tca - thc;
//         float t1 = tca + thc;
//         if (t0 > 0 && t1 > 0) {
//             // Обе точки положительны, выбираем ближайшую
//             if (t0 < t1) {
//                 // t0 ближе к началу луча
//                 return origin + direction * t0;
//             } else {
//                 // t1 ближе к началу луча
//                 return origin + direction * t1;
//             }
//         } else if (t0 > 0) {
//             // Только t0 положительно, луч касается сферы
//             return origin + direction * t0;
//         } else if (t1 > 0) {
//             // Только t1 положительно, луч касается сферы
//             return origin + direction * t1;
//         } else {
//             // Обе точки отрицательны, пересечения нет
//             return Vector3(0, 0, 0);
//         }
//     }
// };
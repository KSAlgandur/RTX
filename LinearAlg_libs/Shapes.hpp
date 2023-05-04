#include "Ray.hpp"
#include "optional"


class Shape
{
    public:
    Shape(double x, double y, double z): x_c(x), y_c(y),z_c(z){};
    virtual std::optional<Vector3_row> beam_intersection(Ray& beam) const = 0;
    protected:
    double x_c, y_c, z_c;
};

class Sphere : public Shape
{
    public: 
        Sphere(double x, double y, double z, double r): Shape(x,y,z),radius(r)
        {
            //Vector3_row Center{{x,y,z}}; //Центр сферы
            Center = Vector3_row{{x,y,z}};
        }

        std::optional<Vector3_row> beam_intersection(Ray &beam)const override
        {
            auto ray_origin = beam.getOrigin();
            auto ray_direction = beam.getDirection();    
            double t1 = 0.0;
            double t2 = 0.0;
        


            Vector3_row L =  ray_origin - Center;
            std::cout << std::setprecision(3) << L << std::endl;
            double B = Ray::dot(ray_direction,L);
            
            std::cout <<"B "<<std::setprecision(3) << B << std::endl;

            
            double C = Ray::norm(L) * Ray::norm(L) - radius * radius;

            std::cout << std::setprecision(3) << C << std::endl;
            double D = B * B - C;

            std::cout << std::setprecision(3) << D << std::endl;
             std::cout <<"B*B " << std::setprecision(3) << B*B << std::endl;


            if(D < 0) 
            {
                return std::nullopt; 
            }
            else
                {
                    t1 = -B - sqrt(D);
                    t2 = -B + sqrt(D);
                    
                    if(t1 > 0 && t2 > 0)
                    {
                        double t = std::min(t1,t2);
                        return ray_origin + ray_direction.scale(t);
                    }
                    else if(t1 > 0)
                    {
                        return ray_origin + ray_direction.scale(t1);
                    }
                     else if(t2 > 0)
                    {
                        return ray_origin + ray_direction.scale(t2);
                    }
                    else
                    {
                        return std::nullopt;
                    }
                    
                }

        }

    private:
        double radius; 
        Vector3_row Center;

       
};


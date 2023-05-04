
// #include "Shapes.hpp"
#include "LinearAlg_libs/Shapes.hpp"
//#include "Matrix.hpp"

int main()
{

   
    // Matrix<int,3,2> m1({{{1,2},{4,5},{7,7}}});
    // Matrix<int,2,3> m2({{{3,4,5},{9,8,9}}});
    // //Matrix<int,3,3> m3 ({{{1,2,3},{4,5,6},{7,8,9}}});
    // Matrix<double,3,3> m3 ({{{1,2,0},{3,2,1},{0,1,2}}});
    // //std::cout << m1 * m2;

    // //std::cout <<"Определитель равен "<< m3.det();
    // std::cout <<"отбратная матрица равна "<< m3.inverse();

    
    // Matrix<double, 3, 3> m1{{1, 2, 3}, {2, 3, 4}, {3, 5, 6}};
    // Matrix<double, 3, 3> m2{{1, 2, 3}, {2, 3, 4}, {3, 5, 6}};

    // std::cout << m1 * m2;

     //Vector3_row v1 {{2,3,5}};
     //std::cout << v1 * 2

    
      
    // Vector3_row v{{x,y,z}};

    // std::cout << v[0][1]; 

    // Vector3_row *C;

    // C = new Vector3_row{{x,y,z}};
    // float a = (*C)[0][1];
    
    // m1.z_RotMatrix(30);
    // //m1.x_RotMatrix(30);
    // std::cout << m1;


    const Vector3_row  a = Vector3_row{{5.0,6.0,0.0}}; //начало 
    const Vector3_row  b = Vector3_row{{-0.6401844, -0.76822128, 0.0}}; // направление

    Ray ab(a,b); // Луч 
    Sphere shar(0,0,0,2);
    
    std::optional<Vector3_row> opt_vec = shar.beam_intersection(ab);
    if(opt_vec)
    {
         std::cout << "Значение задано: " << *opt_vec << std::endl;
    }
    else
    {
       std::cout << "Значение не задано" << std::endl;
    }

    return 0;
}
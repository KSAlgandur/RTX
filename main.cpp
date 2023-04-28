#include "Mat_types.hpp"


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


    float x = 2;
    float y = 3;
    float z = 4;


    Vector3_row v1{{x,y,z}};
    Vector3_row v2{{x+2,y+2,z+2}};

    Vector3_row v3 =  v1 - v2;

    std::cout << v3;  
    // Vector3_row v{{x,y,z}};

    // std::cout << v[0][1]; 

    // Vector3_row *C;

    // C = new Vector3_row{{x,y,z}};
    // float a = (*C)[0][1];
    
    // m1.z_RotMatrix(30);
    // //m1.x_RotMatrix(30);
    // std::cout << m1;
    
    return 0;
}
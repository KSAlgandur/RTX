#include "Matrix.hpp"


int main()
{

   
    // Matrix<int,3,2> m1({{{1,2},{4,5},{7,7}}});
    // Matrix<int,2,3> m2({{{3,4,5},{9,8,9}}});
    // //Matrix<int,3,3> m3 ({{{1,2,3},{4,5,6},{7,8,9}}});
    // Matrix<double,3,3> m3 ({{{1,2,0},{3,2,1},{0,1,2}}});
    // //std::cout << m1 * m2;

    // //std::cout <<"Определитель равен "<< m3.det();
    // std::cout <<"отбратная матрица равна "<< m3.inverse();

    Matrix<double,3,3> m1({{{1,1,1},{1,1,1},{1,1,1}}});
    Matrix<double,3,1> m2({{{0},{0},{0}}});
    
    m1.x_RotMatrix(30);
    std::cout << m1;
    
    return 0;
}
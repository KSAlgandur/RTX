#include "Matrix.hpp"

// typedef Matrix<float, 3, 1> Vector3_col;
// typedef Matrix<float, 1, 3> Vector3_row;


// static float dot(const Vector3_row& v1, const Vector3_row& v2) // скалярное произведение 
// {
//     return v1[0][0] * v2[0][0] + v1[0][1] * v2[0][1] + v1[0][2] * v2[0][2];
// }

// По-хорошему стоило Vector3_row сделать наследником класса Мatrix 



class Vector3_row : public Matrix<float,1,3> //Вектор строка
{
    public:
        Vector3_row() : Matrix<float,1,3>() {}
        Vector3_row(std::initializer_list<std::initializer_list<float>> list): Matrix<float,1,3>(list){}

        
        static float dot(const Vector3_row& v1, const Vector3_row& v2) // скалярное произведение 
        {
        return v1[0][0] * v2[0][0] + v1[0][1] * v2[0][1] + v1[0][2] * v2[0][2];
        }

        Vector3_row operator-(const Vector3_row& v2) const
        {
            Vector3_row result;

            for(size_t i = 0 ; i < 3 ; ++i)
            {
                result[0][i] = this->data[0][i] - v2[0][i];
            }
        return result;
        }

        Vector3_row operator*(const float& t) const
        {
            Vector3_row result;
            for(size_t i = 0 ; i < 3 ; ++i)
            {
                result[0][i] = this->data[0][i] * t;
            }

            return result;
        }

        Vector3_row operator+(const Vector3_row& v2) const
        {
            Vector3_row result;

            for(size_t i = 0 ; i < 3 ; ++i)
            {
                result[0][i] = this->data[0][i] + v2[0][i];
            }

            return result;
        }
};
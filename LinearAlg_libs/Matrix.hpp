#ifndef MATRIX_HPP
#define MATRIX_HPP

// Не использовать больше Шаблоны. Шаблоны - зло : компилируется больше 1 секунды, а это уже не в рамках РПЦ

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <initializer_list>
		

template <typename T, size_t Rows, size_t Colums>
class Matrix
{
private:
    std::array<std::array<T, Colums>, Rows> data;
    int row;
    int col;

public:
    // Конструкторы
    ~Matrix() = default;
    Matrix(std::array<std::array<T, Colums>, Rows> &&d);
    Matrix(std::array<std::array<T, Colums>, Rows> &d);
    Matrix();

    Matrix(std::initializer_list<std::initializer_list<T>> list);

    // Методы
    void displayMatrix() const;
    size_t GetRow() const;
    size_t GetCol() const;
    bool can_multiply(const Matrix<T, Rows, Colums> &other);
    Matrix<T, Colums, Rows> transposed();
    T det();
    Matrix<T, Colums, Rows> inverse();
    T alg_complement(const size_t row,const size_t col);
    void y_RotMatrix(const double& angle);
    void x_RotMatrix(const double& angle);
    void z_RotMatrix(const double& angle);

    // Перегрузки
    Matrix<T, Rows, Colums> &operator=(const Matrix<T, Rows, Colums> &m2);
    Matrix<T, Rows, Colums> &operator+=(const Matrix<T, Rows, Colums> &m2);
    std::array<T, Colums> &operator[](size_t i);             // возвращать ссылку на элемент c помощью []
    const std::array<T, Colums> &operator[](size_t i) const; // возщвращать ссылку на элемент c помощью []  для константных объектов
    T &operator()(size_t i, size_t j);                       // возщвращать ссылку на элемент c помощью ()
    Matrix<T, Rows, Colums> operator*(const T val);          // умножение матрицы на число ;

};

// Конструктор перемещения
template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums>::Matrix(std::array<std::array<T, Colums>, Rows> &&d) : data(d)
{
    std::cout << "Исходная матрица :\n";
    this->row = Rows;
    this->col = Colums;

    displayMatrix();
}

// Конструктор копирования
template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums>::Matrix(std::array<std::array<T, Colums>, Rows> &d)
{
    std::cout << "конструктор копирования" << std::endl;
    for (size_t i = 0; i <= Rows; i++)
    {
        for (size_t j = 0; j <= Colums; j++)
        {
            data[i][j] = d.data[i][j]; /// Была ошибка

            
        }
    }
}

template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums>::Matrix(std::initializer_list<std::initializer_list<T>> list)
{
    
        row = 0;
        col = 0;
        for (const auto& row_list : list) {
            if (row >= Rows) {
                break;
            }
            col = 0;
            for (const auto& value : row_list) {
                if (col >= Colums) {
                    break;
                }
                data[row][col] = value;
                col++;
            }
            row++;
        }
    displayMatrix();
}



template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums>::Matrix()
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colums; j++)
        {
            data[i][j] = 0;
        }
    }
}

// Вывод матрицы на экран
template <typename T, size_t Rows, size_t Colums>
void Matrix<T, Rows, Colums>::displayMatrix() const
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colums; j++)
        {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Получить сроку
template <typename T, size_t Rows, size_t Colums>
size_t Matrix<T, Rows, Colums>::GetRow() const
{
    return Rows;
}

// Получить столбец
template <typename T, size_t Rows, size_t Colums>
size_t Matrix<T, Rows, Colums>::GetCol() const
{
    return Colums;
}

template <typename T, size_t Rows, size_t Colums>
bool Matrix<T, Rows, Colums>::can_multiply(const Matrix<T, Rows, Colums> &other)
{
    return Rows == other.col;
}

template <class T, size_t Rows, size_t Colums>
Matrix<T, Colums, Rows> Matrix<T, Rows, Colums>::transposed()
{
    Matrix<T, Colums, Rows> trans_m;

    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Colums; j++)
        {
            trans_m[j][i] = data[i][j];
        }
    }
    return trans_m;
}

template<typename T,size_t Rows, size_t Colums> // нахождение определителя методом Гаусса
T Matrix<T,Rows,Colums>::det(){
    int n = Rows;
    const double EPS = 1E-9;
    double det = 1;

     static_assert(Colums == Rows, "Matrices do not match in size");

    if(Rows < 1) std::cout << "Определитель вычислить невозможно!" << std::endl;
    if(Rows == 1)
    {
        det = data[0][0];
        return det;
    }
    if(Rows == 2)
    {
        det = data[0][0] * data[1][1] - (data[1][0] * data[0][1]);
        return det;
    }
    else if(Rows > 2)
    {
        for (int i=0; i<n; ++i) {
	    int k = i;
	    for (int j=i+1; j<n; ++j)
		    if (abs (data[j][i]) > abs (data[k][i]))
			    k = j;
	    if (abs (data[k][i]) < EPS) {
		det = 0;
		break;
	}
	std::swap (data[i], data[k]);
	if (i != k)
		det = -det;
	det *= data[i][i];
	for (int j=i+1; j<n; ++j)
    {
        data[i][j] /= data[i][i];
    }
		
	for (int j=0; j<n; ++j){
        if (j != i && abs (data[j][i]) > EPS)
        for (int k=i+1; k<n; ++k)
				data[j][k] -= data[i][k] * data[j][i];
    }
		
			
    }

    return det;
    }


    
}

template<typename T,size_t Rows, size_t Colums>
T Matrix<T,Rows,Colums>::alg_complement(const size_t row,const size_t col)
{
    Matrix<T, Colums - 1, Rows - 1> minor;
    size_t	r_idx;
	size_t	c_idx;

    r_idx = 0;
    for (size_t i = 0; i < Rows; i++)
	{
        c_idx = 0;
		for (size_t j = 0; j < Colums; j++)
        {
            if (i != row && j != col)
			{
				minor(r_idx, c_idx) = data[i][j];
				c_idx++;
			}
        }
        if (i != row)
			r_idx++;
    }

    return (pow(-1,row + col) * minor.det());
}

template<typename T,size_t Rows, size_t Colums>
Matrix<T, Colums, Rows> Matrix<T, Rows, Colums>::inverse()
{
    Matrix<T, Colums, Rows> other_m;

    if (Rows == 1 && Colums == 1)
	{
		other_m[0][0] = 1 / other_m[0][0];
		return (other_m);
	}
    for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < Colums; j++)
			other_m(i,j) = alg_complement(i,j);  
	}

    other_m.transposed();
    
    other_m = other_m * (1 / this->det());

    return other_m ;
}

template<typename T,size_t Rows, size_t Colums>
void Matrix<T, Rows, Colums>::x_RotMatrix(const double& angle)
 {
    
    Matrix<T,3,3> x_rot_matx({{{1,0,0},{0,cos(angle),sin(angle)},{0,-sin(angle),cos(angle)}}});
    
    *this =  x_rot_matx* (*this) ;


 }

template<typename T,size_t Rows, size_t Colums>
void Matrix<T, Rows, Colums>::y_RotMatrix(const double& angle)
 {
    
    Matrix<T,3,3> y_rot_matx({{{cos(angle),0,sin(angle)},{0,1,0},{-sin(angle),0,cos(angle)}}});
    
    *this =  y_rot_matx* (*this) ;


 }

template<typename T,size_t Rows, size_t Colums>
void Matrix<T, Rows, Colums>::z_RotMatrix(const double& angle)
 {
    
    Matrix<T,3,3> z_rot_matx({{{cos(angle),-sin(angle),0},{sin(angle),cos(angle),0},{0,0,1}}});
    
    *this =  z_rot_matx* (*this) ;


 }



// Реализация перегрузок

template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums> &Matrix<T, Rows, Colums>::operator=(const Matrix<T, Rows, Colums> &m2)
{
    std::cout << "оператор= " << std::endl;
    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Colums; j++)
        {
            data[i][j] = m2.data[i][j];
        }
    }
    return *this;
}

template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums> &Matrix<T, Rows, Colums>::operator+=(const Matrix<T, Rows, Colums> &m2)
{
    if (Rows != m2.row || Colums != m2.col)
    {
        throw std::invalid_argument("Matrices have different size!");
    }
    else
        for (size_t i = 0; i <= Rows; i++)
        {
            for (size_t j = 0; j <= Colums; j++)
            {
                data[i][j] += m2.data[i][j];
            }
        }
    return this;
}

template <typename T, size_t Rows, size_t Colums>
std::array<T, Colums> &Matrix<T, Rows, Colums>::operator[](size_t i) // возщвращать ссылку на элемент c помощью []
{
    return data[i];
}

template <typename T, size_t Rows, size_t Colums>
const std::array<T, Colums> &Matrix<T, Rows, Colums>::operator[](size_t i) const // возщвращать ссылку на элемент c помощью []  для константных объектов
{
    return data[i];
}

template <typename T, size_t Rows, size_t Colums>
T &Matrix<T, Rows, Colums>::operator()(size_t i, size_t j) // возщвращать ссылку на элемент c помощью ()
{
    return data[i][j];
}

template <typename T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums> Matrix<T, Rows, Colums>::operator*(const T val) // умножение матрицы на число
{
    for (size_t i = 0; i < Rows; i++)
    {
        for (size_t j = 0; j < Colums; j++)
        {
            data[i][j] *= val;
        }
    }
    return *this;
}

// Перегрузки вне класса
template <class T, size_t Rows, size_t Colums>
std::ostream &operator<<(std::ostream &out, const Matrix<T, Rows, Colums> &matrix) // перегрузка потока вывода <<
{
    out << "Результирующая Матрица : " << std::endl;
    out << "Размерность :" << Rows << " X " << Colums << std::endl;

    for (size_t i = 0; i != Rows; i++)
    {
        for (size_t j = 0; j != Colums; j++)
        {

            out << std::setw(8)<< matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    out << "\n";
    return out;
}

template <class T, size_t Rows, size_t Colums>
Matrix<T, Rows, Colums> operator+(const Matrix<T, Rows, Colums> &m1, const Matrix<T, Rows, Colums> &m2) // перегрузка оператора сложения без дублирования кода за счет прегрузка +=
{
    auto tmp = m1;
    tmp += m2;

    return tmp;
}

template <class T, size_t Rows_1, size_t Colums_1, size_t Rows_2, size_t Colums_2>
Matrix<T, Rows_1, Colums_2> operator*(const Matrix<T, Rows_1, Colums_1> &m1, const Matrix<T, Rows_2, Colums_2> &m2)
{
    static_assert(Colums_1 == Rows_2, "Matrices do not match in size");

    const size_t res_row = Rows_1;
    const size_t res_col = Colums_2;

    Matrix<T, Rows_1, Colums_2> res;

    for (int i = 0; i < res_row; i++)
    {

        for (int j = 0; j < res_col; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < Colums_1; k++)
                res[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return res;
}

typedef Matrix<double, 3, 1> Vector3_col;
typedef Matrix<double, 1, 3> Vector3_row;

#endif
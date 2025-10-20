#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <memory>

//task 1
template<typename T>
void InputAndPrintMatrix(size_t n, size_t m)
{
    std::vector<std::vector<T>>matrix(n,std::vector<T>(m));
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
}
//task 2
template<typename T>
auto SumOfAllElements(const std::vector<std::vector<T>>& matrix) -> T
{
    T sum = T();
    
    for(const auto& row : matrix)
    {
        sum += std::accumulate(row.begin(), row.end(), T());
    }
    
    return sum;
}
//task 3
template<typename T>
auto SumOfElementsOnMainDiagonal(const std::vector<std::vector<T>>& matrix) -> T
{
    T sum = T();
    size_t n = matrix.size();
    for(size_t i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }
    
    return sum;
}

//task 4
template<typename T>
auto SumEachRow(const std::vector<std::vector<T>>& matrix) -> std::vector<T>
{
    std::vector<T> sums;    
    for(const auto& row : matrix)
    {   
        T sum = std::accumulate(row.begin(), row.end(), T());
        sums.push_back(sum);
    }
    
    return sums;
}

template<typename T>
auto SumEachCol(const std::vector<std::vector<T>>& matrix) -> std::vector<T>
{
    if(matrix.empty() || matrix[0].empty()) {
        return {};
    }
    
    size_t numCols = matrix[0].size();
    std::vector<T> sums(numCols, T());
    
    for(const auto& row : matrix) {
        for(size_t col = 0; col < row.size(); col++) {
            sums[col] += row[col];
        }
    }
    
    return sums;
}

template<typename T>
void PrintVector(const std::vector<T>& vec, const std::string& title) {
    std::cout << title << " : [ ";
    for(const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]\n\n";
}

template<typename T>
void PrintSumsOfRowsAndCols(const std::vector<std::vector<T>>& matrix)
{
    auto sumRows = SumEachRow(matrix);
    auto sumCols = SumEachCol(matrix);

    PrintVector(sumRows, "Sums of rows");
    PrintVector(sumCols, "Sums of columns");
}


//task 5
void PrintSquare(size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

//task 6
void PrintRightTriangle(size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i > j)
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

//task 7
void PrintLeftTriangle(size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i < j)
            {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}

//task 8
void PrintSquareDiagolals(size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(i == j || n - i - 1 == j)
            {
                std::cout << "*";
            }
            else
            {
               std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

//task 9
void PrintFrame(size_t n)
{
    for(size_t i = 1; i <= n; i++)
    {
        for(size_t j = 1; j <= n; j++)
        {
            if(i == 1 ||  i == n || j == 1 || j == n)
            {
                std::cout << "*";
            }
            else
            {
               std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

//task 10
void PrintChessboard(size_t n)
{
    for(size_t i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {

            for(size_t j = 1; j <= n; j++)
            {
                if(j % 2 == 1)
                {
                    std::cout << "*";
                }
                else
                {
                    std::cout << " ";
                }
            }

            std::cout << std::endl;
        }
        else
        {
           for(size_t j = 1; j <= n; j++)
            {
                if(j % 2 == 0)
                {
                    std::cout << "*";
                }
                else
                {
                    std::cout << " ";
                }
            }

            std::cout << std::endl;
        }
    }
}
int main(int argc, const char** argv) 
{
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    PrintChessboard(7);

}

#include <array>
#include <iostream>
#include <algorithm>
#include <cmath>



template <int N>
void print_array(const std::array<std::array<int, N>, N>& a) 
{
    std::cout<<"[";
    for (int i=0; i<N; i++) {
        std::cout<<(i?" [":"[");
        for (int j=0; j<N; j++) {
            std::cout<<a[i][j]<<(j<N-1?" ":"");
        }
        std::cout<<(i<N-1?"]\n":"]");
    }
    std::cout<<"]\n";
}


template <int N>
constexpr std::array<std::array<int, N-1>, N-1> subarray(const std::array<std::array<int, N>, N>& a, int m, int k)
{
    std::array<std::array<int, N-1>, N-1> res;
    for (int i=0; i<N; i++) {
        if (i==m) {continue;} 
        for (int j=0; j<N; j++) {
            if (j==k) {continue;}
            res[i<m?i:i-1][j<k?j:j-1]=a[i][j];
        }
    }
    return res;
}


template <int N>
constexpr int det(const std::array<std::array<int, N>, N>& a) 
{
    if constexpr (N==2) {  // c++17 to stop recursive instantiation
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    }
    else {
        int summ = 0;
        for (int i=0; i<N; i++) {
            summ += std::pow(-1, i+2)*a[0][i]*det<N-1>(subarray<N>(a, 0, i));
        }
    }
}

// -------------------------------------
// c++14 to stop recursive instantiation
// -------------------------------------
// template<>
// constexpr int det<1>(const std::array<std::array<int, 1>, 1>& a) 
// {
//     return 0;
// }

int main() 
{
    std::array<std::array<int, 4>, 4> a = 
    {{
        {1, 1, 2, 3}, 
        {1, 2, 3, 4}, 
        {2, 3, 7, 5}, 
        {3, 4, 5, 9}
    }};
    print_array<4>(a);
    int res = det<4>(a);
    std::cout<<res<<'\n';

}
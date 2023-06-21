#include <iostream>
#include <bitset>
#include <vector>

long long pathSum(long long n) {
    std::bitset<64> binary(n);
    std::vector<long long> path;
    int i = 63;
    while(!binary[i]) { i--; }  

    long long sum = 0;
    for(; i >= 0; i--) {
        sum += n;
        n = n / 2;  
    }
    return sum;
}

int main() {
    int iterations;
    std::cin >> iterations;
    while (iterations--)
    {
        long long n;
        std::cin >> n;
        std::cout << pathSum(n) << std::endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int iterations;
    scanf("%d", &iterations);
    while (iterations--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        int left = 0, right = n - 1;
        int sum = 0;
        while (left <= right)
        {
            sum += a[right] - a[left];
            left++;
            right--;
        }
        printf("%d\n", sum);
    }
}
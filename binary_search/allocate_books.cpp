#include <iostream>
#include <vector>
using namespace std;

int required_students(vector<int> &pages, int min)
{
    int students = 1;
    int sum = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        sum += pages[i];
        if (sum > min)
        {
            students++;
            sum = pages[i];
        }
    }

    return students;
}

int allocate_pages(vector<int>&pages, int number)
{
    if (pages.size() < number)
        return -1;
    int left = 0;
    int right = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        right += pages[i];
        left = max(left, pages[i]);
    }

    int mid;
    int result = -1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (required_students(pages, mid) <= number)
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return result;
}

int main()
{
    vector<int> pages = {12, 34, 67, 90};
    int number = 2;

    cout << allocate_pages(pages, number) << endl;

    return 0;
}

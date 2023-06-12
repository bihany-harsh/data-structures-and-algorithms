#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool custom_order(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void activity_selector_rec_util(vector<pair<int, int>> &activities, vector<pair<int, int>> &ans, int curr_index, int end_index)
{
    int m = curr_index + 1;

    while (m <= end_index && activities[m].first < activities[curr_index].second)
        m++;
    
    if (m <= end_index)
    {
        ans.push_back(activities[m]);
        activity_selector_rec_util(activities, ans, m, end_index);
    }
}

vector<pair<int, int>> activity_selector_rec(vector<pair<int, int>> &activities)
{
    sort(activities.begin(), activities.end(), custom_order);
    vector<pair<int, int>> ans;

    if (activities.size() == 0)
        return ans;

    ans.push_back(activities[0]);  // Adding the first activity to the answer vector.
    activity_selector_rec_util(activities, ans, 0, activities.size() - 1); 

    return ans;
}

vector<pair<int, int>> activity_selector_iter(vector<pair<int, int>> &activities)
{
    vector<pair<int, int>> ans;
    if (activities.size() == 0)
        return ans;
    
    sort(activities.begin(), activities.end(), custom_order);

    ans.push_back(activities[0]); 

    int k = 0;

    for (int m = 1; m < activities.size(); m++)
    {
        if (activities[m].first >= activities[k].second)
        {
            ans.push_back(activities[m]);
            k = m;
        }
    }

    return ans;
}

int min_number_rooms(vector<pair<int, int>> &activities)
{
    vector<int> start_times = {};
    vector<int> end_times = {};

    for (int i = 0; i < activities.size(); i++)
    {
        start_times.push_back(activities[i].first);
        end_times.push_back(activities[i].second);
    }

    sort(start_times.begin(), start_times.end());
    sort(end_times.begin(), end_times.end());

    int i = 0, j = 0, ans = 0, curr = 0;

    while (i < start_times.size() && j < end_times.size())
    {
        if (start_times[i] < end_times[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }

        ans = max(ans, curr);
    }

    return ans;
}


int main()
{
    vector<pair<int, int>> activities = {{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}};
    vector<pair<int, int>> ans1 = activity_selector_rec(activities);
    vector<pair<int, int>> ans2 = activity_selector_iter(activities);

    for (auto i : ans1)
        cout << i.first << " " << i.second << endl;

    cout << "-------------------" << endl;

    for (auto i : ans2)
        cout << i.first << " " << i.second << endl;

    cout << "-------------------" << endl;

    cout << min_number_rooms(activities) << endl;
}

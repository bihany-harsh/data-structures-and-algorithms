#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combination(vector<int> &candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>> &ans)
{

    if (currSum > target)
        return;

    if (currSum == target)
    {

        ans.push_back(currComb);

        return;
    }

    for (int i = currIndex; i < candidates.size(); i++)
    {

        if (i > currIndex && candidates[i] == candidates[i - 1])

            continue;

        currComb.push_back(candidates[i]);

        currSum += candidates[i];

        combination(candidates, target, currComb, currSum, i + 1, ans);

        currComb.pop_back();

        currSum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;

    vector<int> currComb;

    combination(candidates, target, currComb, 0, 0, ans);

    sort(ans.begin(), ans.end());

    return ans;
}

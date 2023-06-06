#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int rain_water_trapping(vector<int> &heights) {
    int n = heights.size();
    if (n == 0) return 0;
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] < heights[i]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int left = st.top();
            int curr_width = i - left - 1;
            int curr_height = min(heights[left], heights[i]) - heights[top];
            ans += curr_width * curr_height;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << rain_water_trapping(heights) << endl;
    return 0;
}
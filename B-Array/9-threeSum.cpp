#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &nums) {
    vector<vector<int> > result;
    int n = nums.size();
    if (n < 3) return result;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int lo = i+1, hi = n-1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] == -nums[i]) {
                tmp.clear();
                tmp.push_back(nums[i]);
                tmp.push_back(nums[lo]);
                tmp.push_back(nums[hi]);
                result.push_back(tmp);
                while (lo < n-1 && nums[lo+1] == nums[lo]) 
                    lo++;
                lo++;
            }
            else if (nums[lo] + nums[hi] < -nums[i])
                lo++;
            else 
                hi--;
        }
    }

    return result;
}

int main() {
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(0);
    vector<vector<int> > result = threeSum(nums);

    return 0;
}
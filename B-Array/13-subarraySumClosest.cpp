#include <iostream>
#include <vector>
#include <algorithm>
#include "limits.h"

using namespace std;


// 子序列的和等于前缀的和的差，要求子序列和最接近0，也就是求前缀和最接近。
// 因此将前缀和进行排序，计算出前缀和之间的最小差距，那他们之间的序列就是最接近0的子序列。
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first;
}

vector<int> subarraySumClosest(vector<int>& nums) {
    vector<pair<int, int>> sumArray;
    if (nums.size() == 1) return vector<int>(2, 0);
    sumArray.push_back(pair<int, int>(0, -1));
    int sum = 0;
    for (int i=0; i<nums.size(); i++) {
        sum += nums[i];
        sumArray.push_back(make_pair(sum, i));
    }

    sort(sumArray.begin(), sumArray.end());
    int gap = INT_MAX;
    vector<int> result;
    for (int i=1; i<sumArray.size(); i++) {
        if (sumArray[i].first-sumArray[i-1].first < gap) {
            result.clear();
            gap = sumArray[i].first - sumArray[i-1].first;
            int begin = (sumArray[i-1].second < sumArray[i].second)?sumArray[i-1].second:sumArray[i].second;
            int end = (sumArray[i-1].second < sumArray[i].second)?sumArray[i].second:sumArray[i-1].second;
            result.push_back(begin+1);
            result.push_back(end);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-3, 1, 1, -3, 5};
    vector<int> result = subarraySumClosest(nums);
    for (int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
}
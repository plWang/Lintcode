#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first;
}


// vector<int> twoSum(vector<int> &nums, int target) {
//     // write your code here
//     //First: sort
//     vector<pair<int, int> > pairlist;
//     for (int i=0; i<nums.size(); i++) {
//         pairlist.push_back(make_pair(nums[i], i+1));
//     }
//     sort(pairlist.begin(), pairlist.end(), compare);
//     vector<int> result;
//     if (nums.size() == 0) return result;
//     int lo=0, hi=nums.size()-1;
//     int mid;
//     while (lo <= hi) {
//         if (pairlist[lo].first + pairlist[hi].first == target) {
//             result.push_back(pairlist[lo].second);
//             result.push_back(pairlist[hi].second);
//             return result;
//         }
//         else if (pairlist[lo].first + pairlist[hi].first < target)
//             lo++;
//         else 
//             hi--;
//     }

//     return result;
// }

// int main() {
//     return 0;
// }


vector<int> twoSum(vector<int> &nums, int target) {
    // write your code here
    //First: sort
    unordered_map<int, int> map;
    vector<int> result;
    for (int i=0; i<nums.size(); i++) {
        if (map.find(target-nums[i]) != map.end()) {
            if (map[target-nums[i]] <= i+1) {
                result.push_back(map[target-nums[i]]);
                result.push_back(i+1);
                return result;
            }
            else {
                result.push_back(i+1);
                result.push_back(map[target-nums[i]]);
                return result;
            }
        }
        else {
            map[nums[i]] = i+1;
        }
    }
}
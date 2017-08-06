vector<vector<int> > fourSum(vector<int>& nums) {
    vector<vector<int> > result;
    if (nums.size() < 4) return result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i=0; i<=n-4; i++) {
        if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > 0) continue;
        if (nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < 0) continue;
        for (int j=i+1; j<=n-3; j++) {
            if (j > 1 && nums[j] == nums[j-1]) continue;
            if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > 0) continue;
            if (nums[i]+nums[j]+nums[n-2]+nums[n-1] < 0) continue;
            int lo = j+1, hi = n-1;
            int target = 0 - nums[i] - nums[j];
            vector<int> temp;
            while (lo < hi) {
                if (nums[lo] + nums[hi] == target) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    result.push_back(temp);
                    while (lo < n-1 && nums[lo+1] == nums[lo]) 
                        lo++;
                    lo++;
                }
                else if (nums[lo] + nums[hi] < target)
                    lo++;
                else 
                    hi--;
            }
        }
    }

    return result;
}
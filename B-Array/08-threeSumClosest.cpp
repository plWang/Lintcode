int threeSumClosest(vector<int> nums, int target) {
    // write your code here
    int n = nums.size();
    int closest = INT_MAX, int diff=INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++) {
        int tofind = target - nums[i];
        int lo = i+1, hi=n-1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] == tofind)
                return target;
            else if (nums[lo] + nums[hi] < tofind) {
                if (abs(nums[lo]+nums[hi]-tofind) < diff) {
                    diff = abs(nums[lo]+nums[hi]-tofind);
                    closest = nums[lo]+nums[hi]+nums[i];
                }
                lo++;
            }
            else {
                if (abs(nums[lo]+nums[hi]-tofind) < diff) {
                    diff = abs(nums[lo]+nums[hi]-tofind);
                    closest = nums[lo]+nums[hi]+nums[i];
                }
                hi--;
            }
        }
    }

    return closest;
}
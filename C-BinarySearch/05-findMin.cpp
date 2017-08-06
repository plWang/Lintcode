int findMin(vector<int>& nums) {
    int n = nums.size();
    int lo = 0, hi = n-1;
    if (nums[0] <= nums[n-1]) return nums[0]; //无旋转情况
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
            return nums[mid];
        else if (nums[mid] > nums[hi])
            lo = mid+1;
        else 
            hi = mid-1;
    }
}
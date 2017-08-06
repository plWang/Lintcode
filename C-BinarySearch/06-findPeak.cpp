int findPeak(vector<int>& nums) {
    int n = nums.size();
    int lo = 0, hi = n-1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (mid > 0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        else if (mid != n-1 && nums[mid] < nums[mid+1])
            lo = mid+1;
        else
            hi = mid-1;
    }

    return -1;
}
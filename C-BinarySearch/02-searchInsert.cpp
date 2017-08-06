int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) return 0;
    int lo = 0, hi = n-1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            lo = mid+1;
        else {
            if (mid == 0 || (mid > 0 && nums[mid-1] < target))
                return mid;
            hi = mid - 1;
        }
    }
}
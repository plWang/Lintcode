int binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    int lo = 0, hi = n-1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            if (mid == 0 || (mid > 0 && nums[mid-1] != nums[mid]))
                return mid;
            else hi = mid-1;
        }
        else if (nums[mid] < target)
            lo = mid + 1;
        else 
            hi = mid-1;
    }

    return -1;
}
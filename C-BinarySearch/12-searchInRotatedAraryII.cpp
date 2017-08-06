int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    int lo = 0, hi = n-1;
    int mid, rotate;
    
    // 寻找旋转数组中的最小值（有重复）
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] > nums[hi]) 
            lo = mid+1;
        else if (nums[mid] < nums[hi])
            hi = mid;
        else {
            hi--;
        }
    }
    rotate = lo;

    lo = 0, hi = n-1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int realmid = (mid + rotate) % n;
        if (nums[realmid] == target)
            return true;
        else if (nums[realmid] < target)
            lo = mid+1;
        else 
            hi = mid -1;
    }

    return false;
}
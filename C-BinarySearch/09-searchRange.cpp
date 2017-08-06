vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return vector<int>(2, -1);
    vector<int> result;
    int lo = 0, hi = n-1;
    int mid;
    int begin = -1, end = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            if (mid == 0 || (mid > 0 && nums[mid-1] != nums[mid])) {
                begin = mid;
                break;
            }
            else {
                hi = mid-1;
            }
        }
        else if (nums[mid] < target)
            lo = mid+1;
        else 
            hi = mid-1;
    }
    if (begin == -1) return vector<int>(2, -1);

    lo = 0, hi = n-1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target) {
            if (mid == n-1 || (mid < n-1 && nums[mid+1] != nums[mid])) {
                end = mid;
                break;
            }
            else {
                lo = mid+1;
            }
        }
        else if (nums[mid] < target)
            lo = mid+1;
        else 
            hi = mid-1;
    }
    if (end == -1) return vector<int>(2, -1);

    result.push_back(begin);
    result.push_back(end);
    return result;
}
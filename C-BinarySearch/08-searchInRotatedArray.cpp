int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    int lo = 0, hi = n-1;
    int mid, rotate;
    // if (nums[0] <= nums[n-1]) rotate = 0;
    // else {
    //     while (lo <= hi) {
    //         mid = (lo + hi) / 2;
    //         if (nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
    //             break;
    //         else if (nums[mid] > nums[hi])
    //             lo = mid+1;
    //         else 
    //             hi = mid-1;
    //     }
    //     retate = mid;
    // }

    // find smallest value
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] > nums[hi]) lo = mid+1;
        else hi = mid;
    }

    lo = 0, hi = n-1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int realmid = (mid + rotate) % n;
        if (nums[realmid] == target)
            return realmid;
        else if (nums[realmid] < target)
            lo = mid+1;
        else 
            hi = mid -1;
    }

    return -1;
}
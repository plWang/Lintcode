int partitionArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;
    int lo = 0, hi = n;
    int i = -1, j = hi;
    while (lo <= hi) {
        while (nums[++i] <= k)
            if (i >= hi) break;
        while (nums[--j] >= k)
            if (hi <= lo) break;
        if (i >= j) break;
        swap(nums[i], nums[j]);
    }

    return (i==0 && j==0)?0:j+1;
}
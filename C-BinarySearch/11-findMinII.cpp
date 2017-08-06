//如果用二分查找的话，
// 当中间的值大于最右边的值的时候，那么最小值一定在mid和right中间，
// 当中间值小于最左边值的时候，最小值一定在left和mid中间，
//只有当right mid 和 left的值相同的时候才无法确定最小值在哪个区间，
//无法确定的时候让right的值自减就好，因为right的一定是大于等于最小值的
int findMin(vector<int> &nums) {
    // write your code here
    int n = nums.size()-1;
    int lo = 0, hi = nums.size()-1;
    int mid;
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
    
    return nums[lo];
}
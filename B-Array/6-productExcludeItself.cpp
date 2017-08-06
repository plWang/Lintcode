vector<long long> productExcludeItself(vector<int> &nums) {
    // write your code here
    int n = nums.size();
    vector<long long> B(n, 1);
    long long res = 1;
    for (int i=0; i<n; i++) {
        B[i] = res;
        res *= nums[i];
    }

    res = 1;
    for (int i=n-1; i>=0 ;i--) {
        B[i] *= res;
        res *= nums[i];
    }
}
int firstMissingPositive(vector<int>& nums) {
    for (int i=0; i<nums.size(); i++) {
        while (A[i] <= n && A[i] > 0 && A[A[i]-1] != A[i]) {
            swap(A[A[i]-1], A[i]);
        }
    }

    for (int i=0; i<nums.size(); i++) {
        if (A[i] != i+1)
            return i+1;
    }

    return n+1;
}
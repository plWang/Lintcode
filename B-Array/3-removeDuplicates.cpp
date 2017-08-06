int removeDuplicates(vector<int> &nums) {
    // write your code here
    int i=0, j=0;
    for (int i=0; i<nums.size(); i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            nums[j++] = nums[i];
        }
    }
    
    return j;
}
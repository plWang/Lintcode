vector<int> subarraySum(vector<int> &nums) {
    unordered_map<int, int> map;
    int sum = 0;
    vector<int> result;
    for (int i=0; i<nums.size(); i++) {
        sum += nums[i];
        vector<int> temp;
        if (sum == 0) {
            result.push_back(0);
            result.push_back(i);
            return result;
        }
        if (map.find(sum) != map.end()) {
            result.push_back(map[sum]+1);
            result.push_back(i);
            return result;
        }
        else {
            map[sum] = i;
        }
    }

    return result;
}

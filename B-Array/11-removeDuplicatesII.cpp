#include <iostream>
#include <vector>

using namespace std;

//与“删除重复数字I”不同的是需要用一个变量记录当前数字出现的次数
int removeDuplicates(vector<int>& nums) {
    int i=0, j=0;
    if (nums.size() == 0) return 0;
    int count=1;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i] == nums[j] && count < 2) {
            count++;
            nums[++j] = nums[i];
        }
        else if (nums[i] != nums[j]){
            count = 1;
            nums[++j] = nums[i];
        }
    }

    return j+1;
}

int main() {
    int a[] = {-1014,-1014,-1014,-1006,-1005,-1004,-1002,-1001,-1000,-999,-999,-998,-997,-997,-997,-996,-995,-995,-994,-993,-992,-992,-992,-992,-991,-991,-991,-990,-990,-990,-990,-990,-989,-988,-988,-987,-987,-986,-986,-985,-985,-984,-983,-982,-982,-981,-981,-980,-980,-980};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    int j = removeDuplicates(nums);
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool compareStrings(string A, string B) {
    // write your code here
    if (A.size() < B.size()) return false;
    vector<int> map(256, 0);
    for (int i = 0; i < A.size(); i++) {
        map[A[i]]++;
    }
    
    for (int i = 0; i < B.size(); i++) {
        if (map[B[i]] <= 0) return false;
        map[B[i]]--;
    }
    
    return true;
}

int main() {
    return 0;
}
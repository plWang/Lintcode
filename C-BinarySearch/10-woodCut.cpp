#include <iostream>
#include <vector>
#include "limits.h"

using namespace std;

int woodCut(vector<int>& L, int k) {
    int n = L.size();
    long long sum = 0;
    int maxLen = INT_MIN;
    for (int i=0; i<n; i++) {
        sum += L[i];
        if (L[i] > maxLen)
            maxLen = L[i];
    }
    if (sum < k) return 0;
    long long lo = 1, hi = maxLen;
    long long mid, parts;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        parts = 0;
        for (int i=0; i<n; i++)
            parts += L[i] / mid;
        if (parts == k)
            lo = mid+1;
        else if (parts < k)
            hi = mid - 1;
        else 
            lo = mid + 1;
    }

    return lo-1;
}

int main() {
    int a[] = {2147483644,2147483645,2147483646,2147483647};
    vector<int> L(a, a+sizeof(a)/sizeof(int));
    int k = 4;
    int len = woodCut(L, k);

    return 0;
}
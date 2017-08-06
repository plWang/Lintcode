int sqrt(int x) {
    if (x == 0) return 0;
    int lo=1, hi=x;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (mid == x/mid) //不使用mid*mid与x比较，因为mid*mid可能越界
            return mid;
        else if (mid > x/mid)
            hi = mid-1;
        else {
            if (mid+1 > x / (mid+1)) return mid;
            lo = mid+1;
        }
    }

    return -1;
}
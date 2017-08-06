bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int lo = 0, hi = m*n-1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int i = mid / n;
        int j = mid - i*n;
        if (matrix[i][j] == target) 
            return true;
        else if (matrix[i][j] < target)
            lo = mid+1;
        else 
            hi = mid-1;
    }

    return false;
}
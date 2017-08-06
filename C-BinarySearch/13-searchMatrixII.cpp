int searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    int i = 0, j= n-1;
    int count = 0;
    wihle (i < m && j >= 0) {
        if (matrix[i][j] == target) {
            count++;
            j--;
        }
        else if (matrix[i][j] < target)
            i++;
        else 
            j--;
    }

    return count;
}
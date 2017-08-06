vector<int> mergeSortedArray(vector<int>& A, vector<int>& B) {
    vector<int> result;
    int m = A.size(), n = B.size();
    int i=0, j=0;
    while (i < m || j < n) {
        if (i >= m) 
            result.push_back(B[j++]);
        else if (j >= n) 
            result.push_back(A[i++]);
        else if (A[i] <= B[j])
            result.push_back(A[i++]);
        else 
            result.push_back(B[j++]);
    }

    return result;
}
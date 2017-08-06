// hint: 两个指针
int removeElement(vector<int> &A, int elem) {
    // write your code here
    int n = A.size();
    int i=0, j=0;
    for (int i=0; i<n; i++) {
        if (A[i] != elem)
            A[j++] = A[i];
    }
    return j;
}
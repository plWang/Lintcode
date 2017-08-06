void mergeSortedArray(int A[], int m, int B[], int n) {
    // write your code here
    int i=m-1, j=n-1, k=m+n-1;
    while (i >= 0  || j >= 0) {
        if (i < 0)
            A[k--] = B[j--];
        else if (j < 0)
            A[k--] = A[i--];
        else if (A[i] < B[j])
            A[k--] = B[j--];
        else 
            A[k--] = A[i--];
    }
}
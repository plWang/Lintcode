// class Solution {
// public:
//     /**
//      * Returns a index to the first occurrence of target in source,
//      * or -1  if target is not part of source.
//      * @param source string to be scanned.
//      * @param target string containing the sequence of characters to match.
//      */
//     int strStr(const char *source, const char *target) {
//         // write your code here
//         if (source == NULL || target == NULL) return -1;
//         if (*target == '\0') return 0;
    
//         const char *s = source;
//         const char *t = target;
//         int i = 0;
//         while (*source != '\0') {
//             if (*source == *target) {
//                 s = source;
//                 t = target;
//                 while (*s != '\0' && *t != '\0' && *s == *t) {
//                     s++;
//                     t++;
//                 }
//                 if (*t == '\0')
//                     return i;
//             }
//             source++;
//             i++;
//         }
//         return -1;
//     }
// };
#include <iostream>
#include <vector>

using namespace std;

// KMP　algorithm
vector<int> makeNext(const char *str, int n) {
    vector<int> next(n, 0);
    int q, k;
    for (q=1, k=0; q<n; q++) {
        while (k>0 && str[q] == str[k]) {
            k = next[k-1];
        }
        if (str[q] == str[k]) {
            k++;
        }
        next[q] = k;
    }

    return next;
}

int strStr(const char *source, const char *target) {
    if (source == NULL || target == NULL) return -1;  //空指针检查
    const char *ch = source;
    int m = 0, n = 0;
    while (*ch != '\0') {
        m++;
        ch++;
    }
    ch = target;
    while (*ch != '\0') {
        n++;
        ch++;
    }
    if (n == 0) return 0;　　　　　　　　//如果source==""或target==""
    else if (m == 0) return -1;

    int i, q;
    vector<int> next = makeNext(target, n);
    for (i=0, q=0; i<m; i++) {
        while (q>0 && *(target+q) != *(source+i)) {
            q = next[q-1];
        }
        if (*(target+q) == *(source+i)) {
            q++;
        }
        if (q == n) return i-n+1;
    }

    return -1;
}

int main() {
    return 0;
}
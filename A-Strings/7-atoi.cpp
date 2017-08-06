#include <iostream>
#include <string>
#include "limits.h"

using namespace std;

int atoi(string str) {
    int res = 0, n = str.size();
    int neg_flag = 0, start_flag = 0;
    int tmp;
    for (int i=0; i<n; i++) {
        if (str[i] == '+') {
            if (start_flag == 0)
                start_flag = 1;
            else break;
        }
        else if (str[i] == '-') {
            if (start_flag == 0) {
                start_flag = 1;
                neg_flag = 1;
            }
            else break;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            if (start_flag == 0)
                start_flag = 1;
            tmp = res * 10 + str[i] - '0';
            if (tmp / 10 != res)
                return (neg_flag==1)?INT_MIN:INT_MAX;
            res = tmp;
        } 
        else if (str[i] == ' ') {
            if (start_flag == 1) break;
        }
        else break;
    }

    if (neg_flag == 1 && res == INT_MAX) return INT_MIN;
    return (neg_flag==1)?-res:res;
}

int main() {
    string str;
    cin >> str;
    int res = atoi(str);
    cout << res << endl;
}
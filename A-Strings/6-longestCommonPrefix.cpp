int longestCommonPrefix(vector<string> &strs) {
    int n = strs.size();
    if (n == 0) return "";

    int common = 0;
    string prefix = "";
    for (int i=0; i<strs[0].size(); i++) {
        char c = strs[0][i];
        for (int j=1; j<n; j++) {
            if (i > strs[j].size()-1 || strs[j][i] != c)
                return prefix;
        }
        common++;
        prefix.push_back(c);
    }

    return prefix;
}
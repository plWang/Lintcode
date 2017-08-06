vector<string> anagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > map;
    for (s : strs) {
        string t = s;
        strSort(t);
        map[t].push_back(s);
    }

    for (auto m : map) {
        if (m.second.length > 1)
            return m.second;
    }
}

void strSort(string& s) {
    vector<int> chs(26, 0);
    for (char ch : s) {
        chs[ch-'a']++;
    }

    string result(s.size(), ' ');
    int t = 0;
    for (int i=0; i<26; i++) {
        for (int j=0; j<chs[i]; j++)
            s[t++] = 'a' + chs[i];
    }

}
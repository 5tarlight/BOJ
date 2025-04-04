vector<int> getPi(const string &p) {
    int m = p.size(), len = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (len && p[i] != p[len]) len = pi[len - 1];
        if (p[i] == p[len]) len++;
        pi[i] = len;
    }
    return pi;
}

vector<int> kmp(const string &s, const string &p) {
    vector<int> pi = getPi(p), ans;
    int n = s.size(), m = p.size(), i = 0, j = 0;
    while (i < n) {
        if (s[i] == p[j]) {
            i++; j++;
            if (j == m) { ans.push_back(i - j); j = pi[j - 1]; }
        } else {
            if (j) j = pi[j - 1];
            else i++;
        }
    }
    return ans;
}


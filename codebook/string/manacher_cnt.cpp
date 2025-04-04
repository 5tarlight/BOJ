long long manacher(const string& s) {
    string t;
    for (char c : s) { t += '#'; t += c; }
    t += '#';
    vector<int> p(t.size(), 0);
    int c = 0, r = 0;
    long long ans = 0;
    for (int i = 0; i < t.size(); i++) {
        int mirror = 2 * c - i;
        if (i < r) p[i] = min(r - i, p[mirror]);
        while (i + p[i] + 1 < t.size() && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;
        if (i + p[i] > r) { c = i; r = i + p[i]; }
        ans += (p[i] + 1) / 2;
    }
    return ans;
}


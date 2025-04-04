int manacher(const string& s) {
    string t;
    for (char c : s) { t += '#'; t += c; }
    t += '#';
    vector<int> a(t.size());
    int r = 0, p = 0, ans = 0;
    for (int i = 0; i < t.size(); i++) {
        if (i <= r) a[i] = min(a[2 * p - i], r - i);
        while (i - a[i] - 1 >= 0 && i + a[i] + 1 < t.size() && t[i - a[i] - 1] == t[i + a[i] + 1])
            a[i]++;
        if (i + a[i] > r) { r = i + a[i]; p = i; }
        ans = max(ans, a[i]);
    }
    return ans;
}


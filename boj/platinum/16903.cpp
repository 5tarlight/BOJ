#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

using ll = long long;

constexpr int BIT = 32;

struct Trie {
    bool isEnd = false;
    int cnt = 0;
    ll value = 0;
    Trie* child[2] = {nullptr, nullptr};

    void insert(const string& s, ll x) {
        Trie* node = this;
        for (char c : s) {
            int b = c - '0';
            if (!node->child[b]) node->child[b] = new Trie();
            node = node->child[b];
        }
        node->isEnd = true;
        node->value = x;
        node->cnt++;
    }

    ll maxXor(const string& s, ll x) {
        Trie* node = this;
        for (char c : s) {
            int b = c - '0';
            if (node->child[b ^ 1]) node = node->child[b ^ 1];
            else node = node->child[b];
        }
        return x ^ node->value;
    }
};

string toBinary(ll x) {
    string s(BIT, '0');
    for (int i = BIT - 1; i >= 0; i--) {
        if (x & 1) s[i] = '1';
        x >>= 1;
    }
    return s;
}

bool removed;

void erase(Trie*& node, const string& s, int idx) {
    if (!node) return;

    if (idx == (int)s.size()) {
        node->cnt--;
        if (node->cnt == 0) {
            node->isEnd = false;
            bool leaf = true;
            for (int i = 0; i < 2; i++)
                if (node->child[i]) leaf = false;
            if (leaf) {
                node = nullptr;
                removed = true;
            }
        }
        return;
    }

    int b = s[idx] - '0';
    erase(node->child[b], s, idx + 1);

    if (removed) {
        bool leaf = true;
        for (int i = 0; i < 2; i++)
            if (node->child[i]) leaf = false;
        if (leaf && !node->isEnd) {
            node = nullptr;
        }
    }
}

int main() {
    fio();

    int q;
    cin >> q;

    Trie* root = new Trie();
    root->insert(toBinary(0), 0);

    while (q--) {
        int type;
        ll x;
        cin >> type >> x;

        string b = toBinary(x);

        if (type == 1) {
            root->insert(b, x);
        }
        else if (type == 2) {
            removed = false;
            erase(root, b, 0);
        }
        else {
            cout << root->maxXor(b, x) << '\n';
        }
    }
}
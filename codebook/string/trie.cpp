struct Trie {
    Trie *ch[26]; bool end;
    Trie() {
        end = false;
        for (int i = 0; i < 26; i++) ch[i] = nullptr;
    }
    ~Trie() { for (int i = 0; i < 26; i++) delete ch[i]; }
    void insert(const char *s) {
        if (!*s) { this->end = true; return; }
        int cur = *s - 'A';
        if (!ch[cur]) ch[cur] = new Trie;
        ch[cur]->insert(s + 1);
    }
    bool find(const char *s) {
        if (!*s) return this->end;
        int cur = *s - 'A';
        if (!ch[cur]) return false;
        return ch[cur]->find(s + 1);
    }
    bool findPrefix(const char *s) {
        if (!*s) return true;
        int cur = *s - 'A';
        if (!ch[cur]) return false;
        return ch[cur]->findPrefix(s + 1);
    }
}


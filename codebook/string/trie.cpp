struct Trie {
    bool end;
    Trie *nxt[26];

    Trie() : end(false) { memset(nxt, 0, sizeof(nxt)); }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            delete nxt[i];
    }

    void insert(const char *key) {
        if (*key == '\0')
            end = true;
        else {
            int cur = *key - 'A';
            if (nxt[cur] == NULL)
                nxt[cur] = new Trie();
            nxt[cur]->insert(key + 1);
        }
    }

    Trie *find(const char *key) {
        if (*key == '\0')
            return this;
        int cur = *key - 'A';
        if (nxt[cur] == NULL)
            return NULL;
        return nxt[cur]->find(key + 1);
    }
};

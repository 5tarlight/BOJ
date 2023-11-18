#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> seg;

seg a;
seg sumTree;
seg minTree;
ll maxScore = -1;
int n;

void init(int node, int start, int end) {
    if (start == end) {
        sumTree[node] = a[start];
        minTree[node] = a[start];
    } else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
        minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
    }
}

pair<ll, ll> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return make_pair(0, -1);
    if (left <= start && end <= right)
        return make_pair(sumTree[node], minTree[node]);

    pair<ll, ll> l = query(node * 2, start, (start + end) / 2, left, right);
    pair<ll, ll> r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    ll m;
    if (l.second == -1)
        m = r.second;
    else if (r.second == -1)
        m = l.second;
    else
        m = min(r.second, l.second);
    return make_pair(l.first + r.first, m);
}

void update(int node, int start, int end, int index, long long val) {
    if (index < start || index > end)
        return;
    if (start == end) {
        a[index] = val;
        sumTree[node] = val;
        minTree[node] = val;
        return;
    }
    update(node * 2, start, (start + end) / 2, index, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
}

ll search(int s, int e) {
    if (s == e)
        return a[s] * a[s];
    else {
        int mid = (s + e) / 2;
        ll score = max(search(s, mid), search(mid + 1, e));
        int l = mid;
        int r = mid + 1;

        ll localMin = min(a[r], a[l]);
        ll localSum = a[r] + a[l];
        ll localScore = localMin * localSum;

        while (l > s || r < e) {
            if (l > s && (r == e || a[l - 1] > a[r + 1])) {
                l--;
                localMin = min(localMin, a[l]);
                localSum += a[l];
            } else {
                r++;
                localMin = min(localMin, a[r]);
                localSum += a[r];
            }
            localScore = max(localScore, localSum * localMin);
        }

        score = max(score, localScore);
        return score;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a = seg(n);
    int h = (int)ceil(log2(n));
    int treeSize = 1 << (h + 1);
    minTree = seg(treeSize);
    sumTree = seg(treeSize);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init(1, 0, n - 1);

    cout << search(0, n - 1);
}

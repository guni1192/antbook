#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define lliv vector<long long int>

bool dfs(lli n, lliv a, lli k, lli i, lli sum) {
    if (i == n) return sum == k;
    if (dfs(n, a, k, i + 1, sum)) return true;
    if (dfs(n, a, k, i + 1, sum + a[i])) return true;
    return false;
}

void solve(lli n, lliv a, lli k) {
    if (dfs(n, a, k, 0, 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(void) {
    lliv a;
    lli n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        lli t;
        cin >> t;
        a.push_back(t);
    }

    lli k;
    cin >> k;

    solve(n, a, k);

    return 0;
}

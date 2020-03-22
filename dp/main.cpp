#include <bits/stdc++.h>
using namespace std;

// product.first: weight
// product.second: value
typedef pair<int, int> Product;
typedef vector<Product> Products;

constexpr int MAX_N = 10000;
constexpr int MAX_W = 10000;

int dp[MAX_N + 1][MAX_W + 1];

int rec(Products products, int n, int i, int j) {
    int res;
    if (products.size() == i) {
        res = 0;
    } else if (j < products[i].first) {
        res = rec(products, n, i + 1, j);
    } else {
        res = max(rec(products, n, i + 1, j),
                  rec(products, n, i + 1, j - products[i].first) +
                      products[i].second);
    }
    return res;
}

int rec_memo(Products products, int n, int i, int j) {
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    int res;
    if (products.size() == i) {
        res = 0;
    } else if (j < products[i].first) {
        res = rec_memo(products, n, i + 1, j);
    } else {
        res = max(rec_memo(products, n, i + 1, j),
                  rec_memo(products, n, i + 1, j - products[i].first) +
                      products[i].second);
    }
    return dp[i][j] = res;
}

int main(void) {
    clock_t start, end;
    int n;
    cin >> n;

    Products products;

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        products.push_back(Product(w, v));
    }

    int weight;
    cin >> weight;

    start = clock();
    cout << rec(products, n, 0, weight) << endl;
    end = clock();
    printf("rec(): %.2f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    memset(dp, -1, sizeof(dp));
    cout << rec_memo(products, n, 0, weight) << endl;
    end = clock();
    printf("rec_memo(): %.2f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

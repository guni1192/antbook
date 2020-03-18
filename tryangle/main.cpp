#include <bits/stdc++.h>

int solve(const std::vector<int> a, const int n) {
    int ans = 0;
    int loop = 0;
    for (int i = 0; i < (n / 2); i++) {
        for (int j = i + 1; j < (n - 1); j++) {
            for (int k = j + 1; k < n; k++) {
                loop++;
                const int max_value = std::max(a[i], std::max(a[j], a[k]));
                const int sum = a[i] + a[j] + a[k];
                if (sum - max_value > max_value) {
                    ans = sum;
                }
            }
        }
    }
    std::cout << loop << std::endl;

    return ans;
}

int solve_default(const std::vector<int> a, const int n) {
    int ans = 0;
    int loop = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                loop++;
                const int max_value = std::max(a[i], std::max(a[j], a[k]));
                const int sum = a[i] + a[j] + a[k];
                if (sum - max_value > max_value) {
                    ans = sum;
                }
            }
        }
    }
    std::cout << loop << std::endl;

    return ans;
}

int main(void) {
    int n;
    std::vector<int> a;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }

    std::cout << solve(a, n) << std::endl;
    std::cout << solve_default(a, n) << std::endl;
    return 0;
}

/*

    2 3 4 5 6
    2 3 4
    2 3   5
    2 3     6
    2   4 5
    2   4   6
      3 4 5
      3 4   6
      3   5 6
        4 5 6


 */

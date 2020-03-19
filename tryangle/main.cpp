#include <bits/stdc++.h>

using namespace std;

typedef std::vector<int> Pattern;

void generate_combination(std::vector<Pattern>& result, std::vector<int> arr,
                          Pattern data, int start, int end, int index, int r);

void print_array(const std::vector<int> array) {
    for (auto value : array) {
        printf("%d ", value);
    }
    puts("");
}

void init_combination(std::vector<Pattern>& result, std::vector<int> arr, int n,
                      int r) {
    Pattern data(r);

    generate_combination(result, arr, data, 0, n - 1, 0, r);
}

void generate_combination(std::vector<Pattern>& result, std::vector<int> arr,
                          Pattern data, int start, int end, int index, int r) {
    if (index == r) {
        result.push_back(data);
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        generate_combination(result, arr, data, i + 1, end, index + 1, r);
    }
}

int solve_use_combination(const std::vector<int> a, const int n) {
    int ans = 0;
    int loop = 0;
    std::vector<std::vector<int>> patterns;
    init_combination(patterns, a, n, 3);
    for (auto pattern : patterns) {
        loop++;
        const int max_value =
            std::max(pattern[0], std::max(pattern[1], pattern[2]));
        const int sum = pattern[0] + pattern[1] + pattern[2];
        if (sum - max_value > max_value) {
            ans = sum;
        }
    }
    std::cout << "loop: " << loop << std::endl;

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
    std::cout << "loop: " << loop << std::endl;

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

    std::cout << solve_default(a, n) << std::endl;
    std::cout << solve_use_combination(a, n) << std::endl;
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

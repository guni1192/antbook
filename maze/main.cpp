#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define lliv vector<long long int>

const int MAX_N = 100, MAX_M = 100;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
typedef pair<int, int> Point;

Point find_point(const vector<string> maze, const char ch, const int n,
                 const int m);
void debug(const vector<string> maze, const int n, const int m);
void solve(const vector<string> maze, const int n, const int m);

int bfs(const vector<string> maze, const int n, const int m, Point start,
        Point goal);

void debug(const vector<string> maze, const int n, const int m) {
    for (auto line : maze) {
        cout << line << endl;
    }

    cout << "n: " << n << endl;
    cout << "m: " << m << endl;

    Point start = find_point(maze, 'S', n, m);
    printf("Start: (%d, %d)", start.first, start.second);

    Point goal = find_point(maze, 'G', n, m);
    printf("Start: (%d, %d)", goal.first, goal.second);
}

Point find_point(const vector<string> maze, const char ch, const int n,
                 const int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == ch) {
                return Point(i, j);
            }
        }
    }

    return Point(-1, -1);
}
int bfs(const vector<string> maze, const int n, const int m, Point start,
        Point goal) {
    queue<Point> q;
    int inf = std::numeric_limits<int>::infinity();
    vector<int> t(m, inf);
    vector<vector<int>> d(n, t);
    q.push(start);

    while (q.size()) {
        Point p = q.front();
        q.pop();
        if (p == goal) break;
    }

    for (int i = 0; i < 4; i++) {
        int nx = p.first + dx[i], ny = p.second + dy[i];
    }
}

void solve(const vector<string> maze, const int n, const int m) {
    debug(maze, n, m);
    Point start = find_point(maze, 'S', n, m);
    Point goal = find_point(maze, 'G', n, m);
    cout << bfs(maze, n, m, start, goal) << endl;
}

int main(void) {
    int n, m;

    cin >> n;
    cin >> m;

    vector<string> maze;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        maze.push_back(line);
    }

    solve(maze, n, m);

    return 0;
}

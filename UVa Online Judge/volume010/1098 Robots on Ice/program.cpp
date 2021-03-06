// Robots on Ice
// UVa ID: 1098
// Verdict: Accepted
// Submission Date: 2019-03-25
// UVa Run Time: 4.050s
//
// 版权所有（C）2019，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int m, n, cnt, used[8][8], T;
int offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int checkIn[4][2], checkMove[4], visited[8][8];

int dfs(int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n) return 0;
    if (visited[r][c] || used[r][c]) return 0;
    visited[r][c] = 1;
    return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1);
}

inline bool go(int r, int c, int moves, int spots)
{
    if (r < 0 || r >= m || c < 0 || c >= n) return false;
    if (used[r][c]) return false;
    if (r == checkIn[spots][0] && c == checkIn[spots][1])
        if (moves != checkMove[spots])
            return false;
    if (moves == checkMove[spots])
        if (r != checkIn[spots][0] || c != checkIn[spots][1])
            return false;
    int needed = abs(r - checkIn[spots][0]) + abs(c - checkIn[spots][1]);
    if (moves + needed > checkMove[spots])
        return false;

    used[r][c] = 1;
    memset(visited, 0, sizeof(visited));
    int unused = dfs(0, 1);
    used[r][c] = 0;
    if (unused != (T - moves))
        return false;

    if (r == 0 && c == 1)
        if (moves != T)
            return false;

    return true;
}

void backtrack(int r, int c, int moves, int spots)
{
    if (moves == T) { cnt++; return; }
    if (r == checkIn[spots][0] && c == checkIn[spots][1]) spots++;
    int rr, cc;
    for (int k = 0; k < 4; k++)
    {
        rr = r + offset[k][0], cc = c + offset[k][1];
        if (go(rr, cc, moves + 1, spots))
        {
            used[rr][cc] = 1;
            backtrack(rr, cc, moves + 1, spots);
            used[rr][cc] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases = 0;
    checkIn[3][0] = 0, checkIn[3][1] = 1;
    while (cin >> m >> n)
    {
        if (m == 0) break;
        for (int i = 0; i < 3; i++)
        {
            cin >> checkIn[i][0] >> checkIn[i][1];
            checkMove[i] = (i + 1) * m * n / 4;
        }
        T = m * n, checkMove[3] = m * n;
        memset(used, cnt = 0, sizeof(used));
        used[0][0] = 1;
        backtrack(0, 0, 1, 0);
        cout << "Case " << ++cases << ": " << cnt << '\n';
    }

    return 0;
}

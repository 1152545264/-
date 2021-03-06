// Hartals （罢工）
// PC/UVa IDs: 110203/10050, Popularity: B, Success rate: high Level: 2
// Verdict: Accepted
// Submission Date: 2011-05-23
// UVa Run Time: 0.012s
//
// 版权所有（C）2011，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

int getLostDays(vector < int >parameters, int days)
{
    int lostDays = 0;
    for (int d = 0; d < days; d++)
    {
        int residue = d % 7;
        if (residue == 5 || residue == 6)
            continue;

        for (int p = 0; p < parameters.size(); p++)
        {
            if ((d + 1) % parameters[p] == 0)
            {
                lostDays++;
                break;
            }
        }
    }

    return lostDays;
}

int main(int argc, char *argv[])
{
    int cases, parties, days;
    vector < int >parameters;

    cin >> cases;
    while ((cases--) > 0)
    {
        cin >> days >> parties;

        parameters.resize(parties);
        for (int i = 0; i < parties; i++)
            cin >> parameters[i];

        cout << getLostDays(parameters, days) << endl;
    }

    return 0;
}

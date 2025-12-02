#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;

    int at[n], bt[n];
    vector<pair<int, int>> p;

    for (i = 0;
         i < n; i++)
    {
        cin >> at[i] >> bt[i];
        p.push_back({at[i], bt[i]});
    }

    sort(p.begin(), p.end());

    int time = p[0].first;
    int ct[n], tat[n], wt[n];
    int tot_tat = 0;
    int tot_wt = 0;

    for (i = 0; i < n; i++)
    {
        if (time < p[i].first)
        {
            time = p[i].first;
        }

        time += p[i].second;
        ct[i] = time;
        tat[i] = ct[i] - p[i].first;
        wt[i] = tat[i] - p[i].second;
        tot_tat += tat[i];
        tot_wt += wt[i];
    }

    cout << "AT    BT    CT    TAT    WT" << endl;

    for (i = 0; i < n; i++)
    {
        cout << p[i].first << "     " << p[i].second << "     " << ct[i] << "      " << tat[i] << "     " << wt[i] << endl;
    }

    cout << "Avg TAT and WT" << endl;
    cout << tot_tat / n << " and " << tot_wt / n << endl;

    return 0;
}
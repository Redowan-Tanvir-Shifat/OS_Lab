#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Input:Number of Process, Arrival time and Burst Time
    int n, i;
    cin >> n; // input number of process
    int a[n], b[n];
    vector<pair<int, int>> v;
    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i]; // taking arrival and burst time of process i
        // cout<<a[i]<<" "<<b[i]<<endl;
        v.push_back({a[i], b[i]}); // first element AT, 2nd element BT
    }

    sort(v.begin(), v.end());
    int time = v[0].first; // initial time is arrival time of first process
    int ct[n], tat[n], wt[n];
    int total_tat = 0;
    int total_wt = 0;

    for (i = 0; i < n; i++)
    {
        if (time < v[i].first)
        {
            time = v[i].first; // if CPU is idle, move time to arrival time of current process
        }

        time = time + v[i].second;
        ct[i] = time;
        tat[i] = ct[i] - v[i].first;  // tat = ct - at
        wt[i] = tat[i] - v[i].second; // wt = tat - bt
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "AT          BT            CT           TAT        WT" << endl;

    for (i = 0; i < n; i++)
    {
        cout << v[i].first << "         " << v[i].second << "          " << ct[i] << "          " << tat[i] << "           " << wt[i] << endl;
    }

    // Average turn around time and average waiting time
    cout << " Avg TAT and WT " << endl;
    cout << total_tat / n << "    " << total_wt / n << endl;
}
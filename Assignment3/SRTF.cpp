#include <bits/stdc++.h>
using namespace std;
struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, start_time;
} ps[100];
int main()
{
    int bt_remaining[100];

    int n;
    cout << "enter the number of Process" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Arrival Time for " << i + 1 << " :";
        cin >> ps[i].at;

        cout << "Enter the Burst Time for " << i + 1 << " :";
        cin >> ps[i].bt;

        bt_remaining[i] = ps[i].bt;

        ps[i].pid = i + 1;
    }

    int sumTat = 0;
    int sumWt = 0;

    int completed = 0;
    int current_time = 0;

    bool is_completed[n] = {0};

    while (completed != n)
    {
        int min_index = -1;
        int minimum_burst = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == false)
            {
                if (bt_remaining[i] < minimum_burst)
                {
                    minimum_burst = bt_remaining[i];
                    min_index = i;
                }

                if (bt_remaining[i] == minimum_burst)
                {
                    if (ps[i].at < ps[min_index].at)
                    {
                        minimum_burst = bt_remaining[i];
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            // if (bt_remaining[min_index] == ps[min_index].bt)
            // {
            //     ps[min_index].start_time = current_time;
            // }
            bt_remaining[min_index] -= 1;
            current_time++;

            if (bt_remaining[min_index] == 0)
            {

                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;

                sumTat += ps[min_index].tat;
                sumWt += ps[min_index].wt;

                completed++;
                is_completed[min_index] = true;
            }
        }
    }

    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < n; i++)
    {

        cout << i + 1 << "\t" << ps[i].at << "\t" << ps[i].bt << "\t" << ps[i].ct << "\t" << ps[i].tat << "\t" << ps[i].wt << "\t" << endl;
    }

    return 0;
}
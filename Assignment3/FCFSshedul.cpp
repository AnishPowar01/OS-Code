#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    cout << "Enter the number of Process" << endl;
    cin >> n;

    int PID[n], AT[n], BT[n], CT[n], TAT[n], WT[n];

    for (int i = 0; i < n; i++)
    {
        PID[i] = i + 1;

        cout << "Enter the AT Of Process" << i + 1 << " :";
        cin >> AT[i];

        cout << "Enter the BT Of Process" << i + 1 << " :";
        cin >> BT[i];
    }

    // Swap according to arrival time

    for (int i = 0; i < n; i++)
    {
        int index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (AT[j] < AT[index])
            {
                index = j;
            }
        }

        // SWAP AT

        swap(AT[index], AT[i]);

        //  SWAp BT
        swap(BT[index], BT[i]);

        // SWAP PID

        swap(PID[index], PID[i]);
    }

    CT[0] = AT[0] + BT[0];

    for (int i = 1; i < n; i++)
    {
        CT[i] = CT[i - 1] + BT[i];
    }

    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
    }

    for (int i = 0; i < n; i++)
    {
        WT[i] = TAT[i] - BT[i];
    }

    int TotWT = 0;
    int TowTAT = 0;

    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << PID[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\t" << endl;

        TowTAT += TAT[i];
        TotWT += WT[i];
    }
    

    cout << "Avg Wt " << (float)TotWT / (float)n;
    cout << "Avg tat " << (float)TowTAT / (float)n;
    return 0;
}
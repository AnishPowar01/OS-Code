#include <bits/stdc++.h>

using namespace std;

// A structure "process_struct" is defined to store the details of each process, such as its process ID, arrival time, burst time, completion time, waiting time, turnaround time, response time, start time, and remaining burst time.
struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, start_time;
    int bt_remaining;
} ps[100];

// Two functions are defined to sort the process_struct array based on either arrival time or process ID.
bool comparatorAT(struct process_struct a, struct process_struct b)
{
    int x = a.at;
    int y = b.at;
    return x < y;
}
bool comparatorPID(struct process_struct a, struct process_struct b)
{
    int x = a.pid;
    int y = b.pid;
    return x < y;
}

// The main function starts by reading the total number of processes, arrival time of each process, and burst time of each process from the user.
int main()
{
    int n, index;

    queue<int> q;
    bool visited[100] = {false};
    int current_time = 0;
    int completed = 0, tq;
    cout << "Enter total number of processes: ";
    cin >> n;
    float sum_tat = 0, sum_wt = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Process " << i << " Arrival Time: ";
        cin >> ps[i].at;
        ps[i].pid = i;
    }
    for (int i = 0; i < n; i++)
    {

        cout << "\nEnter Process " << i << " Burst Time: ";
        cin >> ps[i].bt;
        ps[i].bt_remaining = ps[i].bt;
    }
    // The time quantum is also read from the user.
    cout << "\nEnter time quanta: ";
    cin >> tq;
    // sort structure on the basis of Arrival time in increasing order
    sort(ps, ps + n, comparatorAT);

    // A queue is created to store the index of the processes that are ready to execute.

    q.push(0);
    visited[0] = true;
    while (completed != n)
    {

        // The index of the first process in the queue is popped and executed for a time quantum. If the process is executing for the first time, its start time is set to the current time.

        index = q.front();
        q.pop();

        // If the process has burst time remaining, it is pushed back into the queue. If not, the process is marked as completed, and its completion time, waiting time, turnaround time, and response time are calculated.
        if (ps[index].bt_remaining - tq > 0)
        {
            ps[index].bt_remaining -= tq;
            current_time += tq;
        }

        else
        {
            current_time += ps[index].bt_remaining;

            ps[index].bt_remaining = 0;

            completed++;

            ps[index].ct = current_time;
            ps[index].tat = ps[index].ct - ps[index].at;
            ps[index].wt = ps[index].tat - ps[index].bt;

            sum_tat += ps[index].tat;

            sum_wt += ps[index].wt;
        }

        // check which new Processes needs to be pushed to Ready Queue from Input list
        // The next set of processes are added to the queue based on their arrival time and remaining burst time.

        for (int i = 1; i < n; i++)
        {
            if (ps[i].bt_remaining > 0 && ps[i].at <= current_time && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
        // check if Process on CPU needs to be pushed to Ready Queue
        if (ps[index].bt_remaining > 0)
            q.push(index);
        // if queue is empty, just add one process from list, whose remaining burst time > 0
        if (q.empty())
        {

            for (int i = 1; i < n; i++)
            {
                if (ps[i].bt_remaining > 0)
                {
                    q.push(i);
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    sort(ps, ps + n, comparatorPID);
    // Output
    // Finally, the details of each process such as its arrival time, burst time, completion time, waiting time, turnaround time, and response time are printed in a tabular format.
    cout << "\nP No.\tAT\tBurst Time\tCT\t\tTAT\t\tWT\t\tRT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << ps[i].at << "\t\t" << ps[i].bt << "\t\t" << ps[i].ct << "\t\t" << ps[i].tat << "\t\t" << ps[i].wt << "\t\t"
             << endl;
    cout << endl;
    cout << "\nAverage Turn Around time= " << (float)sum_tat / n;
    cout << "\nAverage Waiting Time= " << (float)sum_wt / n;
    return 0;
}
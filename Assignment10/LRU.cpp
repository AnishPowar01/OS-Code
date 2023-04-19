#include <bits/stdc++.h>
using namespace std;
struct PageTable
{
    int frame_no;
    int last_access_time;
    bool valid;
};

bool isPageFound(struct PageTable PT[], int page)
{
    if (PT[page].valid == 1)
    {
        return true;
    }

    return false;
}

void printFrame(int frame[], int no_of_frame)
{
    for (int i = 0; i < no_of_frame; i++)
    {
        cout << frame[i] << " ";
    }

    cout << endl;
}

void updateFrame(struct PageTable PT[], int page, int frame, int status, int time)
{
    PT[page].valid = status;

    if (status == 1)
    {
        PT[page].frame_no = frame;
        PT[page].last_access_time = time;
    }
}

void serachLRUIndex(struct PageTable PT[], int frame[], int frame_no, int *LRU_index)
{

    int min = INT_MAX;

    for (int i = 0; i < frame_no; i++)
    {

        if (PT[frame[i]].last_access_time < min)
        {
            min = PT[frame[i]].last_access_time;
            *LRU_index = i;
        }
    }
}
int main()
{

    int n;

    cout << "Enter the number of pages" << endl;
    cin >> n;

    int reference_string[n];

    cout << "Enter the reference string" << endl;

    for (int i = 0; i < n; i++)
    {

        cin >> reference_string[i];
    }

    int no_of_frames;

    cout << "Enter the number frames you want to allocate" << endl;
    cin >> no_of_frames;

    int frame[no_of_frames];

    // for (int i = 0; i < no_of_frames; i++)
    // {
    //     frame[i] = -1;
    // }

    memset(frame, -1, no_of_frames);
    struct PageTable PT[50];

    for (int i = 0; i < 50; i++)
    {
        PT[i].valid = 0;
    }

    int page_fault = 0;
    bool isOverflow = false;
    int current = 0;

    // Algorithm

    for (int i = 0; i < n; i++)
    {
        if (!isPageFound(PT, reference_string[i]))
        {
            page_fault++;

            if (isOverflow == false && current < no_of_frames)
            {

                frame[current] = reference_string[i];
                printFrame(frame, no_of_frames);
                updateFrame(PT, reference_string[i], current, 1, i);

                current = current + 1;

                if (current == no_of_frames)
                {
                    isOverflow = true;
                }
            }
            else
        {
            int LRU_index;
            serachLRUIndex(PT, frame, no_of_frames, &LRU_index);
            updateFrame(PT, frame[LRU_index], -1, 0, i);

            frame[LRU_index] = reference_string[i];
            printFrame(frame, no_of_frames);

            updateFrame(PT, reference_string[i], LRU_index, 1, i);
        }

        }
        
        PT[reference_string[i]].last_access_time = i;
    }

    cout << "No. of Page fault are :- " << page_fault << " " << endl;
    return 0;
}
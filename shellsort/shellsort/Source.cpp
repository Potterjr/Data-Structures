#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>& a)
{
    //testtttt01
    cout << "Original : ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "-----------------------------------------" << endl;
    int j;
    for (int gap = 5; gap > 0; gap -= 2)
    {
        for (int i = gap; i < a.size(); i++)
        {
            int tmp = a[i];
            for (j = i; j >= gap && tmp < a[j - gap]; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = tmp;
        }

        cout << "after " << gap << "-sort : ";
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
}

int main()
{
    vector<int> a(10);
    a[0] = 60;
    a[1] = 9;
    a[2] = 44;
    a[3] = 18;
    a[4] = 31;
    a[5] = 22;
    a[6] = 38;
    a[7] = 14;
    a[8] = 53;
    a[9] = 1;
    ShellSort(a);

    return 0;
}



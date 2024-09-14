#include <iostream>
using namespace std;

void array_012(int arr[], int n)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }

        int index = 0;
        for (int i = 0; i < count0; i++)
        {
            arr[index++] = 0;
        }
        for (int i = 0; i < count1; i++)
        {
            arr[index++] = 1;
        }
        for (int i = 0; i < count2; i++)
        {
            arr[index++] = 2;
        }
    }
}

int main()
{
    int arr[] = {0, 0, 1, 1, 2, 1, 0, 2, 2};
    int n = 9;
    array_012(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
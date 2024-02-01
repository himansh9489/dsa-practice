#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 6, 5, 9, 3};
    int n = arr.size();
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    // selection sort
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int min = i;
    //     for (int j = i; j < n; j++)
    //     {
    //         if (arr[j] < arr[min])
    //             min = j;
    //     }
    //     swap(arr[i], arr[min]);
    // }
    // tc -> O(n2) for best, ave and worst

    // bubble sort
    // for (int i = n - 1; i > 0; i--)
    // {
    //     int flag = true;
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             swap(arr[j], arr[j + 1]);
    //             flag = false;
    //         }
    //     }
    //     if (flag)
    //         break;
    // }
    // tc -> O(n2) for ave and worst, O(n) for best

    // insertion sort
    // for (int i = 0; i < n; i++)
    // {
    //     int j = i;
    //     while (j > 0 && arr[j - 1] > arr[j])
    //     {
    //         swap(arr[j - 1], arr[j]);
    //         j--;
    //     }
    // }
    // tc -> O(n2) for ave and worst, O(n) for best

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
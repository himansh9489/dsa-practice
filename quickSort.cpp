#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left <= right)
    {
        while (left <= high - 1 && arr[left] <= pivot)
            left++;
        while (right >= low + 1 && arr[right] > pivot)
            right--;
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
}
int main()
{
    vector<int> arr{1, 6, 5, 9, 3};
    int n = arr.size();
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);
    // tc -> O(nlog2n)

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
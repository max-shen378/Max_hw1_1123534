#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void PrintFNI(vector<int> arr, int k)
{
    queue<int> negatives;
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0) {
            negatives.push(i); 
        }
    }
    for (int i = k; i <= n; i++)
    {
        if (!negatives.empty()) 
        {
            cout << arr[negatives.front()] << " "; 
        }
        else {
            cout << "0 "; 
        }

        
        if (!negatives.empty() && negatives.front() <= i - k)
        {
            negatives.pop();
        }

        if (i < n && arr[i] < 0)
        {
            negatives.push(i); 
        }
    }
    cout << endl;
}

int main()
{
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of elements must be a positive integer." << endl;
        return 1; 
    }

    vector<int> arr(n); 
    cout << "Enter " << n << " elements (space-separated):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }

    cout << "Enter the size of the window (k): ";
    cin >> k;

    if (k <= 0 || k > n)
    {
        cout << "The window size must be a positive integer and less than or equal to the number of elements." << endl;
        return 1; 
    }
    PrintFNI(arr, k);

    return 0;
}

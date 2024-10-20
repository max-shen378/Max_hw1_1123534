#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void PrintNGE(vector<int> arr) 
{
    stack<int> st;  
    vector<int> nge(arr.size(), -1);  

    for (int i = 0; i < arr.size(); i++) 
    {
        while (!st.empty() && arr[i] > arr[st.top()]) 
        {
            int index = st.top();
            st.pop();
            nge[index] = arr[i];  
        }
        st.push(i);
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "The number of elements must be a positive integer." << endl;
        return 1;
    }
    vector<int> arr(n);  
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    PrintNGE(arr);
    return 0;
}

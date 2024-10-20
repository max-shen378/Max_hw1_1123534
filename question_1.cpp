#include <iostream>
#include <stack>

using namespace std;


void insertAtBottom(stack<int>& st, int element)
{
  
    if (st.empty()) 
    {
        st.push(element); 
        return;
    } 
    int topElement = st.top();
    st.pop();    
    insertAtBottom(st, element); 
    st.push(topElement);
}
void reverseStack(stack<int>& st) 
{
  
    if (st.empty()) 
    {
        return;
    }
    int topElement = st.top();
    st.pop();  
    reverseStack(st);
    insertAtBottom(st, topElement);
}


void printStack(stack<int> st)
{
    stack<int> tempStack;

    while (!st.empty()) 
    {
        tempStack.push(st.top());
        st.pop();
    }
    while (!tempStack.empty()) 
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

int main() 
{
    stack<int> st;
    int n, element;

    cout << "Enter the number of elements to add to the stack: ";
    cin >> n; 
   
    while (n % 2 != 0 || n <= 0) 
    {
        cout << "Please enter a positive even number: ";
        cin >> n; 
    }
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> element; 
        st.push(element); 
    }

    cout << "Original stack (top to bottom): ";
    printStack(st); 
    reverseStack(st);
    cout << "Reversed stack (top to bottom): ";
    printStack(st); 
    return 0;
}

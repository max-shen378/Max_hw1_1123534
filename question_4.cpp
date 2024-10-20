#include <iostream>
#include <queue>

using namespace std;


void interleaveQueue(queue<int>& q) 
{
    int n = q.size(); 

    
    if (n % 2 != 0) {
        cout << "Queue size must be even." << endl;
        return;
    }

    queue<int> firstHalf; 
    queue<int> secondHalf; 
   
    for (int i = 0; i < n / 2; i++) 
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!q.empty()) 
    {
        secondHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty() && !secondHalf.empty())
 {
        q.push(firstHalf.front()); 
        firstHalf.pop();
        q.push(secondHalf.front()); 
        secondHalf.pop();
    }
}


void printQueue(queue<int> q) 
{
    while (!q.empty()) {
        cout << q.front() << " "; 
        q.pop();                 
    }
    cout << endl; 
}


int main()
{
    queue<int> q;
    int input;

    cout << "Enter integers to add to the queue (enter -1 to stop):" << endl;

   
    while (true) {
        cin >> input;
        if (input == -1) break; 
        q.push(input);         
    }


    if (q.size() % 2 != 0) {
        cout << "The number of elements must be even." << endl;
        return 1; 
    }

    cout << "Original Queue: ";
    printQueue(q);

    interleaveQueue(q); 

    cout << "Interleaved Queue: ";
    printQueue(q); 

    return 0;
}

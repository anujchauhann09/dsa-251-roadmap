#include <bits/stdc++.h>  
using namespace std;

queue<int> reverseQueue(queue<int> q)
{
    // Stack to store the elements temporarily
    stack<int> st;

    // Push all elements from the queue into the stack
    while(!q.empty()) {
        int frontElement = q.front();  // Get the front element of the queue
        st.push(frontElement);  // Push it into the stack
        q.pop();  // Remove the element from the queue
    }

    // Push elements from the stack back into the queue, reversing their order
    while(!st.empty()) {
        int topElement = st.top();  // Get the top element of the stack
        q.push(topElement);  // Push it into the queue
        st.pop();  // Pop the top element from the stack
    }

    return q;  // Return the reversed queue
}

int main() {
    // Test case 1
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    queue<int> reversedQ1 = reverseQueue(q1);
    cout << "Reversed Queue 1: ";
    while(!reversedQ1.empty()) {
        cout << reversedQ1.front() << " ";
        reversedQ1.pop();
    }
    cout << endl;

    // Test case 2
    queue<int> q2;
    q2.push(5);
    q2.push(6);
    q2.push(7);
    queue<int> reversedQ2 = reverseQueue(q2);
    cout << "Reversed Queue 2: ";
    while(!reversedQ2.empty()) {
        cout << reversedQ2.front() << " ";
        reversedQ2.pop();
    }
    cout << endl;

    // Test case 3
    queue<int> q3;
    q3.push(8);
    q3.push(9);
    queue<int> reversedQ3 = reverseQueue(q3);
    cout << "Reversed Queue 3: ";
    while(!reversedQ3.empty()) {
        cout << reversedQ3.front() << " ";
        reversedQ3.pop();
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
The time complexity of the reverseQueue function is O(n), where n is the number of elements in the queue. This is because we iterate through each element twice: once to move it to the stack and once to move it back to the queue.

Space Complexity:
The space complexity is O(n), as we use a stack to store the elements temporarily. The stack requires space proportional to the number of elements in the queue.
*/
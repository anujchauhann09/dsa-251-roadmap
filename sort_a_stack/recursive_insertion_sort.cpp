#include <iostream>
#include <stack>
using namespace std;

// Recursively inserts an element into the correct position of a sorted stack.
// If the stack is empty or the top element is less than the element, it pushes the element;
// otherwise, it temporarily removes the top element and recurses until the proper position is found.
void sort(stack<int> &stack, int element) {
    if (stack.empty() || stack.top() < element) {
        stack.push(element);
        return;
    }
    int top = stack.top();
    stack.pop();
    sort(stack, element);
    stack.push(top);
}

// Recursively sorts the entire stack by removing the top element,
// sorting the remaining stack, and then inserting the removed element
// into its correct position using the 'sort' helper function.
void sortStackHelper(stack<int> &stack) {
    if (stack.empty()) {
        return;
    }
    int top = stack.top();
    stack.pop();
    sortStackHelper(stack);
    sort(stack, top);
}

// Initiates the recursive sort of the stack.
void sortStack(stack<int> &stack) {
    sortStackHelper(stack);
}

// Utility function to print the elements of a stack.
// It makes a copy of the stack and prints the top elements in order.
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    // Test Case 1: Sorting a non-empty unsorted stack.
    // This stack is initialized with several unsorted numbers to demonstrate the complete sorting process.
    stack<int> s1;
    s1.push(34);
    s1.push(3);
    s1.push(31);
    s1.push(98);
    s1.push(92);
    s1.push(23);
    cout << "Original Stack 1: ";
    printStack(s1);
    sortStack(s1);
    cout << "Sorted Stack 1: ";
    printStack(s1);

    // Test Case 2: Sorting an empty stack.
    // This test verifies that the function can gracefully handle a case with no elements.
    stack<int> s2;
    cout << "\nOriginal Stack 2 (empty): ";
    printStack(s2);
    sortStack(s2);
    cout << "Sorted Stack 2 (empty): ";
    printStack(s2);

    // Test Case 3: Sorting a stack with a single element.
    // This minimal case ensures that the algorithm correctly processes a stack containing only one item.
    stack<int> s3;
    s3.push(42);
    cout << "\nOriginal Stack 3: ";
    printStack(s3);
    sortStack(s3);
    cout << "Sorted Stack 3: ";
    printStack(s3);

    return 0;
}

/*
Time Complexity:
The worst-case time complexity for this recursive stack sorting approach is O(n²) because each element insertion may require traversing most of the stack, and the recursion adds an additional layer of iteration.

Space Complexity:
The space complexity is O(n) due to the recursion call stack used to sort the stack elements.
*/

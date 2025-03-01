# Linked List Implementation in C++

## Overview
This project implements a **Singly Linked List** in C++ with various operations such as insertion, deletion, searching, counting nodes, and printing the list.

## Features
- Insert a node at the **beginning** of the list.
- Insert a node at the **end** of the list.
- **Delete** the first node.
- **Delete** a node by value.
- **Search** for a value in the list.
- **Count** the total number of nodes.
- **Print** the linked list.

## Technologies Used
- C++
- Standard Template Library (STL) (for basic input/output operations)

## Getting Started
### Prerequisites
- A C++ compiler (GCC, Clang, MSVC, etc.)

### Compilation and Execution
1. Clone this repository or copy the `linked_list.cpp` file.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using a C++ compiler:
   ```sh
   g++ linked_list.cpp -o linked_list
   ```
4. Run the executable:
   ```sh
   ./linked_list
   ```

## Code Structure
### **Node Structure**
```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};
```

### **Operations and Functions**
- **Insert at Beginning:** `insertAtBeginning(Node*& head, int val)`
- **Insert at End:** `insertAtEnd(Node*& head, int val)`
- **Delete First Node:** `deleteFirstNode(Node*& head)`
- **Delete Node by Value:** `deleteNode(Node*& head, int val)`
- **Search a Value:** `search(Node* head, int key) -> bool`
- **Count Nodes:** `countNodes(Node* head) -> int`
- **Print List:** `printList(Node* head)`

## Example Usage
```cpp
int main() {
    Node* head = nullptr;
    
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 5);
    
    printList(head);
    cout << "Count: " << countNodes(head) << endl;
    
    deleteNode(head, 20);
    printList(head);
    
    cout << "Search 10: " << (search(head, 10) ? "Found" : "Not Found") << endl;
    
    return 0;
}
```

## Sample Output
```
5 -> 10 -> 20 -> 30 -> nullptr
Count: 4
5 -> 10 -> 30 -> nullptr
Search 10: Found
```
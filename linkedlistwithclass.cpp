#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at end (O(1) time)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at beginning (O(1) time)
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Delete first node (O(1) time)
    void deleteFirstNode() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;  // If list is now empty
        delete temp;
    }

    // Delete a node by value (O(n) time)
    void deleteNode(int val) {
        if (head == nullptr) return;
        if (head->data == val) {
            deleteFirstNode();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;  // Value not found
        prev->next = temp->next;
        if (temp == tail) tail = prev;  // Update tail if deleting last node
        delete temp;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

    // Destructor (Frees memory)
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);

    list.printList();  // Output: 5 -> 10 -> 20 -> 30 -> nullptr

    list.deleteNode(20);
    list.printList();  // Output: 5 -> 10 -> 30 -> nullptr

    return 0;
}

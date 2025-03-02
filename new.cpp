#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() { head = nullptr; tail = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;  // Update tail
            return;
        }
        tail->next = newNode;  // Directly insert at tail
        tail = newNode;        // Update tail pointer
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.printList();  // Output: 10 -> 20 -> 30 -> 40 -> nullptr
    return 0;
}

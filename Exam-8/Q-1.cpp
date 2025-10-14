#include <iostream>
using namespace std;

// Node class for Linked List
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Base Class: Dynamic Memory Allocation
class DynamicMemoryAllocation {
private:
    Node* head; // Head pointer

public:
    // Constructor
    DynamicMemoryAllocation() {
        head = NULL;
    }

    // Append node at the end
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display all nodes
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Search for a node
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Element " << key << " not found in the list." << endl;
    }

    // Delete a node by value
    void delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head node holds the key
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << key << " deleted." << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Node not found!" << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Node with value " << key << " deleted." << endl;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "Linked List reversed successfully!" << endl;
    }
};

// Main function
int main() {
    DynamicMemoryAllocation list;
    int choice, value;

    cout << "===== Linked List CRUD Operations =====" << endl;

    do {
        cout << "\n1. Append Node";
        cout << "\n2. Display List";
        cout << "\n3. Insert at Beginning";
        cout << "\n4. Search Element";
        cout << "\n5. Delete Node";
        cout << "\n6. Reverse List";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to append: ";
            cin >> value;
            list.append(value);
            break;

        case 2:
            list.display();
            break;

        case 3:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            list.delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

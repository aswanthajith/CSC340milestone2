//code written using information obtained from ChatGPT
//Aswanth Ajith SFSUN ID:921843868

#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert a node at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert a node at the tail of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a node with a specific value from the list
    void deleteNode(int value) {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                if (current == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    if (tail) tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Move a node to the head or tail of the list
    void moveNode(Node* node, bool toHead) {
        if (!node || (toHead && node == head) || (!toHead && node == tail)) {
            return; // Already in desired position or invalid node
        }

        // Detach node from its current position
        if (node == head) {
            head = node->next;
            head->prev = nullptr;
        } else if (node == tail) {
            tail = node->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        // Insert node at the head or tail
        if (toHead) {
            node->next = head;
            node->prev = nullptr;
            if (head) head->prev = node;
            head = node;
        } else {
            node->prev = tail;
            node->next = nullptr;
            if (tail) tail->next = node;
            tail = node;
        }
    }

    // Print the list forwards or backwards
    void printList(bool forward = true) {
        if (forward) {
            Node* current = head;
            while (current) {
                std::cout << current->value << " ";
                current = current->next;
            }
        } else {
            Node* current = tail;
            while (current) {
                std::cout << current->value << " ";
                current = current->prev;
            }
        }
        std::cout << std::endl;
    }

    // Helper function to find a node with a specific value
    Node* findNode(int value) {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

// Main function to test the doubly linked list
int main() {
    DoublyLinkedList dll;

    // Running testCase1
    std::cout << "Running testCase1:" << std::endl;
    dll.insertAtTail(10);
    dll.insertAtHead(100);
    dll.insertAtTail(20);
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    // Running testCase2
    std::cout << "\nRunning testCase2:" << std::endl;
    dll = DoublyLinkedList(); // Reset list
    dll.insertAtHead(30);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtHead(1000);
    dll.deleteNode(30);
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    // Running testCase3
    std::cout << "\nRunning testCase3:" << std::endl;
    dll = DoublyLinkedList(); // Reset list
    dll.insertAtHead(30);
    dll.insertAtTail(60);
    dll.insertAtHead(1000);
    Node* nodeToMove = dll.findNode(60);
    if (nodeToMove) {
        dll.moveNode(nodeToMove, true);
    }
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    // Running testCase4
    std::cout << "\nRunning testCase4:" << std::endl;
    dll = DoublyLinkedList(); // Reset list
    dll.insertAtHead(90);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtTail(60);
    dll.insertAtHead(1000);
    nodeToMove = dll.findNode(50);
    if (nodeToMove) {
        dll.moveNode(nodeToMove, false);
    }
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    // Running testCase5
    std::cout << "\nRunning testCase5:" << std::endl;
    dll = DoublyLinkedList(); // Reset list
    dll.insertAtHead(90);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtTail(60);
    dll.deleteNode(90);
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    // Running testCase6
    std::cout << "\nRunning testCase6:" << std::endl;
    dll = DoublyLinkedList(); // Reset list
    dll.insertAtHead(30);
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtTail(60);
    dll.insertAtHead(1000);
    dll.deleteNode(60);
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    // Running testCase7
    std::cout << "\nRunning testCase7:" << std::endl;
    dll = DoublyLinkedList(); // Reset list
    dll.insertAtTail(40);
    dll.insertAtTail(50);
    dll.insertAtTail(60);
    dll.insertAtHead(1000);
    dll.deleteNode(60);
    std::cout << "List contents in order:" << std::endl;
    dll.printList();
    std::cout << "List contents in reverse order:" << std::endl;
    dll.printList(false);

    return 0;
}
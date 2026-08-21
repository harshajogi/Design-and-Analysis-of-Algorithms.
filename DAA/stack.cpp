#include <iostream>

struct Node {
    int data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed " << data << " onto stack\n";
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return -1; 
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        Node* current = top;
        std::cout << "Stack components (Top -> Bottom):\n";
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    std::cout << "=== 2. Stack Operations using Linked List ===\n";
    StackLinkedList stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    
    std::cout << "Peek top element: " << stack.peek() << "\n";
    std::cout << "Popped element: " << stack.pop() << "\n";
    stack.display();

    return 0;
}

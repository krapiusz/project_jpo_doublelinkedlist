#pragma once
#include <iostream>

namespace pk::jpo {

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node(const T& v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() { clear(); }

    bool empty() const {
        return head == nullptr;
    }

    void push_front(const T& value) {
        Node* n = new Node(value);

        if (empty()) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void push_back(const T& value) {
        Node* n = new Node(value);

        if (empty()) {
            head = tail = n;
        } else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    void pop_front() {
        if (empty()) return;

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (empty()) return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void clear() {
        while (!empty()) pop_front();
    }

    void print_forward() const {
        Node* cur = head;
        std::cout << "[ ";
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << "]\n";
    }

    void print_backward() const {
        Node* cur = tail;
        std::cout << "[ ";
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->prev;
        }
        std::cout << "]\n";
    }
};

}

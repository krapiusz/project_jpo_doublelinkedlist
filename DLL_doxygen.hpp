#pragma once
#include <iostream>

namespace pk::jpo {

/**
 * \brief Doubly linked list of integers.
 *
 * This class implements a doubly linked list data structure.
 * Each element (node) stores an integer value and pointers
 * to the previous and next nodes in the list.
 *
 * The list supports insertion and removal of elements
 * from both the front and the back, as well as printing
 * its contents in forward and backward order.
 */
class DoublyLinkedList {
private:
    /**
     * \brief Internal node of the doubly linked list.
     *
     * This structure represents a single element of the list.
     * It stores the value and pointers to neighboring nodes.
     *
     * This structure is private because it is an implementation
     * detail and should not be accessed by the user of the list.
     */
    struct Node {
        int value;      /**< Stored value */
        Node* prev;     /**< Pointer to the previous node */
        Node* next;     /**< Pointer to the next node */

        /**
         * \brief Constructs a node with a given value.
         *
         * Initializes the node with the provided value
         * and sets both pointers to nullptr.
         *
         * \param v Value to store in the node.
         */
        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head; /**< Pointer to the first node in the list */
    Node* tail; /**< Pointer to the last node in the list */

public:
    /**
     * \brief Constructs an empty doubly linked list.
     *
     * Initializes the list with no elements.
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    /**
     * \brief Destroys the list and frees all allocated memory.
     *
     * All nodes are removed and deleted.
     */
    ~DoublyLinkedList() { clear(); }

    /**
     * \brief Checks if the list is empty.
     *
     * \return True if the list contains no elements, false otherwise.
     */
    bool empty() const {
        return head == nullptr;
    }

    /**
     * \brief Inserts a value at the beginning of the list.
     *
     * Creates a new node and places it before the current head.
     *
     * \param value Value to insert.
     */
    void push_front(int value) {
        Node* n = new Node(value);

        if (empty()) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    /**
     * \brief Inserts a value at the end of the list.
     *
     * Creates a new node and places it after the current tail.
     *
     * \param value Value to insert.
     */
    void push_back(int value) {
        Node* n = new Node(value);

        if (empty()) {
            head = tail = n;
        } else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
    }

    /**
     * \brief Removes the first element of the list.
     *
     * If the list is empty, no action is taken.
     */
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

    /**
     * \brief Removes the last element of the list.
     *
     * If the list is empty, no action is taken.
     */
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

    /**
     * \brief Removes all elements from the list.
     */
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    /**
     * \brief Prints the list from head to tail.
     *
     * Outputs all stored values in forward order.
     */
    void print_forward() const {
        Node* cur = head;
        std::cout << "[ ";
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << "]\n";
    }

    /**
     * \brief Prints the list from tail to head.
     *
     * Outputs all stored values in backward order.
     */
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
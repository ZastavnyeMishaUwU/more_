#include "List.h"

template <typename T>
List<T>::Node::Node(T val) : data(val), next(nullptr) {}

template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
    DeleteAll();
}

template <typename T>
void List<T>::AddToHead(T value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void List<T>::AddToTail(T value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <typename T>
void List<T>::DeleteFromHead() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::DeleteFromTail() {
    if (head) {
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
}

template <typename T>
void List<T>::DeleteAll() {
    while (head) {
        DeleteFromHead();
    }
}

template <typename T>
void List<T>::Show() const {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
Stack<T>::Stack() {}

template <typename T>
void Stack<T>::Push(T value) {
    list.AddToHead(value);
}

template <typename T>
void Stack<T>::Pop() {
    list.DeleteFromHead();
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return list.head == nullptr;
}

template <typename T>
T Stack<T>::Top() const {
    if (list.head) {
        return list.head->data;
    }
    throw out_of_range("Stack is empty");
}

template <typename T>
void Stack<T>::Show() const {
    list.Show();
}

template <typename T>
Queue<T>::Queue() {}

template <typename T>
void Queue<T>::Enqueue(T value) {
    list.AddToTail(value);
}

template <typename T>
void Queue<T>::Dequeue() {
    list.DeleteFromHead();
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return list.head == nullptr;
}

template <typename T>
T Queue<T>::Front() const {
    if (list.head) {
        return list.head->data;
    }
    throw out_of_range("Queue is empty");
}

template <typename T>
void Queue<T>::Show() const {
    list.Show();
}

template <typename T>
Vector<T>::Vector() : arr(nullptr), size(0), capacity(1) {
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
void Vector<T>::Resize(size_t newCapacity) {
    T* newArr = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::PushBack(T value) {
    if (size == capacity) {
        Resize(capacity * 2);
    }
    arr[size++] = value;
}

template <typename T>
void Vector<T>::PopBack() {
    if (size > 0) {
        --size;
    }
}

template <typename T>
size_t Vector<T>::Size() const {
    return size;
}

template <typename T>
size_t Vector<T>::Capacity() const {
    return capacity;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of bounds");
    }
    return arr[index];
}

template <typename T>
void Vector<T>::Show() const {
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::~Tree() {
    DeleteTree(root);
}

template <typename T>
void Tree<T>::AddRecursive(TreeNode*& node, T value) {
    if (!node) {
        node = new TreeNode(value);
    }
    else if (value < node->data) {
        AddRecursive(node->left, value);
    }
    else {
        AddRecursive(node->right, value);
    }
}

template <typename T>
void Tree<T>::Add(T value) {
    AddRecursive(root, value);
}

template <typename T>
void Tree<T>::InOrderTraversal(TreeNode* node) const {
    if (node) {
        InOrderTraversal(node->left);
        cout << node->data << " ";
        InOrderTraversal(node->right);
    }
}

template <typename T>
void Tree<T>::ShowInOrder() const {
    InOrderTraversal(root);
    cout << endl;
}

template <typename T>
void Tree<T>::DeleteTree(TreeNode* node) {
    if (node) {
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
}

template class List<int>;
template class Stack<int>;
template class Queue<int>;
template class Vector<int>;
template class Tree<int>;

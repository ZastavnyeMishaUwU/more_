#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(T val);
    };

    Node* head;

public:
    List();
    ~List();
    void AddToHead(T value);
    void AddToTail(T value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show() const;
};

template <typename T>
class Stack {
private:
    List<T> list;

public:
    Stack();
    void Push(T value);
    void Pop();
    bool IsEmpty() const;
    T Top() const;
    void Show() const;
};

template <typename T>
class Queue {
private:
    List<T> list;

public:
    Queue();
    void Enqueue(T value);
    void Dequeue();
    bool IsEmpty() const;
    T Front() const;
    void Show() const;
};

template <typename T>
class Vector {
private:
    T* arr;
    size_t size;
    size_t capacity;

    void Resize(size_t newCapacity);

public:
    Vector();
    ~Vector();
    void PushBack(T value);
    void PopBack();
    size_t Size() const;
    size_t Capacity() const;
    T& operator[](size_t index);
    void Show() const;
};

template <typename T>
class Tree {
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void AddRecursive(TreeNode*& node, T value);
    void DeleteTree(TreeNode* node);
    void InOrderTraversal(TreeNode* node) const;

public:
    Tree();
    ~Tree();
    void Add(T value);
    void ShowInOrder() const;
};

#endif

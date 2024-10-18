#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List<int> list;
    list.AddToHead(10);
    list.AddToHead(20);
    list.AddToTail(30);
    list.AddToTail(40);

    cout << "Список після додавання елементів: ";
    list.Show();

    list.DeleteFromHead();
    cout << "Після видалення з голови: ";
    list.Show();

    list.DeleteFromTail();
    cout << "Після видалення з хвоста: ";
    list.Show();

    list.DeleteAll();
    cout << "Після видалення всіх елементів: ";
    list.Show();

    Stack<int> stack;
    stack.Push(100);
    stack.Push(200);
    stack.Push(300);

    cout << "Стек після додавання елементів: ";
    stack.Show();

    stack.Pop();
    cout << "Після видалення з вершини: ";
    stack.Show();

    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    cout << "Черга після додавання елементів: ";
    queue.Show();

    queue.Dequeue();
    cout << "Після видалення з черги: ";
    queue.Show();

    Vector<int> vec;
    vec.PushBack(10);
    vec.PushBack(20);
    vec.PushBack(30);

    cout << "Вектор після додавання елементів: ";
    vec.Show();

    vec.PopBack();
    cout << "Після видалення останнього елементу: ";
    vec.Show();

    return 0;
}

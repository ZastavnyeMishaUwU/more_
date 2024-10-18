#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List<int> list;
    list.AddToHead(10);
    list.AddToHead(20);
    list.AddToTail(30);
    list.AddToTail(40);

    cout << "������ ���� ��������� ��������: ";
    list.Show();

    list.DeleteFromHead();
    cout << "ϳ��� ��������� � ������: ";
    list.Show();

    list.DeleteFromTail();
    cout << "ϳ��� ��������� � ������: ";
    list.Show();

    list.DeleteAll();
    cout << "ϳ��� ��������� ��� ��������: ";
    list.Show();

    Stack<int> stack;
    stack.Push(100);
    stack.Push(200);
    stack.Push(300);

    cout << "���� ���� ��������� ��������: ";
    stack.Show();

    stack.Pop();
    cout << "ϳ��� ��������� � �������: ";
    stack.Show();

    Queue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    cout << "����� ���� ��������� ��������: ";
    queue.Show();

    queue.Dequeue();
    cout << "ϳ��� ��������� � �����: ";
    queue.Show();

    Vector<int> vec;
    vec.PushBack(10);
    vec.PushBack(20);
    vec.PushBack(30);

    cout << "������ ���� ��������� ��������: ";
    vec.Show();

    vec.PopBack();
    cout << "ϳ��� ��������� ���������� ��������: ";
    vec.Show();

    return 0;
}

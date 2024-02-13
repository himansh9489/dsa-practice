
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *arrayToLinkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *tail = new Node(arr[i], NULL, prev);
        prev->next = tail;
        prev = tail;
    }
    return head;
}
void display(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int lengthOfLL(Node *head)
{
    Node *current = head;
    int cnt = 0;
    while (current != nullptr)
    {
        cnt++;
        current = current->next;
    }
    return cnt;
}
Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *prev = head;
    head = head->next;
    prev->next = nullptr;
    head->prev = nullptr;
    delete prev;
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}
Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *next = temp->next;
    Node *prev = temp->prev;
    if (prev == NULL && next == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHead(head);
    }
    else if (next == NULL)
    {
        return deleteTail(head);
    }

    next->prev = prev;
    prev->next = next;

    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}
void deleteNode(Node *temp)
{
    Node *next = temp->next;
    Node *prev = temp->prev;
    if (next == NULL)
    {
        prev->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }

    prev->next = next;
    next->prev = prev;

    temp->next = temp->prev = NULL;
    delete temp;
}
Node *insertBeforeHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->prev = newHead;
    return newHead;
}
Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == NULL)
        return insertBeforeHead(head, val);
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    Node *prev = tail->prev;
    Node *newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->prev = newNode;
    return head;
}
Node *insertBeforeKthElement(Node *head, int val, int k)
{
    if (k == 1)
        return insertBeforeHead(head, val);
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->prev;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->prev = newNode;
    return head;
}
void insertBeforeNode(Node *node, int val)
{
    Node *prev = node->prev;
    Node *newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->prev = newNode;
}

int main()
{
    vector<int> arr{12, 4, 7, 8};
    Node *head = arrayToLinkedList(arr);
    display(head);
    // cout << lengthOfLL(head) << endl;
    // display(deleteHead(head));
    // display(deleteTail(head));
    // display(deleteKthElement(head, 2));
    // deleteNode(head->next->next->next);
    // display(head);
    head = insertBeforeHead(head, 6);
    display(head);
    head = insertBeforeTail(head, 15);
    display(head);
    head = insertBeforeKthElement(head, 100, 2);
    display(head);
    insertBeforeNode(head->next->next, 34);
    display(head);
    // head = insertBeforeValue(head, 12, 23);
    // display(head);
    // head = insertBeforeValue(head, 7, 78);
    // display(head);
}
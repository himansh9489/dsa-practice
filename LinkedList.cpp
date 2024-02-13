#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *arrayToLinkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
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
bool checkIfPresent(Node *head, int k)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == k)
            return true;
        current = current->next;
    }
    return false;
}
Node *deleteHead(Node *head)
{
    Node *current = head;
    current = current->next;
    return current;
}
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *current = head;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
    return head;
}
Node *deleteKthElement(Node *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteElemnt(Node *head, int el)
{
    if (head == nullptr)
        return head;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}
Node *insertTail(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}
Node *insertPosition(Node *head, int k, int el)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(el);
        else
            return head;
    }
    if (k == 1)
    {
        return new Node(el, head);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == (k - 1))
        {
            Node *newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeValue(Node *head, int val, int el)
{
    if (head == NULL)
        return NULL;
    if (head->data == val)
    {
        return new Node(el, head);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr{12, 4, 7, 8};
    Node *head = arrayToLinkedList(arr);
    display(head);
    // cout << lengthOfLL(head) << endl;
    // cout << checkIfPresent(head, 2) << endl;
    // display(deleteHead(head));
    // display(deleteTail(head));
    // display(deleteKthElement(head, 3));
    // display(deleteElemnt(head, 8));
    head = insertPosition(head, 2, 6);
    display(head);
    head = insertPosition(head, 6, 100);
    display(head);
    head = insertBeforeValue(head, 12, 23);
    display(head);
    head = insertBeforeValue(head, 7, 78);
    display(head);
}
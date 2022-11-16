#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node() {
        data = 0;
        next = nullptr;
    }
    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList {
public:
    Node *head;
    void insert(int);
    void insertBeg(int);
    void insertn(int ,int);
    void delete_data(int);
    void reverse();
    void print();
};

void LinkedList::reverse() {
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void LinkedList::insertn(int data,int pos) {
    Node *temp = head;
    int len = 0;
    if(pos == 1) {
        insertBeg(data);
    } else {
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }

        if(pos == len) {
            insert(data);
        } else {
            if(pos > len) {
                cout << "Index out of range...\n";
            } else {
                temp = head;
                for (int i = 0; i < pos -1 ; ++i) {
                    temp = temp->next;
                }
                Node *temp2 = temp;
                Node *newn = new Node(data);
                newn->next = temp->next;
                temp2->next = newn;
            }
        }
    }
}
void LinkedList::insertBeg(int data) {
    Node *newn = new Node(data);
    newn->next = head;
    head = newn;
}

void LinkedList::insert(int data) {
    Node *newn = new Node(data);
    if(head == nullptr) {
        head = newn;
    } else {
        Node *temp;
        temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void LinkedList::delete_data(int pos) {
    Node *temp1 = head;
    Node *temp2 = nullptr;
    int listLen = 0;

    if(head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    while(temp1 != NULL) {
        temp1 = temp1->next;
        listLen++;
    }

    if(pos > listLen) {
        cout<<"Index error\n";
        return;
    }

    if(pos == 1) {
        head = head->next;
        delete temp1;
        return;
    }
    temp1 = head;
    while (pos-- > 1) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
}

void LinkedList::print() {
    Node *temp = head;

    while (temp != nullptr) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

int main() {
    LinkedList linkedList;
    linkedList.insertBeg(99);
    linkedList.insert(3);
    linkedList.insert(7);
    linkedList.insert(1);
    linkedList.insertBeg(9);
    linkedList.insertn(12,1);
    linkedList.insertn(15,5);
    linkedList.insertn(20,3);
    linkedList.delete_data(3);
    linkedList.print();
    linkedList.reverse();
    cout << "After reversing\n";
    linkedList.print();
//    linkedList.delete_data(2);
//    linkedList.print();
    return 0;
}

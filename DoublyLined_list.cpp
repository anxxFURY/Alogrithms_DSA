//
// Created by Lenovo on 10/18/2022.
//
#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    explicit Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedlist {
public:
    Node *head = nullptr;

    void insertBeg(int );
    void insertEnd(int );
    void insertn(int , int);
    void delete_data(int );
    void printFor();
    void printBack();
};

void DoublyLinkedlist::insertBeg(int data) {
    Node *newn = new Node(data);

    if(head == nullptr) {
        head = newn;
        newn->prev = head;
        newn->next = nullptr;
        return;
    }
    newn->next = head;
    head->prev = newn;
    head = newn;
    newn->prev = head;
}

void DoublyLinkedlist::insertEnd(int data) {
    Node *newn = new Node(data);

    if(head == nullptr){
        newn->next = nullptr;
        head = newn;
        newn->prev = head;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newn;
    newn->prev = temp;
    newn->next = nullptr;
}

void DoublyLinkedlist::insertn(int data, int pos) {
    Node *temp = head;
    int len = 0;

    while (temp != nullptr) {
        temp = temp->next;
        len++;
    }

    if(pos >  len) {
        cout << "Index error\n";
        return;
    }

    if(pos == 1){
        insertBeg(data);
        return;
    }

    if(pos == len) {
        insertEnd(data);
        return;
    }
    temp = head;
    for(int i = 0; i < pos -1; i++) {
        temp = temp->next;
    }
    Node *newn = new Node(data);
    Node *temp2 = temp->next;

    newn->next = temp->next;
    newn->prev = temp;
    temp->next = newn;
    temp2->prev = newn;
}

void DoublyLinkedlist::delete_data(int pos) {
    Node *temp1 = head;
    Node *temp2 = nullptr;

    int len = 0;

    while (temp1 != nullptr) {
        temp1 = temp1->next;
        len++;
    }

    if(pos > len) {
        cout << "Index error\n";
        return;
    }

    if(pos == 1) {
        head = head->next;
        temp1->next->prev = head;
        delete temp1;
        return;
    }
    if(pos == len) {
        temp1 = head;
        while (temp1->next != nullptr)
            temp1 = temp1->next;
        temp2 = temp1->prev;
        temp2->next = nullptr;
        delete temp1;
        return;
    }

    temp1 = head;
    for(int  i =0 ; i < pos-2; i++) {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next->prev = temp1;
    delete temp2;

}
void DoublyLinkedlist::printFor() {
    Node *temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\nForward Print\n";
}

void DoublyLinkedlist::printBack() {
    Node *temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != head) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << temp->data << " ";
    cout << "\nBackward Print";
}
int main() {
    DoublyLinkedlist doublyLinkedlist;

    doublyLinkedlist.insertBeg(3);
    doublyLinkedlist.insertBeg(6);
    doublyLinkedlist.insertBeg(10);

    doublyLinkedlist.insertEnd(15);
    doublyLinkedlist.insertEnd(20);

    doublyLinkedlist.insertn(50,1);
    doublyLinkedlist.insertn(60,6);
    doublyLinkedlist.insertn(90,3);

    doublyLinkedlist.delete_data(8);
    doublyLinkedlist.printFor();
    doublyLinkedlist.printBack();
    return 0;
}

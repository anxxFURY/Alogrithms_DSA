//
// Created by Lenovo on 10/19/2022.
//
#include "bits/stdc++.h"

using namespace std;

class Hashtable {
private:
    static const int hashGroups = 10;
    list<pair<int,string>> table[hashGroups];
public:
    bool isEmpty() const;
    static int hashFunc(int key);
    void insertion(int  key, string value);
    void remove(int key);
    void printTable();
};

bool Hashtable::isEmpty() const {
    int sum{};
    for(const auto & i : table) {
        sum += i.size();
    }
    if(!sum)
        return true;
    return false;
}

int Hashtable::hashFunc(int key) {
    return key % hashGroups;
}


void Hashtable::insertion(int key, string value) {
    int hashValue = hashFunc(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists, and value replaced\n";
            break;
        }
    }

    if(!keyExists) {
        cell.emplace_back(key,value);
    }
    return;
}

void Hashtable::remove(int key)  {
    int hashValue = hashFunc(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed\n";
            break;
        }
    }

    if(!keyExists) {
        cout << "[WARNING] Item not removed\n";
    }

    return ;
}

void Hashtable::printTable() {
    for(int i{}; i < hashGroups; i++) {
        if(table[i].empty())
            continue;
        auto bItr = table[i].begin();
        for(;bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << " Value " << bItr->second << endl;
        }
    }

    return;
}
int main() {
    Hashtable HT;

    if(HT.isEmpty()) {
        cout << "Correct Code\n";
    } else {
        cout << "Wrong Code\n";
    }

    HT.insertion(121,"qpo");
    HT.insertion(213,"lki");
    HT.insertion(432,"yht");
    HT.insertion(126,"wed");
    HT.insertion(523,"rft");
    HT.insertion(176,"weq");
    HT.insertion(665,"ajs");
    HT.insertion(665,"ani");

    HT.printTable();

    HT.remove(665);

    HT.printTable();
}
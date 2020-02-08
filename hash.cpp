#include <iostream>
#include <string>
using namespace std;

static const int HASH_TABLE_SIZE = 11;

class ListElt {
public:
    string key;
    int value;
    ListElt* next;
    ListElt(string key_, int value_){
        key = key_;
        value = value_;
    }
};


class HashTable
{
private:
    ListElt *data[HASH_TABLE_SIZE];
    int hash(string key);
public:
    void Insert(string key, int value);
    void PrintContent();
};

int HashTable::hash(string key) {
    int result = 0;
    for (auto c : key) {
        result += c;
    }
    return result;
}

void HashTable::Insert(string key, int value) {
    int bucket = hash(key)%HASH_TABLE_SIZE;
    if (data[bucket] == nullptr) {
        data[bucket] = new ListElt(key, value);
    }
    else {
        ListElt* tail = data[bucket];
        data[bucket] = new ListElt(key, value);
        data[bucket]->next = tail;
    }

}

void HashTable::PrintContent() {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        cout << "[" << i << "]: ";

        ListElt* ptr = data[i];
        if (ptr == nullptr) cout << "nullptr";

        while (ptr != nullptr) {
            cout << "(" << ptr->key << "," << ptr->value << ") -> ";
        //    ptr = ptr->next; 
        }
        cout << "\n";
    }
}

int main()
{
    cout << "before the time\n";
    HashTable ht;
    cout << "before insert\n";
    ht.Insert("test",6);
    cout << "Before print\n";
    ht.PrintContent();

    return 0;
}

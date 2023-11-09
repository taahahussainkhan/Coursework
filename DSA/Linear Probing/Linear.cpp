#include <iostream>
#include <unordered_map>

using namespace std;

class HashTable {
private:
    unordered_map<int, int> table;
    int tableSize;

public:
    HashTable(int size) : tableSize(size) {}

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int value) {
        int index = hashFunction(value);
        while (true) {
            if(table.count(index)!= 0)
            {
                index = (index + 1) % tableSize; // Linear probing
            }
            else
            {
                break;
            }
        }
        table[index] = value;
    }

    int search(int key) {
        int index = hashFunction(key);
        int startIndex = index;
        while (true) {
            if (table.count(index) != 0 && table[index] == key) {
                return table[index]; // Return the value associated with the key
            }
            index = (index + 1) % tableSize; // Linear probing
            if (index == startIndex || table.count(index) == 0) {
                break; // Reached the starting index again or an empty slot, key not found
            }
        }
        return -1; // Key not found
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;
        while (true) {
            if (table.count(index) != 0 && table[index] == key) {
                table.erase(index); // Remove the key-value pair
                return;
            }
            index = (index + 1) % tableSize; // Linear probing
            if (index == startIndex || table.count(index) == 0) {
                break; // Reached the starting index again or an empty slot, key not found
            }
        }
    }

};

int main() {
    HashTable hashTable(10);

    // Inserting elements
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);
    hashTable.insert(40);

    // Searching elements
    cout << hashTable.search(20) << endl;  // Output: 20
    cout << hashTable.search(40) << endl;  // Output: 40
    cout << hashTable.search(50) << endl;  // Output: -1 (not found)

    // Removing elements
    hashTable.remove(20);
    cout << hashTable.search(20) << endl;  // Output: -1 (not found)

    return 0;
}




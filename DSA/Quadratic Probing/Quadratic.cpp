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
        int attempt = 1;
        while (true) {
            if (table.count(index) == 0) {
                table[index] = value;
                return;
            }
            index = (index + (attempt * attempt)) % tableSize; // Quadratic probing
            attempt++;
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        int attempt = 1;
        while (true) {
            if (table.count(index) != 0 && table[index] == key) {
                return table[index]; // Return the value associated with the key
            }
            index = (index + (attempt * attempt)) % tableSize; // Quadratic probing
            attempt++;
            if (table.count(index) == 0 || attempt >= tableSize) {
                break; // Reached an empty slot or made enough attempts, key not found
            }
        }
        return -1; // Key not found
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        int attempt = 1;
        while (true) {
            if (table.count(index) != 0 && table[index] == key) {
                table.erase(index); // Remove the key-value pair
                return;
            }
            index = (index + (attempt * attempt)) % tableSize; // Quadratic probing
            attempt++;
            if (table.count(index) == 0 || attempt >= tableSize) {
                break; // Reached an empty slot or made enough attempts, key not found
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

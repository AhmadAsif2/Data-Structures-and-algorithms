#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 10

typedef struct {
    string name;
    int age;
} person;

person *hash_table[TABLE_SIZE];

class HashTable {
    public:


        int hash(string name) {
            unsigned int hashValue = 0;
            
            for (int i = 0; i < name.length(); i++) {
                hashValue += name[i];
                hashValue = (hashValue * name[i]) % TABLE_SIZE;
            }
            
            return hashValue;
        }

        void initHashTable() {

            for (int i = 0; i < TABLE_SIZE; i++) {
                hash_table[i] = NULL;
            }
        }

        void printTable() {

            cout << "Start" << endl;
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (hash_table[i] == NULL) {
                    cout << "\t" << i << "\t---" << endl;
                } else {
                    cout << "\t" << i << "\t" << hash_table[i]->name << endl;
                }
                
            }
            cout << "End" << endl << endl;
        }

        bool hashTableInsert(person *p) {
            int index = hash(p->name);

            // linear probing
            for (int i = 0; i < TABLE_SIZE; i++) {
                int tmp = (i + index) % TABLE_SIZE;
                if (hash_table[tmp] == NULL) {
                    hash_table[tmp] = p;
                    return true;
                }
            }

            return false;
        }

        person *hashTableLookup(string name) {
            int index = hash(name);
            if (hash_table[index]->name == name && hash_table[index] != NULL) {
                return hash_table[index];
            } else {
                return NULL;
            }
        }

        person *hashTableDelete(string name) {
            int index = hash(name);

            for (int i = 0; i < TABLE_SIZE; i++) {
                int tmp = (i + index) % TABLE_SIZE;
                if (hash_table[tmp] != NULL && hash_table[index]->name == name) {
                    person *ptr = hash_table[tmp];
                    hash_table[tmp] = NULL;
                    return ptr;
                } 
            }       
            
            return NULL;
        }
};

int main() {

    HashTable ht;

    ht.initHashTable();
    ht.printTable();

    // cout << "Nick =>" << ht.hash("Nick") << endl;
    // cout << "Tim =>" << ht.hash("Tim") << endl;
    // cout << "jacob =>" << ht.hash("jacob") << endl;

    // // Collision
    // cout << "\tCollision occurs" << endl;
    // cout << "William =>" << ht.hash("William") << endl;
    // cout << "Sara =>" << ht.hash("Sara") << endl; 

    // cout << "Maren =>" << ht.hash("Maren") << endl;
    // cout << "Bill=>" << ht.hash("Bill") << endl;  

    person jacob = { "jacob", 24 };
    person kate = { "kate", 36 };
    person mpoh = { "mpho", 28 };

    ht.hashTableInsert(&jacob);
    ht.hashTableInsert(&kate);
    ht.hashTableInsert(&mpoh);

    ht.printTable();

    person *tmp = ht.hashTableLookup("mpho");

    if (tmp == NULL) {
        cout << "Not found" << tmp->name << endl;
    } else {
        cout << "found " << tmp->name << endl;
    }

    ht.hashTableDelete("mpho");
    ht.printTable();

    return 0;
}
#include "HashTable.h"
#include <iostream>
#include <cctype>
using namespace std;

HashTable::HashTable() {
    
}

HashTable::~HashTable() {

}

int HashTable::hashFunction(string word) {
    if (word.empty()) {
        return 0;
    }

    char firstChar = tolower(word[0]);

    if (firstChar >= 'a' && firstChar <= 'z') {
        return firstChar - 'a';  
    }

    return 0;  
}

bool HashTable::addWord(string english, string vietnamese) {
   
    if (english.empty() || vietnamese.empty()) {
        return false;
    }

    int index = hashFunction(english);

    if (table[index].exists(english)) {
        cout << "Tu \"" << english << "\" da ton tai trong tu dien!" << endl;
        return false;
    }

    table[index].insertAtHead(english, vietnamese);
    return true;
}

string HashTable::searchWord(string english) {
    int index = hashFunction(english);
    return table[index].search(english);
}

bool HashTable::deleteWord(string english) {
    int index = hashFunction(english);
    return table[index].remove(english);
}

bool HashTable::updateWord(string english, string newVietnamese) {
    int index = hashFunction(english);
    return table[index].update(english, newVietnamese);
}

void HashTable::displayAll() {
    bool hasWords = false;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i].isEmpty()) {
            hasWords = true;
            char letter = 'A' + i;
            cout << "\n=== Nhom " << letter << " ("
                << table[i].getSize() << " tu) ===" << endl;
            table[i].display();
        }
    }

    if (!hasWords) {
        cout << "Tu dien trong!" << endl;
    }
}

void HashTable::displayByLetter(char letter) {
    letter = toupper(letter);

    if (letter < 'A' || letter > 'Z') {
        cout << "Chu cai khong hop le!" << endl;
        return;
    }

    int index = letter - 'A';

    if (table[index].isEmpty()) {
        cout << "Khong co tu nao bat dau bang chu " << letter << endl;
        return;
    }

    cout << "\n=== Cac tu bat dau bang " << letter
        << " (" << table[index].getSize() << " tu) ===" << endl;
    table[index].display();
}

int HashTable::getTotalWords() {
    int total = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        total += table[i].getSize();
    }
    return total;
}
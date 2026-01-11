#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <string>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 26;  
    LinkedList table[TABLE_SIZE];      

    
    int hashFunction(string word);

public:
   
    HashTable();

    ~HashTable();

    bool addWord(string english, string vietnamese);

    string searchWord(string english);

    bool deleteWord(string english);

    bool updateWord(string english, string newVietnamese);

    void displayAll();

    void displayByLetter(char letter);

    int getTotalWords();
};

#endif 
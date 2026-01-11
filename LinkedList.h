#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Word.h"
#include <string>
using namespace std;

class LinkedList {
private:
    Word* head;  
    int size;    

public:
  
    LinkedList();

    ~LinkedList();

    void insertAtHead(string english, string vietnamese);

    void insertAtTail(string english, string vietnamese);

    string search(string english);

    bool exists(string english);

    bool remove(string english);

    bool update(string english, string newVietnamese);

    void display();

    int getSize();

    bool isEmpty();

    void clear();

    Word* getHead();
};

#endif 
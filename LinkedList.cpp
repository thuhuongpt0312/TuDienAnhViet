#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::insertAtHead(string english, string vietnamese) {
    Word* newWord = new Word(english, vietnamese);
    newWord->next = head;
    head = newWord;
    size++;
}

void LinkedList::insertAtTail(string english, string vietnamese) {
    Word* newWord = new Word(english, vietnamese);

    if (head == nullptr) {
        head = newWord;
    }
    else {
        Word* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newWord;
    }
    size++;
}

string LinkedList::search(string english) {
    Word* current = head;
    while (current != nullptr) {
        if (current->english == english) {
            return current->vietnamese;
        }
        current = current->next;
    }
    return "";  
}

bool LinkedList::exists(string english) {
    Word* current = head;
    while (current != nullptr) {
        if (current->english == english) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool LinkedList::remove(string english) {
    if (head == nullptr) {
        return false;
    }

    if (head->english == english) {
        Word* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Word* current = head;
    Word* prev = nullptr;

    while (current != nullptr) {
        if (current->english == english) {
            prev->next = current->next;
            delete current;
            size--;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;  
}

bool LinkedList::update(string english, string newVietnamese) {
    Word* current = head;
    while (current != nullptr) {
        if (current->english == english) {
            current->vietnamese = newVietnamese;
            return true;
        }
        current = current->next;
    }
    return false;  
}

void LinkedList::display() {
    if (head == nullptr) {
        cout << "  (Danh sach trong)" << endl;
        return;
    }

    Word* current = head;
    int count = 1;
    while (current != nullptr) {
        cout << "  " << count << ". " << current->english
            << " : " << current->vietnamese << endl;
        current = current->next;
        count++;
    }
}

int LinkedList::getSize() {
    return size;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

void LinkedList::clear() {
    Word* current = head;
    while (current != nullptr) {
        Word* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

Word* LinkedList::getHead() {
    return head;
}
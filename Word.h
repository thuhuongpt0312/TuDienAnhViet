#pragma once
#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;

struct Word {
    string english;      
    string vietnamese;   
    Word* next;          

    Word(string eng, string vie) : english(eng), vietnamese(vie), next(nullptr) {}
};

#endif 
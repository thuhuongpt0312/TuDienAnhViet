#include <iostream>
#include <limits>
#include <string>
#include <Windows.h>
#include "HashTable.h"

using namespace std;


void setupConsole() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}


void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "      TU DIEN ANH - VIET" << endl;
    cout << "========================================" << endl;
    cout << "1. Them tu moi" << endl;
    cout << "2. Tra cuu tu" << endl;
    cout << "3. Hien thi tat ca tu" << endl;
    cout << "4. Hien thi tu theo nhom chu cai" << endl;
    cout << "5. Xoa tu" << endl;
    cout << "6. Sua nghia tu" << endl;
    cout << "0. Thoat" << endl;
    cout << "========================================" << endl;
    cout << "Chon chuc nang: ";
}


void addSampleWords(HashTable& dict) {
    dict.addWord("apple", "qua tao");
    dict.addWord("book", "quyen sach");
    dict.addWord("cat", "con meo");
    dict.addWord("dog", "con cho");
    dict.addWord("elephant", "con voi");
    dict.addWord("fish", "con ca");
    dict.addWord("grape", "qua nho");
    dict.addWord("house", "ngoi nha");
    dict.addWord("ice", "bang, da");
    dict.addWord("jacket", "ao khoac");
    dict.addWord("king", "vua");
    dict.addWord("lion", "su tu");
    dict.addWord("monkey", "con khi");
    dict.addWord("notebook", "vo ghi chep");
    dict.addWord("orange", "qua cam");
    dict.addWord("pen", "but muc");
    dict.addWord("queen", "nu hoang");
    dict.addWord("river", "con song");
    dict.addWord("sun", "mat troi");
    dict.addWord("tree", "cay");
    dict.addWord("umbrella", "cai o");
    dict.addWord("violin", "dan vi cam");
    dict.addWord("water", "nuoc");
    dict.addWord("xylophone", "dan moc cam");
    dict.addWord("yellow", "mau vang");
    dict.addWord("zebra", "ngua van");
}

int main() {
    
    setupConsole();

    HashTable dictionary;
    int choice;
    string english, vietnamese;
    char letter;

    
    cout << "Dang khoi tao tu dien voi du lieu mau..." << endl;
    addSampleWords(dictionary);
    cout << "Da them 26 tu mau vao tu dien (moi chu cai A-Z co 1 tu)!" << endl;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
        case 1: {
            
            cout << "\n--- THEM TU MOI ---" << endl;
            cout << "Nhap tu tieng Anh: ";
            getline(cin, english);
            cout << "Nhap nghia tieng Viet: ";
            getline(cin, vietnamese);

            if (dictionary.addWord(english, vietnamese)) {
                cout << "Da them tu \"" << english << "\" thanh cong!" << endl;
            }
            else {
                cout << "Khong the them tu!" << endl;
            }
            break;
        }

        case 2: {
            
            cout << "\n--- TRA CUU TU ---" << endl;
            cout << "Nhap tu can tra: ";
            getline(cin, english);

            string meaning = dictionary.searchWord(english);
            if (!meaning.empty()) {
                cout << english << " : " << meaning << endl;
            }
            else {
                cout << "Khong tim thay tu \"" << english << "\" trong tu dien!" << endl;
            }
            break;
        }

        case 3: {
            
            cout << "\n--- DANH SACH TAT CA TU ---" << endl;
            dictionary.displayAll();
            break;
        }

        case 4: {
            
            cout << "\n--- HIEN THI THEO NHOM CHU CAI ---" << endl;
            cout << "Nhap chu cai (A-Z): ";
            cin >> letter;
            cin.ignore(1000, '\n');
            dictionary.displayByLetter(letter);
            break;
        }

        case 5: {
            
            cout << "\n--- XOA TU ---" << endl;
            cout << "Nhap tu can xoa: ";
            getline(cin, english);

            if (dictionary.deleteWord(english)) {
                cout << "Da xoa tu \"" << english << "\" thanh cong!" << endl;
            }
            else {
                cout << "Khong tim thay tu \"" << english << "\" de xoa!" << endl;
            }
            break;
        }

        case 6: {
            
            cout << "\n--- SUA NGHIA TU ---" << endl;
            cout << "Nhap tu can sua: ";
            getline(cin, english);
            cout << "Nhap nghia moi: ";
            getline(cin, vietnamese);

            if (dictionary.updateWord(english, vietnamese)) {
                cout << "Da cap nhat tu \"" << english << "\" thanh cong!" << endl;
            }
            else {
                cout << "Khong tim thay tu \"" << english << "\" de sua!" << endl;
            }
            break;
        }

        case 0:
            cout << "\nCam on ban da su dung tu dien!" << endl;
            break;

        default:
            cout << "Lua chon khong hop le! Vui long chon lai." << endl;
        }

    } while (choice != 0);

    return 0;
}
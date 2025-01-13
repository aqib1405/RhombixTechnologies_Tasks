#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char Caesar(char v1) {
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int index;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] == v1) {
            index = i;
            break;
        }
    }
    return alphabets[(index + 3) % 26]; 
}

char ReverseCaesar(char v1) {
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int index;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] == v1) {
            index = i;
            break;
        }
    }
    return alphabets[(index - 3) % 26];
}

string Encryption(string line, int size) {
    char character, crypt;
    string word = "";
    for (int i = 0; i < size; i++) {
        character = line[i];
        if (character == ' ') {
            word.push_back(' '); 
        } else {
            crypt = Caesar(character);
            word.push_back(crypt);
        }
    }
    return word;
}

string Decryption(string line, int size) {
    char character, decrypt;
    string word = "";
    for (int i = 0; i < size; i++) {
        character = line[i];
        if (character == ' ') {
            word.push_back(' '); 
        } else {
            decrypt = ReverseCaesar(character);
            word.push_back(decrypt);
        }
    }
    return word;
}

int main() {
    fstream file1, file2;
    file1.open("bash.txt", ios::in);
    file2.open("dash.txt", ios::in);

    if (!file1.is_open()) {
        cerr << "Error: Could not open the file 'bash.txt'" << endl;
    }
    if (!file2.is_open()) {
        cerr << "Error: Could not open the file 'dash.txt'" << endl;
    }

    string option = "";
    string line = "";
    string line1 = "";
    int size, size1;
    string encrypted = "";
    string decrypted = "";

    cout << "Which algorithm do you want to test? " << endl;
    cin >> option;  

    if (option == "encryption") {
        while (getline(file1, line)) {
            size = line.size();
            encrypted = Encryption(line, size);
            cout << "The encrypted string is: " << endl;
            cout << encrypted << endl;
        }
    } else if (option == "decryption") {
        while (getline(file2, line1)) {
            size1 = line1.size();
            decrypted = Decryption(line1, size1);
            cout << "The decrypted string is: " << endl;
            cout << decrypted << endl;
        }
    }

    file1.close(); 
}

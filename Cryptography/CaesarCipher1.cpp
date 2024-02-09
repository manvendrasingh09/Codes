#include <iostream>
#include <string>

using namespace std;

void Decoder() {
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    for (int k = 0; k < 26; k++) {
        string output = "";
        for (int i = 0; i < input.length(); i++) {
            char ch = input[i];
            if (isalpha(ch)) {
                char base = isupper(ch) ? 'A' : 'a';
                output += static_cast<char>((ch - base - k + 26) % 26 + base);
            } else if (isdigit(ch)) {
                int base = 48;
                output += static_cast<char>((ch - base - k + 10) % 10 + base);
            } else {
                output += ch;
            }
        }
        cout << k << " : " << output << endl;
    }
}

int main() {
    Decoder();
    return 0;
}
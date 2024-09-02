#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

string uniqueCharactersInOrder(string s) {
    unordered_set<char> seen;
    string result;

    for (char c : s) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }

    return result;
}

int main() {
    string s;
    cin >> s;

    string uniqueStr = uniqueCharactersInOrder(s);
    cout << "String with unique characters in order: " << uniqueStr << endl;

    return 0;
}

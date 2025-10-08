//#include <iostream>
//#include <string>
//#include <conio.h>  
//using namespace std;
//
//char toLower(char c) {
//    if (c >= 'A' && c <= 'Z') {
//        return c +32;
//    }
//    return c;
//}
//bool isAlphaCustom(char c) {
//    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
//}
//bool checkPalindrome(string& word) {
//    string filtered = "";
//    for (int i = 0; i < word.length(); i++) {
//        if (isAlphaCustom(word[i])) {
//            filtered += toLower(word[i]);
//        }
//    }
//    if (filtered.empty()) {
//        return false;
//    }
//    int start = 0;
//    int end = filtered.length() - 1;
//    while (start < end) {
//        if (filtered[start] != filtered[end]) {
//            return false;
//        }
//        start++;
//        end--;
//    }
//    return true;
//}
//
//int main() {
//    string input;
//    char key;
//    cout << "Palindrome Checker Program" << endl;
//    while (true) {
//        cout << "Enter a string: ";
//        getline(cin, input);
//        if (input.empty()) {
//            cout << "Please enter a non-empty string." << endl;
//            continue;
//        }
//        bool hasAlpha = false;
//        for (char c : input) {
//            if (isAlphaCustom(c)) {
//                hasAlpha = true;
//                break;
//            }
//        }
//        if (!hasAlpha) {
//            cout << "Please enter a valid word or sentence containing alphabets.\n";
//            continue;
//        }
//        bool result = checkPalindrome(input);
//        if (result) {
//            cout << input << " is a palindrome." << endl;
//        }
//        else {
//            cout << input << " is not a palindrome." << endl;
//        }
//        cout << "Press 'Esc' to quit, or any other key to continue.";
//        key = _getch(); 
//        if (key == 27) {                        //27 ASCII of Escape key
//            cout << endl<<"Program ends." << endl;
//            break;
//        }
//        cout << endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//using namespace std;
//
//#define MAX_ATTEMPTS 7
//
//char toLowerCustom(char c) {
//    if (c >= 'A' && c <= 'Z') {
//        return c + 32;
//    }
//    return c;
//}
//bool isAlphaCustom(char c) {
//    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
//}
//int safeIntegerInput(int min, int max) {
//    int choice;
//    while (true) {
//        cin >> choice;
//        if (cin.fail() || choice < min || choice > max) {
//            cout << "Invalid input! Please enter a number between " << min << " and " << max << ": ";
//            cin.clear();
//            cin.ignore();
//        }
//        else {
//            cin.ignore(); 
//            return choice;
//        }
//    }
//}
//string getRandomWordFromFile(const string& category) {
//    ifstream file(category + ".txt");
//    if (!file.is_open()) {
//        cout << "Error: Could not open file '" << category << ".txt'. Please make sure it exists.\n";
//        return "";
//    }
//    string word, words[100];
//    int count = 0;
//    while (getline(file, word)) {
//        if (!word.empty()) {
//            words[count++] = word;
//        }
//    }
//    if (count == 0) {
//        cout << "No words found in file '" << category << ".txt'.\n";
//        return "";
//    }
//    int randomIndex = rand() % count;
//    return words[randomIndex];
//}
//void drawHangman(int attemptsLeft) {
//    cout << "\n---- HANGMAN ----\n";
//    cout << "Attempts left: " << attemptsLeft << endl;
//    switch (attemptsLeft) {
//    case 7:
//        cout << "   +---+\n"
//            << "       |\n"
//            << "       |\n"
//            << "       |\n"
//            << "       |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 6:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "       |\n"
//            << "       |\n"
//            << "       |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 5:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "   O   |\n"
//            << "       |\n"
//            << "       |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 4:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "   O   |\n"
//            << "   |   |\n"
//            << "       |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 3:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "   O   |\n"
//            << "  /|   |\n"
//            << "       |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 2:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "   O   |\n"
//            << "  /|\\  |\n"
//            << "       |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 1:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "   O   |\n"
//            << "  /|\\  |\n"
//            << "  /    |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    case 0:
//        cout << "   +---+\n"
//            << "   |   |\n"
//            << "   O   |\n"
//            << "  /|\\  |\n"
//            << "  / \\  |\n"
//            << "       |\n"
//            << "  =========\n";
//        break;
//    }
//}
//string selectCategory() {
//    cout << "\nAvailable Categories:\n"
//        << "1. Fruits\n"
//        << "2. Vegetables\n"
//        << "3. Sports\n"
//        << "4. Countries\n"
//        << "5. Animals\n"
//        << "Select a category (1-5): ";
//    int choice = safeIntegerInput(1, 5);
//    switch (choice) {
//    case 1: return "Fruits";
//    case 2: return "Vegetables";
//    case 3: return "Sports";
//    case 4: return "Countries";
//    case 5: return "Animals";
//    }
//    cout << "Invalid choice.Setting default to fruits." << endl;
//    return "Fruits"; 
//}
//void playGame() {
//    string category = selectCategory();
//    string secretWord = getRandomWordFromFile(category);
//    if (secretWord.empty()) {
//        cout << "Cannot start game due to missing or empty file.\n";
//        return;
//    }
//    string currentWord(secretWord.size(), '_');
//    string guessedLetters = "";
//    int attemptsLeft = MAX_ATTEMPTS;
//    while (attemptsLeft > 0 && currentWord != secretWord) {
//        drawHangman(attemptsLeft);
//        cout << "\nCategory: " << category;
//        cout << "\nWord: " << currentWord;
//        cout << "\nGuessed Letters: " << guessedLetters;
//        cout << "\nEnter a letter: ";
//        string input;
//        cin >> input;
//        if (input.length() != 1 || !isAlphaCustom(input[0])) {
//            cout << "Please enter a single valid letter.\n";
//            continue;
//        }
//        char guess = toLowerCustom(input[0]);
//        if (guessedLetters.find(guess) != string::npos) {
//            cout << "You already guessed that letter!\n";
//            continue;
//        }
//        guessedLetters += guess;
//        bool found = false;
//        for (size_t i = 0; i < secretWord.size(); i++) {
//            char actualChar = toLowerCustom(secretWord[i]);
//            if (actualChar == guess) {
//                currentWord[i] = secretWord[i];
//                found = true;
//            }
//        }
//        if (found) {
//            cout << "Good guess!\n";
//        }
//        else { 
//            cout << "Wrong guess!\n"; attemptsLeft--;
//        }
//    }
//    drawHangman(attemptsLeft);
//    if (currentWord == secretWord) {
//        cout << "\n Congratulations! You guessed the word: " << secretWord << endl;
//    }
//    else {
//        cout << "\n Game Over! The word was: " << secretWord << endl;
//    }
//}
//
//int main() {
//    srand(static_cast<unsigned int>(time(0)));
//    cout << "==============================\n";
//    cout << "        HANGMAN GAME\n";
//    cout << "==============================\n";
//    char choice;
//    do {
//        playGame();
//        cout << "\nDo you want to play again? (y/n): ";
//        cin >> choice;
//        choice = toLowerCustom(choice);
//    } while (choice == 'y');
//    cout << "\nThanks for playing Hangman!\n";
//    return 0;
//}
/***********************
 * Автор: Дедушев П.А. *
 ***********************/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

char toLowerAlpha(char c) {
  c = tolower(static_cast<unsigned char>(c));
  return isalpha(static_cast<unsigned char>(c)) ? c : '\0';
}

int main() {
  ifstream file("input.txt");
  map<char, int> letterFreq;
  map<string, int> bigramFreq;
  char prevChar = '\0';
  string line;

  while (getline(file, line)) {
    for (char c : line) {
      char letter = toLowerAlpha(c);
      if (letter == '\0') continue;
        letterFreq[letter]++;
        if (prevChar != '\0') {
        bigramFreq[string(1, prevChar) + letter]++;
        }
        prevChar = letter;
    }
    prevChar = '\0';
}

  cout << "Letter frequencies:\n";
  for (const auto& p : letterFreq) {
    cout << p.first << ": " << p.second << "\n";
  }

  cout << "\nBigram frequencies:\n";
  for (const auto& p : bigramFreq) {
    cout << p.first << ": " << p.second << "\n";
  }

  return 0;
}
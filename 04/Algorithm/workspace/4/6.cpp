#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define START_INDEX 0
#define ALPHABET_LENGTH 26

using namespace std;

int calculateMaxValue(int *letterValues, const vector<string>& wordList, unordered_map<char, int>& letterCount, int wordIndex, int currentValue);

int main() {
    int wordCount, letterCount;
    cin >> wordCount >> letterCount;

    unordered_map<char, int> availableLetters;
    vector<string> wordList(wordCount);

    int i = START_INDEX;
    while (i < wordCount) {
        cin >> wordList[i];
        ++i;
    }

    char character;
    int j = START_INDEX;
    while (j < letterCount) {
        cin >> character;
        availableLetters[character]++;
        ++j;
    }

    int* letterValues = new int[ALPHABET_LENGTH];
    int k = START_INDEX;
    while (k < ALPHABET_LENGTH) {
        cin >> letterValues[k];
        ++k;
    }

    cout << calculateMaxValue(letterValues, wordList, availableLetters, START_INDEX, START_INDEX);

    delete[] letterValues;
    return 0;
}

int calculateMaxValue(int* letterValues, const vector<string>& wordList, unordered_map<char, int>& letterCount, int wordIndex, int currentValue) {
    if (wordIndex == wordList.size()) {
        return currentValue;
    }

    unordered_map<char, int> tempLetterCount = letterCount;

    int valueWithoutCurrentWord = calculateMaxValue(letterValues, wordList, letterCount, wordIndex + 1, currentValue);

    string currentWord = wordList[wordIndex];
    int isValidWord = 1;

    int charIndex = START_INDEX;
    while (charIndex < currentWord.size()) {
        if (tempLetterCount[currentWord[charIndex]] > START_INDEX) {
            tempLetterCount[currentWord[charIndex]]--;
        } else {
            isValidWord = START_INDEX;
            break;
        }
        ++charIndex;
    }

    int valueWithCurrentWord = currentValue;
    if (isValidWord) {
        int wordValue = START_INDEX;
        charIndex = START_INDEX;
        while (charIndex < currentWord.size()) {
            wordValue += letterValues[currentWord[charIndex] - 'a'];
            ++charIndex;
        }
        valueWithCurrentWord = calculateMaxValue(letterValues, wordList, tempLetterCount, wordIndex + 1, currentValue + wordValue);
    }

    return max(valueWithCurrentWord, valueWithoutCurrentWord);
}

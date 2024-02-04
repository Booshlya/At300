#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WordSorter {
public:
    static void runSort() {
        vector<string> words;

        // Read words from the user
        cout << "Enter words (type 'XT' to stop):\n";
        string input;
        while (true) {
            cin >> input;
            if (input == "XT") {
                break;
            }
            words.push_back(input);
        }


        cout << "\nYour input:\n";
        for (const auto& word : words) {
            cout << word << ' ';
        }
        cout << '\n';

        // Sorting
        sort(words.begin(), words.end());

        // Display  sorted words
        cout << "\nSorted words:\n";
        for (const auto& word : words) {
            cout << word << ' ';
        }
        cout << '\n';
    }
};

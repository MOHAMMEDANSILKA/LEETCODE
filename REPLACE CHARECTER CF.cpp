#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string minimizeDistinctPermutations(string s) {
    unordered_map<char, int> freq;
    
    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }
    
    // Find the character with maximum frequency
    char maxChar = s[0];
    int maxCount = freq[maxChar];
    
    for (const auto& pair : freq) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxChar = pair.first;
        }
    }
    
    // Replace all characters with maxChar to minimize distinct permutations
    fill(s.begin(), s.end(), maxChar);
    
    return s;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the string
        string s;
        cin >> s; // Input string

        cout << minimizeDistinctPermutations(s) << endl; // Output modified string
    }

    return 0;
}

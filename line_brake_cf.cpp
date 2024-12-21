#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases

    while (t--) {
        int n, m;
        cin >> n >> m;  // Read number of words and max length of the first strip

        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];  // Read each word
        }

        int total_length = 0;
        int count = 0;

        // Calculate how many words can fit on the first strip
        for (const auto& word : words) {
            if (total_length + word.length() <= m) {
                total_length += word.length();
                count++;
            } else {
                break;  // Stop if adding this word exceeds m
            }
        }

        cout << count_it << endl;  // Output the result for this test case
    }

    return 0;
}

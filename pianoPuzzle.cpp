/*
*   Problem: The Piano Puzzle
*   Problem Link: https://hyperskill.org/learn/daily/53139
* */

#include<bits/stdc++.h>
using namespace std;


string solve(string &s, string &t) {
    map<char, int> window{};
    map<char, int> freq{};
    
    for (char ch : t) {
        freq[ch]++;
    }
    
    int minLen = s.size();
    int idx{}, have{};
    int need = freq.size();
    
    for (int left = 0, right = 0; right < s.size(); right++) {
        char ch = s[right];
        
        if (!freq.count(ch))
            continue;
        
        if (++window[ch] == freq[ch])
            have++;

        while(have == need) {
            int windowLen = right - left + 1;
            if (windowLen < minLen) {
                idx = left;
                minLen = windowLen;
            }
            
            window[s[left]]--;
            if (window[s[left]] < freq[s[left]])
                have--;
            
            left++;
        }
    }
    
    return s.substr(idx, minLen);
}

int main() {
    ifstream file("hyperskill-dataset-117366133.txt");
    string sequence;
    file >> sequence;
    string notes = "ABCDEFG";
    cout << solve(sequence, notes);
    return 0;
}

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Alternate implementation 
        
        // unordered_map<char, int> magMap;

        // for (int i = 0; i < magazine.length(); i++) {
        //     if (magMap.find(magazine[i]) != magMap.end()) {
        //         magMap[magazine[i]] += 1;
        //     } else {
        //         magMap[magazine[i]] = 1;
        //     }
        // }

        // for (int j = 0; j < ransomNote.length(); j++) {
        //     if (magMap.find(ransomNote[j]) != magMap.end()) {
        //         if (magMap[ransomNote[j]] > 1) {
        //             magMap[ransomNote[j]] -= 1;
        //         } else {
        //             magMap.erase(ransomNote[j]);
        //         }
        //     } else {
        //         return false;
        //     }
        // }

        for (int i = 0; i < ransomNote.length(); i++) {
            // Tries to search for character, if successful, returns index, else
            // returns -1.
            int index = magazine.find(ransomNote[i]);
            if (index != -1) {
                magazine.erase(index, 1);   // Index to erase and the count of characters to erase
            } else {
                return false;
            }
        }

        return true;
    }
};
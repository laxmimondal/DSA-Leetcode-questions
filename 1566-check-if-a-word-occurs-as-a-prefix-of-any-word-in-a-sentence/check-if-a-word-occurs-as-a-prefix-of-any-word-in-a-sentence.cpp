class Solution {
public:
    // Function to find if the searchWord is a prefix of any word in the sentence.
    // Returns the word's index if found, otherwise returns -1.
    int isPrefixOfWord(string sentence, string searchWord) {
        // Initialize a stringstream with the given sentence
        stringstream ss(sentence);
      
        // Variable to store each word while extracting from the sentence
        string currentWord;
      
        // Variable to keep track of the word's index
        int wordIndex = 1;
      
        // Extract words one by one from the stringstream
        while (ss >> currentWord) {
            // Check if the current word starts with the searchWord
            if (currentWord.find(searchWord) == 0) {
                // If searchWord is a prefix of currentWord,
                // return the current word's index
                return wordIndex;
            }
            // Move to the next word
            ++wordIndex;
        }
        // If the searchWord is not a prefix of any word, return -1
        return -1;
    }
};
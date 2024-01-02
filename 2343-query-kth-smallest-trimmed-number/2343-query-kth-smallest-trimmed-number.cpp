
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& numbers, vector<vector<int>>& queries) {
        
        int numOfNumbers = numbers.size(); 
        // Total number of strings in the numbers vector
        
        
        vector<pair<string, int>> trimmedNumbers(numOfNumbers); 
        // Pair to hold trimmed strings and original indices
        
        
        vector<int> answer; 
        // Vector to hold the final results

        // Iterate through each query
        for (auto& query : queries) {
            int k = query[0];  // kth smallest number to find after trimming
            int trimLength = query[1]; // Length of the number to consider after trimming

            // Prepare the trimmed numbers along with their original indices
            for (int i = 0; i < numOfNumbers; ++i) {
                // Trim the number keeping the last 'trimLength' digits and store the original index
                trimmedNumbers[i] = {numbers[i].substr(numbers[i].size() - trimLength), i};
            }

            // Sort the trimmed numbers, (since we're using pairs, it sorts by the first element (trimmed string), and uses the   second element (original index) for tie-breaking)
            sort(trimmedNumbers.begin(), trimmedNumbers.end());

            // Add the original index of the kth smallest trimmed number to the answer vector
            answer.push_back(trimmedNumbers[k - 1].second);
        }

        // Return the final result after processing all queries
        return answer;
    
    }
};
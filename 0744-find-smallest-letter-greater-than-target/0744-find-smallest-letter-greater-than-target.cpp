class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;

        // If target is greater or equal to the last letter, wrap around
        if (target >= letters.back()) return letters[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        // low will point to the smallest element greater than target
        return letters[low];
    }
};

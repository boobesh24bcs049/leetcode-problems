class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maximumOverlap = 0;

        for (int dr = -(n - 1); dr <= n - 1; dr++) {
            for (int dc = -(n - 1); dc <= n - 1; dc++) {
                int currentOverlap = 0;

                for (int row = 0; row < n; row++) {
                    for (int col = 0; col < n; col++) {
                        int shiftedRow = row + dr;
                        int shiftedCol = col + dc;

                        if (shiftedRow >= 0 && shiftedRow < n &&
                            shiftedCol >= 0 && shiftedCol < n) {
                            if (img1[row][col] == 1 &&
                                img2[shiftedRow][shiftedCol] == 1) {
                                currentOverlap++;
                            }
                        }
                    }
                }

                maximumOverlap = max(maximumOverlap, currentOverlap);
            }
        }

        return maximumOverlap;
    }
};
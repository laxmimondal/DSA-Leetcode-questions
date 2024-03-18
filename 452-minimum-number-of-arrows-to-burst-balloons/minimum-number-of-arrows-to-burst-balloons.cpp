class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort the intervals based on the end points
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1; // At least one arrow is needed
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the previous balloon ends,
            // we need another arrow
            if (points[i][0] > end) {
                ++arrows;
                end = points[i][1];
            }
        }

        return arrows;
    }
};
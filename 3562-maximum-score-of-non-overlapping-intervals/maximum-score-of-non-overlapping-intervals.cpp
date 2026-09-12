class Solution {
public:
    using ll = long long;

    struct Result {
        ll totalWeight = 0;
        vector<int> selectedIndices;
    };

    vector<vector<int>> sortedIntervals;
    vector<int> startTimes;
    vector<vector<Result>> memo;
    int intervalCount;

    bool isBetter(const Result& first, const Result& second) {
        if (first.totalWeight != second.totalWeight)
            return first.totalWeight > second.totalWeight;

        return first.selectedIndices < second.selectedIndices;
    }

    Result findBest(int currentIndex, int selectedCount) {
        if (currentIndex == intervalCount || selectedCount == 4)
            return {0, {}};

        Result& cachedResult = memo[currentIndex][selectedCount];

        if (cachedResult.totalWeight != -1)
            return cachedResult;

        Result skipCurrent = findBest(currentIndex + 1, selectedCount);

        int nextIndex = upper_bound(
            startTimes.begin(),
            startTimes.end(),
            sortedIntervals[currentIndex][1]
        ) - startTimes.begin();

        Result takeCurrent = findBest(nextIndex, selectedCount + 1);

        takeCurrent.totalWeight += sortedIntervals[currentIndex][2];
        takeCurrent.selectedIndices.push_back(
            sortedIntervals[currentIndex][3]
        );

        sort(
            takeCurrent.selectedIndices.begin(),
            takeCurrent.selectedIndices.end()
        );

        return cachedResult =
            isBetter(takeCurrent, skipCurrent)
            ? takeCurrent
            : skipCurrent;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        intervalCount = intervals.size();

        sortedIntervals.clear();

        for (int index = 0; index < intervalCount; index++) {
            sortedIntervals.push_back({
                intervals[index][0],
                intervals[index][1],
                intervals[index][2],
                index
            });
        }

        sort(sortedIntervals.begin(), sortedIntervals.end());

        startTimes.clear();

        for (const auto& interval : sortedIntervals)
            startTimes.push_back(interval[0]);

        memo.assign(intervalCount, vector<Result>(4));

        for (int i = 0; i < intervalCount; i++) {
            for (int j = 0; j < 4; j++) {
                memo[i][j].totalWeight = -1;
            }
        }

        return findBest(0, 0).selectedIndices;
    }
};
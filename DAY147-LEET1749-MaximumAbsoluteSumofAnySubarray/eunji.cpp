class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
	vector<int>dpMax;
	vector<int>dpMin;
	dpMax.assign(nums.begin(), nums.end());
	dpMin.assign(nums.begin(), nums.end());

	int numMax=dpMax[0];
	int numMin = dpMin[0];
	for (int i = 1; i < nums.size(); i++) {
		if (dpMax[i - 1] > 0)dpMax[i] += dpMax[i - 1];
		if (dpMax[i] > numMax) numMax = dpMax[i];

		if (dpMin[i - 1] < 0)dpMin[i] += dpMin[i - 1];
		if (dpMin[i] < numMin) numMin = dpMin[i];
	}

	return numMax > (-numMin) ? numMax : -numMin;
    }
};

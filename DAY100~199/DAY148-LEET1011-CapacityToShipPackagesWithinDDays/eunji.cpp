class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int size = weights.size();
		int weightSum = 0;
		int max = 0;
		for (int i = 0; i < size; i++) {
			weightSum += weights[i];
			if (weights[i] > max) max = weights[i];
		}
		int start = max > (weightSum / D) ? max : weightSum / D;
		int end = weightSum;
		int mid;
		while (start != end) {
			mid = (start + end) / 2;
			if (CountDays(weights, mid, size) <= D) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		return start;
	}

	int CountDays(vector<int> weights, int maxWeight, int size) {
		int sum = 0;
		int days = 1;
		for (int i = 0; i < size; i++) {
			sum += weights[i];
			if (sum > maxWeight) {
				days++;
				sum = weights[i];
			}
		}
		return days;
	}
};

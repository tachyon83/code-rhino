//수정중
bool isPossibleDivide(vector<int>& nums, int k) {
	if (nums.size() % k != 0) return false;
	sort(nums.begin(), nums.end());
	vector<int> divide(nums.size()/k,0);
	int row=0;
	int prev=nums[0];
	divide[0]++;
	int temp=row;
	for (int i = 1; i < nums.size(); i++) {
		if (divide[row] == k) row++;
		if (nums[i] == prev) {
		//	if (temp + 1 >= divide.size()) return false;
			divide[++temp]++;
		}
		else {
			if (divide[row] != 0 && prev + 1 != nums[i]) return false;
			temp = row;
			divide[row]++;
			prev = nums[i];
		}
	}
	return true;
}

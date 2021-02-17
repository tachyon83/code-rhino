int solution(string name) {
	int sum = 0;
	int size = name.size();
	sum += minUpdown(name[0]);
	if (size == 1) return sum;

	int start = 0;
	int end = 0;
	int maxdegree = 0;
	int last = 0;
	for (int i = 1; i < size; i++) {
		if (name[i] == 'A') continue;
		sum += minUpdown(name[i]);
		if (start == 0) start = i;
		else { 
			if (i - end > maxdegree && end!=0) {
				maxdegree = i - end;
				last = i;
			}
			end = i;
		}
	}

	if (start == 0) return 0;
	int move2 = 999999999;
	if (end == 0) end=start;
	else {
		move2 = (last - maxdegree) * 2 + (size - last);
	}
	//int move2 = last-maxdegree<=size-last?last-maxdegree:size-last;
	int move= (size - start) <= end ? size - start : end;
	sum += (move <= move2 ? move : move2);

	return sum;

	//사람들이 올려놓은 테케 11번 예제보고 코드 바꿧는데... 실행결과 테스트11은 통과안하네요...
	//음...

}

int minUpdown(char k) {
	if (k == 'N') { return 13; }
	else if (k < 'N') { return k - 'A'; }
	else { return 'Z' - k + 1; }
}

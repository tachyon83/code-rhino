import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Solution {
    public String[] solution(String[] files) {
        Arrays.sort(files, new Comparator<String>() {

			@Override
			public int compare(String o1, String o2) {
				String head1 = new StringTokenizer(o1, "0123456789").nextToken().toUpperCase();
				String head2 = new StringTokenizer(o2, "0123456789").nextToken().toUpperCase();

				int result = head1.compareTo(head2);
				if (result == 0) {
					int num1 = 0;
					boolean flag = false;
					for (char a : o1.toCharArray()) {
						if (a >= '0' && a <= '9') {
							num1 *= 10;
							num1 += (a - '0');
							flag = true;
							continue;
						}
						if (flag) {
							break;
						}
					}
					int num2 = 0;
					flag = false;
					for (char a : o2.toCharArray()) {
						if (a >= '0' && a <= '9') {
							num2 *= 10;
							num2 += (a - '0');
							flag = true;
							continue;
						}
						if (flag) {
							break;
						}
					}

					result = Integer.compare(num1, num2);
				}

				return result;
			}

		});

		return files;
    }
}
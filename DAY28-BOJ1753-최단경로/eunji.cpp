#include <iostream>
#define INF 999999;

//다익스트라 - 우선순위 큐 말고 그냥 배열이용함--> 메모리초과->힙이용해야될듯

using namespace std;

int main() {
	int V, E, K;

	cin >> V >> E;
	cin >> K;

	//동적할당후 arr[0]를 다익스트라를 이용하며 저장할것임.
	//visited는 방문한곳 표시

	int **arr = (int **)calloc(V + 1, sizeof(int*));
	int *visited = (int *)calloc(V + 1, sizeof(int));
	for (int i = 0; i <= V + 1; i++) {
		arr[i] = (int *)calloc(V + 1, sizeof(int));
}

	for (int i = 0; i < E; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		arr[start][end] = weight;
	}
	
	int start;
	int min = INF;
	int count=1;
	for (int i = 1; i <= V; i++) {
		if (i == K) {
			arr[0][i] = 0;
		}
		else if (arr[K][i] != 0) {
			arr[0][i] = arr[K][i];
		}
		else {
			arr[0][i] = INF;
		}
	}
	visited[K] = 1;
	

	while (1) {
		if (++count>V) {
			break;
		}
		for (int j = 1; j <= V; j++) {
			if (arr[0][j] < min && visited[j] == 0) {
				min = arr[0][j];
				start = j;
			}
		}

		visited[start] = 1;
		for (int i = 1; i <= V; i++) {
			if (arr[start][i] != 0 && i != start) {
				int dis = arr[0][start] + arr[start][i];
				if (dis < arr[0][i]) {
					arr[0][i] = dis;
				}
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (arr[0][i] == 999999) {
			cout << "INF" << endl;
		}
		else {
			cout << arr[0][i] << endl;
		}
	}

}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CNT_ASCII 95 //출력 가능한 ASCII (알파벳 26*2 + 숫자 10 + 특수문자32 + 공백 1) 32~126
#define MAX_STR 31

char name[MAX_STR];
int count;

struct Trie {
	int count;
	int finish;

	struct Trie *children[CNT_ASCII];
};

void insert(struct Trie *p, char *name) {
	int temp;

	if (*name == 0) {
		p->count++;
		return;
	}

	temp = *name - 32;

	if (p->children[temp] == 0) {
		p->children[temp] = (struct Trie *)malloc(sizeof(struct Trie));
		p->children[temp]->count = 0;
		memset(p->children[temp]->children, 0, sizeof(struct Trie *) * CNT_ASCII);
	}
	insert(p->children[temp], name + 1);
}

void print(struct Trie *p, int depth) {
	int i;
	float result;

	for (i = 0; i < CNT_ASCII; i++) {
		if (p->children[i] == 0)
			continue;

		name[depth] = i + 32;
		if (p->children[i]->count) {
			name[depth + 1] = '\0';
			printf("%s %.4f\n", name, ((float)p->children[i]->count * 100 / count));
			p->children[i]->count = 0;
		}
		print(p->children[i], depth + 1);
	}
}

void free_trie(struct Trie *p) {
	int i;

	for (i = 0; i < CNT_ASCII; i++) {
		if (p->children[i] == 0)
			continue;

		free_trie(p->children[i]);
		free(p->children[i]);
	}
}

int main() {
	struct Trie root;

	memset(root.children, 0, sizeof(struct Trie *) * CNT_ASCII);

	//freopen("input.txt", "r", stdin);

	while (1) {
		memset(name, 0, MAX_STR);
		scanf("%[^\n] ", name);

		if (name[0] == 0)
			break;

		count++;
		insert(&root, name);
	}

	print(&root, 0);

	free_trie(&root);

	return 0;
}

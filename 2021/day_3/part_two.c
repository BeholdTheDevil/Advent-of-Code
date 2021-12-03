#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int count;
	struct node *one;
	struct node *zero;
} Node;

typedef Node* Tree;

Node *create_node()
{
	Node *n = malloc(sizeof(struct node));

	n->count = 0;
	n->one = NULL;
	n->zero = NULL;

	return n;
}

void process_line(Tree t, char *s, int len)
{
	Node *n = t;

	for(int i = 0; i < len && n != NULL ; i++) {
		if(s[i] == '1') {
			if(n->one == NULL) {
				n->one = create_node();
			}
			n->one->count++;
			n = n->one;
		}
		else {
			if(n->zero == NULL) {
				n->zero = create_node();
			}
			n->zero->count++;
			n = n->zero;
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Usage: %s <inputfile> <optional outputfile>\n", argv[0]);
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	int line_length = 12;
	char line[line_length+1];

	Tree t = create_node(line_length);

	while(fscanf(fp, "%s\n", line) == 1) {
		process_line(t, line, line_length);
	}

	unsigned int oxy = 0;
	int i = 0;

	Node *n = t;
	while(i < line_length) {
		oxy <<= 1;
		if(n->zero == NULL) {
			printf("%d ", 1);
			oxy |= 1;
			n = n->one;
		}
		else if(n->one == NULL) {
			printf("%d ", 0);
			oxy |= 0;
			n = n->zero;
		}
		if(n->one->count >= n->zero->count) {
			oxy |= 1;
			n = n->one;
		}
		else {
			oxy |= 0;
			n = n->zero;
		}
		i++;
	}

	int co2 = 0;
	i = 0;
	n = t;
	while(i < line_length && n != NULL) {
		co2 <<= 1;
		if(n->zero == NULL) {
			printf("%d ", 1);
			co2 |= 1;
			n = n->one;
		}
		else if(n->one == NULL) {
			printf("%d ", 0);
			co2 |= 0;
			n = n->zero;
		}
		else if(n->zero->count <= n->one->count) {
			printf("%d ", 0);
			co2 |= 0;
			n = n->zero;
		}
		else {
			printf("%d ", 1);
			co2 |= 1;
			n = n->one;
		}
		i++;
	}

	printf("\n\nOxygen: %u\nCarbon Dioxide: %u\nLife Support Rating: %u\n", oxy, co2, oxy*co2);

	fclose(fp);
	return 0;
}

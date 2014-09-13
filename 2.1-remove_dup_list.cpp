#include <iostream>
#include <cstring>
using namespace std;

typedef struct node {
	int data;
	node *next;
} node;
bool myhash[100];

node* init(int a[], int n) {
	node *head, *p;
	for (int i = 0; i < n; ++i) {
		node *nd = new node();
		nd->data = a[i];
		if (i == 0) {
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}
void removedulicate(node *head) {
	if (head == NULL)
		return;
	node *p = head, *q = head->next;
	myhash[head->data] = true;
	while (q) {
		if (myhash[q->data]) {
			node *t = q;
			p->next = q->next;
			q = p->next;
			delete t;
		} else {
			myhash[q->data] = true;
			p = q;
			q = q->next;
		}
	}
}
void removedulicate1(node *head) {
	if (head == NULL)
		return;
	node *p, *q, *c = head;
	while (c) {
		p = c;
		q = c->next;
		int d = c->data;
		while (q) {
			if (q->data == d) {
				node *t = q;
				p->next = q->next;
				q = p->next;
				delete t;
			} else {
				p = q;
				q = q->next;
			}
		}
		c = c->next;
	}
}
void print(node *head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void freelist(node *head) {
	node* tmp;
	while (head) {
		tmp=head;
		head = head->next;
		delete tmp;
	}
}
int main() {
	int n = 10;
	int a[] = { 3, 2, 1, 3, 5, 6, 2, 6, 3, 1 };
	memset(myhash, false, sizeof(myhash));
	node *head = init(a, n);
	removedulicate1(head);
	print(head);
	freelist(head);
	return 0;
}

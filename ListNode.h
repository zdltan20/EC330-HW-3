#ifndef _LISTNODE
#include <cstddef>
#define _LISTNODE

struct DListNode {
	int val;
	DListNode *prev;
	DListNode *next;
	DListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

#endif


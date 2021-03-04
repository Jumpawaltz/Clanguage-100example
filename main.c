#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *createNode(int);
struct node *getIndexOf(struct node *, int);
void visit(struct node *list);
void traverse(struct node *, void (*)(struct node *), void (*)(void));
void printNewLine(void);
int getLength(struct node *);
void insert(struct node *, int, struct node *);
void append(struct node *, struct node *);
struct node *removeAt(struct node *, int );
struct node *removeTail(struct node *);
void dispose(struct node *);

int main(void) {
    struct node *pHead = createNode(5);
    if (pHead == NULL) {
        puts("分配内存失败!");
        return 0;
    }
    traverse(pHead, &visit,&printNewLine);
    struct node *p = getIndexOf(pHead, 2);
    p->data = 12;
    getIndexOf(pHead, 2)->data = 2;
    traverse(pHead, &visit, &printNewLine);

    return 0;
}

struct node *createNode(int count) {
    struct node *head = malloc(sizeof(struct node));
    if (head == NULL) {
        puts("创建头节点失败!!");
        return 0;
    }
    head->data = 0;
    head->next = NULL;
    struct node *tail = head;
    for (int i = 0; i < count - 1; ++i) {
        struct node *p;
        do {
            p = malloc(sizeof(struct node));
        } while (p == NULL);
        p->next = NULL;
        p->data = 0;
        tail->next = p;
        tail = p;
    }
    return head;
}

struct node *getIndexOf(struct node *list, int index) {
    if (index == 1) {
        return list;
    }
    struct node *tail = list;
    for (int i = 0; i < index; ++i) {
        tail = tail->next;
    }
    return tail;
}

void traverse(struct node *list, void (*visitor)(struct node *), void (*onEnding)(void)) {
    struct node *p = list;
    while (list->next != NULL) {
        (*visitor)(p);
        p = p->next;
    }
    (*onEnding)();
}

void visit(struct node *list) {
    printf("%d ", list->data);
}


void printNewLine(void) {
    putchar('\n');
}

int getLength(struct node *list) {
    int count = 1;
    struct node *p = list->next;
    while (p->next != NULL) {
        count++;
        p = p->next;
    }
    return 0;
}

void insert(struct node *list, int index, struct node *pNode) {
    int length = getLength(list);
    if (index > length) {
        puts("插入索引越界!");
    }
    struct node *p = getIndexOf(list, index);
    struct node *q = p->next;
    p->next = pNode;
    pNode->next = q;
}

void append(struct node *list, struct node *pNode) {
    struct node *p = list;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = pNode;
    pNode->next = NULL;
}

struct node *removeAt(struct node *list, int index) {
    struct node *q, *r;
    struct node *p = getIndexOf(list, index - 1);
    q = p->next;
    r = q->next;
    p->next = r;
    return p;
}

struct node *removeTail(struct node *list) {
    int length = getLength(list);
    struct node *pTail = getIndexOf(list, length - 1);
    struct node *returnNode = pTail;
    pTail->next = NULL;
    return returnNode;
}

void dispose(struct node *list) {
    struct node *p = list, *q = p;
    while (p->next != NULL) {
        p = p->next;
        free(q);
    }
}
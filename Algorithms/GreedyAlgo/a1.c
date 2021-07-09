#include <stdio.h>
#include <stdlib.h>

#define MXTREHEIGHT 100
// huffman tree node
struct minHeapNode
{
    char data;
    u_int32_t freq;
    struct minHeapNode *left, *right;
};

// minheap
struct minHeap
{
    u_int32_t size;     //.. current size
    u_int32_t capacity; //.. capacity

    struct minHeapNode **arr;
};

/**
 * @def huffman creation from minheap
 */
struct minHeapNode *newNode(char data, u_int32_t freq)
{
    struct minHeapNode *temp = (struct minHeapNode *)malloc(sizeof(struct minHeapNode));

    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

/**
 * @def MinHeap creation
 */
struct minHeap *createMinHeap(u_int32_t cap)
{
    struct minHeap *x = (struct minHeap *)malloc(sizeof(struct minHeap));

    x->size = 0;
    x->capacity = cap;
    x->arr = (struct minHeapNode **)malloc(x->capacity * sizeof(struct minHeapNode *));

    return x;
}

void swapMinHeapNode(struct minHeapNode **a, struct minHeapNode **b)
{
    struct minHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct minHeap *heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest = left;

    if (right < heap->size &&
        heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&heap->arr[smallest], &heap->arr[idx]);
        heapify(heap, smallest);
    }
}

int isSize1(struct minHeap *minHeap)
{
    return (minHeap->size == 1);
}

// to extract the minimum value node from heap
struct minHeapNode *extractMin(struct minHeap *x)
{
    struct minHeapNode *t = x->arr[0];
    x->arr[0] = x->arr[x->size - 1];

    --(x->size);
    heapify(x, 0);

    return t;
}

void insertMinHeapEle(struct minHeap *heap, struct minHeapNode *huffman)
{
    ++(heap->size);
    int i = heap->size - 1;
    while (i && huffman->freq < heap->arr[(i - 1) / 2]->freq /*parent index heap*/)
    {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->arr[i] = huffman;
}

void buildMinHeap(struct minHeap *x)
{
    int n = x->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; i--)
        heapify(x, i);
}

/* leaf in huffman node or not*/
int isLeaf(struct minHeapNode *root)
{
    return (!(root->left) && !(root->right));
}

// Creates a min heap of capacity equal to size and inserts all character of data[] in min heap. Initially size of min heap is equal to capacity
/* main function to create the minHeap */
struct minHeap *createandBuildminHeap(char data[], u_int32_t freq[], int size)
{
    struct minHeap *xy = createMinHeap(size);
    for (int i = 0; i < size; i++)
        xy->arr[i] = newNode(data[i], freq[i]);

    xy->size = size;
    buildMinHeap(xy);

    return xy;
}

/* main f() to builds the huffman tree */
struct minHeapNode *buildHuffmanTree(char data[], u_int32_t freq[], int size)
{
    struct minHeapNode *left, *right, *top;
    // create minHeap of capacity equal to size
    struct minHeap *minheap = createandBuildminHeap(data, freq, size);

    while (!isSize1(minheap))
    {
        // extract the two minumim freq items from minheap
        left = extractMin(minheap);
        right = extractMin(minheap);

        // create a new internal node with frequency == to the sum of the two nodes
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeapEle(minheap, top);
    }
    // the remaining node is the root node and the tree is complete
    return extractMin(minheap);
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");
}

void printCodes(struct minHeapNode *root, int ar[], int top)
{
    // left child assign '0'
    if (root->left)
    {
        ar[top] = 0;
        printCodes(root->left, ar, top + 1);
    }
    // right child assign '1'
    if (root->right)
    {
        ar[top] = 1;
        printCodes(root->right, ar, top + 1);
    }
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        print(ar, top);
    }
}

void huffmanCode(char data[], u_int32_t freq[], int size)
{
    struct minHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MXTREHEIGHT], top = 0;
    printCodes(root, arr, top);
}

int main(int argc, char const *argv[])
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    u_int32_t freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    huffmanCode(arr, freq, size);
    remove(argv[0]);
    return 0;
}

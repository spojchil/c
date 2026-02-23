#ifndef BIN_HEAP_H
#define BIN_HEAP_H

typedef int Elem;

typedef struct bin_heap {
    int capacity;
    int size;
    Elem *data;
} *bin_heap_t;

bin_heap_t bin_heap_create(int capacity);
void bin_heap_destroy(bin_heap_t heap);
int bin_heap_insert(bin_heap_t heap, Elem elem);
int bin_heap_remove_min(bin_heap_t heap, Elem *elem);
int bin_heap_is_empty(bin_heap_t heap);
int bin_heap_is_full(bin_heap_t heap);
int bin_heap_find_min(bin_heap_t heap, Elem *elem);

#endif // BIN_HEAP_H
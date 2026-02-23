#include "bin_heap.h"
#include <stdlib.h>

bin_heap_t bin_heap_create(int capacity) {
    bin_heap_t heap = malloc(sizeof(struct bin_heap));
    if (heap) {
        heap->capacity = capacity;
        heap->size = 0;
        heap->data = malloc(capacity * sizeof(Elem));
        if (!heap->data) {
            free(heap);
            return NULL;
        }
    }
    return heap;
}

void bin_heap_destroy(bin_heap_t heap) {
    if (heap) {
        free(heap->data);
        free(heap);
    }
}

int bin_heap_is_full(bin_heap_t heap) {
    return heap->size >= heap->capacity;
}

int bin_heap_is_empty(bin_heap_t heap) {
    return heap->size == 0;
}

int bin_heap_insert(bin_heap_t heap, Elem elem) {
    if (bin_heap_is_full(heap)) {
        return -1; // Heap is full
    }
    heap->data[heap->size++] = elem;
    if (heap->size > 1) {
        // Percolate up
        int i = heap->size - 1;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap->data[i] < heap->data[parent]) {
                Elem temp = heap->data[i];
                heap->data[i] = heap->data[parent];
                heap->data[parent] = temp;
                i = parent;
            } else {
                break;
            }
        }
    }
    return 0; // Success
}

int bin_heap_remove_min(bin_heap_t heap, Elem *elem) {
    if (bin_heap_is_empty(heap)) {
        return -1; // Heap is empty
    }
    *elem = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    // Percolate down
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            Elem temp = heap->data[i];
            heap->data[i] = heap->data[smallest];
            heap->data[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return 0; // Success
}

int bin_heap_find_min(bin_heap_t heap, Elem *elem) {
    if (bin_heap_is_empty(heap)) {
        return -1; // Heap is empty
    }
    *elem = heap->data[0];
    return 0; // Success
}


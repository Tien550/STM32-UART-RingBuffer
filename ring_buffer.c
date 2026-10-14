#include "ring_buffer.h"

void RingBuffer_Init(RingBuffer_t *rb) {
    rb->head = 0;
    rb->tail = 0;
}

bool RingBuffer_Push(RingBuffer_t *rb, uint8_t data) {
    uint16_t next_head = (rb->head + 1) % BUFFER_SIZE;
    
    // Check if buffer is full
    if (next_head == rb->tail) {
        return false; 
    }
    
    rb->buffer[rb->head] = data;
    rb->head = next_head;
    return true;
}

bool RingBuffer_Pop(RingBuffer_t *rb, uint8_t *data) {
    // Check if buffer is empty
    if (rb->head == rb->tail) {
        return false; 
    }
    
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    return true;
}

bool RingBuffer_IsEmpty(const RingBuffer_t *rb) {
    return (rb->head == rb->tail);
}

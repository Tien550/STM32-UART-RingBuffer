#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} RingBuffer_t;

// Function Prototypes
void RingBuffer_Init(RingBuffer_t *rb);
bool RingBuffer_Push(RingBuffer_t *rb, uint8_t data);
bool RingBuffer_Pop(RingBuffer_t *rb, uint8_t *data);
bool RingBuffer_IsEmpty(const RingBuffer_t *rb);

#endif /* RING_BUFFER_H */

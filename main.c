#include "stm32f4xx.h"
#include "ring_buffer.h"

RingBuffer_t uart_rx_buffer;

int main(void) {
    RingBuffer_Init(&uart_rx_buffer);
    
    // Hardware initialization code omitted for brevity
    // ...
    
    while(1) {
        uint8_t received_byte;
        // Process data outside of the interrupt (Main Loop)
        if (RingBuffer_Pop(&uart_rx_buffer, &received_byte)) {
            // Do something with received_byte
        }
    }
}

// EVENT HANDLER: UART Receive Interrupt Service Routine
void USART1_IRQHandler(void) {
    // Check if RX Not Empty event triggered the interrupt
    if (USART1->SR & USART_SR_RXNE) {
        uint8_t data = USART1->DR; // Read hardware register
        RingBuffer_Push(&uart_rx_buffer, data); // Push to software buffer safely
    }
}

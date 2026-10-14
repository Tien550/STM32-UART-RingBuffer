# STM32-UART-RingBuffer
Interrupt-Safe Circular Buffer for UART Communication
# STM32 Interrupt-Safe Circular Buffer
A lightweight, ISR-safe circular (ring) buffer implementation in C, designed for embedded systems running on ARM Cortex-M microcontrollers (specifically STM32).
## Purpose
In embedded systems, handling asynchronous hardware events like UART byte reception requires efficient memory management. This project demonstrates how to safely decouple the hardware Interrupt Service Routine (ISR) from the main application loop using a non-blocking circular buffer.
## Key Features
- **ISR-Safe:** Utilizes volatile keywords for head/tail indices to prevent compiler optimization bugs during context switches.
- **Lock-Free (Single Producer/Single Consumer):** Designed so that the interrupt only modifies the head index, while the main loop only modifies the tail index, eliminating the need for complex mutexes.
- **O(1) Complexity:** Constant time insertion and extraction.

## Usage
Simply include ring_buffer.h and initialize the struct. Push data inside your hardware event handler (e.g., USART_IRQHandler) and pop data in your while(1) loop.

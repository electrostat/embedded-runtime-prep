# embedded-runtime-prep

This repository contains a collection of small, self-contained pure-software embedded modules developed during Summer 2026. Each module is isolated, testable, and designed to be integrated into the larger `embedded-runtime` framework later.

## Modules

- **[Scheduler](ca://s?q=Start_the_scheduler_module)** — Cooperative task scheduler with tick handling and drift correction.
- **[Event Queue](ca://s?q=Implement_an_event_queue_in_C)** — Circular buffer + event dispatcher.
- **[Mock HAL](ca://s?q=Design_a_HAL_for_embedded_C)** — Hardware abstraction interfaces with mock implementations.
- **[UART Simulator](ca://s?q=Build_a_UART_protocol_simulator)** — Framing, CRC, parser, and simulated RX/TX.
- **[Unit Test Harness](ca://s?q=Build_an_embedded_unit_test_framework)** — Minimal test runner with mocks and fixtures.

Each module lives in its own directory with its own README and tests.

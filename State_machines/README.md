# State machines
## Summary
Hi everyone! Here you'll find state machine templates that use different approaches:
- The classical approach of using conditionals inside the main (or infinite loop for embedded systems)
- The table driven approach in which you can define a single function that can handle the transitions by passing
  the current state and last event as arguments. Having then a single function call inside the main.
  
The table driven approach has many implementations, i only included one that i created by modifying and comparing patterns that i found in books ("Design Patterns for Embedded Systems in C" and "Making Embedded Systems" for example) and blogs/forums. I will probably add a bunch more if i have the chance of implementing the template in a complex project.
#### Thanks for passing by!

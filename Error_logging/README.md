# Error Logging
## Summary
The idea of this C module is to create an abstraction layer between our code and the error handling that we want to implement. 
As we know, we can mantain the header and change the source file, having then an interface that is coherent across the whole code base. You could:
- Mantaining the header, change the log print from writing to a file, to send an error code through some communication protocol, or to write the log into
an embedded database, etc
- You can implement different source files, compiling it into different objects and using each one of them in different situations.
But as this implementation has an overhead, it may be suitable for debugging purposes only.
#### Thanks for passing by!

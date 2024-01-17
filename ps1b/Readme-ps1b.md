# PS0: Hello SFML

## Contact
Name: Jeongjae Han	
Section: 051
Time to Complete: 8 hours


## Description
Explain what the project does.

The program encrypts the every pixel by left shifting the code 8 times and xor with the color code.
 
### Features
Describe what your major decisions were and why you did things that way.

I tried to preserve the pixel.cpp and tried to implement ps0 codes so I can interact with the pictures. The program did not let me use unsigned bit for the sizes, so I had to put (signed) for every size.

### Issues
What doesn't work.  Be honest.  You might be penalized if you claim something works and it doesn't.

When it encrypts and decrypts there is the data loss as you can see on the screenshot that I saved in the folder, but it does its job.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

I made the binary bit string by adding the characters of the string up and %2 and /2 the integer. I implemented it to the header file then, I can test if the program the codes are running properly.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

stackoverflow
cplusplus.com
ps0
youtube.com

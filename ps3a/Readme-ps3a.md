# PS3a: N-Body Simulation

## Contact
Name: Jeongjae Han (Jason)
Section: 051
Time to Complete: 10 hours


## Description
Explain what the project does.

This program reads the text file and takes the informations in it and register them into the program and run.

### Features
Describe what your major decisions were and why you did things that way.

I used vector because I used vector for the previous program, so it was easier than other containers to declare the planets. I drew the planets with iterator since I used vector, so it was easy to draw.
.gch files get produced when I compile, but I put the code in Makefile that it cleans it. 

### Memory
Describe how you managed the lifetimes of your objects, including if you used smart pointers.

I just learned about smart pointers today, so I did not use it because I thought it is going to take longer to finish this project. I will try to use it for ps3b by modifying ps3a codes.
I could build this program by using normal pointers.
For memory, I made destructor to delete the datas that the classes are storing.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

when I compile the codes, it shows error with hpp files. It said it has problem with #pragma once, but if I compile it again, it compiles fine.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

I put the background picture. It is my cat and her name is Layla, so I declared all the sf::image, texture, and sprite as layla.


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

c++.com
stackoverflow
Izzy on discord group

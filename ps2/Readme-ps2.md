# PS0: Hello SFML

## Contact
Name: Jeongjae Han(Jason)
Section: 051
Time to Complete: 10 hours

## Description
Explain what the project does.

This program uses SFML graphic library and recursive function to draw the triangles, I used vector to store small triangles and iteration to draw all the triangles.

### Features
Describe what your major decisions were and why you did things that way.

I used sf::drawable as a parent inheritance since the project prompt told me to. I tried to make it as a tree only with the class by making other triangles as the members, but it was not working well, so I used vector since c++ has the library for it.

I decided to have many member function, so the class can pass it to smaller triangles.

I made the constructor make the triangle because there is sf::ConvexShape variable so it stores how it is shaped, so I do not have to worry about making it in the main function.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I have one issue with cpplint. I am not sure which code I have to run it with. Whenever I run cpplint code that is provided, it says, "FATAL ERROR: No files were specified." However, I tried to run it with the one on the lectrue note which is ```cpplint *.cpp, *.hpp, it shows many error messages and for some of them which I do not understand what it is asking for.. Also, ironically, it does not check cpp files, so I have to run the code just for cpp again. Since the prompt provided the code, I put that code in my Makefile.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

The triangles have different colors. I assigned random color code for each triangle's rgb.


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

Samin Patel
sfml-dev.org
c++.com
stackoverflow
youtube


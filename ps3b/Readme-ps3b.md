# PS3b: N-Body Simulation

## Contact
Name: Jeongjae Han
Section: 011
Time to Complete: 20 hours


## Description
Explain what the project does.

This projects read a text file and register it to the classes and bring the files it needs and display on the window. Also, it calculates the numbers from the text and move the planets. 
I used leapfrog method to get acceleration, velocity and position for each planets. This was not hard because for accelaration I just have to devide force by mass and for velocity and position I have to multiply time.

### Features
Describe what your major decisions were and why you did things that way.

I tried to use the unique pointer, but I could not make it work because push back did not work, so I ended up using shared pointer since push_back worked like a normal vector.
At first, in order to get force, sun is fixed argument and the planets have to be other arugments, then it moved the planets to the right. Therefore, I tried with all the planets and it worked properly.
I made a lot of mutator and accessor function since member variables are private.

### Memory
Describe how you managed the lifetimes of your objects, including if you used smart pointers.

Since I am using the smart pointer it will delete the data itself. Also, I made destructor so classes delete all the stored data.


### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I learend how to use smart pointer and vector as a smart pointer. Also, got familiar with the SFML library more.
It runs as it should.
I tried to play the music and found the code on SFML website, but it does not run it, so I commented it out.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
If you created your own universe file.  Describe it here and explain why it is interesting.

I put the elapsed time at the left top corner with a unit.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

SFML website
stackoverflow
c++.com
lecture slide: physics, smart_ptr

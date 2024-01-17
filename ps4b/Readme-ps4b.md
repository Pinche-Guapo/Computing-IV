# PS4b: StringSound

## Contact
Name: Jeongjae Han
Section: 011
Time to Complete: 16 hours


## Description
Explain what the project does.

This project uses the Karplus-Strong algorithm to simulate the plucking of a guitar, CircularBuffer.hpp that I made for ps4a to store the keys and notes.

### Features
Describe what your major decisions were and why you did things that way.

Instead of switch, I made the program finds and recognizes the input and finds the right note.
For the lambda expression, I tried the template on the lecture slide, but it was not working. Therefore, I googled it and cppreference showed me different ways to use it and found a syntax that works for this.


### Testing
What exceptions did you use?  What tests did you write?  Does your code pass the tests?

I wrote the tests for all the public functions: Constructors, pluck, time, tic, and sample. I constructor to throw invalid_argument exception when the user tries to put invalid argument. Other fuctions passed the test.


### Lambda
What does your lambda expression do?  What function did you pass it to?

I used lambda for Karplus-Strong algorithm. In order to get the return value of tick, I needed to use the average of two items that are stored in CircularBuffer and multiply by decay rate. I used the lambda to get average of two items. I did not use any algorithm functions because it was easier to code by myself.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I learned how to use SFML more with a sound library, and make it as a synthesizer with the Karplus-Strong algorithm. I did not know I could make an instrument with a computer, codes, and an algorithm. 
I faces a lot of troubles such as assigning right keys for the notes, for the test, etc. 
I found out that I should use pointer for CircularBuffer member for StringSound late unfortunately when I was going over the rubric before I turned it in, but I did not have time to change it...
However, the program runs as it should.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
Did you make a new instrument?  What is the instrument and how did you make it?  How does the user choose between the guitar or the new instrument?

No extra credit work.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

cppreference
stackoverflow
youtube
lecture slide

# PS4b: StringSound

## Contact
Name: Jeongjae Han
Section: 011
Time to Complete: 13 hours


## Description
Explain what the project does.

This program takes a string and two integers. one of the integer decides how many characters the map is going to store from the string. Then, interacts with the map to randomly produce a character or a string.

### Features
Describe what your major decisions were and why you did things that way.

I created input17.txt and it has example string that the prompt provided.

I tried to use size_t for index for for-loops because we covered it in during the class.

Also, for iterator, I used auto p instead of ::iterator p and for-each loop because the map was declared as private member of the class, so the compiler was asking for operator functions.

### Testing
What tests did you write?  What exceptions did you use?  Does your code pass the tests?

My test has no error.
I made two tests. My test.cpp file tests all the public functions, and exception, but generate function because I am not sure how to make a test for a generate which generates a random string that I cannot even predict the result.

### Lambda
What does your lambda expression do?  What function did you pass it to?

I could not use lambda expression as parameter for this project, I tried to use it in the kRand. I made a random function by using lambda expression and declaring a variable as auto, but I am not sure if this is working as a parameter.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

The program runs well as it should.

I learned how I should interact with a map. For comp3, there was an assignment that I have to use map, and it helped me to get to know about map, but this project helped me to get used to it. I also refered the assignement for this project.

I had hard time understanding the prompt. I am not sure input17.txt is a file I produce or it is provided. However, I just put the example string in the text file.


### Extra Credit
Anything special you did.  This is required to earn bonus points.
Did you make a new instrument?  What is the instrument and how did you make it?  How does the user choose between the guitar or the new instrument?

No extra credit codes...

### Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

Youtube
Comp3 assignments
stackoverflow
c++reference
how to loop through a map.pdf

### Changes

My program had problem that if I set k other than 2. It was because of the codes that tests freq and kRand because those code run when k is 2 but if it is not 2 it fails. Therefore, I commented it out, then the code runs well when k is not 2.

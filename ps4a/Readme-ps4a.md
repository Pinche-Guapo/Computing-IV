# PS4a: CircularBuffer

## Contact
Name: Jeongjae Han (Jason)
Section: 011
Time to Complete: 9 hours

## Description
Explain what the project does.

This project is to prepare a header file for ps4b.
we have to store a data into the container and use it for later.

### Features
Describe what your major decisions were and why you did things that way.

I used vector to store the datas because I am used to it. I used this for 2 other projects.
For member variables I have 5 because we need vector to store, beg to find out the first vector, end for the last, and si for size of the vector and cap for capacity of the vector.

### Testing
What exceptions did you use?  What tests did you write?  Does your code pass the tests?

I made tests for all the functions I have for headerfile : Constructor, size(), isEmpty(), isFull(), peek(), enqueue(T item), and dequeue().
For exceptions I used invalid_argument and run_time error and the code throws the exceptions properly.

### Complexity
Discuss the time and space complexity of your CircularBuffer.  Do all of the functions require the same amount of time, or do some of them require more then others?

Yes, since I have the index for begin and end, so it is O(1).

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I got used to using template more and for the constructor, I have to declare argument's original datatype to pass it properly. It took a while to find it out.
By this project, I learned how to use the vector as private member variable. I was having hard time putting vector container as private member variable for previous projects.
For the construct argument, due to the type size_t, negative value cannot be passed, so I tried to figure out how to throw an exception, but could not find out anywhere.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
Did you write a lambda expression?  What does it do and what function did you pass it to?

No extra credit since I do not see any algorithm is used for this project.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

Lecture slide: template
stackoverflow
youtube

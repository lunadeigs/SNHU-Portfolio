# CS 210 Project One
##### By: Luna Deighan

### Summarize the project and what problem it was solving.

This project was to create a clock that a user would be able to tweak with their inputs and view the time on. There was a 12 hour clock as well as a 24 hour one and each dealt with incrementing time and catching overflow as to keep the program moving fluidly.

### What did you do particularly well?

I personally think that my error handling was very good on this application. I learned how to use cin.ignore() and cin.clear() to ensure that the data being input was valid and an integer instead of something like a string or double when that was not required. I spent a lot of time on that and it is (at least to the best of my knowledge) impossible to break on input.

### Where could you enhance your code? How would these improvements make your code mroe efficient, secure, and so on?

I think I could implement new features to allow the clock to actively tick forward with time instead of just via user interaction. More features in general for the application could be interesting as right now the program does not do too much besides handle user input validation and work with some other functions.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

I found the input validation to not only be my strongest element, but also the hardest to write. I spent a long time trying to realize why the inputs I was recieving kept crashing my program until realizing I had to flush my cin to allow it to continue. I think some tools I'm adding to my support network is mainly my notebook of quick reference iostream items for c++ so I have access to whatever functions I need quickly and easily.

### What skills from this project will be particularly transferable to other projects or course work?

I believe function creation and maintaining the outputs as well as input validation are going to be helpful not just for projects and course work in this class, but for all of my other courses as they are fundamental building blocks for many different pieces of code out there. I also believe that the class writing skills are extremely helpful as it helped me to learn how private and public elements of an object work and where to incorporate them.

### How did you make this program maintainable, readable, and adaptable

I think the main ways I make this program more readable to the next programmer is by the use of whitespace and seperation of methods and functions by use. I also believe that I relegated a large portion of the heavy lifting of the program specifically to functions, therefore when reading the end main function as a programmer, one can pretty easily determine what is happening and if they have questions dig deeper into each specific function for answers.

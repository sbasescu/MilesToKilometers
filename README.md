Name: Simon Basescu
Email: sbasescu@middlebury.edu
Date: 9/19/18
Collaborators: Will Kelley, Simon Scharf, Ruben Gilbert, Lillie Atkins, Scott Westvold, Campbell Boswel

To compile: gcc sbasescu_hw1.c -o sbasescu_hw1
            ./sbasescu_hw1 int_start int_stop (int_end)

to run: User must enter two or three integer inputs. The program will print out
a table starting at the value of the first input and continuing up to (but not including)
the value of the second input (the third input tells the program how much to increment
each subsequent value in the table after the first input; if no input is given,
it increments each value by one.) Each of the values in the table is printed out
under a header titled "miles", and in the next column, the corresponding
distance in kilometers is printed out (to two decimal places) under the
header titled "kilometers".



Hardening my Program:
The first "if" and "else if" statements catches if there are not enough or too many
arguments provided and tells the user whether they need to add another
argument or take away an argument. If two inputs are provided, the program
sets the step value equal to one, so that the default step is one if the user
only enters two inputs. Otherwise, it sets the step value equal to the entered
user input using strtol. Likewise, the program then sets the start and end values equal
to the user's input. It then checks to see if the values entered were valid inputs
using the strtol function and checking to see if the endpointer is null. If
not null, it means that a non digit char was entered and thus prints out an error
message telling the user that they must enter positive integers as inputs.

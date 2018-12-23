#include <stdio.h>
#include <stdlib.h>
/*
Assignment 1

Name: Simon Basescu
Email: sbasescu@middlebury.edu
Date: 9/19/18
Collaborators: Will, Simon Scharf, Ruben Gilbert, Lillie Atkins, Scott Westvold, Campbell Boswel

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
*/

/*
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
*/

void printtopline(int sm, int sk) {
  printf("+");
  for(int i = 0; i < sm + 2; i++) {
    printf("-");
  }
  printf("+");
  for (int i = 0; i < sk + 2; i++) {
    printf("-");
  }
  printf("+\n");
}

void printheader(int sm, int sk) {
  printtopline(sm, sk);
  printf("| %*s | %*s |\n", sm, "miles", sk, "kilometers");
  printtopline(sm, sk);

}

void converter(int start, int end, int step){

  if (end < 100000) {
    printf("+-------+------------+\n");
    printf("| miles | kilometers |\n");
    printf("+-------+------------+\n");
    for (int i = start; i < end; i += step){
      printf("| %5d | %10.2f |\n", i, i * 1.60934);
    }
    printf("+-------+------------+\n");
  }
  else {  //if end >= 100000
    int largestmile;
    float largestkm;
    int spacesformiles = 0;
    int spacesforkms = 3; //3 extra spaces allocated for the decimal places (plus period)

    if ((start + step) > end) {
       largestmile = start;
       largestkm = largestmile * 1.60934;
    }
    else {
      largestmile = start + end - step;
      largestkm = largestmile * 1.60934;
    }

    int tempmile = largestmile;
    while (tempmile >= 1) {
      tempmile = tempmile / 10;
      spacesformiles++;
    }

    float tempkm = largestkm;
    while (tempkm >= 1) {
      tempkm = tempkm / 10;
      spacesforkms++;
    }
    printheader(spacesformiles, spacesforkms);

    for (int i = start; i < end; i+= step) {
      printf("| %*d | %*.2f |\n", spacesformiles, i, spacesforkms, i * 1.60934);
    //calculate num digits in start
    }
    printtopline(spacesformiles, spacesforkms);
  }
}

int main(int argc, char * argv[]) {
  int x, y, z;

  if (argc < 3) {
    printf("Error: too few arguments provided. Please provide at least two arguments.\n");
  }
  else if (argc > 4) {
    printf("Error: too many arguments provided. Please provide at most three arguments.\n");
  }

  else {
    char * end1;
    char * end2;
    char * end3;
    if (argc == 3) {
      z = 1;
    }
    else {
      z = strtol(argv[3], &end3, 10);
    }
    x = strtol(argv[1], &end1, 10);
    y = strtol(argv[2], &end2, 10);
        if (*end1 == '\0' && *end2 == '\0' && (z == 1 || *end3 == '\0')) {
        converter(x, y, z);
      }
      else {
        printf("Error: please enter positive integers as arguments.\n");
      }
  }
}

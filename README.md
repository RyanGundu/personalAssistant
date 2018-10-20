# personalAssistant

Student Information

Ryan Gundu
rgundu@uoguelph.ca

Program Description

- This program reads provided keywords and respnses and stores it in a binary tree for quick access. It can gradually learn to respond more accurately based on user feedback

Important things to consider

— The file is assumed to contain the keyword then its response directly on the next line
- This submission contains a dictionary file "testFile.txt" that you may use and alter if you wish
- NOTE: do not add any spaces before or after a word when adding a new keyword to the tree, the program will recognize it and store it with the space in the word. 
- Learning rate is a constant of 0.5 for this assignment

Additional Features

- The program is defensive towards invalid input for all prompts

To run the program

- To run the test main run "make" , and then "make runTest" , this runs the 
line "./bin/runTest"

- To run the main run "make" and then "make run" , this will run 
the line "./bin/runMe testFile.txt" which includes the name of the file it reads from

# Sodoku Solver
 
 ## Author
 Jose A Garcia -  12/19/19 Version 1.0
 
 ## Purpose
 The Purpose of this program is to introuduce the topic of Dynamic Progamming.
 This progam will compute the correct output BUT in O(n^2).
 
 ## Learned
 I learned the process of backtracking and how long it takes to compute, EX: i had input
 the "hardest Sodoku puzzle" and I got no answer. At first i stopped the code and looked for potential errors.
 Then i ran the code using a debugger ( Insane amount of steps), until came to the realization that
 every possible input is attempted ( Starting from 0 -> 9). I re-ran my code and after 10 seconds
 i got the correct answer.
 
 ## Future
 Find ways to optimize the program, maybe introducing Parallel programming.
 Create a GUI so the user can understand the process of backtracking.
 
 
 

 
```bash
Input Board:
8 0 0  0 0 0  0 0 0 
0 0 3  6 0 0  0 0 0 
0 7 0  0 9 0  2 0 0 

0 5 0  0 0 7  0 0 0 
0 0 0  0 4 5  7 0 0 
0 0 0  1 0 0  0 3 0 

0 0 1  0 0 0  0 6 8 
0 0 8  5 0 0  0 1 0 
0 9 0  0 0 0  4 0 0 

Solution Found!

OutputBoard:
8 1 2  7 5 3  6 4 9 
9 4 3  6 8 2  1 7 5 
6 7 5  4 9 1  2 8 3 

1 5 4  2 3 7  8 9 6 
3 6 9  8 4 5  7 2 1 
2 8 7  1 6 9  5 3 4 

5 2 1  9 7 4  3 6 8 
4 3 8  5 2 6  9 1 7 
7 9 6  3 1 8  4 5 2 

```


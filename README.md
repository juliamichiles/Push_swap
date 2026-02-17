_This project has been created as part of the 42 curriculum by juliatav_

## Description

The goal of this project is to sort a stack of integers using two stacks (a and b) and the minimum amount of the following operations:

	- sa (swap a): Swap the first 2 elements at the top of stack a.
	- sb (swap b): Swap the first 2 elements at the top of stack b.
	- ss : sa and sb at the same time.
	- pa (push a): Take the first element at the top of b and put it at the top of a.
	- pb (push b): Take the first element at the top of a and put it at the top of b.
	- ra (rotate a): Shift up all elements of stack a by 1.
	- rb (rotate b): Shift up all elements of stack b by 1.
	- rr : ra and rb at the same time.
	- rra (reverse rotate a): Shift down all elements of stack a by 1.
	- rrb (reverse rotate b): Shift down all elements of stack b by 1.
	- rrr : rra and rrb at the same time

This implementation uses a cost-based sorting strategy inspired by the Turk Algorithm. It works by pushing elements from `stack a` to `stack b` until only three elements remain in `stack a`. Those three elements will be sorted in a few operations. After that, each element in `stack b` will be reinserted in `stack a` in its correct position by choosing the option with the lowest calculated cost.
						
---
## Instructions

- To compile the program:
```
make
```
- To run the program with a list of integers:
```
./push_swap -2 100 42 10 8
```

---
## Resources

This project was done using the following references:

#### Big-O & Complexity Analysis
- Analysis of Algorithms (Big-O) — GeeksforGeeks  
  https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/

- Time Complexities of All Sorting Algorithms — GeeksforGeeks  
  https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/

#### Turk Algorithm & Push_swap Strategy


- Push_swap Turk Algorithm Explained in 6 Steps  
  https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

- Push_swap Overview (Medium)  
  https://medium.com/@ayogun/push-swap-c1f5d2d41e97

- Push_swap — Least Amount of Moves with Two Stacks  
  https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

#### Video Resource
- Push_swap Explanation (YouTube)  
  https://www.youtube.com/watch?v=wRvipSG4Mmk

**AI usage:** AI was used to clarify algorithmic concepts, review edge cases, assist in writing testing scripts, and help refine explanations in the README. All algorithm implementation, logic design, debugging, and optimization were done manually.

# push_swap
42 / 21 push_swap project
## The goal:  
Create two programms "checker" and "push_swap". "Push_swap" must read the stack from arguments, sort it during allowed commands and display list of commands followed by '\n'. "Checker" also must read the stack from arguments and then read and execute the commands from standard output. If the stack is sorted after execution, "checker" prints "OK", otherwise "KO".  
"Checker" and "push_swap" work together:  
`ARG="0 67 12 81 17"; ./push_swap $ARG | ./checker $ARG`. 
## Allowed commands:
-_sa_ : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).  
-_sb_ : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).  
-_ss_ : sa and sb at the same time.  
-_pa_ : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
-_pb_ : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
-_ra_ : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.  
-_rb_ : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.  
-_rr_ : ra and rb at the same time.  
-_rra_ : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.  
-_rrb_ : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.  
-_rrr_ : rra and rrb at the same time.  

## What I did:
After reading I calculate the median of sorted A-stack. To sort A-stack I used timsort-algo. Then I pushed elements, which are less then median, in stack B and repeat this steps untill there is 2 elems in A or A is slice. Slice is stack needed only ra/rra to be sorted.  
Now I have A-slice (if there are 2 unsorted elems in A, simply do sa) and B with some values. Now I should push all elems in A back, but first I should push any element of B to the top of B, find the right place in A during ra/rra and finaly calculate count of operations for each element in B.  
So I push in A such element of B, which has the least count of operations to be inserted in A, untill B is empty.  
I sort 500 values by ±4300 operations.

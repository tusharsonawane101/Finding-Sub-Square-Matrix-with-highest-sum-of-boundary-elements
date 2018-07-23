# Finding-Sub-Square-Matrix-with-highest-sum-of-boundary-elements

This Repo contains my solution to the coding challenge given below.
This solution uses a Brute Force Approach. 
To get the solution in optimal time, please refer Kadane's Algorithm.

Coding Challenge : 

Consider a 2D matrix of numbers from 0 to 9 with variable width and height. Find the square submatrix with the highest sum of boundary elements.

Input :	

Input width and height of matrix: 6 8

Input Matrix with numbers from 0 to 9:

	2 0 6 1 2 5	
	1 0 5 0 1 3	
	3 0 1 2 4 1	
	0 1 3 1 1 9	
	4 1 0 8 5 2	
	0 1 0 1 2 3
	6 5 3 1 0 2
	0 0 1 6 0 4	
	
Input maximum width of square submatrix (for square submatrix height and width are same) : 3

Output : 

As sum of highlighted submatrix is maximum (calcute sum of boundary elements only 2,4,1,9,2,5,8,1),

	2 0 6 1 2 5	
	1 0 5 0 1 3	
	3 0 1 2 4 1	
	0 1 3 1 1 9	
	4 1 0 8 5 2	
	0 1 0 1 2 3
	6 5 3 1 0 2
	0 0 1 6 0 4	
 
Output should be :

	 2 4 1	
	 1 1 9	
	 8 5 2

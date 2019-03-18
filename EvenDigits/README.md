Problem

Supervin has a unique calculator. This calculator only has a display, a plus button, and a minus button. Currently, the integer N is displayed on the calculator display.

Pressing the plus button increases the current number displayed on the calculator display by 1. Similarly, pressing the minus button decreases the current number displayed on the calculator display by 1. The calculator does not display any leading zeros. For example, if 100 is displayed on the calculator display, pressing the minus button once will cause the calculator to display 99.

Supervin does not like odd digits, because he thinks they are "odd". Therefore, he wants to display an integer with only even digits in its decimal representation, using only the calculator buttons. Since the calculator is a bit old and the buttons are hard to press, he wants to use a minimal number of button presses.

Please help Supervin to determine the minimum number of button presses to make the calculator display an integer with no odd digits.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line containing an integer N: the integer initially displayed on Supervin's calculator.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of button presses, as described above.
Limits

1 ≤ T ≤ 100.
Time limit: 20 seconds per test set.
Memory limit: 1GB.
Small dataset (Test set 1 - Visible)

1 ≤ N ≤ 105.
Large dataset (Test set 2 - Hidden)

1 ≤ N ≤ 1016.
Sample

Input
4
42
11
1
2018
	
Output
Case #1: 0
Case #2: 3
Case #3: 1
Case #4: 2

  

In Sample Case #1, the integer initially displayed on the calculator has no odd digits, so no button presses are needed.

In Sample Case #2, pressing the minus button three times will cause the calculator to display 8. There is no way to satisfy the requirements with fewer than three button presses.

In Sample Case #3, either pressing the minus button once (causing the calculator to display 0) or pressing the plus button once will cause the calculator to display an integer without an odd digit.

In Sample Case #4, pressing the plus button twice will cause the calculator to display 2020. There is no way to satisfy the requirements with fewer than two button presses. 


Analysis

Even Digits: Analysis

To make our discussion easier, let us define a beautiful integer as an integer which has only even digits in its decimal representation.
Small dataset

One useful observation for solving this problem is that we either only want to press the minus button or only want to press the plus button. It is useless to have both types in the same sequence, since they cancel each other out.

Therefore, we want to either keep pressing the minus button, or keep pressing the plus button, until we have a beautiful integer. Let M be the minimum number of minus button presses before reaching a beautiful integer, and let P be the minimum number of plus button presses before reaching a beautiful integer. Then the answer is the smaller of M and P.

Note that for this problem, the answer for an input N is bounded above by N, since we can just press the minus button N times to reach the beautiful integer 0. Therefore, since N ≤ 105, we can solve the Small dataset using complete search.

We can loop over a value i in the range [0, N], and, for each i, check whether N+i or N-i is a beautiful integer. If that is the case, then we break the loop and return i as the answer.
Large dataset

Iterating over the range [0, N] would be too slow for this dataset. Therefore, we need another approach.

To find the value of M, we must find the largest beautiful integer that is still no greater than N. Let us call this integer X. Similarly, to find the value of P, we can find the smallest beautiful integer that is still no smaller than N. Let us call this integer Y.

We can find X by decreasing the first odd digit in N by one and then replacing all digits to the right of that odd digit with the largest even digit (i.e. 8). For example, if N=4436271, then X=4428888. This can create a leading 0, which we can simply drop the leading 0 in that case. If there are no odd digits in N, then N is a beautiful integer, thus X=N.

By constructing X this way, it is guaranteed that there will be no beautiful integer between X and N, since the next beautiful integer after X would be larger than N at the first odd digit. For the example above, the next beautiful integer after X is 4440000, which is larger than N.

Similarly, we can find Y by increasing the first odd digit in N by one and replacing all digits to the right of that odd digit with the smallest even digit (i.e. 0). If there are no odd digits in N, then N is a beautiful integer, thus Y=N. However, when finding Y, we must watch out for some tricky cases. If the first odd digit is 9, then we must replace the digit directly to the left of that odd digit as well with the next even digit. For example, if N=86912, then Y=88000.

Another tricky case is when the digit directly to the left of the first odd digit is 8. In this case, we must replace the digit directly to the left of that 8 digit as well, and keep doing this until we have a non-8 digit. For example, if N=6488962, then Y=6600000. Finally, if all digits to the left continue to be 8 until we reach the leftmost digit, or if the first digit of N is a 9, then we must add the smallest non-zero even digit (i.e. 2) as a new digit on the left. For example, if N=88892 or N=91112, then Y=200000.

Once we know X and Y, we also know M and P, and we can take the smallest of those values, just as we did before.


Problem

Scott has an ant farm containing N ants. Each ant has a certain length and weight.

Today, as a challenge for the ants, Scott has placed some food at the top of the ant farm. The ants will try to reach it by arranging themselves into a vertical stack, with each ant in the stack directly holding the next on its back. In this way, each ant bears the weight of all ants above it. Scott's ants are very strong for their size and are able to carry up to 6 times their own weight. For example, an ant that weights 8 milligrams can carry two other ants weighing 24 milligrams each! Each ant also has a body length; the exact lengths are not important, except that they are all different.

    The stack must be linear. Each ant except for the top ant must be directly below exactly one ant, and each ant except for the bottom ant must be directly above exactly one ant.
    The lengths of the ants in the stack must be strictly decreasing from the bottom to the top of the stack; this ensures that each new ant that joins the stack will be able to climb up to the top.
    For each ant, the sum of the weights of all the ants above it in the stack must be no more than 6 times the weight of that ant.

What is the maximum number of these ants that can form such a stack?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line with an integer N: the number of ants in the colony. Then, a second line follows containing N integers W1, W2, ..., WN, where Wi is the weight in milligrams of the i-th ant. The ants are listed in strictly increasing order of length. Notice that no actual length values are given; only the order is important.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of the given ants that can form a stack that obeys the rules above.
Limits

7 ≤ T ≤ 100.
Time limit: 15 seconds per test set.
Memory limit: 1GB.
Test set 1 (Visible)

For exactly 6 cases, N = 100; for the other T - 6 cases, 2 ≤ N ≤ 50.
1 ≤ Wi ≤ 1000, for all i.
Test set 2 (Hidden)

For exactly 6 cases, N = 105; for the other T - 6 cases, 2 ≤ N ≤ 500.
1 ≤ Wi ≤ 109, for all i.
Sample

Input

3
2
9 1
3
8 4 100
9
10 10 10 10 10 10 10 10 100

Output	

Case #1: 1
Case #2: 3
Case #3: 8

In Sample Case #1, there are two ants. The first weighs 9 mg; the second weighs 1 mg, and is longer than the first ant. The first ant is strong enough to hold the second ant (since it can hold up to 9 × 6 mg), but it cannot, because the second ant is longer. The second ant is not strong enough to hold the first ant (since it can only hold up to 1 × 6 mg, which is less than 9 mg). So it is only possible to make a "stack" of one of the two ants.

In Sample Case #2, it is possible for all three ants to form a stack, with the third holding up the second, which holds up the first.

In Sample Case #3, the optimal solution has the ninth ant on the bottom, and then seven of the other ants above it. 

Analysis

Test set 1

To solve this test set, we can use dynamic programming (DP). We define a function f(x, y) as the maximum number of ants that can form a stack (following the stack requirements given in the problem statement), in which we only consider ants from the first ant to the x-th ant, inclusive, and the sum of the ants' weight is not more than y.

We can compute the value of f(x, y) by considering two cases:

    Suppose we don't put the x-th ant on the bottom of the stack. Then we can ignore the x-th ant, and so the value of f(x, y) from this case becomes f(x - 1, y).
    Suppose we put the x-th ant on the bottom of the stack. Then we need to maximize the number of ants to be put on top of the x-th ant, which is the value of f(x - 1, min(6Wx, y - Wx)). Counting the x-th ant as well, the value of f(x, y) from this case becomes f(x - 1, min(6Wx, y - Wx)) + 1. Note that we only consider this case if y ≥ Wx. 

Between the two cases (or only one case if y < Wx), we take the larger value as the value of f(x, y).

The answer for the problem is the value of f(N, ∞). Since there are O(N) possible values for x, O(max(W)) possible values for y, and O(1) iterations for each computation of f(x, y), this solution runs in O(N × max(W)) time.

There is also another solution involving another DP formulation f', where f'(x, y) only considers ants from the x-th ant to the N-th ant (instead of the first ant to the x-th ant).
Test set 2

To solve this test set, we need to find the value of K, the maximum possible answer to the problem. To have a stack with as many ants as possible, where the upper-bound of the ants' weight is fixed by a constant (i.e. 109 in this problem), we greedily put the lightest ant possible on the bottom of the stack. In other words, a stack with as many ants as possible will have ants with weights something like (1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 6, ...). We stop as soon as we need to add an ant with a weight more than 109. By creating a simple script, we can determine that the value of K is 139, much smaller than N.

Therefore, we can solve this test set with another DP formula. We define a function g(x, y) as the minimum sum of the weights of the ants that can form a stack of y ants where only the ants from the first ant to the x-th ant are considered, or ∞ if no such stack exists.

Again, we can compute the value of g(x, y) by considering two cases:

    Suppose we don't put the x-th ant on the bottom of the stack. Then we can ignore the x-th ant, and so the value of g(x, y) from this case becomes g(x - 1, y).
    Suppose we want to put the x-th ant on the bottom of the stack. We first need to check whether this is possible. We can compute the value of g(x - 1, y - 1), the minimum sum of the weights of the ants that can form a stack of y - 1 ants where only the ants from the first ant to the (x - 1)-th ant are considered. If g(x - 1, y - 1) ≤ 6Wx, then it is possible to put the x-th ant on the bottom of the stack. The value of g(x, y) from this case becomes g(x - 1, y - 1) + Wx. 

Between the two cases (or only one case if g(x - 1, y - 1) > 6Wx), we take the smaller value as the value of g(x, y).

The answer for the problem is the largest possible value S where g(N, S) < ∞. Since there are O(N) possible values for x, O(K) possible values for y, and O(1) iterations for each computation of g(x, y), this solution runs in O(NK) time.

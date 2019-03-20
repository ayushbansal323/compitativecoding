Problem

You are participating in the Grand Kickstart Lucky Dip with many fantastic and amazing prizes (and some not so good ones)!

In this Lucky Dip, there is a bag with N items. The i-th item in the bag has value Vi. You will put your hand into the bag and draw one item at random; all items in the bag have an equal probability of being chosen. The organizers want contestants to feel that they have some element of choice, so after you draw an item, you can either keep it, or "redip" by returning it to the bag and drawing again. (Note that the returned item is now just as likely to be chosen as any of the other items in the bag.) You may only redip a maximum of K times. If you use K redips, you must keep the item that you draw on your (K + 1)-th draw.

If you play optimally to maximize the value of the item you will end the game with, what is the expected value of that item?
Input

The input starts with one line containing one integer T: the number of test cases. T test cases follow.

Each test case consists of two lines. The first line consists of two integers N and K: the number of items in the bag, and the maximum number of times you may redip. The second line consists of N integers Vi, each representing the value of the i-th item.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the expected value described above. Your answer will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.
Limits
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Vi ≤ 109.
1 ≤ N ≤ 2 * 104.
Small dataset (Test set 1 - Visible)
Time limit: 20 seconds.
0 ≤ K ≤ 1.
Large dataset (Test set 2 - Hidden)
Time limit: 60 seconds.
0 ≤ K ≤ 5 * 104.
Sample

Input
  	
Output
 

5
4 0
1 2 3 4
3 1
1 10 1
3 15
80000 80000 80000
1 1
10
5 3
16 11 7 4 1

  

	

Case #1: 2.500000
Case #2: 6.000000
Case #3: 80000.000000
Case #4: 10.000000
Case #5: 12.358400


  

In Sample Case #1, you cannot redip, so the expected value is just the mean of the items in the bag which is (1 + 2 + 3 + 4) / 4 = 2.5.

In Sample Case #2, the best strategy is to keep the item of value 10 if you get it, and redip otherwise. The chance of getting that item (on either the first or second draw) is 1 - (2/3)2 = 5/9, hence the expected value is (5/9 * 10) + (4/9 * 1) = 6.

In Sample Case #3, since all the items have the same value, it does not matter how many times you redip and hence the expected value is 80000.

Note that cases #3 and #5 would not appear in the Small dataset. 



Analysis

Lucky Dip: Analysis
Given the array of N integers, define E[k] as the optimal expected value of the item drawn given k redips.
Small dataset

There are two cases to consider for the small dataset: K = 0 and K = 1.

When K = 0, we must accept the first item which we draw. Since the chance of obtaining each item is the same, the expected value is the average value of all the items in the bag.

When K = 1, we note that if we redip, the expected value that we draw is going to be the same as the case when K = 0. Thus, the best strategy is to keep the item if the value of the item is greater than the average value of the items in the bag, or return the item otherwise.

Thus, we have the following equations to compute the values for E[0] and E[1]:

  E[0] = Σ Vi / N
  E[1] = Σ max(Vi, E[0]) / N

The values for E[0] and E[1] can be computed in O(N) time.
Large dataset

When K > 1, we may proceed with a similar recursion as in the case when K = 1. Given k redips, we should keep the item if the value of the item is greater than the expected value for k-1 redips, and we should return the item otherwise. This gives rise to the following recursion:

  E[k] = Σ max(Vi, E[k-1]) / N

Computing E[K] using the above approach requires us to compute E[0], E[1], ..., E[K - 1], each of which requires O(N) time. Thus, the total runtime amounts to O(NK), which is fast enough to pass the large dataset. However, it is possible to derive an even faster solution.

Suppose we have already computed the value for E[k - 1]. If our array of Vis is sorted, we can use a binary search to quickly determine the quantity of items which have value less than or equal to E[k - 1]. Let us denote this quantity with xk. Note that the probability of drawing one of these xk items is xk / N. This corresponds to the case when we return the item and redip.

On the other hand, there is an equal likelihood for drawing each of the remaining N - xk items. This gives us the following equation for E[k]:

  E[k] = xk * E[k - 1] / N + Σi>xk Vi / N

For fast computation, we precompute by sorting the array of Vis in increasing order, and computing the suffix sums for the array. We will then compute E[0], E[1], ..., E[K] accordingly, in which each step takes O(log N) time. The total runtime is then O(N + N log N + K log N) = O((N + K) log N).

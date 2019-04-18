Problem

These days, robots can drive cars, but can they throw a good party? The Code Jam team's research into this topic is still at an early stage. We just deployed R robot shoppers to our local supermarket to buy party supplies for our World Finals in Toronto, but their first-order model of a Canadian party was very simple: they just bought B "bits" (a bit being a small donut-like treat found in the area). We will work on improving their AI later, but for now, we want to help them purchase all of those bits as quickly as possible.

The supermarket has C cashiers who can scan customers' purchases. The i-th cashier will:

    accept a maximum of Mi items per customer
    take Si seconds to scan each item
    spend a further Pi seconds handling payment and packaging up the bits.

That is, a customer who brings N bits to the i-th cashier (where N must be less than or equal to Mi) will spend a total of Si × N + Pi seconds interacting with that cashier.

Before the robots interact with any cashiers, you will distribute the bits among the robots however you want. (Bits must remain intact; you cannot break them up into fractional pieces!) Any robot that gets no bits will not get to interact with a cashier, and will go away disappointed.

Then, for each robot with at least one bit, you will choose a different single cashier. (Two robots cannot use the same cashier, and a robot cannot use more than one cashier.) The robots all start interacting with their cashiers at time 0. Note that once a robot finishes interacting with its cashier, it cannot be given more bits and cannot interact with other cashiers.

If you help the robots make optimal choices, what is the earliest time at which all of the robots can finish interacting with their cashiers?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line with three integers R, B, and C: the numbers of robot shoppers, bits, and cashiers. Then, there are C more lines. The i-th of these represents the i-th cashier, and it has three integers Mi, Si, and Pi: the maximum number of bits, scan time per bit (in seconds), and payment/packaging time (in seconds) for that cashier, as described above.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the earliest time (in seconds) at which all robots can finish interacting with their cashiers.
Limits

1 ≤ T ≤ 100.
1 ≤ Mi ≤ 109, for all i.
1 ≤ Si ≤ 109, for all i.
1 ≤ Pi ≤ 109, for all i.
The sum of the R largest values of Mi ≥ B. (It is possible for at least one subset of R cashiers to handle all of the bits.)
Time limit: 15 seconds per test set.
Memory limit: 1GB.
Test set 1 (Visible)

1 ≤ R ≤ C ≤ 5.
1 ≤ B ≤ 20.
Test set 2 (Hidden)

1 ≤ R ≤ C ≤ 1000.
1 ≤ B ≤ 109.
Sample

Input

3
2 2 2
1 2 3
1 1 2
2 2 2
1 2 3
2 1 2
3 4 5
2 3 3
2 1 5
2 4 2
2 2 4
2 5 1

Output	

Case #1: 5
Case #2: 4
Case #3: 7

In Sample Case #1, there are two robots, two bits, and two cashiers, and each cashier can only handle one item. So, you must give one bit to each robot. Cashier 1 takes 5 seconds, and Cashier 2 takes 3 seconds, so the time required is 5 seconds.

Sample Case #2 is similar to the previous case, except that now Cashier 2 can handle up to 2 items. So, it is best to give all the bits to one robot and have that robot use Cashier 2. This takes 1 second per item plus 2 seconds = 4 seconds.

In Sample Case #3, the optimal strategy is to send one robot with 2 bits to cashier 2, and two robots with 1 bit each to any of the other cashiers. 

Analysis

Test set 1

We might consider enumerating all the ways of assigning bits to cashiers, but with 20 bits and 5 cashiers, there could be as many as 520 ways — too many to check! We need to take advantage of the fact that the bits are interchangeable, and instead find all the ways to partition B bits among R of the C cashiers (since we will only be able to use as many cashiers as we have robots). Then, we can compute how much time each of those ways takes, and pick the minimum of those values.

We can calculate the number of ways to partition 20 bits among 5 robots using this method. It turns out there are only (24 choose 4) = 10,626 ways to check. If we have fewer robots than cashiers, then we need to introduce another multiplicative factor of (C choose R), but this cannot be larger than 10 in test set 1. Each check takes O(R) time, which is very small given that R is at most 5. So, test set 1 should be solvable well within the 15 second time limit, regardless of your language choice.
Test set 2

To solve this test set, we need to be able to answer the following question: Given a time limit T, is there a possible assignment of bits such that all the robots can finish interacting with their cashiers in no more than T seconds? Let f(T) be the answer to this question.

How can we find f(T)? The maximum number of bits that the i-th cashier can process in not more than T seconds is max(0, min(Mi, floor((T - Pi) / Si))). Let us call this value Capacityi.

Then, we want to know whether a total of B bits can be assigned to R robots, and each of those robot to a cashier, such that the number of bits processed by the i-th cashier is not more than Capacityi. To do this, we can greedily sort the Capacity values into nonincreasing order, and then assign the R robots to the first R cashiers. f(T) is true if and only if the total number of bits that can be processed by the first R cashiers is at least B. Therefore, we can compute the value of f(T) for any T in O(C log(C)) time (which is the time it takes to sort the Capacity values). (Aside: We can even avoid the sort, and instead partition in O(C) time, by using introselect, for example.)

Since we want to minimize the time taken for all robots to interact with their cashiers, we want to find the minimum possible value of T such that f(T) is true. That value of T will also satisfy the following:

    f(x) is false for all x < T.
    f(x) is true for all x ≥ T.

Therefore, we can find the value of T using binary search. Since the maximum answer will not be more than O(max(S) × B + max(P)), this solution will run in O(C log(C) log(max(S) × B + max(P))) time.
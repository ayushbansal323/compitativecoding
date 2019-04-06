Problem

An alien robot is threatening the universe, using a beam that will destroy all algorithms knowledge. We have to stop it!

Fortunately, we understand how the robot works. It starts off with a beam with a strength of 1, and it will run a program that is a series of instructions, which will be executed one at a time, in left to right order. Each instruction is of one of the following two types:

    C (for "charge"): Double the beam's strength.
    S (for "shoot"): Shoot the beam, doing damage equal to the beam's current strength.

For example, if the robot's program is SCCSSC, the robot will do the following when the program runs:

    Shoot the beam, doing 1 damage.
    Charge the beam, doubling the beam's strength to 2.
    Charge the beam, doubling the beam's strength to 4.
    Shoot the beam, doing 4 damage.
    Shoot the beam, doing 4 damage.
    Charge the beam, increasing the beam's strength to 8.

In that case, the program would do a total of 9 damage.

The universe's top algorithmists have developed a shield that can withstand a maximum total of D damage. But the robot's current program might do more damage than that when it runs.

The President of the Universe has volunteered to fly into space to hack the robot's program before the robot runs it. The only way the President can hack (without the robot noticing) is by swapping two adjacent instructions. For example, the President could hack the above program once by swapping the third and fourth instructions to make it SCSCSC. This would reduce the total damage to 7. Then, for example, the president could hack the program again to make it SCSSCC, reducing the damage to 5, and so on.

To prevent the robot from getting too suspicious, the President does not want to hack too many times. What is this smallest possible number of hacks which will ensure that the program does no more than D total damage, if it is possible to do so?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line containing an integer D and a string P: the maximum total damage our shield can withstand, and the robot's program.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is either the minimum number of hacks needed to accomplish the goal, or IMPOSSIBLE if it is not possible.
Limits

1 ≤ T ≤ 100.
1 ≤ D ≤ 109.
2 ≤ length of P ≤ 30.
Every character in P is either C or S.
Time limit: 20 seconds per test set.
Memory limit: 1GB.
Test set 1 (Visible)

The robot's program contains either zero or one C characters.
Test set 2 (Hidden)

No additional restrictions to the Limits section.
Sample

Input

 

6
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS

  	
Output	

Case #1: 1
Case #2: 0
Case #3: IMPOSSIBLE
Case #4: 2
Case #5: 0
Case #6: 5

Note that the last three sample cases would not appear in test set 1.

In Sample Case #1, the President can swap the two instructions to reduce the total damage to 1, which the shield can withstand.

In Sample Case #2, the President does not need to hack the program at all, since the shield can already withstand the 2 total damage it will cause.

In Sample Case #3, the program will do more damage than the shield can withstand, and hacking will do nothing to change this. The universe is doomed.

Sample Case #4 uses the program described in the problem statement. The statement demonstrates one way to reduce the total damage to 5 using two hacks. It is not possible to reduce the damage to 6 or less by using only one hack; remember that the President can only swap adjacent instructions.

In Sample Case #5, the robot will never shoot, and so it will never do any damage. No hacking is required.

In Sample Case #6, five hacks are required. Notice that even if two hacks swap the instructions at the same two positions, they still count as separate hacks. 

Analysis

Test set 1

Since there is at most one C instruction in this test set, we can solve the two cases independently.

If there is no C instruction in P, then none of our swaps will have any effect, so all we can do is check whether the damage of the beam exceeds D.

If there is one C instruction in P, then we can try every possible position for the C instruction in the program. Assuming that there is at least one position for the C instruction that causes the total damage not to exceed D, we can choose the scenario that requires the fewest swaps; the number of required swaps for a scenario is equal to the distance between the original and final positions of the C instruction.
Test set 2

To solve test set 2, we will first derive a formula to compute the total damage based on the positions of the C and S instructions in P. Let NC and NS be the number of C and S instructions in P, respectively. Let Ci be the number of S instructions to the right of the i-th C instruction, where i uses 1-based indexing.

Note that the i-th C instruction will increase the damage of the subsequent beams by 2i-1. For example, in the input program CSSCSSCSS, initially, all of the S instructions will inflict a damage of 1. Consider the damage dealt by the last S instruction. Since the robot has been charged twice, the damage output by the last instruction will be 4. Alternatively, we see that the damage, 4 = 1 (initial damage) + 20 (damage caused by the first C) + 21 (damage caused by the second C). By breaking down the damage by each S instruction in the same manner, the total damage output, D, of the input program is given by:

  D = NS + C1 × 1 + C2 × 2 + ... + CNC × 2NC - 1 .

Next, we investigate how each swap affects the amount of damage. A swap on adjacent characters which are the same will not affect the equation. When we swap the i-th C instruction with a S instruction to its right, the value of Ci will decrease by 1 since now there is one less S than before. On the other hand, swapping the i-th C instruction with an S instruction on its left will increase the value of Ci by 1. Note that in either case, we will only modify the value of Ci, and the other C values will remain the same. This suggests that we should only ever swap adjacent instructions of the form CS.

Therefore, executing M swaps is equivalent to reducing the values of Cis such that the total amount of reduction across all Cis is M. We want the total damage (according to the above equation) to be minimized. Clearly, we should reduce the values of Ci that contribute to the largest damage output, while making sure that each of the Cis is nonnegative.

Intuitively, all of this math boils down to a very simple algorithm! As long as there is an instance of CS in the current program, we always swap the latest (rightmost) instance. After each swap, we can recompute the damage and check whether it is still more than D. If it is not, then we can terminate the program. If we ever run out of instances of CS to swap, but the damage that the program will cause is still more than D, then the universe is doomed.


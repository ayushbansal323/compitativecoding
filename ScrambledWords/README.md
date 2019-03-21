Problem

Professor Scrmable noticed spelling mistakes in a research paper she was reviewing, but she had no difficulty in reading or understanding the words. Upon doing some research, she found an interesting article as described below:

According to a study at an English University, it doesn't matter in what order the letters in a word are, the only important thing is that the first and last letter be at the correct place. The rest can be a total mess and you can still read it without a problem. This is because the human mind does not read every letter by itself but the word as a whole.

Or rather ...

Aoccdrnig to a study at an Elingsh uinervtisy, it deosn't mttaer in waht oredr the ltteers in a wrod are, the olny iprmoetnt tihng is taht the frist and lsat ltteer be at the corecrt pclae. The rset can be a toatl mses and you can sitll raed it wouthit a porbelm. Tihs is bcuseae the huamn mnid deos not raed ervey lteter by istlef, but the wrod as a wlohe.

Professor Scrmable wants to explore this concept further and starts compiling different sentences containing similarly scrambled words to send to a popular publication. Unfortunately, the space key on the professor's keyboard is not working, so she has produced one long string of characters. She has asked you to determine how many of the words in her dictionary appear (at least once) as substrings in the long string of characters, either in their original or scrambled forms. (A scrambled form consists of the same set of letters with the first and last letters in the same places, and the others in any order.)

Note that a dictionary word can appear multiple times in the string (though it should be counted only once since we only need to know whether it shows up at least once). For example, if we had the word this in the dictionary, the possible valid words which would be counted are this (original version) and tihs (scrambled version), whereas tsih, siht and other variations are not valid since they do not start with t and end with s. Also, tis, tiss, and thiss are not scrambled forms, because they are not reorderings of the original set of letters.

Since the professor is extremely busy, she gives this task to you, her favorite and most trusted research assistant. Given a dictionary, can you count the number of words in the dictionary that appear as a substring in the professor's string at least once, in either their scrambled or original forms.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each testcase contains three lines. The first line contains an integer L. The second line contains a list of L words made of lowercase English letters; these make up the dictionary. The third line contains two lowercase English letters S1 and S2, and five integers N, A, B, C and D. S1 and S2 are the first two characters of the professor's string S, N is the length of S, and the other four integers are parameters that you should use to generate the characters of S, as follows:

First we define ord(c) as the decimal value of a character c and char(n) as the character value of a decimal n. For example, ord('a') = 97 and char(97) = 'a'. You can refer to ASCII table for other conversions.

Now, define x1 = ord(S1), x2 = ord(S2). Then, use the recurrence below to generate xi for i = 3 to N:

    xi = ( A * xi-1 + B * xi-2 + C ) modulo D.

We define Si = char(97 + ( xi modulo 26 )), for all i = 3 to N.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of words from the dictionary that appear (in their original or scrambled forms, as defined above) as substrings of the given string.
Limits

1 ≤ T ≤ 20.
Memory limit: 1 GB.
No two words in the dictionary are the same.
Each word in the dictionary is between 2 and 105 letters long, inclusive.
The sum of lengths of all words in the dictionary does not exceed 105.
S1 and S2 are lowercase English letters.
0 ≤ A ≤ 109.
0 ≤ B ≤ 109.
0 ≤ C ≤ 109.
1 ≤ D ≤ 109.
Small dataset (Test set 1 - Visible)

Time limit: 20 seconds.
1 ≤ L ≤ 1000.
2 ≤ N ≤ 1000.
Large dataset (Test set 2 - Hidden)

Time limit: 150 seconds.
1 ≤ L ≤ 20000.
2 ≤ N ≤ 106.
Sample

Input
  	

 

1
5
axpaj apxaj dnrbt pjxdn abd
a a 50 1 1 1 30

Output  
Case #1: 4

  

In Sample Case #1, using the generation method, the generated string S is aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. Scrambled or original occurences of dictionary words are highlighted as follows:

    axpaj occurs in its scrambled form as aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt.
    apxaj occurs in its scrambled form as aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. Note that even though apxaj is the scrambled form of another dictionary word axpaj, both should be counted.
    dnrbt occurs twice in its original form as aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt, though it should be counted only once.
    pjxdn occurs in its scrambled form as aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. Note this occurence overlaps with occurence of another dictionary word, but still they're counted independently.
    abd doesn't occur at all.

Note: We do not recommend using interpreted/slower languages for the Large dataset of this problem. 

Scrambled Words: Analysis

Let us first discuss how to check if two words are equivalent. A word is equivalent to another if their corresponding starting and ending letters are same and the sets of letters in between are either the same or permutations of each other. To check if two words are equivalent, after verifying that their starting and ending letters are equal, we populate a frequency array of the characters in each string and check if the two frequency arrays are same or not. Since the strings in this problem consist of only lowercase English letters, the array only needs to hold 26 integers (the counts of those letters' frequencies), and we can compare two such arrays very quickly. arrays will be very fast. An example of this would be the frequency away [1, 1, 2, 0, ... 0] for the string bcca.
Small dataset

Given the relatively small caps on L and N in the Small dataset, one solution that may come to mind is as follows: For each word in the dictionary, iterate over the Professor's text and check for substring match at each position in the text using the method of frequency arrays described above. But we should think carefully about how we check substrings against each other. Suppose that the length of our dictionary word is W. If we do it naively, for each position in the text (assume the length of the dict word is W), we check the substring of length W starting at that position by iterating over it, which is suboptimal. We should maintain a running frequency array. Suppose the frequency array is populated for the substring starting at position i. When we move our substring window one character to the right, we need to decrement the frequency of text[i] and increment the frequency of text[i+l]. This will give us the frequency array of the substring starting at position i+1. These two operations take constant time.

Since we iterate over the whole text for every dictionary word and there are L words and the length of the text is N, the total time complexity of this solution will be O(NL).
Large dataset

The above approach will not work in the large dataset because there are too many words in the dictionary.

The solution for this dataset hinges on the observation that if the total length of the words in the dictionary is bounded by M, the maximum possible number of distinct word lengths is atmost √M. This can be seen as follows. Let X be the bound on the number of distinct lengths; then X*(X+1)/2 ≤ M.

The above solution is now modified by iterating over only those lengths which are present in the dictionary, and for each such length, we perform the same process as above, checking against only the dictionary words with that length.. Let M be the upper bound on the dictionary which is given as 105. Since there are at most √M distinct lengths, the overall complexity of the solution is O(N √M).

Help Ritika
Problem Description
Ritika has a string-related task to complete, and she is seeking your assistance. Let us look at what the task involves.

Ritika has N substrings and a main string. Her goal is to select and concatenate these substrings to create the main string. Before concatenating, from the selected substring, she will remove all the unwanted characters (if and only if she has enough deletions left). She can use each substring an unlimited number of times, but she has a limit of K on the total number of characters she can delete.

Given the substrings, the main string, and the value of K, Ritika will attempt to build the main string from left to right while staying within the K deletions. Her task is to print the output as per specified output format explained below.

Please note that the printed portion of the main string should not include any extra characters which are not present in the main string. Each substring can only be concatenated, once after all unwanted characters have been removed.

Constraints
1 <= N <= 100

1 <= K <= 1000

1 <= length of main string <= 1000

1 <= length of each substring <= 20

All the substrings and main string consist of lower-case alphabets only.

Input
The first line contains an integer N denoting the number of substrings that Ritika has.

The next N lines each contain a substring, with one substring per line.

Next line consists of the main string.

Last line consists of an integer K denoting the number of character Ritika can delete in the process of forming the main string from left to right.

Output
Output could be one of the four possibilities.

If it is possible to form the entire main string within the allowed number of deletions, print "Possible"
If it is impossible to form the entire main string with any number of deletions, print "Impossible"
If it is possible to form the main string but not without exceeding the quota of K deletions, then print the portion of the main string that can be formed within K deletions
If it is not possible to form any portion of the given main string within the given number of deletions, print "Nothing"
Time Limit (secs)
2

Examples
Example 1

Input

8

ruined

goat

started

stray

goal

get

nemo

earring

getstringsring

10

Output

getstringsr

Explanation

Given main string is getstringsring

Let us select the substrings shown in the below table.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@48f5bde6:image1.png

With the remaining one deletion, we cannot remove anything from the provided strings to create the desired string. Since the entire main string cannot be formed with the maximum allowed deletions, we should print "getstringsr."

No other selection of substrings will allow us to form the main string beyond "getstringsr".

Example 2

Input

6

ant

eagle

yes

nine

ship

kite

english

15

Output

Possible

Explanation

Given main string is english

Let us select the substrings shown in the below table.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@48f5bde6:image2.png

Since we can form the entire given main string with a maximum of 15 deletions, we should print "Possible".

Please note that the table above illustrates one of the possible ways to construct the main string.

Example 3

Input

4

blue

green

black

red

eagles

5

Output

Impossible

Explanation

As you can see, the letter "s" is present in the main string but is not found in any of the substrings. Therefore, regardless of the number of deletions allowed, we cannot form the given main string. Thus, we should print "Impossible".
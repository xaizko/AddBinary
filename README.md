This approach is not the best, it ran in 3ms only beating 8.63% of other solutions.  

The solution is simple, reverse the array of inputs so that you can start adding the binaries from right to left (least to greatest)  

Afterwards, simply compare the values of the arrays and use binary addition to determine the output as well as keeping track of the carry out. You only have to account for the smallest binary because everything else can be filled in (and the last carryout).  

As mentioned, after computing the additions up until the smallest binary, you fill in the rest up to the biggest binary  

The final step is to reverse the array as we were working from the far most right so in order to get the actual expected output the binary must be reversed.  

And finally include the null terminator and you're done!

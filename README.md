Project 1: The Conditional Grade Calculator
This program calculates a student's final course grade. It processes input for a final exam, a midterm, and five projects, and computes the final score using two specific grading policies:

Grade Forgiveness: The program automatically converts the final exam score into a percentage. If this final exam percentage is higher than the score on the midterm or any of the five individual projects, it overwrites those lower scores.

The 40/60 Exam Rule: The program evaluates a base exam score (weighted 75% final, 25% midterm) before deciding how much the projects matter.

If the base exam score is 40% or lower, the projects are entirely ignored (0% weight).

If the exam score is 60% or higher, the projects receive their maximum weight (33.3% of the overall course grade).

If the exam score falls between 40% and 60%, the weight of the projects scales linearly.

Project 2: Mathematics and Binary Utilities
This program is a collection of four standalone computational tools that perform mathematical and binary operations strictly from scratch.

Integer Logarithm (log10): Calculates the base-10 logarithm of a number (effectively finding its digit count minus one) by iteratively multiplying a base value by 10 until it exceeds the input.

Console Graphics (pattern): Uses nested loops to calculate spacing and render a perfectly symmetrical, text-based "hourglass" shape out of asterisks.

Binary Counter (count): Analyzes a 32-bit integer and calculates exactly how many 1s or 0s make up its binary representation by mathematically subtracting descending powers of 2.

Byte Swapper (swap_bytes): Takes a 32-bit integer, manually breaks it apart into its four component bytes, and rearranges them by swapping two specifically targeted bytes using bitwise logical OR operations and shifting.

Project 4: C-String Toolkit
This program functions as a custom text-manipulation toolkit, operating entirely on raw character arrays (char*).

Fundamental Text Operations: The software processes text character-by-character to calculate string lengths, copy text from one location to another, and evaluate alphabetical order.

Array Management: It includes sorting algorithms designed to organize entire arrays of words into alphabetical order and automatically scrub out any consecutive duplicate entries.

Distance: It uses recursion to calculate the exact number of single-character edits (insertions, deletions, or substitutions) required to morph one word into another. If the software searches a dictionary array and cannot find an exact match for a word, it uses this mathematical distance to return the closest possible suggestion.

Project 5: Linked-List Mathematical Set
This program implements an object-oriented Mathematical Set. A data structure that holds integers but strictly forbids any duplicate values.

Underlying Structure: The set operates as a singly-linked list. Every time a new number is introduced, the program scans the entire existing list. The number is only added as a new "node" if it does not already exist.

Set Theory Operations: The program repurposes standard C++ math operators to combine different sets. It can merge unique items from two sets (Union via |), isolate only the numbers they share (Intersection via &), or remove shared elements (Difference via -).

Relational Comparisons: It uses comparison operators and overloading to evaluate the relationship between two different sets, mathematically verifying if they are identical (==), or if one set completely contains all the elements of another (Subset/Superset via <= and >=).

Memory Management: The program operates with highly specific rules for safely copying, assigning, and destroying sets to ensure that dynamically allocated memory is cleanly deleted and pointer conflicts are avoided.

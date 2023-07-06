# implementing a parser for a simple context-free grammar using python NLTK library
# Grammar:
# E → E + T | T
# T → T * F | F
# F → (E) | a

import nltk
from nltk import CFG
from nltk.parse import ChartParser
from nltk.parse import RecursiveDescentParser

grammar = CFG.fromstring("""
    E -> E '+' T | T
    T -> T '*' F | F
    F -> '(' E ')' | 'a'
""")
# parser = RecursiveDescentParser(grammar)

# exp = input("Enter the expression: ")
# try:
#     for tree in parser.parse(exp):
#         print(tree)
# except ValueError:
#     print("Invalid Expression")


# parser = ChartParser(grammar)
# exp = input("Enter the expression: ")
# try:
#     for tree in parser.parse(exp):
#         tree[0]

# except ValueError:
#     print("Invalid Expression")


sentence = "the giraffe dreams".split()
grammar = nltk.CFG.fromstring("""
            S -> NP VP
            NP -> Det N
            VP -> TV NP
            Det -> "the" | "a"
            N -> "giraffe" | "apple"
            IV -> "dreams"
            TV -> "eats"|"dreams"
 """)
parse = nltk.RecursiveDescentParser(grammar)
for tree in parse.parse(sentence):
    print(tree)

# Problem Statement:
# In this assignment, you will be implementing a parser for a simple context-free grammar. The
# grammar describes a language of arithmetic expressions involving addition and multiplication,
# along with parentheses for grouping. The grammar is given below:

# Grammar:
# E → E + T | T
# E → T * F | F
# F → (E) | a

# Defining the grammar
grammar = {
    'E': ['E + T', 'T'],
    'T': ['T * F', 'F'],
    'F': ['(E)', 'a']
}

# Write the program to check the expression and print the parse tree
# Sample Input:
# (a + a) * a
# Sample Output:
# E
# T * F
# F * F
# (E) * F
# (E + T) * F
# (T + T) * F
# (F + T) * F
# (a + F) * F
# (a + a) * F
# (a + a) * a


def parse_tree(exp):
    stack = []
    stack.append('E')
    i = 0
    while len(stack) != 0:
        if stack[-1] == exp[i]:
            stack.pop()
            i += 1
        else:
            if stack[-1] in grammar:
                stack.pop()
                for j in grammar[stack[-1]]:
                    stack.append(j)
    if i == len(exp):
        print("Valid Expression")
    else:
        print("Invalid Expression")


exp = input("Enter the expression: ")
parse_tree(exp)


class CFG_Parser:
    def __init__(self, string):
        self.string = string
        self.index = 0

    def parse(self):
        return self.parse_E()

    def parse_E(self):
        if self.parse_T():
            if self.index < len(self.string) and self.string[self.index] == "+":
                self.index += 1
                return self.parse_E()
            return True
        return False

    def parse_T(self):
        if self.parse_F():
            if self.index < len(self.string) and self.string[self.index] == "*":
                self.index += 1
                return self.parse_T()
            return True
        return False

    def parse_F(self):
        if self.index < len(self.string) and self.string[self.index] == "(":
            self.index += 1
            if self.parse_E():
                if self.index < len(self.string) and self.string[self.index] == ")":
                    self.index += 1
                    return True
            return False
        return self.parse_a()

    def parse_a(self):
        if self.index < len(self.string) and self.string[self.index] == "a":
            self.index += 1
            return True
        return False

# import nltk
# sentence = "the giraffe dreams".split()
# grammar = nltk.CFG.fromstring("""
#             S -> NP VP
#             NP -> Det N
#             VP -> TV NP
#             Det -> "the" | "a"
#             N -> "giraffe" | "apple"
#             IV -> "dreams"
#             TV -> "eats"|"dreams"
#  """)
# parse = nltk.RecursiveDescentParser(grammar)
# for tree in parse.parse(sentence):
#     print(tree)

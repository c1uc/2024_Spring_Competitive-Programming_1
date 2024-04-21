"""
NOT FINISHED
"""

import re

MOD = 10**9 + 7

class Tokenizer:
    def __init__(self, input):
        self.tokens = re.findall(r'\d+|[+*<=>?:()]', input)
        self.index = 0

    def peek(self):
        return self.tokens[self.index] if self.index < len(self.tokens) else None

    def next(self):
        token = self.peek()
        self.index += 1
        return token

class Parser:
    def __init__(self, tokenizer):
        self.tokenizer = tokenizer

    def parse(self):
        return self.parseComparisonExpression()

    def parseIntegerExpression(self):
        return int(self.tokenizer.next())

    def parseAdditionExpression(self):
        left = self.parseMultiplicationExpression()
        while self.tokenizer.peek() == '+':
            self.tokenizer.next()
            right = self.parseMultiplicationExpression()
            left = (left + right) % MOD
        return left

    def parseMultiplicationExpression(self):
        left = self.parseIntegerExpression()
        while self.tokenizer.peek() == '*':
            self.tokenizer.next()
            right = self.parseIntegerExpression()
            left = (left * right) % MOD
        return left

    def parseComparisonExpression(self):
        self.tokenizer.next()  # (
        left = self.parseAdditionExpression()
        self.tokenizer.next()  # <=>
        right = self.parseAdditionExpression()
        self.tokenizer.next()  # )
        self.tokenizer.next()  # ?
        value1 = self.parseAdditionExpression()
        self.tokenizer.next()  # :
        value2 = self.parseAdditionExpression()
        self.tokenizer.next()  # :
        value3 = self.parseAdditionExpression()
        if left < right:
            return value1
        elif left == right:
            return value2
        else:
            return value3

def evaluate(input):
    tokenizer = Tokenizer(input)
    parser = Parser(tokenizer)
    return parser.parse()

print(evaluate("( 5 <=> 3 ) ? ( 1 ) : ( 2 ) : ( 3 )"))  # Output: 3

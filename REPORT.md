# Project Report: Expression Evaluation Using Stack

## Introduction
Infix expressions place operators between operands. A calculator must follow precedence and parentheses to produce the expected result. This project demonstrates stacks in a command-line arithmetic evaluator written in C.

## Problem statement
Accept arithmetic expressions, respect operator precedence and parentheses, and calculate results using the stack data structure.

## Objectives
- Demonstrate stack push and pop operations.
- Convert infix expressions to postfix notation.
- Evaluate postfix expressions.
- Handle malformed expressions and division by zero.

## Scope
Supports integer and decimal numbers, parentheses, unary plus/minus, `+`, `-`, `*`, `/`, and exponentiation `^`. It does not include variables, functions, or a graphical interface.

## Data structures
Two array-based stacks are used. The operator stack holds operators and opening parentheses during conversion. The number stack holds operands and intermediate values during evaluation. Each stack uses a `top` index and follows last-in, first-out order.

## Algorithm
### Infix to postfix
Scan left to right. Output numbers directly. Push opening parentheses. Before pushing an operator, pop higher-precedence operators (and equal-precedence left-associative operators) to the output. At a closing parenthesis, pop until the matching opening parenthesis. Pop remaining operators at the end. This is the Shunting-yard algorithm.

### Postfix evaluation
Scan tokens left to right. Push each number. For a binary operator, pop the right operand then the left operand, apply the operation, and push the result. Unary signs apply to the top value. The final stack value is the answer.

### Precedence
Exponentiation precedes multiplication/division, which precede addition/subtraction. Parentheses group operations. Exponentiation is right-associative.

## Example
`2 + 3 * 4` becomes postfix `2 3 4 * +`. The evaluator multiplies 3 and 4, then adds 2, producing 14.

## Error handling
Unsupported characters, invalid operator sequences, incomplete input, and mismatched parentheses are rejected. Division by zero is reported.

## Complexity
For n tokens, conversion and evaluation each take O(n) time; the stacks and output require O(n) space.

## Limitations
Fixed-size input/output and stacks limit expression length. Variables, functions, and implicit multiplication (for example `2(3+4)`) are not supported.

## Conclusion
The project shows how stacks preserve evaluation order. Postfix conversion handles precedence, while postfix evaluation uses simple last-in, first-out operations.

## References
- Course textbook or class notes on stacks and expression conversion.
- C standard library documentation for string, input, and math functions.

## Student details
Name: Are Sumedha Rani Suri
Roll number: 20251ECE0162
Class/course: 3ECE03/CSE

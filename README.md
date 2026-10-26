# Expression Evaluation Using Stack (C)

A command-line calculator that converts infix arithmetic expressions to postfix notation and evaluates them using stacks.

## Features
- Supports `+`, `-`, `*`, `/`, exponentiation `^`, parentheses, decimal numbers, and unary plus/minus.
- Follows operator precedence and parentheses.
- Reports malformed expressions and division by zero.
- Displays postfix form and the result.

## Stack usage
An operator stack is used during infix-to-postfix conversion (Shunting-yard algorithm). A number stack stores operands and intermediate results while evaluating postfix.

## Compile and run
Install GCC or another C compiler. With GCC:

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o expression_calculator -lm
```

Run `expression_calculator.exe` on Windows or `./expression_calculator` on macOS/Linux. Type `q` to exit.

## Example
```text
Enter expression: 2 + 3 * 4
Postfix: 2 3 4 * +
Result: 14
```

See [REPORT.md](REPORT.md) and [TEST_CASES.md](TEST_CASES.md). Add your name, roll number, class and faculty details before submitting.

## Publish to GitHub
1. Create a new repository named `expression-evaluation-using-stack` on GitHub. For a faculty submission link, set visibility to Public unless your faculty requests Private.
2. In this folder, run these commands (replace `YOUR-USERNAME`):

```bash
git remote add origin https://github.com/YOUR-USERNAME/expression-evaluation-using-stack.git
git branch -M main
git push -u origin main
```

After pushing, submit the repository page URL: `https://github.com/YOUR-USERNAME/expression-evaluation-using-stack`.

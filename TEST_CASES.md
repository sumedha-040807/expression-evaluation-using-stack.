# Test Cases

Compile using the command in README.md, then enter each expression. Results below are expected values; error cases should print an error.

| # | Input | Expected result/behavior | Purpose |
|---|---|---|---|
| 1 | `2 + 3` | `5` | Addition |
| 2 | `2 + 3 * 4` | `14` | Precedence |
| 3 | `(2 + 3) * 4` | `20` | Parentheses |
| 4 | `20 / 5 - 1` | `3` | Division and subtraction |
| 5 | `2 ^ 3 ^ 2` | `512` | Right-associative exponentiation |
| 6 | `-5 + 2` | `-3` | Unary minus |
| 7 | `3.5 * 2` | `7` | Decimal operands |
| 8 | `((1 + 2) * (3 + 4))` | `21` | Nested parentheses |
| 9 | `8 / 0` | Division-by-zero error | Error handling |
| 10 | `(2 + 3` | Invalid expression / parentheses error | Unmatched opening parenthesis |
| 11 | `2 + * 3` | Invalid expression error | Invalid operator sequence |
| 12 | `2 + a` | Invalid expression error | Unsupported character |

Also enter `q` to check clean exit.

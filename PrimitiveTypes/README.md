# C++ Bitwise Operators and Best Practices

This README covers **bitwise operations in C++**, masks, fast bit tricks (low/high bits), signedness, caching, and operator properties.

---

## 1. Bitwise Operators

| Operator | Symbol | Simple Explanation | Example |
|----------|--------|-----------------|---------|
| AND      | `&`    | Keeps a bit 1 only if both are 1 | `5 & 3 → 0101 & 0011 = 0001 → 1` |
| OR       | `|`    | Sets a bit to 1 if **either** is 1 | `5 | 3 → 0101 | 0011 = 0111 → 7` |
| XOR      | `^`    | Sets a bit to 1 if bits are **different** | `5 ^ 3 → 0101 ^ 0011 = 0110 → 6` |
| NOT      | `~`    | Flips all bits (0 → 1, 1 → 0) | `~5 → 0101 → 1010 → -6` |
| Left shift | `<<` | Moves bits left; multiplies by 2 per shift | `5 << 1 → 0101 << 1 = 1010 → 10` |
| Right shift | `>>` | Moves bits right; unsigned fills 0, signed may keep sign | `5 >> 1 → 0101 >> 1 = 0010 → 2` |

---

## 2. Using Bit Masks

Masks allow **selecting, setting, clearing, or toggling specific bits**.

### Common Patterns

```cpp
uint8_t flags = 0b10101100;

// Set bit 3 (0-indexed)
flags |= (1 << 3);  // 10101100 | 00001000 → 10101100

// Clear bit 2
flags &= ~(1 << 2); // 10101100 & 11111011 → 10101100

// Toggle bit 0
flags ^= (1 << 0);  // 10101100 ^ 00000001 → 10101101

// Check if bit 7 is set
bool is_set = flags & (1 << 7); // true



// Clear bits 2,3,4
flags &= ~(0b00011100); // AND with inverted mask

// Set bits 0,1,2
flags |= 0b00000111;     // OR with mask


uint32_t x = 0b1011000;

// Get lowest set bit
uint32_t lsb = x & -x; // 0b0001000

// Clear lowest set bit
x &= (x - 1);          // 0b1010000

// Set lowest unset bit
x |= (x + 1);          // 0b1011001




Signedness and Shifts
	•	Unsigned integers: safe and predictable; shifting works as expected.
	•	Signed integers: left shift of negative values or overflow is undefined; right shift may keep the sign (arithmetic shift).

Rule of thumb: use unsigned integers for bitwise operations.

When to Use a Cache
	•	Bitwise operations are cheap, but repeated complex calculations (like masks, popcount, or bit scans) can benefit from caching.
	•	Example: precompute powers-of-two masks or lookup tables for repeated bit manipulations.

Commutativity & Associativity
	•	Commutative: a & b == b & a, a | b == b | a, a ^ b == b ^ a
→ You can reorder operands freely.
	•	Associative: (a & b) & c == a & (b & c) (same for | and ^)
→ You can group operations in any order, useful for parallel computation.

Example: summing OR across an array can be split across threads and combined later.

⸻

7. Quick Summary / Rules
	1.	Use & to keep certain bits, | to set, ^ to toggle, ~ to invert.
	2.	Masks help select or manipulate specific bits.
	3.	LSB tricks are fastest for low-level bit operations.
	4.	Always consider unsigned types for shifting.
	5.	Cache repeated calculations if they are expensive or repeated.
	6.	Reorder AND/OR/XOR operations safely using commutativity and associativity for optimization or parallelism.

⸻


Constants

numeric_limits<int>::min()
numeric_limits<float>::max()
numeric_limits<double>::infinity()

cmath: 

abs()
fabs()
ceil()
floor()
min()
max()
pow(,)
log()
sqrt()

char to int: 

x - '0'

int to string: 

to_string(123)

string to int
stoi("123")


random functions: 

uniform_int_distribution<> dis(1,6) -> returns an integer value in [1,6] inclusive 

uniform_real_distribution<double> dis(1.3, 2.9) which returns a floating point number in [1.3,2.9]

generate_canonical<double, 10> which returns a value in [0,1)

use swap(x,y) to exchange values succinctly 
# C++ modules 00–09

Ten short modules that introduce C++ one topic at a time. All the code is **C++98**, compiled with `-Wall -Wextra -Werror -std=c++98`. Each exercise has its own folder and `Makefile`.

| Module | Topic | Exercises |
| --- | --- | --- |
| [cpp00](cpp00) | Classes, member functions, I/O streams | `megaphone`, a `PhoneBook` of `Contact`s |
| [cpp01](cpp01) | Memory allocation, references, pointers to members, `switch` | `Zombie` on the stack and the heap, `HumanA` vs `HumanB` (reference vs pointer to a `Weapon`), find and replace in a file, `Harl` complaint levels through a table of member function pointers |
| [cpp02](cpp02) | Orthodox Canonical Form, operator overloading | a `Fixed`-point number class with arithmetic and comparison operators, and a point-in-triangle test (BSP) |
| [cpp03](cpp03) | Inheritance | `ClapTrap` → `ScavTrap`, `FragTrap` → `DiamondTrap` (diamond inheritance with `virtual` base classes) |
| [cpp04](cpp04) | Polymorphism, abstract classes, deep copy | `Animal`/`Dog`/`Cat` with virtual functions, and a `WrongAnimal` showing what happens without them; each animal owns a heap-allocated `Brain` that must be deep-copied |
| [cpp05](cpp05) | Exceptions | `Bureaucrat`s with grades that throw when out of range, forms that need a minimum grade to sign and execute, and an `Intern` that creates forms by name |
| [cpp06](cpp06) | C++ casts | a scalar type converter (`char`/`int`/`float`/`double`, with `nan` and `inf`), pointer serialization with `reinterpret_cast`, runtime type identification with `dynamic_cast` |
| [cpp07](cpp07) | Templates | `swap`/`min`/`max`, `iter` over an array, and an `Array<T>` class template |
| [cpp08](cpp08) | STL containers, iterators, algorithms | `easyfind` over any container, a `Span` that finds the shortest and longest distance between numbers, and a `MutantStack` that adds iterators to `std::stack` |
| [cpp09](cpp09) | Choosing containers | below |

## cpp09

- **ex00 `btc`:** loads a CSV of historical Bitcoin prices into a `std::map` and, for each `date | amount` line of an input file, prints the value at that date, using the closest earlier date when there's no exact match. Malformed dates, negative or too-large amounts are reported line by line.
- **ex01 `RPN`:** evaluates an expression in Reverse Polish Notation with a `std::stack`, e.g. `./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"` prints `42`.
- **ex02 `PmergeMe`:** sorts a sequence of positive integers with the **Ford-Johnson merge-insertion sort**, once with `std::vector` and once with `std::deque`, and times both. Elements are paired and the larger ones are sorted recursively. The smaller ones are then inserted by binary search, in an order given by the **Jacobsthal numbers**, which keeps the number of comparisons low. A helper checks that every input number is in the result.

```bash
cd cpp09/ex02 && make
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
```

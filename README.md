### Bag Data Structure

This project implements a collection of data structures in C++, including `Bag`, `KeyedBag`, and `Set`, along with corresponding operations that can be performed on these data structures. Each data structure is implemented with an array-based approach, and a variety of operators are overloaded to perform operations like union, intersection, subtraction, and comparisons. The project also includes a `main.cpp` file that demonstrates how to use these data structures and their associated functions.

### Files' Descriptions

1. **`bag.h` & `bag.cpp`**
   - These files define and implement the `Bag` class, which represents a simple unordered collection of items that allows duplicates. The class provides functionalities such as insertion, deletion, and basic arithmetic operations between two bags.
   
2. **`keyed_bag.h` & `keyed_bag.cpp`**
   - These files define and implement the `KeyedBag` class, which extends the functionality of a `Bag` by associating each item with a unique key. This allows for operations based on keys, in addition to the basic bag functionalities.
   
3. **`set.h` & `set.cpp`**
   - These files define and implement the `Set` class, which represents a collection of unique items. This class provides set operations like union, intersection, difference, and subset checks. It also overloads several operators to facilitate these operations.
   
4. **`main.cpp`**
   - This file contains the main function and demonstrates the usage of the `Bag`, `KeyedBag`, and `Set` classes. It includes examples of how to create instances of these classes, perform operations on them, and display the results.

### Functionality Overview

- **Bag**: Supports operations like insertion, deletion, union, subtraction, and equality comparison.
- **KeyedBag**: Extends `Bag` by allowing items to be associated with unique keys. Supports all `Bag` operations along with key-based operations.
- **Set**: Implements a collection of unique elements with set-specific operations like union, intersection, difference, subset, and proper subset checks. Also includes overloaded operators for ease of use.

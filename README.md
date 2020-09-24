# Practice C++

- [Practice C++](#practice-c)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Data Structures](#data-structures)


Repository with my implementations of the most diverse algorithms and their respective tests. The real intention of this repository is to create a way to demonstrate my knowledge and developments in the C++ language, and, nothing better than using codes to show this.

## Installation

```bash
mkdir build && cd build/
cmake ../
make
```

## Usage

```bash
cd build
./linked_lists/linked_lists_run
```

## Data Structures

- [ ] Linked list
  - [x] size() - returns number of data elements in list
  - [x] empty() - bool returns true if empty
  - [x] value_at(index) - returns the value of the nth item (starting at 0 for first)
  - [x] push_front(value) - adds an item to the front of the list
  - [x] pop_front() - remove front item and return its value
  - [x] push_back(value) - adds an item at the end
  - [x] pop_back() - removes end item and returns its value
  - [x] front() - get value of front item
  - [x] back() - get value of end item
  - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
  - [ ] erase(index) - removes node at given index
  - [ ] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
  - [ ] reverse() - reverses the list
  - [ ] remove_value(value) - removes the first item in the list with this value
- [ ] Stack
- [ ] Queue
- [ ] Hash table
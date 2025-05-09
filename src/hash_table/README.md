# External Chaining and Open-Addressing

### Separate Chaining has several advantages over open addressing:
- Collision resolution is simple and efficient.
- The hash table can hold more elements with the large performance deterioration of open addressing. (The load factor can be 1 or greater)
- The performance of chaining declines much more slowly than open addressing
- Deletion is easy - no special flag values are necessary.
- Table size need not be a prime number.
- The keys of the objects to be hashed need not be unique.

### Disadvantages of Separate Chaining
- It requires the implementation of a separate data structure for chains, and code to manage it.
- Tha main cost of chaining is the ectra space required for the linked lists.
- For some languages, creating new nodes (for linked lists) is expensive and slows down the system.

Read more about [here](https://en.wikipedia.org/wiki/Hash_table).
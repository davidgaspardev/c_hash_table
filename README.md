# Hash Table

In computing, a **hash table** (hash map) is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a **hash function** to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. It offers O (1) amortized time in searching, inserting and deleting. A collision occurs when two or more elements are hashed (mapped) to same value.

![hash tables](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7d/Hash_table_3_1_1_0_1_0_0_SP.svg/1200px-Hash_table_3_1_1_0_1_0_0_SP.svg.png)

## Hashing with Open Addressing

In this section we will see what is the hashing by open addressing. The open addressing is another technique for collision resolution. Unlike chaining, it does not insert elements to some other data-structures. It inserts the data into the hash table itself. The size of the hash table should be larger than the number of keys.

There are three different popular methods for open addressing techniques. These methods are:
 - Linear Probing
 - Quadratic Probing
 - Double Hashing

In this technique, we use a hash function like other hash techniques. If the place is free, then insert the element into that location. Now if that place is not free, we will find another free element by using some equations. For the linear probing, we will use some linear equations, for quadratic probing, we will use some quadratic equations.

In the double hashing, when a collision occurs, we will use another hash function, then put into that location. That hash function is called the secondary hash function. That will not be used directly, if there is no collision.

### Is JSON hash table ?

**JSON** supportd dictionary type elements. People may refer to these as `hash tables`, which are a type of data structure. Referring to JSON dictionaries as `hash tables would` be technically incorrect, however, as there is no particular data structure implementation associated with the JSON data itself.
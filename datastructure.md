# 📚 Data Structures

## 📌 Introduction
Data structures are fundamental concepts in computer science that enable efficient storage, organization, and retrieval of data. They are essential for designing optimal algorithms and building scalable software.

---

## 🧱 Types of Data Structures

### 1. 📦 Arrays
- **Definition**: A collection of elements identified by index.
- **Characteristics**: Fixed size, elements are stored in contiguous memory.
- **Operations**: 
  - Access: `arr[i]`
  - Insertion/Deletion: via index (may require shifting)
  - Traversal: `for` loop or `forEach`

---

### 2. 🔗 Linked Lists
- **Definition**: A linear collection of elements (nodes), each pointing to the next.
- **Types**:
  - Singly Linked List
  - Doubly Linked List
  - Circular Linked List
- **Operations**:
  - Insertion/Deletion: at head, tail, or middle
  - Traversal: using pointers

---

### 3. 🥞 Stacks
- **Definition**: Follows **LIFO** (Last In, First Out).
- **Operations**:
  - `push()` – Add to top
  - `pop()` – Remove top
  - `peek()` – View top without removing

---

### 4. 🚦 Queues
- **Definition**: Follows **FIFO** (First In, First Out).
- **Types**:
  - Simple Queue
  - Circular Queue
  - Priority Queue
  - Deque (Double-Ended Queue)
- **Operations**:
  - `enqueue()` – Add to rear
  - `dequeue()` – Remove from front
  - `front()` – Peek first element
  - `rear()` – Peek last element

---

### 5. 🌳 Trees
- **Definition**: Hierarchical structure of nodes with one root node.
- **Types**:
  - Binary Tree
  - Binary Search Tree (BST)
  - AVL Tree
  - B-Tree
  - Heap (Min/Max)
- **Operations**:
  - Insertion
  - Deletion
  - Traversals:
    - In-Order (LNR)
    - Pre-Order (NLR)
    - Post-Order (LRN)
    - Level-Order

---

### 6. 🔗 Graphs
- **Definition**: A set of nodes (vertices) connected by edges.
- **Types**:
  - Directed / Undirected
  - Weighted / Unweighted
  - Cyclic / Acyclic
- **Operations**:
  - Traversals: BFS (Breadth-First), DFS (Depth-First)
  - Shortest Path: Dijkstra, Bellman-Ford
  - Cycle Detection, Connectivity

---

### 7. #️⃣ Hash Tables
- **Definition**: Maps keys to values using a **hash function**.
- **Characteristics**:
  - Fast average time complexity for search, insert, delete: `O(1)`
  - Handle collisions via chaining or open addressing
- **Operations**:
  - `put(key, value)`
  - `get(key)`
  - `remove(key)`

---

## 🧠 Conclusion
Mastering data structures is key to solving complex computational problems efficiently. The right data structure depends on the specific needs of your application, balancing trade-offs in speed, memory, and complexity.

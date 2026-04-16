*This project has been created as part of the 42 curriculum by npawlak, lamarty.*

# DESCRIPTION
Push_swap is an algorithmic project that requires sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. The goal is to manipulate two stacks (A and B) and implement various sorting algorithms to achieve specific time complexity targets depending on the initial disorder of the provided data.

# INSTRUCTION
## COMPILATION
To compile the project, run the following command at the root of the repository:
make

## EXECUTION
Run the program with a list of integers as arguments:
./push_swap <list_of_integers>

Optional flags can be used to enforce specific sorting strategies or display metrics:
./push_swap --simple <list_of_integers>
./push_swap --medium <list_of_integers>
./push_swap --complex <list_of_integers>
./push_swap --adaptive <list_of_integers>
./push_swap --bench <list_of_integers>

# RESOURCES
## REFERENCES
Standard computer science literature regarding sorting algorithms, time complexity (Big-O notation), and data structures.

## AI USAGE
Artificial Intelligence was utilized during this project strictly for the following purposes:
- Assistance with the generation and formatting of this README.
- Brainstorming and thought process assistance.
- Debugging assistance.

# ALGORITHMS
The program incorporates multiple sorting strategies to handle different levels of data disorder, complying with the strict complexity constraints.

## STRATEGIES
- Simple Algorithm O(n^2): Adaptation of Selection Sort.
- Medium Algorithm O(n√n): Block-based partitioning and chunk sorting.
- Complex Algorithm O(n log n): Advanced Greedy algorithm calculating the most cost-effective operations based on circular distance.
- Adaptive Algorithm: Evaluates the initial disorder metric to automatically route the data to the appropriate sorting strategy.

## TASK DISTRIBUTION
- lamarty: Implementation of stack operation swap, Selection sort logic, make_in_order function, and the adapt_choice routing system.
- npawlak: Implementation of the Complex algorithm (Greedy approach), core optimization logic, and advanced mathematical distance calculations for circular stack management.
- Together: Overall program architecture, error handling, input parsing, and general integration, other stacks operations.
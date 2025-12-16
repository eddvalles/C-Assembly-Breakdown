Software Engineering Observation:
1. Some programmers feel that break and continue violate the norms of structured programming. The effects of these
    statements can be achieved by structured programming techniques.
2. For all but the most performance-intensive situations, apply the following guidelines:
    First, make your code simple and correct; then make it fast and small, but only if necessary.

Performance Tip:
1. The break and continue statements, when used properly, perform faster than structured programming.
2. In expressions using operator (&&), make the condition that's most likely to be FALSE the left-most condition.
    (due to Short Circuit Evaluation)
3. In expressions using operator (||), make the condition that's most likely to be TRUE the left-most condition.
    (due to Short Circuit Evaluation)


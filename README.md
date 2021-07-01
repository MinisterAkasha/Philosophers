# Philosophers
👨👨👨 Philosophers is a classic multithreading problem

## Conditions:

- Several philosophers are sitting at a round table doing one of three things: eating,
thinking, or sleeping.
- While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping.
- The philosophers sit at a circular table with a large bowl of spaghetti in the center.
- There are some forks on the table.
- As spaghetti is difficult to serve and eat with a single fork, it is assumed that a
philosopher must eat with two forks, one for each hand.
- The philosophers must never be starving.
- Every philosopher needs to eat.
- Philosophers don’t speak with each other.
- Philosophers don’t know when another philosopher is about to die.
- Each time a philosopher has finished eating, he will drop his forks and start sleeping.
- When a philosopher is done sleeping, he will start thinking.
- The simulation stops when a philosopher dies.

## philo_one

### Additional conditions:

- One fork between each philosopher, therefore if they are multiple philosophers, there
will be a fork at the right and the left of each philosopher.
- Each philosopher should be a thread. 
- Threads and mutexes are used

## philo_two

### Additional conditions:

- All forks are placed in the center of the table.
- Each philosopher should be a thread. 
- Threads and semaphore are used.

## philo_three

### Additional conditions:

- All forks are placed in the center of the table.
- Each philosopher should be a process. 
- Processes and semaphore are used.

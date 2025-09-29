# Lab: Intro to Processes (fork)

**Author:** Ashley Nfonga

---

## Files Included
- `main.c` – Demonstrates `fork()` creating two processes without distinguishing parent and child.
- `main2.c` – Demonstrates `fork()` with clear parent and child process roles.

---

## Compilation Instructions

Open a terminal in Codio (or any Unix/Linux environment) and run:

```bash
gcc main.c -o main
./main

gcc main2.c -o main2
./main2

---

## How It Works

- `fork()` is used to create a child process.  
- After `fork()`, both parent and child execute the next statement independently.  
- `main.c` shows both processes running without distinction.  
- `main2.c` distinguishes parent and child:
  - `pid == 0` → child process  
  - `pid > 0` → parent process  

- `usleep()` is used in the loops to make output interleave clearly.

---

## Example Output


**main.c:**


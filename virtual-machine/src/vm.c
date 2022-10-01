#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// instruction enum
typedef enum
{
  HLT, // stop
  PSH, // load
  ADD, // add two registers
  SUB, // subtract two regitsters
  SET  // store register in output
} InstructionSet;

// registers
typedef enum
{
  IP,
  A,
  B,
  IN,
  OUT,
  NUM_OF_REGISTERS
} Registers;

// example program
const int program[12] = {
    PSH, A, 5,
    PSH, B, 6,
    ADD, A, B,
    SET, A,
    HLT};

int registers[NUM_OF_REGISTERS];

#define IP (registers[IP])
#define OUT (registers[OUT])
#define A (registers[A])
#define B (registers[B])

// is the program running
bool running = true;

// fetch function
int fetch()
{
  return program[IP];
}

// eval function
void eval(int instr)
{
  switch (instr)
  {
  case HLT:
    running = false;
    printf("%d\n", OUT);
    break;
  case PSH: {
    IP += 1;
    if (registers[program[IP]] == A) {
      A = program[(IP + 1)];
    } else {
      B = program[(IP + 1)];
    }
    IP += 2;
    break;
  }
  case ADD:
    // a = a + b
    A = A + B;
    IP += 3;
    break;
  case SUB: {
    // a = a - b
    A = A - B;
    IP += 3;
    break;
  }
  case SET: {
    OUT = A;
    IP += 2;
  }
  }
}

int main()
{
  while (running)
  {
    eval(fetch());
  }
}
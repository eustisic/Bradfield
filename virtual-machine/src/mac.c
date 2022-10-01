#include <stdbool.h>
#include <stdio.h>

// instruction enum
typedef enum
{
  PSH, // load
  ADD, // add two registers
  SUB, // subtract two regitsters
  POP, //
  SET, // store
  HLT
} InstructionSet;

// example program
const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT};

int ip = 0;  // instruction pointer - index to the array of instructions being implemented
int sp = -1; // stack pointer
int stack[256];
bool running = true;

// registers
typedef enum {
  A, B, C, D, E, F,
  NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];

// eval function
void eval(int instr)
{
  switch (instr)
  {
  case HLT:
    running = false;
    break;
  case PSH:
    sp++;
    stack[sp] = program[++ip];
    break;
  case POP: {
    int val_popped = stack[sp--];
    printf("popped %d\n", val_popped);
    break;
  }
  case ADD: {
    // pop and store as 'a'
    int a = stack[sp--];

    // pop and store as b
    int b = stack[sp--];

    // then add result and push
    int result = b + a;
    sp++;
    stack[sp] = result;
    break;
  }
  }
}

// fetch function
int fetch()
{
  return program[ip];
}

int main()
{
  while (running)
  {
    eval(fetch());
    ip++;
  }
}
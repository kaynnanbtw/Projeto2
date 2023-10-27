#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REGISTER_COUNT 32
#define MEMORY_SIZE 1000

typedef struct {
    int registers[REGISTER_COUNT];
    int memory[MEMORY_SIZE];
} State;

void initializeState(State *state) {
    for (int i = 0; i < REGISTER_COUNT; i++) {
        state->registers[i] = 0;
    }
    for (int i = 0; i < MEMORY_SIZE; i++) {
        state->memory[i] = 0;
    }
}

int main() {
    State state;
    initializeState(&state);

    int N;
    scanf("%d", &N);
    char instruction[20];
    int rx, ry, rz, address, value;

    for (int i = 0; i < N; i++) {
        scanf("%s", instruction);
        if (strcmp(instruction, "EXIT") == 0) {
            break;
        } else if (strcmp(instruction, "MOV") == 0) {
            char op1[20], op2[20];
            scanf(" R%d %s", &rx, op1);
            if (op1[0] >= '0' && op1[0] <= '9') {
                value = atoi(op1);
                state.registers[rx] = value;
            } else {
                scanf(" R%d", &ry);
                state.registers[rx] = state.registers[ry];
            }
        } else if (strcmp(instruction, "ADD") == 0) {
            scanf(" R%d R%d R%d", &rx, &ry, &rz);
            state.registers[rx] = state.registers[ry] + state.registers[rz];
        } else if (strcmp(instruction, "SUB") == 0) {
            scanf(" R%d R%d R%d", &rx, &ry, &rz);
            state.registers[rx] = state.registers[ry] - state.registers[rz];
        } else if (strcmp(instruction, "MUL") == 0) {
            scanf(" R%d R%d R%d", &rx, &ry, &rz);
            state.registers[rx] = state.registers[ry] * state.registers[rz];
        } else if (strcmp(instruction, "DIV") == 0) {
            scanf(" R%d R%d R%d", &rx, &ry, &rz);
            if (state.registers[rz] != 0) {
                state.registers[rx] = state.registers[ry] / state.registers[rz];
            }
        } else if (strcmp(instruction, "MOD") == 0) {
            scanf(" R%d R%d R%d", &rx, &ry, &rz);
            if (state.registers[rz] != 0) {
                state.registers[rx] = state.registers[ry] % state.registers[rz];
            }
        } else if (strcmp(instruction, "BEQ") == 0) {
            scanf(" R%d R%d %d", &rx, &ry, &address);
            if (state.registers[rx] == state.registers[ry]) {
                i = address - 1; 
            }
        } else if (strcmp(instruction, "BLT") == 0) {
            scanf(" R%d R%d %d", &rx, &ry, &address);
            if (state.registers[rx] < state.registers[ry]) {
                i = address - 1; 
            }
        } else if (strcmp(instruction, "JMP") == 0) {
            scanf("%d", &address);
            i = address - 1; 
        } else if (strcmp(instruction, "LOAD") == 0) {
            scanf(" R%d R%d", &rx, &ry);
            if (ry >= 0 && ry < MEMORY_SIZE) {
                state.registers[rx] = state.memory[ry];
            }
        } else if (strcmp(instruction, "STORE") == 0) {
            scanf(" R%d R%d", &rx, &ry);
            if (ry >= 0 && ry < MEMORY_SIZE) {
                state.memory[ry] = state.registers[rx];
            }
        } else if (strcmp(instruction, "PRINT") == 0) {
            scanf(" R%d", &rx);
            printf("\n");
            printf("%d\n", state.registers[rx]);
        }
    }

    return 0;
}

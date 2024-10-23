#include <stdio.h>

int status = 0;

#define Z_FLAG 0x08;  // Zero flag is 1000
#define N_FLAG 0x04;  // Negative flag is 0100
#define C_FLAG 0x02;  // Carry flag is 0010
#define R_FLAG 0x01;  // Reserve flag is 0001
                      // This is because the values are represented as binary values.  

void set_zero_flag(int result) {
    if (result == 0) {
        status = status | Z_FLAG;
    } else {
        status = status & ~Z_FLAG;
    }
}

void set_negative_flag(int result) {
    if (result < 0) {
        status = status | N_FLAG;
    } else {
        status = status & ~N_FLAG;
    }
}

void set_carry_flag(int result) {
    if(result > 0) {
        status = status | C_FLAG;
    } else {
        status = status & ~C_FLAG;
    }
}

void set_reserve_flag(int result) {
    if(result == 1) {
        status = status | R_FLAG;
    } else {
        status = status & ~R_FLAG;
    }
}

int main() {
    set_zero_flag(0);
    set_negative_flag(-1);       // Sets the negative flag because the result is negative
    set_carry_flag(1);
    set_reserve_flag(1);

    printf("Final Status: 0x%02X\n", status); // Prints the status in hexadecimal
    return 0;
}

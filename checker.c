#include <stdio.h>
#include <assert.h>

typedef struct {
    float value;
    float min;
    float max;
    char errorMessage[50];  
} ParameterCheck;

int isParameterOk(ParameterCheck check) {
    if (check.value < check.min || check.value > check.max) {
        printf("%s\n", check.errorMessage);
        return 0;
    }
    return 1;
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
   
    ParameterCheck checks[3] = {
        {temperature, 0, 45, "Temperature out of range!"},
        {soc, 20, 80, "State of Charge out of range!"},
        {chargeRate, 0, 0.8, "Charge Rate out of range!"}
    };

    for (int i = 0; i < 3; i++) {
        if (!isParameterOk(checks[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7)); 
    assert(!batteryIsOk(50, 85, 0));  
}

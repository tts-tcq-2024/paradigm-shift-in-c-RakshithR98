#include <stdio.h>
#include <assert.h>

int checkRange(float value, float min, float max, const char* message) {
    int inRange = (value >= min && value <= max);
    if (!inRange) {
        printf("%s\n", message);
    }
    return inRange;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkRange(temperature, 0, 45, "Temperature out of range!") &&
           checkRange(soc, 20, 80, "State of Charge out of range!") &&
           checkRange(chargeRate, 0, 0.8, "Charge Rate out of range!");
}

int main() {
    assert(batteryIsOk(25, 70, 0.7)); 
    assert(!batteryIsOk(50, 85, 0)); 
}

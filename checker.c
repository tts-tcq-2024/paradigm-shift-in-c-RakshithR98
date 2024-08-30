#include <stdio.h>
#include <assert.h>

int isInRange(float value, float min, float max, const char* message) {
    if (value < min || value > max) {
        printf("%s\n", message);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isInRange(temperature, 0, 45, "Temperature out of range!") &&
           isInRange(soc, 20, 80, "State of Charge out of range!") &&
           isInRange(chargeRate, 0, 0.8, "Charge Rate out of range!");
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}

#include <iostream>
#include "PID.h"

int main()
{
    PID pid(0.2, 0.2, 0.005);
    // PID pid(0.2, 0, 0);
    int cur_time = 0;
    double cur = 0;
    while (cur_time<100)
    {
        cur += pid.calculate(100, cur);
        cout << ++cur_time << "->" << cur << endl;
    }
    return 0;
}

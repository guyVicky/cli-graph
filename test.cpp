#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (float i = 1; i <= 100; i++)
    {
        cout << "sine of " << i << " : " << 100 * sin((i / 100) * M_PI) << endl;
    }

    return 0;
}
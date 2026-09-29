#include <iostream>
using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    // Default Constructor
    Angle() {
        degrees = 0;
        minutes = 0.0;
        direction = 'N';
    }

    // Parameterized Constructor
    Angle(int deg, float min, char dir) {
        setAngle(deg, min, dir);
    }

    void setAngle(int deg, float min, char dir) {
        dir = toupper(dir);
        if (dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W') {
            cout << "Invalid Direction! Defaulting to 'N'.\n";
            direction = 'N';
        } else {
            direction = dir;
        }

        if (min < 0.0 || min >= 60.0) {
            cout << "Invalid Minutes! Defaulting to 0.0.\n";
            minutes = 0.0;
        } else {
            minutes = min;
        }

        degrees = deg;
    }

    void getAngle() {
        int deg;
        float min;
        char dir;
        cout << "Degrees enter karein: ";
        cin >> deg;
        cout << "Minutes (0-59.9) enter karein: ";
        cin >> min;
        cout << "Direction (N, S, E, W) enter karein: ";
        cin >> dir;

        setAngle(deg, min, dir);
    }

    void display() const {
        // Output format: 149°34.8' W
        cout << degrees << "\xF8" << minutes << "' " << direction;
    }
};

int main() {
    Angle lat(17, 31.5, 'S');
    Angle lon(149, 34.8, 'W');

    cout << "Latitude: ";
    lat.display();
    cout << "\nLongitude: ";
    lon.display();
    cout << "\n\n--- User Input Test ---\n";

    Angle userAngle;
    userAngle.getAngle();
    cout << "Entered Angle: ";
    userAngle.display();
    cout << endl;

    return 0;
}
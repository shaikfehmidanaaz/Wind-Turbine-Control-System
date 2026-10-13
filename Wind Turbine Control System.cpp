
#include <iostream>
#include <iomanip>
using namespace std;

class WindTurbineControlSystem {
private:
    double windSpeed;
    double ratedPower;

    const double cutInSpeed = 3.0;   // m/s
    const double ratedSpeed = 12.0;  // m/s
    const double cutOutSpeed = 25.0; // m/s

public:
    WindTurbineControlSystem(double speed, double power) {
        windSpeed = speed;
        ratedPower = power;
    }

    double calculatePower() {
        if (windSpeed < cutInSpeed || windSpeed >= cutOutSpeed) {
            return 0.0;
        }

        if (windSpeed >= ratedSpeed) {
            return ratedPower;
        }

        // Simplified cubic power curve
        double ratio = windSpeed / ratedSpeed;
        return ratedPower * ratio * ratio * ratio;
    }

    string getStatus() {
        if (windSpeed < 0) {
            return "INVALID WIND SPEED";
        } else if (windSpeed < cutInSpeed) {
            return "STOPPED - WIND TOO LOW";
        } else if (windSpeed >= cutOutSpeed) {
            return "STOPPED - HIGH WIND SAFETY";
        } else if (windSpeed >= ratedSpeed) {
            return "RUNNING - RATED POWER";
        } else {
            return "RUNNING - GENERATING POWER";
        }
    }

    void displayResult() {
        double power = calculatePower();

        cout << "\n----- Wind Turbine Control System -----\n";
        cout << fixed << setprecision(2);
        cout << "Wind Speed       : " << windSpeed << " m/s\n";
        cout << "Rated Power      : " << ratedPower << " kW\n";
        cout << "Cut-in Speed     : " << cutInSpeed << " m/s\n";
        cout << "Rated Speed      : " << ratedSpeed << " m/s\n";
        cout << "Cut-out Speed    : " << cutOutSpeed << " m/s\n";
        cout << "Generated Power  : " << power << " kW\n";
        cout << "Turbine Status   : " << getStatus() << "\n";
    }
};

int main() {
    double windSpeed;
    double ratedPower;

    cout << "Enter wind speed (m/s): ";
    cin >> windSpeed;

    cout << "Enter turbine rated power (kW): ";
    cin >> ratedPower;

    if (windSpeed < 0 || ratedPower <= 0) {
        cout << "Invalid input. Values must be positive.\n";
        return 1;
    }

    WindTurbineControlSystem turbine(windSpeed, ratedPower);
    turbine.displayResult();

    return 0;
}

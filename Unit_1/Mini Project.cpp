#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Device {
private:
    string deviceId;
    string location;
    string status;
    string lastUpdated;

public:
    Device(string id, string loc, string stat, string time)
        : deviceId(id), location(loc), status(stat), lastUpdated(time) {}

    void switchOn(string time) {
        status = "ON";
        lastUpdated = time;
    }

    void switchOff(string time) {
        status = "OFF";
        lastUpdated = time;
    }

    void display() const {
        cout << "Device ID: " << deviceId
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated << endl;
    }
};

int main() {
    vector<Device> devices;

    devices.emplace_back("D001", "Living Room", "OFF", "08:00");
    devices.emplace_back("D002", "Bedroom", "ON", "08:05");
    devices.emplace_back("D003", "Main Door", "OFF", "08:10");
    devices.emplace_back("D004", "Kitchen", "ON", "08:15");

    cout << "=== Smart Home Dashboard ===" << endl;

    for (const auto& device : devices) {
        device.display();
    }

    return 0;
}

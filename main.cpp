#include <iostream>
#include <vector>

class Location {
    private:
    std::string address;
    double latitude;
    double longitude;
    public:
    Location(std::string address, double latitude, double longitude)
        : address(address), latitude(latitude), longitude(longitude) {}
    Location(double latitude, double longitude)
        : address("Unknown"), latitude(latitude), longitude(longitude) {}

    void display() const {
        std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
    }
};

int main() {
    bool programRunning = true;
    std::vector<Location> badmintonCourts = {
        Location("Persiaran Multimedia, 63100 Cyberjaya, Selangor",2.9272342240047107, 101.64309256580782), // MMU Court
        Location("Lot 5225, 4, Jalan Puchong Utama 7e, Taman Puchong Utama, 47100 Puchong, Selangor", 2.989928867751879, 101.61626328392457),  // KSL Court Puchong
        Location("64959, Jalan CJ 15, Kawasan Perindustrian Cheras Jaya, 43200 Seri Kembangan, Selangor", 3.020870690407236, 101.76515845343319),    // Cheras Court
        Location("Sunsuria Avenue, Persiaran Mohagani, Kota Damansara, 47810 Petaling Jaya, Selangor", 3.1573298623475234, 101.59005806349877), // Kota Damansara Court
        Location("Jalan Makmur, Kawasan Perusahaan Sesama, 68100 Batu Caves, Selangor", 3.240364703242958, 101.70037518774967), // Batu Cave Court
        Location("Lot 965 kg sri delima Jalan kuching pekan, 52000 Kuala Lumpur, Wilayah Persekutuan Kuala Lumpur", 3.2037377358676444, 101.66802981330616), // Sri Delima Court
        Location("Lot 1617, Jalan Genting Kelang, Taman Danau Kota, 53100 Kuala Lumpur, Wilayah Persekutuan Kuala Lumpur", 3.203099333012631, 101.71846148664879), // Danau Kota Court
        Location("Level 5, Mines 2, Jalan Mines 2, Mines Wellness City, 43300 Seri Kembangan, Selangor", 3.028749587275076, 101.71527007859078) // Mines Court
    };
    while (programRunning) {
        double lat, lon;
        std::cout << "Enter latitude and longitude (or 'q' to quit): ";
        std::cin >> lat >> lon;

        if(std::cin.fail()) { // if non-numeric input is given 
            programRunning = false;
            break;
        }

        Location loc(lat, lon);
        loc.display();
    }
    return 0;
}
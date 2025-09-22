#include <iostream>
#include <vector>
#include <cmath>

class Location {
    private:
    std::string address;
    double latitude;
    double longitude;
    public:
    Location() : address("Unknown"), latitude(0.0), longitude(0.0) {}
    Location(std::string address, double latitude, double longitude)
        : address(address), latitude(latitude), longitude(longitude) {}
    Location(double latitude, double longitude)
        : address("Unknown"), latitude(latitude), longitude(longitude) {}

    std::string getAddress() const { return address; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    void display() const {
        std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
    }
};

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}

// Function to calculate the distance between two points using the Haversine formula
double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double EARTH_RADIUS_KM = 6371.0;

    // Convert latitudes and longitudes from degrees to radians
    double radLat1 = toRadians(lat1);
    double radLon1 = toRadians(lon1);
    double radLat2 = toRadians(lat2);
    double radLon2 = toRadians(lon2);

    // Calculate the difference in latitudes and longitudes
    double dLat = radLat2 - radLat1;
    double dLon = radLon2 - radLon1;

    // Apply the Haversine formula
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(radLat1) * cos(radLat2) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS_KM * c;

    return distance;
}




int main() {
    bool programRunning = true;

    // Can integrate with Google Maps API to fetch real-time data in the future
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
        Location nearestCourt;
        double minDistance = std::numeric_limits<double>::max();
        std::cout << "Enter latitude and longitude (or 'q' to quit): ";
        std::cin >> lat >> lon;

        if(std::cin.fail()) { // if non-numeric input is given 
            programRunning = false;
            break;
        }

        std::cout << std::endl;

        for (const Location& court : badmintonCourts) {
            double distance = haversine(lat, lon, court.getLatitude(), court.getLongitude());
            std::cout << "Distance to court "<< court.getAddress() <<" : " << distance << " km" << std::endl;
            if (distance < minDistance) {
                minDistance = distance;
                nearestCourt = court;
            }
        }
        std::cout << "\nNearest court is at: " << nearestCourt.getAddress() << " which is " << minDistance << " km away." << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }
    return 0;
}
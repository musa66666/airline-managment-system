#include<iostream>
#include<string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include<fstream>
#include<sstream>
#include<conio.h>
using namespace std;
int numofairport = 10;
bool isAdminLoggedIn = false;
bool search_passenger(const string& username, const string& password) {
    ifstream infile("passenger_data.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            size_t pos = line.find(',');
            string stored_username = line.substr(0, pos);
            string stored_password = line.substr(pos + 1);

            if (stored_username == username && stored_password == password) {
                infile.close();
                return true;  // User found
            }
        }
        infile.close();
    }
    return false;  // User not found
}

bool isValidPassword(string password)
{
    if (password.length() < 8) {
        return false;
    }
    bool hasSpecialChar = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    for (char c : password) {
        if (ispunct(c)) {
            hasSpecialChar = true;
        }
        else if (isupper(c)) {
            hasUpper = true;
        }
        else if (islower(c)) {
            hasLower = true;
        }
        else if (isdigit(c)) {
            hasDigit = true;
        }
    }

    return hasSpecialChar && hasUpper && hasLower && hasDigit;
}
class Flight {
private:
    string flightNumber;
    float departureTime;
    float arrivalTime;
    int availableSeats;
    float ticketPrice;
    bool isInternational;
    string arrivalplace;
    string departureplace;
    string departureairportname;
    string arrivalairport;
public:
    Flight() {
        flightNumber = "";
        departureTime = 0;
        arrivalTime = 0;
        availableSeats = 0;
        ticketPrice = 0;
        isInternational = false;
        arrivalplace = "";
        departureplace = "";
        arrivalairport = "";
        departureairportname = "";
    }

    Flight(string flightNumber, float departureTime, float arrivalTime, bool isInternational, float ticketPrice, string arrivalplace, string departureplace, string departureairportname, string arrivalairport) {
        this->flightNumber = flightNumber;
        this->departureTime = departureTime;
        this->arrivalTime = arrivalTime;
        this->isInternational = isInternational;
        this->ticketPrice = ticketPrice;
        this->arrivalplace = arrivalplace;
        this->departureplace = departureplace;
        this->departureairportname = departureairportname;
        this->arrivalairport = arrivalairport;
        availableSeats = 0;
    }



    float getDepartureTime() {
        return departureTime;
    }

    void setDepartureTime(float departureTime) {
        this->departureTime = departureTime;
    }

    float getArrivalTime() {
        return arrivalTime;
    }

    void setArrivalTime(float arrivalTime) {
        this->arrivalTime = arrivalTime;
    }

    int getAvailableSeats() {
        return availableSeats;
    }

    void setAvailableSeats(int availableSeats) {
        this->availableSeats = availableSeats;
    }

    float getTicketPrice() {
        return ticketPrice;
    }

    void setTicketPrice(float ticketPrice) {
        this->ticketPrice = ticketPrice;
    }

    bool getIsInternational() {
        return isInternational;
    }

    void setIsInternational(bool isInternational) {
        this->isInternational = isInternational;
    }

    int gethours()
    {

        return (this->departureTime - this->arrivalTime);

    }

    void setarrivalplace(string s)
    {
        this->arrivalplace = s;
    }
    string getarrivalplace()
    {
        return this->arrivalplace;
    }
    void setdepartureplace(string a)
    {
        this->departureplace = a;
    }
    string getdepartureplace()
    {
        return this->departureplace;
    }
    void setflightnumber(string s)
    {
        this->flightNumber = s;
    }
    string  getFlightNumber() {



        return this->flightNumber;

    }
    void setarrivalairport1(string s)
    {
        this->arrivalairport = s;
    }
    string getarrivalairport()
    {
        return this->arrivalairport;
    }
    void setdepartureairport(string s)
    {
        departureairportname = s;
    }
    string getdepatureairport()
    {
        return this->departureairportname;
    }
};
class cities
{
private:
    string name;
public:
    void setname(string s)
    {
        this->name = s;


    }
    string getname()
    {
        return this->name;
    }

};


class passenger
{
private:
    string username;
    string password;
    string cnic;
    string firstName;
    string lastName;
    string email;
    string phoneNumber;



public:
    passenger()
    {
        username = "";
        password = "";
        cnic = "";
        firstName = "";
        lastName = "";
        email = "";
        phoneNumber = "";

    }
    passenger(string s, string k, string c, string f, string l, string e, string m)
    {
        username = s;
        password = k;
        cnic = c;
        firstName = f;
        lastName = l;
        email = e;
        phoneNumber = m;

    }

    void set_username(string s)
    {
        username = s;
    }

    void set_password(string p)
    {
        password = p;
    }

    string get_username()
    {
        return this->username;
    }

    string get_password_asterisk() {
        string password_asterisk(password.length(), '*');
        return password_asterisk;
    }

    void set_cnic(string c)
    {
        cnic = c;
    }

    string get_cnic()
    {
        return this->cnic;
    }

    void set_first_name(string n)
    {
        this->firstName = n;
    }

    string get_first_name()
    {
        return this->firstName;
    }

    void set_last_name(string l)
    {
        this->lastName = l;
    }

    void set_phone_number(string l)
    {
        this->phoneNumber = l;
    }

    string get_phone_number()
    {
        return this->phoneNumber;
    }

    void set_email(string a)
    {
        this->email = a;
    }

    string get_email()
    {
        return this->email;
    }
    string getlastname()
    {
        return this->lastName;
    }
};
class Admin {
private:
    string username;
    string password;
    //string role;
    Flight* f;
public:
    Admin() {
        this->username = "";
        this->password = "";
    }
    Admin(string username, string password) {
        this->username = username;
        this->password = password;

    }
    void setpassword(string pass)
    {
        this->password = pass;

    }
    string getpassword()
    {
        return this->password;
    }
    void setusername(string s)
    {
        this->username = s;
    }
    string getusername()
    {
        return this->username;
    }
    void addflight(Flight* f, int num) {
        for (int i = 0; i < num; i++) {
            string flightNumber; float arrivalTime, departureTime; string arrivalPlace;string  arrivalAirport;
            int availableSeats, ticketPrice;
            bool isInternational;

            // Input flight details
            cout << "Enter Flight Number: ";
            cin >> flightNumber;
            cout << "Enter Arrival Time: ";
            cin >> arrivalTime;
            cout << "Enter Departure Time: ";
            cin >> departureTime;
            cout << "Enter Arrival Place: ";
            cin >> arrivalPlace;
            cout << "Enter Arrival Airport: ";
            cin >> arrivalAirport;
            cout << "Enter Available Seats: ";
            cin >> availableSeats;
            cout << "Enter Ticket Price: ";
            cin >> ticketPrice;
            cout << "Is International (1 for Yes, 0 for No): ";
            cin >> isInternational;

            // Set flight details in the Flight object
            f[i].setflightnumber(flightNumber);
            f[i].setArrivalTime(arrivalTime);
            f[i].setDepartureTime(departureTime);
            f[i].setarrivalplace(arrivalPlace);
            f[i].setarrivalairport1(arrivalAirport);
            f[i].setAvailableSeats(availableSeats);
            f[i].setTicketPrice(ticketPrice);
            f[i].setIsInternational(isInternational);
        }
    }

};

class login_and_registration {
private:
    int num_passengers;
    passenger* passengers_arr;
    Admin* a;
    int num_admin;

public:
    login_and_registration() {
        num_passengers = 0;
        passengers_arr = nullptr;
        a = nullptr;
        num_admin = 0;

    }
    void adminlogin()
    {
        string adminpass;
        string adminid;
        a = new Admin[num_admin + 1];
        std::cout << "Enter admin id :" << endl;
        getline(cin, adminpass);
        std::cout << "Enter admin pass :" << endl;
        getline(cin, adminid);
        if (adminpass == "admin12" && adminid == "admin123")
        {
            cout << "correct password entered" << endl;
        }
        else

        {
            cout << "You have entered wrong password" << endl;
        }
       
        Admin* a = new Admin(adminpass, adminid);
        num_admin++;
        cout << "Congratulations! admin login" << endl;
        isAdminLoggedIn = true;

    }
    void adminlogout()
    {
        isAdminLoggedIn = false;
    }

    void register_new_passenger(passenger* p) {
        bool exists = false;
        // Check if username already exists in file
        ifstream infile("passenger_data.txt");
        if (infile.is_open()) {
            string line;
            while (getline(infile, line)) {
                size_t pos = line.find(",");
                string username = line.substr(0, pos);
                if (username == p->get_username()) {
                    cout << "User already exists." << endl;
                    exists = true;
                    break;
                }
            }
            infile.close();
        }
        else {
            cout << "user does not exists in file" << endl;
        }

        if (!exists) {
            passenger* temp = new passenger[num_passengers + 1];
            for (int i = 0; i < num_passengers; i++) {
                temp[i] = passengers_arr[i];
            }
            temp[num_passengers] = *p;
            delete[] passengers_arr;
            passengers_arr = temp;
            num_passengers++;

            // Write passenger data to file
            ofstream outfile("passenger_data.txt", ios::app);
            if (outfile.is_open()) {
                outfile << p->get_username() << "," << p->get_password_asterisk() << "," << p->get_cnic() << "," << p->get_email() << "," << p->get_phone_number() << "," << p->get_first_name() << "," << p->getlastname() << endl;
                outfile.close();
                cout << "Registration successful." << endl;
            }
            else {
                cout << "Error: Unable to open file for writing." << endl;
            }
        }
    }
    void login_passenger() {
        string username, password;
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);

        if (search_passenger(username, password)) {
            cout << "Login successful." << endl;
            // Perform actions for logged-in passenger
        }
        else {
            cout << "Invalid username or password." << endl;
        }
    }
    void reset_passwords() {
        string username;
        cout << "Enter username: ";
        getline(cin, username);

        // Search for the passenger with the specified username
        int passengerIndex = -1;
        for (int i = 0; i < num_passengers; i++) {
            if (passengers_arr[i].get_username() == username) {
                passengerIndex = i;
                break;
            }
        }

        if (passengerIndex != -1) {
            string new_password;
            do {
                cout << "Enter new password (must be 8 characters long and contain at least one special character, one uppercase letter, one lowercase letter, and one numeric digit): ";
                getline(cin, new_password);
            } while (!isValidPassword(new_password));

            passengers_arr[passengerIndex].set_password(new_password);
            cout << "Password reset successful." << endl;

            // Update passenger data in the file
            ofstream outfile("passenger_data.txt");
            if (outfile.is_open()) {
                for (int i = 0; i < num_passengers; i++) {
                    outfile << passengers_arr[i].get_username() << "," << passengers_arr[i].get_password_asterisk() << endl;
                }
                outfile.close();
            }
            else {
                cout << "Error: Unable to open file for writing." << endl;
            }
        }
        else {
            cout << "Invalid username." << endl;
        }
    }

    ~login_and_registration() {
        delete[] passengers_arr;
    }
};



class Airport {
private:
    string airportname;
    string location;
    int capacity;
    int numPlanes;
    int numLandingSlots;
    int localFlightsPerAirport;
    int internationalFlightsPerAirport;
    int numofpassengers;
public:
    Airport() {
        this->airportname = "";
        this->location = "";
        this->capacity = 5;
        this->numPlanes = 5;
        this->numLandingSlots = 5;
        this->localFlightsPerAirport = 10;
        this->internationalFlightsPerAirport = 5;
    }
    Airport(string name, string location) {
        this->airportname = name;
        this->location = location;
        this->capacity = 10;
        this->numPlanes = 5;
        this->numLandingSlots = 5;
        this->localFlightsPerAirport = 10;
        this->internationalFlightsPerAirport = 5;
    }
    void setName(string name) {
        this->airportname = name;
    }
    string getName() {
        return this->airportname;
    }
    void setLocation(string location) {
        this->location = location;
    }
    string getLocation() {
        return this->location;
    }
    void setCapacity(int capacity) {
        this->capacity = capacity;
    }
    int getCapacity() {
        return this->capacity;
    }
    void setNumPlanes(int numPlanes) {
        this->numPlanes = numPlanes;
    }
    int getNumPlanes() {
        return this->numPlanes;
    }
    void setNumLandingSlots(int numLandingSlots) {
        this->numLandingSlots = numLandingSlots;
    }
    int getNumLandingSlots() {
        return this->numLandingSlots;
    }

};

class Finance {
private:
    float ticketPrice;
    string paymentDetails;
    bool verified;
public:
    Finance() {
        ticketPrice = 0.0;
        paymentDetails = "";
        verified = false;
    }

    void setTicketPrice(float price) {
        ticketPrice = price;
    }

    float getTicketPrice() {
        return ticketPrice;
    }

    void setPaymentDetails(string details) {
        paymentDetails = details;
    }

    string getPaymentDetails() {
        return paymentDetails;
    }

    void setVerified(bool status) {
        verified = status;
    }

    bool isVerified() {
        return verified;
    }

    float calculateTicketPrice(Flight flight, int numPassengers) {
        float price = flight.getTicketPrice() * numPassengers;
        return price;
    }

    bool verifyPayment(string creditCardNumber, string cvv, string expirationDate) {

        return true;
    }
};
class flight_disposals {
private:
    int num_flights;
    Flight* f;
public:
    flight_disposals() {
        num_flights = 0;
        f = nullptr;
    }

    void addflight(Flight* flights, int num) {
        num_flights = 7;
        f = flights;

    }
    void display_flights() {
        for (int i = 0; i < num_flights; i++) {
            cout << "Arrival Time: " << f[i].getArrivalTime() << endl;
            cout << "Departure Time: " << f[i].getDepartureTime() << endl;
            cout << "Available Seats: " << f[i].getAvailableSeats() << endl;
            cout << "Flight Number: " << f[i].getFlightNumber() << endl;
            cout << "Hours: " << f[i].gethours() << endl; // Uncomment if 'hours' variable is defined in the Flight class
            cout << "Is International: " << (f[i].getIsInternational() ? "Yes" : "No") << endl;
            cout << "Ticket Price: " << f[i].getTicketPrice() << endl;
            cout << "Flight  arrival Airport :" << f[i].getarrivalairport() << endl;
            cout << "Flight departure Airport :" << f[i].getdepatureairport() << endl;
            cout << "Flight departure country :" << f[i].getdepartureplace() << endl;
            cout << "Flight arrival country :" << f[i].getarrivalplace() << endl;
            cout << endl;
        }
    }
    void store_data_in_file(Flight* f) {
        ofstream outfile("Flight.txt");
        if (outfile.is_open()) {
            for (int i = 0; i < num_flights; i++) {
                outfile << "Arrival Time: " << f[i].getArrivalTime() << endl;
                outfile << "Departure Time: " << f[i].getDepartureTime() << endl;
                outfile << "Available Seats: " << f[i].getAvailableSeats() << endl;
                outfile << "Flight Number: " << f[i].getFlightNumber() << endl;
                // outfile << "Hours: " << f[i].getHours() << endl; // Uncomment if 'hours' variable is defined in the Flight class
                outfile << "Is International: " << (f[i].getIsInternational() ? "Yes" : "No") << endl;
                outfile << "Ticket Price: " << f[i].getTicketPrice() << endl;
                outfile << endl;
            }
            outfile.close();
            cout << "Data stored in file: " << "Flights" << endl;
        }
        else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
    Flight* getFlightByNumber(string flightNumber) {
        for (int i = 0; i < num_flights; i++) {
            if (f[i].getFlightNumber() == flightNumber) {
                return &f[i];
            }
        }
        return nullptr;
    }
    Flight* d() {

        return f;
    }
    int getflight()
    {
        return this->num_flights;
    }
};


/*class Plane
{
private:
    int num_plane;
    string planename;
    int passengerGap;
    int num_of_seats;
    Plane* p;
public:
    Plane()
    {
        this->num_of_seats = 60;
        this->num_plane = 0;
    }
    void setnumOfplane(int a)
    {
        this->num_of_seats = a;
    }
    int getnumofplane()
    {
        return this->num_plane;
    }
    void setnumofseats(int n)
    {
        this->num_of_seats = n;
    }
    void setnanmeofplane(string s)
    {
        this->planename= s;
    }
    string getnameof()
    {
        return this->planename;
    }

};*/
class AirportManagement {
private:
    int numofairport;
    Airport* a;

public:
    // Default constructor
    AirportManagement() {
        numofairport = 10;
        a = new Airport[numofairport];
        a[0].setLocation("Karachi South");
        a[0].setName("Karachi");
        a[0].setNumLandingSlots(5);
        a[0].setNumPlanes(5);

        a[1].setLocation("Karachi North");
        a[1].setName("Karachi");
        a[1].setNumLandingSlots(5);
        a[1].setNumPlanes(5);

        a[2].setLocation("Islamabad South");
        a[2].setName("Islamabad");
        a[2].setNumLandingSlots(5);
        a[2].setNumPlanes(5);

        a[3].setLocation("Islamabad North");
        a[3].setName("Islamabad");
        a[3].setNumLandingSlots(5);
        a[3].setNumPlanes(5);

        a[4].setLocation("Peshawar South");
        a[4].setName("Peshawar");
        a[4].setNumLandingSlots(5);
        a[4].setNumPlanes(5);

        a[5].setLocation("Peshawar North");
        a[5].setName("Peshawar");
        a[5].setNumLandingSlots(5);
        a[5].setNumPlanes(5);

        a[6].setLocation("Lahore South");
        a[6].setName("Lahore");
        a[6].setNumLandingSlots(5);
        a[6].setNumPlanes(5);

        a[7].setLocation("Lahore North");
        a[7].setName("Lahore");
        a[7].setNumLandingSlots(5);
        a[7].setNumPlanes(5);

        a[8].setLocation("Quetta South");
        a[8].setName("Quetta");
        a[8].setNumLandingSlots(5);
        a[8].setNumPlanes(5);

        a[9].setLocation("Quetta North");
        a[9].setName("Quetta");
        a[9].setNumLandingSlots(5);
        a[9].setNumPlanes(5);


    }

    // Parameterized constructor
    AirportManagement(int size) {
        numofairport = size;
        a = new Airport[numofairport];

        for (int i = 0; i < numofairport; i++) {
            a[i].setLocation("Default Location");
            a[i].setName("Default Name");
            a[i].setNumLandingSlots(0);
            a[i].setNumPlanes(0);
        }
    }
    void modifyFlight(int index) {
        if (index >= 0 && index < numofairport) {
            // Prompt the user to modify flight details
            // You can use cin or any other input method to get the new values
            string location, name;
            int numLandingSlots, numPlanes;

            cout << "Enter new location: ";
            cin >> location;
            a[index].setLocation(location);

            cout << "Enter new name: ";
            cin >> name;
            a[index].setName(name);

            cout << "Enter new number of landing slots: ";
            cin >> numLandingSlots;
            a[index].setNumLandingSlots(numLandingSlots);

            cout << "Enter new number of planes: ";
            cin >> numPlanes;
            a[index].setNumPlanes(numPlanes);
        }
        else {
            cout << "Invalid flight index!" << endl;
        }
    }

    Airport* getAirports() {
        return a;
    }

    int getNumOfAirports() {
        return numofairport;
    }
};

class Country {
private:
    string name;
    int numofcounties;

public:
    Country() {
        name = "";
        numofcounties = 0;


    }

    string getName() {
        return name;
    }

    void setname(string s) {
        this->name = s;
    }


};
class booking {
private:
   Flight f;
public:
    void bookFlight(Flight* flightData, int numFlights, Country* C, cities* v) {
        char choice;
        cout << "Do you want to book this flight? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            string destinationCountry;
            string destinationAirport;
            cout << "   WE ONLY OPERATE IN THESE   COUNTRIES" << endl;
            for (int i = 0; i < 25; i++)
            {
                cout << "   " << C[i].getName() << "   " << endl;
            }
            cout << "Enter the destination country: ";
            getline(cin, destinationCountry);
            cout << "Enter the destination airport: ";
            getline(cin, destinationAirport);
            bool countrymatch = false;
            for (int i = 0; i < 25; i++)
            {
                if (C[i].getName() == destinationCountry)
                {
                    countrymatch = true;
                    cout << "Destination country is among the countries in which NFAS works" << endl;
                }
            }
            if (countrymatch == false)
            {
                cout << "In this country NFAS dont operate" << endl;
                getline(cin, destinationCountry);

            }

            bool foundMatchingFlights = false;

            for (int i = 0; i < numFlights; i++) {
                if (flightData[i].getarrivalplace() == destinationCountry && flightData[i].getarrivalairport() == destinationAirport) {
                    foundMatchingFlights = true;
                    cout << "Flight Details:" << endl;
                    cout << "Flight Number: " << flightData[i].getFlightNumber() << endl;
                    cout << "Arrival Time: " << flightData[i].getArrivalTime() << endl;
                    cout << "Departure Time: " << flightData[i].getDepartureTime() << endl;
                    cout << "Available Seats: " << flightData[i].getAvailableSeats() << endl;
                    cout << "Ticket Price: " << flightData[i].getTicketPrice() << endl;
                    cout << endl;

                    char choice;
                    cout << "Do you want to book this flight? (Y/N): ";
                    cin >> choice;
                    {
                        int numPassengers;
                        cout << "Enter the number of passengers: ";
                        cin >> numPassengers;

                        // Perform the booking process here

                        // Example: Update the available seats
                        flightData[i].setAvailableSeats(flightData[i].getAvailableSeats() - numPassengers);

                        cout << "Flight booked successfully!" << endl;
                        cout << "Enjoy your trip!" << endl;
                    }
                }
            }

            if (!foundMatchingFlights) {
                cout << "No flights found matching the destination." << endl;
            }
        }
        else
        {
            bool b1 = false;
            cout << "WE OPERATE JUST IN THESE 5 CITIES FOR LOCAL FLIGHTS" << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << v[i].getname() << endl;


            }
            cout << "Enter arrival city" << endl;
            string city;
            getline(cin, city);
            cout << "Enter arrival city airport" << endl;
            string airport;
            getline(cin, airport);
            for (int i = 0; i < numFlights; i++) {
                if (flightData[i].getarrivalplace() == city && flightData[i].getarrivalairport() == airport)
                {
                    b1 = true;
                    cout << "Flight Details:" << endl;
                    cout << "Flight Number: " << flightData[i].getFlightNumber() << endl;
                    cout << "Arrival Time: " << flightData[i].getArrivalTime() << endl;
                    cout << "Departure Time: " << flightData[i].getDepartureTime() << endl;
                    cout << "Available Seats: " << flightData[i].getAvailableSeats() << endl;
                    cout << "Ticket Price: " << flightData[i].getTicketPrice() << endl;
                    cout << endl;
                }
            }
        }


    }
};
class Main
{
private:
    Flight* f ;
    int numofflights;
public:
    void adminlogin()
    {
        login_and_registration l;
        l.adminlogin();
        isAdminLoggedIn = true;
      
        cout << "Enter 1 perfrom admin tasks" << endl;
        cout << "Enter 2 to logout" << endl;
  }
    void passengerR()
    {
        login_and_registration k;
        string username;
        string password;
        string cnic;
        string firstName;
        string lastName;
        string email;
        string phoneNumber;
        char ch;

        cin.ignore(); // Ignore the newline character from previous input

        do {
            cout << "Enter first name: " << endl;
            getline(cin, firstName);
        } while (firstName.empty());

        // Validate last name
        do {
            cout << "Enter last name: " << endl;
            getline(cin, lastName);
        } while (lastName.empty());

        // Validate username
        do {
            cout << "Enter username: " << endl;
            getline(cin, username);
        } while (username.empty());

        // Validate CNIC
        do {
            cout << "Enter CNIC: " << endl;
            getline(cin, cnic);
        } while (cnic.empty() || cnic.length() != 13 || !isdigit(cnic[0]) || !isdigit(cnic[1]) || !isdigit(cnic[2]) || !isdigit(cnic[3]) || !isdigit(cnic[4]) || !isdigit(cnic[5]) || !isdigit(cnic[6]) || !isdigit(cnic[7]) || !isdigit(cnic[8]) || !isdigit(cnic[9]) || !isdigit(cnic[10]) || !isdigit(cnic[11]) || !isdigit(cnic[12]));

        // Validate password
        do {
            password = "";
            std::cout << "Enter password: ";

            while ((ch = _getch()) != 13) {
                if (ch == 8) {  // Backspace key
                    if (!password.empty()) {
                        password.pop_back();
                        std::cout << "\b \b";  // Erase the previous asterisk
                    }
                }
                else {
                    std::cout << '*';
                    password += ch;
                }
            }

            std::cout << std::endl;
        } while (!isValidPassword(password));

        cout << "Correct password is entered" << endl;
        do {
            cout << "Enter email: " << endl;
            getline(cin, email);
        } while (email.empty());

        // Validate phone number
        do {
            cout << "Enter phone number: " << endl;
            getline(cin, phoneNumber);
        } while (phoneNumber.empty());


        passenger* p = new passenger(username, password, cnic, firstName, lastName, email, phoneNumber);
        k.register_new_passenger(p);
        cout << "added successfully" << endl;
        cout << "now you can perfromm tasks" << endl;


    }
    void flightbooking()
    {

        flight_disposals flights;
        Flight* f = new Flight[7];

        f[0].setarrivalplace("America");
        f[0].setAvailableSeats(60);
        f[0].setIsInternational(true);
        f[0].setArrivalTime(12);
        f[0].setDepartureTime(1);
        f[0].setTicketPrice(1200);
        f[0].setdepartureplace("Pakistan");
        f[0].setflightnumber("F1000");
        f[0].setdepartureairport("Karachi(south)");
        f[0].setarrivalairport1("New york");



        f[1].setarrivalplace("Qatar");
        f[1].setAvailableSeats(60);
        f[1].setIsInternational(true);
        f[1].setArrivalTime(12);
        f[1].setDepartureTime(1);
        f[1].setTicketPrice(1200);
        f[1].setdepartureplace("Pakistan");
        f[1].setflightnumber("F1001");
        f[1].setdepartureairport("LAHORE(NORTH)");
        f[1].setarrivalairport1("DOHA");




        f[2].setarrivalplace("DUBAI");
        f[2].setAvailableSeats(60);
        f[2].setIsInternational(true);
        f[2].setArrivalTime(12);
        f[2].setDepartureTime(1);
        f[2].setTicketPrice(1200);
        f[2].setdepartureplace("Pakistan");
        f[2].setflightnumber("F2002");
        f[2].setdepartureairport("Karachi(south)");
        f[2].setarrivalairport1("New york");


        f[3].setarrivalplace("SAUDIA ARAB");
        f[3].setAvailableSeats(60);
        f[3].setIsInternational(true);
        f[3].setArrivalTime(12);
        f[3].setDepartureTime(1);
        f[3].setTicketPrice(300000);
        f[3].setdepartureplace("Pakistan");
        f[3].setflightnumber("F1003");
        f[3].setdepartureairport("LAHORE(NORTH)");
        f[3].setarrivalairport1("jaddah");


        f[4].setarrivalplace("JAPAN");
        f[4].setAvailableSeats(60);
        f[4].setIsInternational(true);
        f[4].setArrivalTime(12);
        f[4].setDepartureTime(1);
        f[4].setTicketPrice(1200);
        f[4].setdepartureplace("Pakistan");
        f[4].setflightnumber("F1004");
        f[4].setdepartureairport("LAHORE(SOUTH)");
        f[4].setarrivalairport1("jaddah");


        f[5].setarrivalplace("TURKEY");
        f[5].setAvailableSeats(60);
        f[5].setIsInternational(true);
        f[5].setArrivalTime(12);
        f[5].setDepartureTime(1);
        f[5].setTicketPrice(1200);
        f[5].setdepartureplace("Pakistan");
        f[5].setflightnumber("F1005");
        f[5].setdepartureairport("Peshawar(south)");
        f[5].setarrivalairport1("Istambul");

        f[6].setarrivalplace("Karachi");
        f[6].setAvailableSeats(60);
        f[6].setIsInternational(false);
        f[6].setArrivalTime(4);
        f[6].setDepartureTime(5);
        f[6].setTicketPrice(1200);
        f[6].setdepartureplace("Peshawar");
        f[6].setflightnumber("F1006");
        f[6].setdepartureairport("Peshawar(south)");
        f[6].setarrivalairport1("Karachi(South)");
        flights.addflight(f, 7);

        cout << "Flight added" << endl;
        flights.display_flights();
        flights.store_data_in_file(f);
    }
    void booking1()
    {
        flight_disposals flights;
        Flight* f = new Flight[7];

        f[0].setarrivalplace("America");
        f[0].setAvailableSeats(60);
        f[0].setIsInternational(true);
        f[0].setArrivalTime(12);
        f[0].setDepartureTime(1);
        f[0].setTicketPrice(1200);
        f[0].setdepartureplace("Pakistan");
        f[0].setflightnumber("F1000");
        f[0].setdepartureairport("Karachi(south)");
        f[0].setarrivalairport1("New york");



        f[1].setarrivalplace("Qatar");
        f[1].setAvailableSeats(60);
        f[1].setIsInternational(true);
        f[1].setArrivalTime(12);
        f[1].setDepartureTime(1);
        f[1].setTicketPrice(1200);
        f[1].setdepartureplace("Pakistan");
        f[1].setflightnumber("F1001");
        f[1].setdepartureairport("LAHORE(NORTH)");
        f[1].setarrivalairport1("DOHA");




        f[2].setarrivalplace("DUBAI");
        f[2].setAvailableSeats(60);
        f[2].setIsInternational(true);
        f[2].setArrivalTime(12);
        f[2].setDepartureTime(1);
        f[2].setTicketPrice(1200);
        f[2].setdepartureplace("Pakistan");
        f[2].setflightnumber("F2002");
        f[2].setdepartureairport("Karachi(south)");
        f[2].setarrivalairport1("New york");


        f[3].setarrivalplace("SAUDIA ARAB");
        f[3].setAvailableSeats(60);
        f[3].setIsInternational(true);
        f[3].setArrivalTime(12);
        f[3].setDepartureTime(1);
        f[3].setTicketPrice(300000);
        f[3].setdepartureplace("Pakistan");
        f[3].setflightnumber("F1003");
        f[3].setdepartureairport("LAHORE(NORTH)");
        f[3].setarrivalairport1("jaddah");


        f[4].setarrivalplace("JAPAN");
        f[4].setAvailableSeats(60);
        f[4].setIsInternational(true);
        f[4].setArrivalTime(12);
        f[4].setDepartureTime(1);
        f[4].setTicketPrice(1200);
        f[4].setdepartureplace("Pakistan");
        f[4].setflightnumber("F1004");
        f[4].setdepartureairport("LAHORE(SOUTH)");
        f[4].setarrivalairport1("jaddah");


        f[5].setarrivalplace("TURKEY");
        f[5].setAvailableSeats(60);
        f[5].setIsInternational(true);
        f[5].setArrivalTime(12);
        f[5].setDepartureTime(1);
        f[5].setTicketPrice(1200);
        f[5].setdepartureplace("Pakistan");
        f[5].setflightnumber("F1005");
        f[5].setdepartureairport("Peshawar(south)");
        f[5].setarrivalairport1("Istambul");

        f[6].setarrivalplace("Karachi");
        f[6].setAvailableSeats(60);
        f[6].setIsInternational(false);
        f[6].setArrivalTime(4);
        f[6].setDepartureTime(5);
        f[6].setTicketPrice(1200);
        f[6].setdepartureplace("Peshawar");
        f[6].setflightnumber("F1006");
        f[6].setdepartureairport("Peshawar(south)");
        f[6].setarrivalairport1("Karachi(South)");
        cout << "flight added" << endl;
        flights.display_flights();
        flights.store_data_in_file(f);
        const int ARRAY_SIZE = 5;
        cities* b = new cities[ARRAY_SIZE];
        string la = "Cities.txt"; // Replace with the actual file name
        ifstream m(la);
        if (m.is_open()) {
            string ca;
            int index = 0;

            if (getline(m, ca)) {
                stringstream ss(ca);
                string countryName;

                while (getline(ss, ca, ',')) {
                    b[index].setname(ca);
                    index++;

                    if (index >= 5) {
                        break;
                    }
                }
            }

            m.close();


        }
        else {
            cout << "Failed to open file: " << la << endl;
        }
        const int MAX_COUNTRIES = 25;
        Country* c = new Country[MAX_COUNTRIES];  // Object array to store country objects

        // Read country names from file
        string filename = "countries.txt"; // Replace with the actual file name
        ifstream file(filename);
        if (file.is_open()) {
            string countryNames;
            int index = 0;

            if (getline(file, countryNames)) {
                stringstream ss(countryNames);
                string countryName;

                while (getline(ss, countryName, ',')) {
                    c[index].setname(countryName);
                    index++;

                    if (index >= MAX_COUNTRIES) {
                        break;
                    }
                }
            }

            file.close();
        }


        Flight* flightData = flights.d();

        int numFlights = flights.getflight();

        booking book;
        book.bookFlight(flightData, numFlights, c, b);
        flights.display_flights();
        flights.store_data_in_file(flightData);



    }


};



int main() {
    Main m;
    int choice;


    do {
        cout << "Welocome to NFAS" << endl;
        cout << "====== Main Menu ======" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Booking" << endl;
        cout << "3. Flight adding" << endl;
        cout << "4. Passenger Registration" << endl;
        cout << "5. Exit" << endl;
        cout << "=======================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                m.adminlogin();
                break;
            case 2:
                m.booking1();
                break;
            case 3:
                m.flightbooking();
                break;
            case 4:
                m.passengerR();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            case 6:
                
                flight_disposals flights;
                Flight* flightData = flights.d();

                int numFlights = flights.getflight();
                Admin* A;
                int num;
                cin >> num;
                A->addflight(flightData, num);
                    break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}

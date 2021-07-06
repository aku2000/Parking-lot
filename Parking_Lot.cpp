#include<bits/stdc++.h>
using namespace std;
class ParkingFloor;
class ParkingSpot;
class ParkingDisplayBoard;
class CustomerInfoPanel;
class EntrancePanel;
class ExitPanel;
class Vehicle;
// Following is the skeleton code for our parking lot system:
// Enums and Constants: Here are the required enums, data types, and constants:
enum class VehicleType
{
    CAR,
    TRUCK,
    ELECTRIC,
    VAN,
    MOTORBIKE
};
enum class ParkingSpotType
{
    HANDICAPPED,
    COMPACT,
    LARGE,
    MOTORBIKE,
    ELECTRIC
};

enum class AccountStatus
{
    ACTIVE,
    BLOCKED,
    BANNED,
    COMPROMISED,
    ARCHIVED,
    UNKNOWN
};

enum class ParkingTicketStatus
{
    ACTIVE,
    PAID,
    LOST
};

class Address
{
    private :
        string streetAddress;
        string city;
        string state;
        string zipCode;
        string country;
};

class Person
{
    private:
        string name;
        Address address;
        string email;
        string phone;
};

// Account, Admin, and ParkingAttendant : These classes represent various people that interact with our system:

// For simplicity, we are not defining getter and setter functions. The reader can
// assume that all class attributes are private and accessed through their respective
// public getter methods and modified only through their public methods function.

class Account
{
    private :
        string userName;
        string password;
        AccountStatus status;
        Person person;

    public:
        bool resetPassword();
};
class Admin : public Account
{
    public:
        bool addParkingFloor(ParkingFloor floor);
        bool addParkingSpot(string floorName, ParkingSpot spot);
        bool addParkingDisplayBoard(string floorName, ParkingDisplayBoard displayBoard);
        bool addCustomerInfoPanel(string floorName, CustomerInfoPanel infoPanel);

        bool addEntrancePanel(EntrancePanel entrancePanel);
        bool addExitPanel(ExitPanel exitPanel);
};

class ParkingAttendant : public Account
{
    public:
        bool processTicket(string TicketNumber);
};

//ParkingSpot: Here is the definition of ParkingSpot and all of its children classes:

class ParkingSpot {
    private: 
    string number;
    bool free;
    Vehicle vehicle;
    ParkingSpotType type;

    public: 
    bool IsFree();
    ParkingSpot(ParkingSpotType type) {
        this->type = type;
    }

    public:
    bool assignVehicle(Vehicle vehicle) {
        this->vehicle = vehicle;
        free = false;
    }

    public:
    bool removeVehicle() {
        this->vehicle = NULL;
        free = true;
    }
};

class HandicappedSpot : public ParkingSpot {
  public HandicappedSpot() {
    (ParkingSpotType.HANDICAPPED);
  }
};

class CompactSpot : public ParkingSpot {
  public CompactSpot() {
    (ParkingSpotType.COMPACT);
  }
};

class LargeSpot : public ParkingSpot {
  public LargeSpot() {
    (ParkingSpotType.LARGE);
  }
};

class MotorbikeSpot : public ParkingSpot {
  public MotorbikeSpot() {
    (ParkingSpotType.MOTORBIKE);
  }
};

class ElectricSpot : public ParkingSpot {
  public:
   ElectricSpot() {
    (ParkingSpotType.ELECTRIC);
  }
};

//Vehicle: Here is the definition for Vehicle and all of its child classes:

class Vehicle
{
    private:
        string licenseNumber;
          VehicleType type;
        ParkingTicket ticket;

    public:
        Vehicle(VehicleType type)
        {
            this->type = type;
        }

        void assignTicket(ParkingTicket ticket)
        {
            this->ticket = ticket;
        }
};

class Car : public Vehicle
{
    public:
        Car()
        {
            (VehicleType.CAR);
        }
};

class Van : public Vehicle
{
    public:
        Van()
        {
            (VehicleType.VAN);
        }
};

class Truck : public Vehicle
{
    public:
        Truck()
        {
            (VehicleType.TRUCK);
        }
};

// Similarly we can define classes for Motorcycle and Electric vehicles

//ParkingFloor: This class encapsulates a parking floor:
class ParkingFloor
{
    private:
        string name;
        unordered_map<string, HandicappedSpot> handicappedSpots;
        unordered_map<string, CompactSpot> compactSpots;
        unordered_map<string, LargeSpot> largeSpots;
        unordered_map<string, MotorbikeSpot> motorbikeSpots;
        unordered_map<string, ElectricSpot> electricSpots;
        unordered_map<string, CustomerInfoPortal> infoPortals;
        ParkingDisplayBoard displayBoard;

    public:
        ParkingFloor(string name)
        {
            this->name = name;
        }

    public:
        void addParkingSpot(ParkingSpot spot)
        {
            switch (spot.getType())
            {
            case ParkingSpotType.HANDICAPPED:
                handicappedSpots.put(spot.getNumber(), spot);
                break;
            case ParkingSpotType.COMPACT:
                compactSpots.put(spot.getNumber(), spot);
                break;
            case ParkingSpotType.LARGE:
                largeSpots.put(spot.getNumber(), spot);
                break;
            case ParkingSpotType.MOTORBIKE:
                motorbikeSpots.put(spot.getNumber(), spot);
                break;
            case ParkingSpotType.ELECTRIC:
                electricSpots.put(spot.getNumber(), spot);
                break;
            default:
                cout<<("Wrong parking spot type!");
            }
        }

    public:
        void assignVehicleToSpot(Vehicle vehicle, ParkingSpot spot)
        {
            spot.assignVehicle(vehicle);
            switch (spot.getType())
            {
            case ParkingSpotType.HANDICAPPED:
                updateDisplayBoardForHandicapped(spot);
                break;
            case ParkingSpotType.COMPACT:
                updateDisplayBoardForCompact(spot);
                break;
            case ParkingSpotType.LARGE:
                updateDisplayBoardForLarge(spot);
                break;
            case ParkingSpotType.MOTORBIKE:
                updateDisplayBoardForMotorbike(spot);
                break;
            case ParkingSpotType.ELECTRIC:
                updateDisplayBoardForElectric(spot);
                break;
            default:
                cout<<("Wrong parking spot type!");
            }
        }

    private:
        void updateDisplayBoardForHandicapped(ParkingSpot spot)
        {
            if (this->displayBoard.getHandicappedFreeSpot().getNumber() == spot.getNumber())
            {
                // find another free handicapped parking and assign to displayBoard
                for (string key : handicappedSpots.keySet())
                {
                    if (handicappedSpots.get(key).isFree())
                    {
                        this->displayBoard.setHandicappedFreeSpot(handicappedSpots.get(key));
                    }
                }
                this->displayBoard.showEmptySpotNumber();
            }
        }

    private:
        void updateDisplayBoardForCompact(ParkingSpot spot)
        {
            if (this->displayBoard.getCompactFreeSpot().getNumber() == spot.getNumber())
            {
                // find another free compact parking and assign to displayBoard
                for (string key : compactSpots.keySet())
                {
                    if (compactSpots.get(key).isFree())
                    {
                        this->displayBoard.setCompactFreeSpot(compactSpots.get(key));
                    }
                }
                this->displayBoard.showEmptySpotNumber();
            }
        }

    public:
        void freeSpot(ParkingSpot spot)
        {
            spot.removeVehicle();
            switch (spot.getType())
            {
            case ParkingSpotType.HANDICAPPED:
                freeHandicappedSpotCount++;
                break;
            case ParkingSpotType.COMPACT:
                freeCompactSpotCount++;
                break;
            case ParkingSpotType.LARGE:
                freeLargeSpotCount++;
                break;
            case ParkingSpotType.MOTORBIKE:
                freeMotorbikeSpotCount++;
                break;
            case ParkingSpotType.ELECTRIC:
                freeElectricSpotCount++;
                break;
            default:
                cout<<("Wrong parking spot type!");
            }
        }
};

//ParkingDisplayBoard: This class encapsulates a parking display board:
class ParkingDisplayBoard {
    private:
    string id;
    HandicappedSpot handicappedFreeSpot;
    CompactSpot compactFreeSpot;
    LargeSpot largeFreeSpot;
    MotorbikeSpot motorbikeFreeSpot;
    ElectricSpot electricFreeSpot;

    public: void showEmptySpotNumber() {
        string message = "";
        if(handicappedFreeSpot.IsFree()){
        message += "Free Handicapped: " + handicappedFreeSpot.getNumber();
        } else {
        message += "Handicapped is full";
        }
        message += System.lineSeparator();

        if(compactFreeSpot.IsFree()){
        message += "Free Compact: " + compactFreeSpot.getNumber();
        } else {
        message += "Compact is full";
        }
        message += System.lineSeparator();

        if(largeFreeSpot.IsFree()){
        message += "Free Large: " + largeFreeSpot.getNumber();
        } else {
        message += "Large is full";
        }
        message += System.lineSeparator();

        if(motorbikeFreeSpot.IsFree()){
        message += "Free Motorbike: " + motorbikeFreeSpot.getNumber();
        } else {
        message += "Motorbike is full";
        }
        message += System.lineSeparator();

        if(electricFreeSpot.IsFree()){
        message += "Free Electric: " + electricFreeSpot.getNumber();
        } else {
        message += "Electric is full";
        }

        Show(message);
    }
};

//ParkingLot: Our system will have only one object of this class. This can be enforced by using the Singleton pattern. In software engineering, the singleton pattern is a software design pattern that restricts the instantiation of a class to only one object.
class ParkingLot
{
    private:
        string name;
        Location address;
        ParkingRate parkingRate;

        int compactSpotCount;
        int largeSpotCount;
        int motorbikeSpotCount;
        int electricSpotCount;
          int maxCompactCount;
          int maxLargeCount;
          int maxMotorbikeCount;
          int maxElectricCount;

        unordered_map<string, EntrancePanel> entrancePanels;
        unordered_map<string, ExitPanel> exitPanels;
        unordered_map<string, ParkingFloor> parkingFloors;

        // all active parking tickets, identified by their ticketNumber
        unordered_map<string, ParkingTicket> activeTickets;

        // singleton ParkingLot to ensure only one object of ParkingLot in the system,
        // all entrance panels will use this object to create new parking ticket: getNewParkingTicket(),
        // similarly exit panels will also use this object to close parking tickets
    private:
        static ParkingLot parkingLot = NULL;

        // private constructor to restrict for singleton
    private:
        ParkingLot()
        {
            // 1. initialize variables: read name, address and parkingRate from database
            // 2. initialize parking floors: read the parking floor map from database,
            //  this map should tell how many parking spots are there on each floor. This
            //  should also initialize max spot counts too.
            // 3. initialize parking spot counts by reading all active tickets from database
            // 4. initialize entrance and exit panels: read from database
        }

        // static method to get the singleton instance of StockExchange
    public:
        static ParkingLot getInstance()
        {
            if (parkingLot == NULL)
            {
                parkingLot = new ParkingLot();
            }
            return parkingLot;
        }

        // note that the following method is 'synchronized' to allow multiple entrances
        // panels to issue a new parking ticket without interfering with each other
    public:
        synchronized ParkingTicket getNewParkingTicket(Vehicle vehicle) throws ParkingFullException
        {
            if (this->isFull(vehicle.getType()))
            {
                throw new ParkingFullException();
            }
            ParkingTicket ticket = new ParkingTicket();
            vehicle.assignTicket(ticket);
            ticket.saveInDB();
            // if the ticket is successfully saved in the database, we can increment the parking spot count
            this->incrementSpotCount(vehicle.getType());
            this->activeTickets.put(ticket.getTicketNumber(), ticket);
            return ticket;
        }

    public:
        bool isFull(VehicleType type)
        {
            // trucks and vans can only be parked in LargeSpot
            if (type == VehicleType.Truck || type == VehicleType.Van)
            {
                return largeSpotCount >= maxLargeCount;
            }

            // motorbikes can only be parked at motorbike spots
            if (type == VehicleType.Motorbike)
            {
                return motorbikeSpotCount >= maxMotorbikeCount;
            }

            // cars can be parked at compact or large spots
            if (type == VehicleType.Car)
            {
                return (compactSpotCount + largeSpotCount) >= (maxCompactCount + maxLargeCount);
            }

            // electric car can be parked at compact, large or electric spots
            return (compactSpotCount + largeSpotCount + electricSpotCount) >= (maxCompactCount + maxLargeCount + maxElectricCount);
        }

        // increment the parking spot count based on the vehicle type
    private:
        bool incrementSpotCount(VehicleType type)
        {
            if (type == VehicleType.Truck || type == VehicleType.Van)
            {
                largeSpotCount++;
            }
            else if (type == VehicleType.Motorbike)
            {
                motorbikeSpotCount++;
            }
            else if (type == VehicleType.Car)
            {
                if (compactSpotCount < maxCompactCount)
                {
                    compactSpotCount++;
                }
                else
                {
                    largeSpotCount++;
                }
            }
            else
            { // electric car
                if (electricSpotCount < maxElectricCount)
                {
                    electricSpotCount++;
                }
                else if (compactSpotCount < maxCompactCount)
                {
                    compactSpotCount++;
                }
                else
                {
                    largeSpotCount++;
                }
            }
        }

    public:
        bool isFull()
        {
            for (string key : parkingFloors.keySet())
            {
                if (!parkingFloors.get(key).isFull())
                {
                    return false;
                }
            }
            return true;
        }

    public:
        void addParkingFloor(ParkingFloor floor)
        {
        /* store in database */ }

    public:
        void addEntrancePanel(EntrancePanel entrancePanel)
        {
        /* store in database */ }

    public:
        void addExitPanel(ExitPanel exitPanel)
        {
        /* store in database */ }
};
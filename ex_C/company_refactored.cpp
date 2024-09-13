#include <string>
#include <vector>
using namespace std;

enum class EmployeeState
{
    Active,
    Suspended,
    Retired,
    Fired
};

class Company
{
private:
    string name;
    Address address;
    Date dateEstablished;
    vector<Employee> employees;
    vector<Customer> customers;

public:
    // getters, setters and more...
};

class Employee
{
private:
    Name name;
    Address address;
    Date birthday;
    EmployeeState state;

public:
    // getters, setters and more...
};

class Customer
{
private:
    Name name;
    Address address;
    string phone;

public:
    // getters, setters and more...
};

class Name
{
private:
    string firstName;
    string lastName;

public:
    // getters, setters and more...
};

class Address
{
private:
    string street;
    string city;
    string postalCode;
    string country;

public:
    // getters, setters and more...
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // getters, setters and more...
};

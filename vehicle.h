// File:        vehicle.h
// Author:      Geoffrey Tien
// Date:        2015-05-13
// Description: Declaration of a Vehicle class to be used for CMPT 225 assignment #1

#pragma once
#include <string>
using namespace std;

class Vehicle
{
    private:
        string licenseplate;
        string make;
        string model;
        string colour;
        
    public:
        // Default constructor
        Vehicle();
        
        // Parameterized constructor
        Vehicle(string plate, string vmake, string vmodel, string vcolour);
        
        // Destructor not required.
        // Class does not contain any member variables in dynamic memory
        
        // MUTATORS
        // Methods for updating vehicle's private fields
        // Update will only occur if parameter is not empty string
        // Returns true if update is successful, false otherwise.
        bool UpdatePlate(string plate);
        bool UpdateMake(string vmake);
        bool UpdateModel(string vmodel);
        bool UpdateColour(string vcolour);
        bool Update(string plate, string vmake, string vmodel, string vcolour);
        
        //ACCESSORS
        // Methods for retrieving vehicle information
        string GetPlate() const;
        string GetMake() const;
        string GetModel() const;
        string GetColour() const;
};
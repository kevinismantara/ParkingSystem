//
//  vehicle.cpp
//  Assignment 1
//
//  Created by Kevin Ismantara on 2015-05-21.
//  Copyright (c) 2015 Kevin Ismantara. All rights reserved.
//

#include <stdio.h>
#include "vehicle.h"
// File:        vehicle.cpp
// Author:      Geoffrey Tien
// Date:        2015-05-13
// Description: Implementation of a Vehicle class to be used for CMPT 225 assignment #1



// Default constructor
Vehicle::Vehicle()
{
    licenseplate = "";
    make = "";
    model = "";
    colour = "";
}

// Parameterized constructor
Vehicle::Vehicle(string plate, string vmake, string vmodel, string vcolour)
{
    licenseplate = plate;
    make = vmake;
    model = vmodel;
    colour = vcolour;
}

// MUTATORS
// Methods for updating vehicle's private fields
// Update will only occur if parameter is not empty string
// Returns true if update is successful, false otherwise.
bool Vehicle::UpdatePlate(string plate)
{
    if (plate != "")
    {
        licenseplate = plate;
        return true;
    }
    return false;
}

bool Vehicle::UpdateMake(string vmake)
{
    if (vmake != "")
    {
        make = vmake;
        return true;
    }
    return false;
}

bool Vehicle::UpdateModel(string vmodel)
{
    if (vmodel != "")
    {
        model = vmodel;
        return true;
    }
    return false;
}

bool Vehicle::UpdateColour(string vcolour)
{
    if (vcolour != "")
    {
        colour = vcolour;
        return true;
    }
    return false;
}

bool Vehicle::Update(string plate, string vmake, string vmodel, string vcolour)
{
    if (plate != "" && vmake != "" && vmodel != "" && vcolour != "")
    {
        licenseplate = plate;
        make = vmake;
        model = vmodel;
        colour = vcolour;
        return true;
    }
    return false;
}

//ACCESSORS
// Methods for retrieving vehicle information
string Vehicle::GetPlate() const
{
    return licenseplate;
}

string Vehicle::GetMake() const
{
    return make;
}

string Vehicle::GetModel() const
{
    return model;
}

string Vehicle::GetColour() const
{
    return colour;
}
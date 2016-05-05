//
//  vehicleregistry.cpp
//  Assignment 1
//
//  Created by Kevin Ismantara on 2015-05-18.
//  Copyright (c) 2015 Kevin Ismantara. All rights reserved.
//

#include <iostream>
#include <string>
#include "vehicleregistry.h"

VehicleRegistry::VehicleRegistry()
{
    vehicles = new Vehicle[4];
    numvehicles = 0;
    maxsize = 4;
}


void VehicleRegistry::CopyArray(const VehicleRegistry& vr)
{
    vehicles = new Vehicle[maxsize];
    for(int i=0; i<maxsize; i++){
        vehicles[i] = vr.vehicles[i];
    }
}


VehicleRegistry::VehicleRegistry(const VehicleRegistry &vr)
{
    //Copy vr to vehicles
    
    //    reg's numvehicles = vr's numvehicles
    numvehicles = vr.numvehicles;
    
    //    reg's maxsize = vr's maxsize
    maxsize = vr.maxsize;
    
    //    reg's vehicles = vr's vehicles
    vehicles = new Vehicle[maxsize];
    
    for(int i=0; i<maxsize; i++){
    
        vehicles[i]=vr.vehicles[i];
    }
    
}

VehicleRegistry::~VehicleRegistry()
{
    delete[] vehicles;
}

//inserts a vehicle in the array
//if array is full, create a new array with double the size
//if array does not contain the vehicle, return true
//else, return false

bool VehicleRegistry::Insert(Vehicle vehicle)
{
    for(int i = 0; i < maxsize; i++){
    
        if(vehicle.GetPlate() == vehicles[i].GetPlate()){
        
            // License plate is in the registry, return false
            return false;
        }
    }
    
    // If array is full, double the size
    if(numvehicles == maxsize){
    
        //Double the array size
        Vehicle* old_vehicles = vehicles;
        maxsize = maxsize * 2;
        vehicles = new Vehicle[maxsize];
        
        //Copy the old vehicle registry elements to the new Vehicle array
        for(int i=0; i<maxsize/2; i++){
        
            vehicles[i] = old_vehicles[i];
        }
        //Free memory
        delete[] old_vehicles;
    }
    // If array is not full, just insert.
    // Loop through array and find empty spot, then insert
    for(int i = 0; i < maxsize; i++){
    
        if(vehicles[i].GetPlate() == ""){
        
            vehicles[i] = vehicle;
            //cout << "Vehicle with license plate " << vehicles[i].GetPlate() << " is now being inserted into the registry" << endl;
            numvehicles ++;
            return true;
        }
    }

    return false;
}



bool VehicleRegistry::Remove(Vehicle vehicle)
{
    // Check if item to be removed is empty
    if(vehicle.GetPlate()=="" || vehicle.GetModel()=="" || vehicle.GetMake()=="" || vehicle.GetColour()==""){
    
        return false;
    }
    // If item to be removed is not empty
    else{
        
        //loops through array to check matching parameters as target
        for(int i=0; i < maxsize; i++){
        
            if(vehicles[i].GetPlate()==vehicle.GetPlate() && vehicles[i].GetModel() == vehicle.GetModel() && vehicles[i].GetMake() == vehicle.GetMake() && vehicles[i].GetColour() == vehicle.GetColour()){
            
                // Found matching vehicle
               // cout << "Vehicle with license plate " << vehicles[i].GetPlate() << " is now being removed from the registry" << endl;
                vehicles[i] = Vehicle();
                numvehicles --;
                return true;
            }
        }
    }
    
    return false;
}

//Finds the vehicle specified in the parameters
//Returns its index if found
//Return -1 if not found
int VehicleRegistry::Find(Vehicle vehicle) const
{
    //checks if the target has empty any string elements
    //if it does, return -1
    if(vehicle.GetPlate()=="" || vehicle.GetModel()=="" || vehicle.GetMake()=="" || vehicle.GetColour()==""){
    
        return -1;
    }
    
    
    for(int i=0; i< maxsize; i++){
    
        if(vehicles[i].GetPlate()==vehicle.GetPlate()){
        
            return i;
        }
    }
    return -1;
}
//Returns the total number of vehicles in the vehicle array
int VehicleRegistry::Count() const
{
    return numvehicles;
}


//Returns the set union of vehicles between 2 parking spots
VehicleRegistry VehicleRegistry::Join(const VehicleRegistry& vr) const
{
    VehicleRegistry result;
    result.vehicles = new Vehicle[maxsize];
    result.maxsize = maxsize;
    result.numvehicles = 0;
    
    //inserts all vehicles from the vehicles array into the result array
    for(int i=0; i<maxsize; i++){
        result.Insert(vehicles[i]);
    }
    
    //inserts all vehilces from the vr array that do not exist
    //in the result array
    for(int i=0;i<vr.maxsize;i++){
        result.Insert(vr.vehicles[i]);
    }
    
    return result;
}



//Returns the intersection of vehicles between 2 parking spots
VehicleRegistry VehicleRegistry::Common(const VehicleRegistry& vr) const
{
    VehicleRegistry result;
    result.vehicles = new Vehicle[maxsize];
    result.maxsize = maxsize;
    result.numvehicles = 0;
    
    //checks if the number of vehicles in the vehicle array is larger
    //than the number of vehicles in the vr array
    if(numvehicles>vr.numvehicles)
    {
        for(int i=0;i<vr.maxsize;i++){              //checks each vehicle in the vr.vechile array with the vehciles in the vehicle array
            for(int j=0; j<maxsize; j++){           //if it exists, add it to the result array
                if(vr.vehicles[i].GetPlate() == vehicles[j].GetPlate()){
                    result.vehicles[i] = vehicles[i];
                    result.numvehicles++;
                }
            }
        }
    }
    else                                            //checks each vehicle in the vehicle array with the vehciles in the vr.vehicle array
    {                                               //if it exists, add it to the result array
        for(int i=0; i<maxsize;i++){
            for(int j=0; j<vr.maxsize;j++){
                if(vehicles[i].GetPlate() == vr.vehicles[j].GetPlate()){
                    result.vehicles[i] = vehicles[i];
                    result.numvehicles++;
                }
            }
        }
    }
    
    return result;
    
}

//Returns the set differnce of vehicles between 2 parking spots
VehicleRegistry VehicleRegistry::Split(const VehicleRegistry& vr) const
{
    VehicleRegistry result;
    result.vehicles = new Vehicle[maxsize];
    result.maxsize = maxsize;
    result.numvehicles = 0;
    
    
    if(numvehicles>vr.numvehicles){                 //checks each vehicle in the vehicle array
        for(int i=0;i<vr.maxsize;i++){              //if the vehicle does not exist in the vr.vehile array, add it to the result array
            for(int j=0; j<maxsize; j++){
                if(vehicles[i].GetPlate()!=vr.vehicles[i].GetPlate()){
                    result.vehicles[i]=vr.vehicles[i];
                }
            }
        }
    }
   
    else{
        for(int i=0; i<maxsize;i++){                //checks each vehicle in the vehicle array
            for(int j=0; j<vr.maxsize;j++){         //if the vehicle does not exist in the vr.vehile array, add it to the result array
                if(vr.vehicles[i].GetPlate()!=vehicles[i].GetPlate()){
                    result.vehicles[i]=vehicles[i];
                }
            }
        }
    }
    return result;
    
    // use common and return the opposite
}
 

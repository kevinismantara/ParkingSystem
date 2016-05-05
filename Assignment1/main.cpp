// File:        a1simpledriver.h
// Author:      Geoffrey Tien
// Date:        2015-05-13
// Description: A partial automated test driver for CMPT 225 assignment #1
//              Note that it is your responsibility to thoroughly test any
//              cases and/or functions not included in this partial test.

#include <iostream>
#include <string>
#include "vehicle.h"
#include "vehicleregistry.h"
using namespace std;

// Forward declarations for functions called by main
void PrintResult(bool res);

int main()
{
    
    
    
    Vehicle x = Vehicle("APE 824", "Nissan", "240SX", "red");
    Vehicle y = Vehicle("BAT 542", "Honda", "CRX Si", "red/silver");
    Vehicle z = Vehicle("CAT 112", "Toyota", "MR2", "white");
    
    VehicleRegistry reg;
    reg.Insert(x);
    reg.Insert(y);
    reg.Insert(z);
    reg.Remove(x);
    
    
    VehicleRegistry reg2 = VehicleRegistry(reg);
    
    //Copy constructor: Copy reg into reg2
    //cout << reg2.Find(x);
    

    
    
    
    
    string input; // for keeping window open when program has almost completed
    
    cout << "**************************************\n"
    << "* Simple test driver for CMPT 225 A1 *\n"
    << "**************************************\n" << endl;
    
    cout << "Creating a VehicleRegistry object SFUregistry... ";
    VehicleRegistry SFUregistry;
    cout << "done." << endl;
    cout << "Adding 8 vehicles to SFUregistry... " << endl;
    SFUregistry.Insert(Vehicle("APE 824", "Nissan", "240SX", "red"));
    SFUregistry.Insert(Vehicle("BAT 542", "Honda", "CRX Si", "red/silver"));
    SFUregistry.Insert(Vehicle("CAT 112", "Toyota", "MR2", "white"));
    SFUregistry.Insert(Vehicle("BAC 112", "Mazda", "CX-5", "black"));
    SFUregistry.Insert(Vehicle("509 PCM", "Nissan", "Murano", "Grey"));
    SFUregistry.Insert(Vehicle("TAV 542", "BMW", "328i", "White"));
    SFUregistry.Insert(Vehicle("WMC 123", "Audi", "Q5", "white"));
    SFUregistry.Insert(Vehicle("DAS 223", "BMW", "x3", "black"));
    
    cout << "done." << endl;
    cout << "Index of vehicle with plate DAS 223: " << SFUregistry.Find(Vehicle("509 PCM", "custom", "custom", "unpainted")) << endl;
    cout << "Attempting to remove vehicle with plate APE 824 and non-matching parameters... ";
    bool result = SFUregistry.Remove(Vehicle("APE 824", "Nissan", "240SX", "red"));
    PrintResult(result);
    cout << "Attempting to remove vehicle with plate APE 824 and matching parameters... ";
    result = SFUregistry.Remove(Vehicle("APE 824", "Nissan", "240SX", "red"));
    PrintResult(result);
    cout << "Index of vehicle with plate CAT 112: " << SFUregistry.Find(Vehicle("CAT 112", "custom", "custom", "unpainted")) << endl;
    
    cout << "Creating a VehicleRegistry object SFUSurreyregistry as copy of SFUregistry... ";
    VehicleRegistry SFUSurreyregistry(SFUregistry);
    cout << "done." << endl;
    cout << "SFUSurreyregistry contains " << SFUSurreyregistry.Count() << " cars." << endl;
    
    // Enter your own code to thoroughly test all cases of your VehicleRegistry functions.
    
    
    cout << "Type anything to continue: ";
    cin >> input;
    return 0;
    
    
}

void PrintResult(bool res)
{
    if (res) cout << "success!" << endl;
    else cout << "failed." << endl;
}
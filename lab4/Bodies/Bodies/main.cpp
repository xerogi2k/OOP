#include <iostream>
#include <vector>
#include <sstream>
#include "CBody.h"
#include "CSphere.h"
#include "CParallelepiped.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CCompound.h"

using namespace std;
const string BODY_CONTROL_MENU = "Body Control Menu\n"
"1. Create Sphere <density> <radius>\n"
"2. Create Parallelepiped <density> <width> <height> <depth>\n"
"3. Create Cone <density> <base_radius> <height>\n"
"4. Create Cylinder <density> <base_radius> <height>\n"
"5. Add Compound Body\n"
"6. Find Body with Maximum Mass\n"
"7. Find Body with Minimum Weight in Water\n"
"8. Display All Bodies\n"
"9. Exit\n";
const string MENU_DIVIDER = "_______________________\n";
const string SPHERE_CREATED_SUCCESS = "Sphere created successfully!\n";
const string PARALLELEPIPED_CREATED_SUCCESS = "Parallelepiped created successfully!\n";
const string CONE_CREATED_SUCCESS = "Cone created successfully!\n";
const string CYLINDER_CREATED_SUCCESS = "Cylinder created successfully!\n";
const string NO_BODIES_FOUND = "No bodies found!\n";
const string ENTER_COMPONENTS_COUNT = "Enter the number of components: ";
const string INVALID_INPUT = "Invalid input! Please enter a valid number.\n";
const string INVALID_INPUTS = "Invalid input! Please enter valid numbers.";
const string ENTER_COMPONENT_TYPE = "Enter component type (1. Sphere, 2. Parallelepiped, 3. Cone, 4. Cylinder,  5. Compound): ";
const string ENTER_DENSITY_AND_RADIUS = "Enter density and radius: ";
const string ENTER_DENSITY_WIDTH_HEIGHT_DEPTH = "Enter density, width, height, and depth: ";
const string ENTER_DENSITY_BASE_RADIUS_HEIGHT = "Enter density, base_radius, and height: ";
const string INVALID_COMPONENT_TYPE = "Invalid component type! Please try again.\n";
const string COMPOUND_BODY_ADDED_SUCCESS = "Compound body added successfully!\n";
const string ALL_BODIES_LABEL = "All Bodies:\n";
const string EXITING = "Exiting...\n";
const string INVALID_COMMAND = "Invalid command. Type 'help' or '0' for the list of commands.\n";
const string BODY_WITH_MAXIMUM_MASS = "Body with maximum mass:\n";
const string BODY_WITH_MINIMUM_WEIGHT_IN_WATER = "Body with minimum weight in water:\n";
const string PROMPT = "> ";
const string SPACE = " ";

bool ValidateInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void DisplayMenu() {
    cout << BODY_CONTROL_MENU;
}

void CreateSphere(vector<BodyPtr>& bodies, double density, double radius) 
{
    bodies.push_back(make_shared<CSphere>(density, radius));
    cout << SPHERE_CREATED_SUCCESS;
}

void CreateParallelepiped(vector<BodyPtr>& bodies, double density, double width, double height, double depth) 
{
    bodies.push_back(make_shared<CParallelepiped>(density, width, height, depth));
    cout << PARALLELEPIPED_CREATED_SUCCESS;
}

void CreateCone(vector<BodyPtr>& bodies, double density, double baseRadius, double height) 
{
    bodies.push_back(make_shared<CCone>(density, baseRadius, height));
    cout << CONE_CREATED_SUCCESS;
}

void CreateCylinder(vector<BodyPtr>& bodies, double density, double baseRadius, double height) 
{
    bodies.push_back(make_shared<CCylinder>(density, baseRadius, height));
    cout << CYLINDER_CREATED_SUCCESS;
}

void FindMaxBodyMass(vector<BodyPtr>& bodies)
{
    auto maxMassBody = MaxBodyMass(bodies);
    if (maxMassBody)
    {
        cout << BODY_WITH_MAXIMUM_MASS << maxMassBody->ToString() << endl;
    }
    else
    {
        cout << NO_BODIES_FOUND << endl;
    }
}

void FindMinWeightInWater(vector<BodyPtr>& bodies)
{
    auto minWeightInWaterBody = MinWeightInWater(bodies);
    if (minWeightInWaterBody) 
    {
        cout << BODY_WITH_MINIMUM_WEIGHT_IN_WATER << minWeightInWaterBody->ToString();
    }
    else {
        cout << NO_BODIES_FOUND << endl;
    }
}

shared_ptr<CCompound> AddCompoundBodyRecursive(int indentation = 0)
{
    auto compound = make_shared<CCompound>();

    int numComponents;
    cout << ENTER_COMPONENTS_COUNT;
    cin >> numComponents;

    if (!ValidateInput())
    {
        cout << INVALID_INPUT << endl;
        return nullptr;
    }

    double density, radius, width, height, depth, baseRadius;

    for (int i = 0; i < numComponents; ++i)
    {
        for (int i = 0; i < indentation; ++i)
        {
            cout << SPACE;
        }
        cout << ENTER_COMPONENT_TYPE;
        int choice;
        cin >> choice;

        if (!ValidateInput()) {
            cout << INVALID_INPUT << endl;
            --i;
            continue;
        }

        for (int i = 0; i < indentation; ++i)
        {
            cout << SPACE;
        }

        switch (choice)
        {
        case 1:
            cout << ENTER_DENSITY_AND_RADIUS;
            cin >> density >> radius;
            if (!ValidateInput())
            {
                cout << INVALID_INPUTS << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CSphere>(density, radius));
            break;
        case 2:
            cout << ENTER_DENSITY_WIDTH_HEIGHT_DEPTH;
            cin >> density >> width >> height >> depth;
            if (!ValidateInput())
            {
                cout << INVALID_INPUTS << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CParallelepiped>(density, width, height, depth));
            break;
        case 3:
            cout << ENTER_DENSITY_BASE_RADIUS_HEIGHT;
            cin >> density >> baseRadius >> height;
            if (!ValidateInput())
            {
                cout << INVALID_INPUTS << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CCone>(density, baseRadius, height));
            break;
        case 4:
            cout << ENTER_DENSITY_BASE_RADIUS_HEIGHT;
            cin >> density >> baseRadius >> height;
            if (!ValidateInput())
            {
                cout << INVALID_INPUTS << endl;
                --i;
                continue;
            }
            compound->AddChildBody(make_shared<CCylinder>(density, baseRadius, height));
            break;
        case 5:
            compound->AddChildBody(AddCompoundBodyRecursive(indentation + 4));
            break;
        default:
            cout << INVALID_COMPONENT_TYPE;
            --i;
            break;
        }
    }
    return compound;
}

void AddCompoundBody(vector<BodyPtr>& bodies)
{
    auto finalcompound = AddCompoundBodyRecursive();
    if (finalcompound)
    {
        bodies.push_back(finalcompound);
        cout << COMPOUND_BODY_ADDED_SUCCESS;
    }
}

int GetUserChoice() {
    int choice;
    while (true) {
        cout << PROMPT;
        cin >> choice;
        if (ValidateInput()) {
            break;
        }
        else {
            cout << INVALID_INPUT << endl;
        }
    }
    return choice;
}

int main()
{
    vector<BodyPtr> bodies;
    double density, radius, width, height, depth, baseRadius;
    int choice = 0;

    while (choice != 9) {

        choice = GetUserChoice();

        switch (choice) {
        case 0:
            DisplayMenu();
            break;
        case 1:
            cout << ENTER_DENSITY_AND_RADIUS;
            cin >> density >> radius;
            if (!ValidateInput()) {
                cout << INVALID_INPUTS << endl;
                break;
            }
            CreateSphere(bodies, density, radius);
            break;
        case 2:
            cout << ENTER_DENSITY_WIDTH_HEIGHT_DEPTH;
            cin >> density >> width >> height >> depth;
            if (!ValidateInput()) {
                cout << INVALID_INPUTS << endl;
                break;
            }
            CreateParallelepiped(bodies, density, width, height, depth);
            break;
        case 3:
            cout << ENTER_DENSITY_BASE_RADIUS_HEIGHT;
            cin >> density >> baseRadius >> height;
            if (!ValidateInput()) {
                cout << INVALID_INPUTS << endl;
                break;
            }
            CreateCone(bodies, density, baseRadius, height);
            break;
        case 4:
            cout << ENTER_DENSITY_BASE_RADIUS_HEIGHT;
            cin >> density >> baseRadius >> height;
            if (!ValidateInput()) {
                cout << INVALID_INPUTS << endl;
                break;
            }
            CreateCylinder(bodies, density, baseRadius, height);
            break;
        case 5:
            AddCompoundBody(bodies);
            break;
        case 6:
        {
            FindMaxBodyMass(bodies);
        }
        break;
        case 7:
        {
            FindMinWeightInWater(bodies);
        }
        break;
        case 8:
            cout << ALL_BODIES_LABEL;
            for (const auto& body : bodies) {
                cout << body->ToString() << endl;
                cout << endl;
            }
            break;
        case 9:
            cout << EXITING;
            break;
        default:
            cout << INVALID_COMMAND;
            break;
        }
    }

    return 0;
}
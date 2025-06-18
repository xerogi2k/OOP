    #include <iostream>
    #include <limits>
    #include "Vector3D.h"

    using namespace std;

    const string MENU = "Menu:\n"
        "1. Calculate the length of a vector\n"
        "2. Normalize a vector\n"
        "3. Calculate dot product of two vectors\n"
        "4. Calculate cross product of two vectors\n"
        "5. Check if two vectors are equal\n"
        "6. Add two vectors\n"
        "7. Subtract two vectors\n"
        "8. Multiply a vector by a scalar\n"
        "9. Divide a vector by a scalar\n"
        "10. Exit\n";
    const string INVALID_INPUT = "Invalid input. Please enter numeric values.\n";
    const string PROMPT = "> ";
    const string ENTER_COORDINATES = "Enter the coordinates of the vector (x, y, z): ";
    const string LENGTH_OF_VECTOR = "Length of the vector: ";
    const string NORMALIZED_VECTOR = "Normalized vector: ";
    const string ENTER_COORDINATES_FIRST = "Enter the coordinates of the first vector (x1, y1, z1): ";
    const string ENTER_COORDINATES_SECOND = "Enter the coordinates of the second vector (x2, y2, z2): ";
    const string DOT_PRODUCT_RESULT = "Dot product of the vectors: ";
    const string CROSS_PRODUCT_RESULT = "Cross product of the vectors: ";
    const string VECTORS_EQUALITY_TRUE = "The vectors are equal.\n";
    const string VECTORS_EQUALITY_FALSE = "The vectors are not equal.\n";
    const string SUM_OF_VECTORS = "Sum of the vectors: ";
    const string DIFFERENCE_OF_VECTORS = "Difference of the vectors: ";
    const string VECTOR_SCALAR_PRODUCT = "Product of the vector and the scalar: ";
    const string VECTOR_SCALAR_DIVISION = "Division of the vector by the scalar: ";
    const string ENTER_SCALAR = "Enter the scalar: ";
    const string EXITING = "Exiting...\n";
    const string INVALID_COMMAND = "Invalid command. Type 'help' or '0' for the list of commands.\n";


    void DisplayMenu() {
        cout << MENU;
    }

    bool InputErrorHandler()
    {
        if (cin.fail()) 
        {
            cout << INVALID_INPUT << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;

        }
        return false;
    }

    void CalculateVectorLength(CVector3D& vec, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES;
        cin >> x >> y >> z;
        if (InputErrorHandler()) 
        {
            return;
        }
        vec = CVector3D(x, y, z);
        cout << LENGTH_OF_VECTOR << vec.GetLength() << endl;
    }

    void NormalizeVector(CVector3D& vec, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES;
        cin >> x >> y >> z;
        if (InputErrorHandler()) 
        {
            return;
        }
        vec = CVector3D(x, y, z);
        vec.Normalize();
        cout << NORMALIZED_VECTOR << vec << endl;
    }

    void CalculateDotProduct(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES_FIRST;
        cin >> x >> y >> z;
        if (InputErrorHandler()) 
        {
            return;
        }
        vec1 = CVector3D(x, y, z);
        cout << ENTER_COORDINATES_SECOND;
        cin >> x >> y >> z; 
        if (InputErrorHandler()) 
        {
            return;
        }
        vec2 = CVector3D(x, y, z);
        cout << DOT_PRODUCT_RESULT << DotProduct(vec1, vec2) << endl;
    }

    void CalculateCrossProduct(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES_FIRST;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec1 = CVector3D(x, y, z);
        cout << ENTER_COORDINATES_SECOND;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec2 = CVector3D(x, y, z);
        cout << CROSS_PRODUCT_RESULT << CrossProduct(vec1, vec2) << endl;
    
    }

    void CheckVectorsEquality(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES_FIRST;
        cin >> x >> y >> z;     
        if (InputErrorHandler())
        {
            return;
        }
        vec1 = CVector3D(x, y, z);
        cout << ENTER_COORDINATES_SECOND;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec2 = CVector3D(x, y, z);
        if (vec1 == vec2)
        {
            cout << VECTORS_EQUALITY_TRUE << endl;
        }
        else
        {
            cout << VECTORS_EQUALITY_FALSE << endl;
        }
    }

    void AddVectors(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES_FIRST;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec1 = CVector3D(x, y, z);
        cout << ENTER_COORDINATES_SECOND;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec2 = CVector3D(x, y, z);
        cout << SUM_OF_VECTORS << (vec1 + vec2) << endl;
    }

    void SubtractVectors(CVector3D& vec1, CVector3D& vec2, double& x, double& y, double& z) 
    {
        cout << ENTER_COORDINATES_FIRST;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec1 = CVector3D(x, y, z);
        cout << ENTER_COORDINATES_SECOND;
        cin >> x >> y >> z; 
        if (InputErrorHandler())
        {
            return;
        }
        vec2 = CVector3D(x, y, z);
        cout << DIFFERENCE_OF_VECTORS << (vec1 - vec2) << endl;
    }

    void MultiplyVectorByScalar(CVector3D& vec, double& x, double& y, double& z, double scalar) 
    {
        cout << ENTER_COORDINATES;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec = CVector3D(x, y, z);
        cout << ENTER_SCALAR;
        cin >> scalar;
        if (InputErrorHandler())
        {
            return;
        }
        cout << VECTOR_SCALAR_PRODUCT << (vec * scalar) << endl;
    }

    void DivideVectorByScalar(CVector3D& vec, double& x, double& y, double& z, double scalar)
    {
        cout << ENTER_COORDINATES;
        cin >> x >> y >> z;
        if (InputErrorHandler())
        {
            return;
        }
        vec = CVector3D(x, y, z);
        cout << ENTER_SCALAR;
        cin >> scalar;
        if (InputErrorHandler())
        {
            return;
        }
        cout << VECTOR_SCALAR_DIVISION << (vec / scalar) << endl;
    }

    int main() 
    {
        int choice = 0;
        CVector3D vec1, vec2;
        double x, y, z, scalar;
        scalar = 0;
        while (choice != 10)
        {
        
            cout << PROMPT;
            cin >> choice;

            if (cin.fail())
            {
                cout << INVALID_COMMAND << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) 
            {
            case 0:
                DisplayMenu();
                break;
            case 1:
                CalculateVectorLength(vec1, x, y, z);
                break;
            case 2:
                NormalizeVector(vec1, x, y, z);
                break;
            case 3:
                CalculateDotProduct(vec1, vec2, x, y, z);
                break;
            case 4:
                CalculateCrossProduct(vec1, vec2, x, y, z);
                break;
            case 5:
                CheckVectorsEquality(vec1, vec2, x, y, z);
                break;
            case 6:
                AddVectors(vec1, vec2, x, y, z);
                break;
            case 7:
                SubtractVectors(vec1, vec2, x, y, z);
                break;
            case 8:
                MultiplyVectorByScalar(vec1, x, y, z, scalar);
                break;
            case 9:
                DivideVectorByScalar(vec1, x, y, z, scalar);
                break;
            case 10:
                cout << EXITING << endl;
                break;
            default:
                cout << INVALID_COMMAND << endl;
                break;
            }
        }

        return 0;
    }
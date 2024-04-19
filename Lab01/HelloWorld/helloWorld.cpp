#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct DietaryInfo
{
    int animalID;
    string species;
    float dailyFoodIntake;
    string specialDietaryRequirements;
} DietaryInfo;

typedef struct HealthRecord
{
    int animalID;
    string species;
    int lastCheckUpDate[3];
    string currHealthStatus;
    string medication;
} HealthRecord;

typedef struct EnrichmentActivity
{
    int animalID;
    string species;
    string activityName;
    string frequency;
    int duration;
} EnrichmentActivity;

typedef struct EnclosureManintanance
{
    int enclosureID;
    string species;
    int lastMaintananceDate[3];
    string maintananceType;
    int nextScheduledMaintenance[3];
} EnclosureManintanance;

DietaryInfo dietaryInfos[5];
HealthRecord healthRecords[5];
EnrichmentActivity enrichmentActivities[5];
EnclosureManintanance enclosureManintanances[5];

int sDietaryInfo(int index)
{
    std::cout << "\nEnter data for Dietary Info (Instance " << index + 1 << "):" << std::endl;
    std::cout << "Animal ID: ";
    std::cin >> dietaryInfos[index].animalID;
    std::cout << "\nSpecies: ";
    std::cin >> dietaryInfos[index].species;
    std::cout << "\nDaily Food Intake: ";
    std::cin >> dietaryInfos[index].dailyFoodIntake;
    std::cout << "\nSpecial Dietary Requirements: ";
    std::cin >> dietaryInfos[index].specialDietaryRequirements;
    int rIndex = index + 1;
    return rIndex;
}

int *getDate(std::string s)
{
    // Remove the brackets at the beginning and end
    s.erase(0, 1); // Remove the opening '['
    s.pop_back();  // Remove the closing ']'

    // Find positions of commas
    size_t pos1 = s.find(',');
    size_t pos2 = s.find(',', pos1 + 1);

    // Extract the substrings and convert to integers
    std::string part1 = s.substr(0, pos1);
    std::string part2 = s.substr(pos1 + 2, pos2 - (pos1 + 2)); // +2 to skip the comma and space
    std::string part3 = s.substr(pos2 + 2);                    // +2 to skip the comma and space
    std::cout << part1 << " " << part2 << " " << part3 << std::endl;
    // Convert strings to integers
    int a = std::stoi(part1);
    int b = std::stoi(part2);
    int c = std::stoi(part3);
    int arr[] = {a, b, c};

    return arr;
}
int sHealthRecord(int index)
{
    std::cout << "\nEnter data for Health Record (Instance " << index + 1 << "):";
    std::cout << "\nAnimal ID: ";
    std::cin >> healthRecords[index].animalID;
    std::cout << "\nSpecies: ";
    std::cin >> healthRecords[index].species;
    string s;
    std::cout << "\nLast Check Up Date: ";
    std::cin >> s;
    int *date = getDate(s);
    healthRecords[index].lastCheckUpDate[0] = date[0];
    healthRecords[index].lastCheckUpDate[1] = date[1];
    healthRecords[index].lastCheckUpDate[2] = date[2];
    std::cout << "\nCurrent Health Status: ";
    std::cin >> healthRecords[index].currHealthStatus;
    std::cout << "\nMedication: ";
    std::cin >> healthRecords[index].medication;
    int rIndex = index + 1;
    return rIndex;
}

void sEnrichmentActivity(int index)
{
}

void sEnclosureMaintenance(int index)
{
}

void mains()
{
    int nIndexOfDietaryInfo = 0;
    int nIndexOfHealthRecord = 0;
    int nIndexOfEnrichmentActivity = 0;
    int nIndexOfEnclosureMaintenance = 0;
    bool isRunning = true;

    while (isRunning)
    {
        std::cout << nIndexOfDietaryInfo << "\n";
        cout << "Welcome to the Animal Care Management Program!" << "\n";
        cout << "Please choose an option to enter data:" << "\n";
        if (nIndexOfDietaryInfo == 0)
            cout << "1. Enter Dietary Info" << "\n";
        else
            cout << "1. Enter Dietary Info (Next available instance: " << nIndexOfDietaryInfo + 1 << ")" << "\n";
        if (nIndexOfHealthRecord == 0)
            cout << "2. Enter Health Record" << "\n";
        else
            cout << "2. Enter Health Record (Next available instance: " << nIndexOfHealthRecord + 1 << ")" << "\n";

        if (nIndexOfEnrichmentActivity == 0)
            cout << "3. Enter Enrichment Activity" << "\n";
        else
            cout << "3. Enter Enrichment Activity (Next available instance: " << nIndexOfEnrichmentActivity + 1 << ")" << "\n";
        if (nIndexOfEnclosureMaintenance == 0)
            cout << "4. Enter Enclosure Maintenance" << "\n";
        else
            cout << "4. Enter Enclosure Maintenance (Next available instance: " << nIndexOfEnclosureMaintenance + 1 << ")" << "\n";
        cout << "5. Exit and print entered data" << "\n";

        int type;
        std::cout << "Enter your choice: ";
        cin >> type;
        switch (type)
        {
        case 1:
            nIndexOfDietaryInfo = sDietaryInfo(nIndexOfDietaryInfo);
            break;
        case 2:
            nIndexOfHealthRecord = sHealthRecord(nIndexOfHealthRecord);
            break;
        case 3:
            sEnrichmentActivity(0);
            break;
        case 4:
            sEnclosureMaintenance(0);
            break;
        case 5:
            isRunning = false;
            break;
        }
    }
}

int main(int argc, char **argv)
{
    mains();
    return 0;
}

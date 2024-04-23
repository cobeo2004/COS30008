#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
double a;
struct DietaryInfo
{
    int animal_id;
    string species;
    float daily_food_intake;
    string special_dietary_requirements;
};
struct HealthRecord
{
    int animal_id;
    string species;
    int last_checkup_date[3];
    string current_health_status;
    string medication;
};
struct EnrichmentActivity
{
    int animal_id;
    string species;
    string activity_name;
    string frequency;
    int duration;
};
struct EnclosureMaintenance
{
    int enclosure_id;
    string species;
    int last_maintenance_date[3];
    string maintenace_type;
    int next_scheduled_maintenance[3];
};
struct AnimalTimeAnalysis
{
    int choice;
    string species;
    vector<int> viewingTimes;
};

struct DietaryInfo dietaryinfo_array[5];
struct HealthRecord healthrecord_array[5];
struct EnrichmentActivity enrichmentactivity_array[5];
struct EnclosureMaintenance enclosuremaintenance_array[5];
vector<struct AnimalTimeAnalysis> animal_analysis_vector(5);

int structchoice;
int index_dietary_info = 0;
int index_health_record = 0;
int index_enrichmment_activity = 0;
int index_enclosure_maintenance = 0;

double age_factor(double age)
{
    if (age >= 0 && age <= 1)
    {
        return 1.3;
    }
    else if (age >= 2 && age <= 3)
    {
        return 1.1;
    }
    else if (age >= 4 && age <= 6)
    {
        return 0.9;
    }
    else
    {
        return 0.7;
    }
}
double daily_food_for_kangaroo(double age, double weight)
{
    double a = age_factor(age);
    return weight * 0.04 + a * sqrt(weight);
}
double daily_food_for_koala(double age, double weight)
{
    double a = age_factor(age);
    return (weight * 0.02 + a) * log(weight);
}
double daily_food_for_wombat(double age, double weight)
{
    double a = age_factor(age);
    return weight * 0.7 + a * sin(weight);
}
double daily_food_for_emu(double age, double weight)
{
    double a = age_factor(age);
    return weight * 0.05 + a * cos(weight);
}
double daily_food_for_platypus(double age, double weight)
{
    double a = age_factor(age);
    return weight * 0.03 + a * pow(weight, 0.5);
}
void dietary_info_detail(int index)
{
    cout << "Enter data for Dietary Info (Instance " << index + 1 << ")" << endl;
    cout << "Animal ID: ";
    cin >> dietaryinfo_array[index].animal_id;
    cout << "Species: ";
    cin >> dietaryinfo_array[index].species;
    cout << "Daily Food Intake (kg): ";
    cin >> dietaryinfo_array[index].daily_food_intake;
    cout << "Special Dietary Requirements: ";
    cin >> dietaryinfo_array[index].special_dietary_requirements;
}
void health_record_detail(int index)
{
    cout << "Enter data for Health Record (Instance " << index + 1 << ")" << endl;
    cout << "Animal ID: ";
    cin >> healthrecord_array[index].animal_id;
    cout << "Species: ";
    cin >> healthrecord_array[index].species;
    cout << "Last Check-up Date in the format [DD, MM, YYYY]: ";
    cin >> healthrecord_array[index].last_checkup_date[0] >>
        healthrecord_array[index].last_checkup_date[1] >>
        healthrecord_array[index].last_checkup_date[2];
    cout << "Current Health Status: ";
    cin >> healthrecord_array[index].current_health_status;
    cout << "Medication: ";
    cin >> healthrecord_array[index].medication;
}
void enrichment_activity_detail(int index)
{
    cout << "Enter data for Enrichment Activity (Instance " << index + 1 << ")"
         << endl;
    cout << "Animal ID: ";
    cin >> enrichmentactivity_array[index].animal_id;
    cout << "Species: ";
    cin >> enrichmentactivity_array[index].species;
    cout << "Activity Name ";
    cin >> enrichmentactivity_array[index].activity_name;
    cout << "Frequency: ";
    cin >> enrichmentactivity_array[index].frequency;
    cout << "Duration (minutes): ";
    cin >> enrichmentactivity_array[index].duration;
}
void enclosure_maintenance_detail(int index)
{
    cout << "Enter data for Enclosure Maintenance (Instance " << index + 1 << ")"
         << endl;
    cout << "Enclosure ID: ";
    cin >> enclosuremaintenance_array[index].enclosure_id;
    cout << "Species: ";
    cin >> enclosuremaintenance_array[index].species;
    cout << "Last Maintenance Date in the format [DD, MM, YYYY]: ";
    cin >> enclosuremaintenance_array[index].last_maintenance_date[0] >>
        enclosuremaintenance_array[index].last_maintenance_date[1] >>
        enclosuremaintenance_array[index].last_maintenance_date[2];
    cout << "Maintenance Type: ";
    cin >> enclosuremaintenance_array[index].maintenace_type;
    cout << "Next Schedules Maintenance in the format [DD, MM, YYYY]: ";
    cin >> enclosuremaintenance_array[index].next_scheduled_maintenance[0] >>
        enclosuremaintenance_array[index].next_scheduled_maintenance[1] >>
        enclosuremaintenance_array[index].next_scheduled_maintenance[2];
}
void displaying_information_dietary_info(int index)
{
    for (int index = 0; index < index_dietary_info; index++)
    {
        cout << "Dietary Info (Instance " << index + 1 << ") - "
             << dietaryinfo_array[index].species << endl;
        cout << "Animal ID: " << dietaryinfo_array[index].animal_id << endl;
        cout << "Daily Food Intake (kg): "
             << dietaryinfo_array[index].daily_food_intake << endl;
        cout << "Special Dietary Requirements: "
             << dietaryinfo_array[index].special_dietary_requirements << endl;
    }

    for (int index = 0; index < index_health_record; index++)
    {

        cout << "Health Record (Instance " << index + 1 << ") - "
             << healthrecord_array[index].species << endl;
        cout << "Animal ID: " << healthrecord_array[index].animal_id << endl;
        cout << "Last Check_up Date in the format [DD, MM, YYYY]: "
             << healthrecord_array[index].last_checkup_date[0]
             << healthrecord_array[index].last_checkup_date[1]
             << healthrecord_array[index].last_checkup_date[2] << endl;
        cout << "Current Health Status: "
             << healthrecord_array[index].current_health_status << endl;
        cout << "Medication: " << healthrecord_array[index].medication << endl;
    }

    for (int index = 0; index < index_enrichmment_activity; index++)
    {

        cout << "Enrichment Activity (Instance " << index + 1 << ") - "
             << enrichmentactivity_array[index].species << endl;
        cout << "Animal ID: " << enrichmentactivity_array[index].animal_id << endl;
        cout << "Acitvity Name: " << enrichmentactivity_array[index].activity_name
             << endl;
        cout << "Frequency: " << enrichmentactivity_array[index].frequency << endl;
        cout << "Duration (minutes): " << enrichmentactivity_array[index].duration
             << endl;
    }
    for (int index = 0; index < index_enclosure_maintenance; index++)
    {

        cout << "Enclosure Maintenance (Instance " << index + 1 << ") - "
             << enclosuremaintenance_array[index].species << endl;
        cout << "Enclosure ID: " << enclosuremaintenance_array[index].enclosure_id
             << endl;
        cout << "Last Maintenance Date in the format [DD, MM, YYYY]: "
             << enclosuremaintenance_array[index].last_maintenance_date[0]
             << enclosuremaintenance_array[index].last_maintenance_date[1]
             << enclosuremaintenance_array[index].last_maintenance_date[2] << endl;
        cout << "Maintennace Type: "
             << enclosuremaintenance_array[index].maintenace_type << endl;
        cout << "Next schedules Maintenance in the format [DD, MM,YYYY]: "
             << enclosuremaintenance_array[index].next_scheduled_maintenance[0]
             << enclosuremaintenance_array[index].next_scheduled_maintenance[1]
             << enclosuremaintenance_array[index].next_scheduled_maintenance[2]
             << endl;
    }
}

void init_data()

{
    // Viewing times for each animal
    int default_viewing_times[5][11] = {
        {10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30},
        {15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35},
        {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
        {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23},
        {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}};

    // Choice and species
    animal_analysis_vector[0].choice = 0;
    animal_analysis_vector[0].species = "Kangaroo";
    animal_analysis_vector[1].choice = 1;
    animal_analysis_vector[1].species = "Koala";
    animal_analysis_vector[2].choice = 2;
    animal_analysis_vector[2].species = "Wombat";
    animal_analysis_vector[3].choice = 3;
    animal_analysis_vector[3].species = "Emu";
    animal_analysis_vector[4].choice = 4;
    animal_analysis_vector[4].species = "Platypus";

    vector<int> viewing_times;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {

            viewing_times.push_back(default_viewing_times[i][j]);
        }

        animal_analysis_vector[i].viewingTimes = viewing_times;
        viewing_times.clear();
    }
}

void print_current_analysis()
{
    cout << "Current Viewing Time Analysis Data: \n";
    for (int i = 0; i < 1; i++)
    {
        cout << "         ";
        for (int j = 0; j < animal_analysis_vector[i].viewingTimes.size(); j++)
        {
            cout << j + 1 << "   ";
        }
        cout << endl;
    }
    for (int i = 0; i < animal_analysis_vector.size(); i++)
    {
        cout << animal_analysis_vector[i].species;
        for (int j = 0; j < animal_analysis_vector[i].viewingTimes.size(); j++)
        {
            cout << " " << animal_analysis_vector[i].viewingTimes[j] << " ";
        }
        cout << endl;
    }
}

void add_viewing_data()
{
    int species_choice;
    cout << "\nSelect an animal to add new viewing time data:\n 1. Kangaroo\n 2. "
            "Koala\n 3. Wombat\n 4. Emu \n 5. Platypus\n";
    cout << "Enter your choice: ";
    cin >> species_choice;
    for (int i = 0; i < animal_analysis_vector.size(); i++)
    {
        if (species_choice - 1 == animal_analysis_vector[i].choice)
        {
            int viewing_time;
            cout << "Enter the next viewing time for "
                 << animal_analysis_vector[i].species << " (in hours): ";
            cin >> viewing_time;
            animal_analysis_vector[i].viewingTimes.push_back(viewing_time);
        }
    }
}

int main()
{
    printf("Question One\n");
    string animal;
    int input = 0;
    double age;
    double weight;
    double dailyfood;
    cout << "Enter input:";
    cin >> input;
    while (input == 1)
    {
        cout << "Select an animal below:\n Kangaroo \n Koala \n Wombat \n Emu \n "
                "Platypus \n";
        cin >> animal;
        while (animal != "kangaroo" && animal != "Kangaroo" && animal != "koala" &&
               animal != "Koala" && animal != "wombat" && animal != "Wombat" &&
               animal != "emu" && animal != "Emu" && animal != "platypus" &&
               animal != "Platypus")
        {
            cout << "Invalid value. Please enter an animal in the list: ";
            cin >> animal;
        }
        cout << "Enter the animal's weight in kilograms: ";
        cin >> weight;
        while (weight <= 0)
        {
            cout << "Invalid value. Please enter value again: ";
            cin >> weight;
        }
        cout << "Enter the animal's age in years: ";
        cin >> age;
        while (age < 0)
        {
            cout << "Invalid value. Please enter value again: " << age << endl;
        }
        if (animal == "Kangaroo" || animal == "kangaroo")
        {
            dailyfood = daily_food_for_kangaroo(age, weight);
        }
        else if (animal == "Koala" || animal == "koala")
        {
            dailyfood = daily_food_for_koala(age, weight);
        }
        else if (animal == "Wombat" || animal == "wombat")
        {
            dailyfood = daily_food_for_wombat(age, weight);
        }
        else if (animal == "Emu" || animal == "emu")
        {
            dailyfood = daily_food_for_emu(age, weight);
        }
        else if (animal == "Platypus" || animal == "platypus")
        {
            dailyfood = daily_food_for_platypus(age, weight);
        }

        cout << "Entered values: " << animal << ", weight = " << weight
             << "kg, age = " << age << " years." << endl;
        cout << "Output: The daily food requirement for " << animal
             << " is approximately " << dailyfood << "kg." << endl;
    }

    while (input == 2)
    {
        cout << "Question Two \n Welcome to the Animal Care Manangement Program! "
                "\n Please choose an option to enter data: \n";
        if (index_dietary_info == 0)
            cout << "1. Enter Dietary Info \n";
        else
            cout << "1. Enter Dietary Info (Next available instance: "
                 << index_dietary_info + 1 << ")\n";
        if (index_health_record == 0)
            cout << "2. Enter Health Record \n";
        else
            cout << "2. Enter Health Record (Next available instance: "
                 << index_health_record + 1 << ")\n";
        if (index_enrichmment_activity == 0)
            cout << "3. Enter Enrichment Activity \n";
        else
            cout << "3. Enter Enrichment Activity (Next available instance: "
                 << index_enrichmment_activity + 1 << ")\n";
        if (index_enclosure_maintenance == 0)
            cout << "4. Enter Enclosure Maintenance \n";
        else
            cout << "4. Enter Enclosure Maintenance (Next available instance: "
                 << index_enclosure_maintenance + 1 << ") \n";
        cout << "5. Exit and print entered data \n";
        cout << "\nEnter your choice: ";
        cin >> structchoice;
        if (structchoice >= 1 && structchoice <= 5)
        {
            if (structchoice == 1)
            {
                dietary_info_detail(index_dietary_info);
                index_dietary_info = index_dietary_info + 1;
            }
            else if (structchoice == 2)
            {
                health_record_detail(index_health_record);
                index_health_record = index_health_record + 1;
            }
            else if (structchoice == 3)
            {
                enrichment_activity_detail(index_enrichmment_activity);
                index_enrichmment_activity = index_enrichmment_activity + 1;
            }
            else if (structchoice == 4)
            {
                enclosure_maintenance_detail(index_enclosure_maintenance);
                index_enclosure_maintenance = index_enclosure_maintenance + 1;
            }
            else if (structchoice == 5)
            {
                displaying_information_dietary_info(index_dietary_info);
                break;
            }
        }
        cout << "\nData entered successfully!\n";
    }

    if (input == 3)
    {
        cout << "Question Three:\n";
        cout << "Welcome to the Animal Viewing Time Analysis Program!\n";
        init_data();
        print_current_analysis();
        while (true)
        {
            cout << "Please choose an option:" << endl;
            cout << "Add New Viewing Time Data" << endl;
            cout << "Print Viewing Time Data" << endl;
            cout << "Print Accumulating Sum Data" << endl;
            cout << "Exit Program" << endl;

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                add_viewing_data();
            }
            else if (choice == 2)
            {
                print_current_analysis();
            }
            else if (choice == 3)
            {
            }
            else if (choice == 4)
            {
                cout << "Goodbye!";
                break;
            }
            else
            {
                cout << "Wrong options, please choose again";
            }
        }
    }
    return 0;
}

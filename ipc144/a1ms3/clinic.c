
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#define MAX_INDEX 20

int AppointCounter = 0;

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu (hub) for application
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
        }

    }
    putchar('\n');
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");

        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);


}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i = 0, counter = 0, newPatientNum = 0;
    int index[MAX_INDEX] = { 99,99,99,99,99,99,99 };

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index[i] = i;
            counter++;
        }
    }

    if (counter > 1)
    {
        newPatientNum = nextPatientNumber(patient, max);
        for (i = 0; i < max; i++)
        {
            if ((index[i] != 99) && (counter > 1))
            {
                patient[index[i]].patientNumber = newPatientNum;
                inputPatient(&patient[index[i]]);
                counter--;
            }
        }
        printf("*** New patient record added ***\n\n");

    }
    else if (counter == 1)
    {
        newPatientNum = nextPatientNumber(patient, max);
        for (i = 0; i < max; i++)
        {
            if ((index[i] != 99) && (counter == 1))
            {
                patient[index[i]].patientNumber = newPatientNum;
                inputPatient(&patient[index[i]]);
                counter--;
            }
        }
        printf("*** New patient record added ***\n\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n");
        putchar('\n');
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int edPatientNum = 0, found = 0;

    printf("Enter the patient number: ");
    scanf(" %d", &edPatientNum);
    clearInputBuffer();
    putchar('\n');
    found = findPatientIndexByPatientNum(edPatientNum, patient, max);
    if (found != -1)
    {
        menuPatientEdit(&patient[found]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
        suspend();
    }

}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int delPatientNum = 0, found = 0;
    char answer = 'a';

    printf("Enter the patient number: ");
    scanf(" %d", &delPatientNum);
    clearInputBuffer();
    putchar('\n');
    found = findPatientIndexByPatientNum(delPatientNum, patient, max);
    if (found != -1)
    {
        displayPatientData(&patient[found], 1);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        answer = inputCharOption("yn");
        clearInputBuffer();
        if (answer == 'y')
        {
            patient[found].patientNumber = 0;
            strcpy(patient[found].name, "aaaaaa");
            strcpy(patient[found].phone.number, "0000000000");
            strcpy(patient[found].phone.description, "TBD");
            printf("Patient record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }

    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }

}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i = 0, showAll = 1, showDate = 1, found;
    int j;
    int index[16]={0};
    struct ClinicData* test;
    test = data;

    displayScheduleTableHeader(&test->appointments->date, showAll);

    int num_items = AppointCounter+1;
    struct Appointment testApp;
    for (i = 0; i < num_items - 1; i++) //selection sort for year
    {
        for (j = i+1; j < num_items; j++)
        {
            if (test->appointments[i].patientNum != 0)
            {
                if (test->appointments[i].date.year > test->appointments[j].date.year)
                {
                    testApp = test->appointments[i];
                    test->appointments[i] = test->appointments[j];
                    test->appointments[j] = testApp;
                }
            }

        }
    }

    for (i = 0; i < num_items - 1; i++) //selection sort for day
    {
        for (j = i + 1; j < num_items; j++)
        {
            if (test->appointments[i].patientNum != 0)
            {

                if (test->appointments[i].date.year == test->appointments[j].date.year)
                {
                    if (test->appointments[i].date.month == test->appointments[j].date.month)
                    {
                        if (test->appointments[i].date.day > test->appointments[j].date.day)
                        {
                            testApp = test->appointments[i];
                            test->appointments[i] = test->appointments[j];
                            test->appointments[j] = testApp;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < num_items - 1; i++) //selection sort for hour
    {
        for (j = i + 1; j < num_items; j++)
        {
            if (test->appointments[i].patientNum != 0)
            {


                if (test->appointments[i].date.year == test->appointments[j].date.year)
                {
                    if (test->appointments[i].date.month == test->appointments[j].date.month)
                    {
                        if (test->appointments[i].date.day == test->appointments[j].date.day)
                        {
                            if (test->appointments[i].time.hour > test->appointments[j].time.hour)
                            {
                                testApp = test->appointments[i];
                                test->appointments[i] = test->appointments[j];
                                test->appointments[j] = testApp;
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < num_items - 1; i++) //selection sort for min
    {
        for (j = i + 1; j < num_items; j++)
        {
            if (test->appointments[i].patientNum != 0)
            {
                if (test->appointments[i].date.year == test->appointments[j].date.year)
                {
                    if (test->appointments[i].date.month == test->appointments[j].date.month)
                    {
                        if (test->appointments[i].date.day == test->appointments[j].date.day)
                        {
                            if (test->appointments[i].time.hour == test->appointments[j].time.hour)
                            {
                                if (test->appointments[i].time.min > test->appointments[j].time.min)
                                {
                                    testApp = test->appointments[i];
                                    test->appointments[i] = test->appointments[j];
                                    test->appointments[j] = testApp;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i <= AppointCounter; i++)
    {
        if (test->appointments[i].patientNum != 0)
        {
            found = findPatientIndexByPatientNum(test->appointments[i].patientNum, test->patients, MAX_INDEX);
            index[i] = found;
            displayScheduleData(&test->patients[index[i]], &test->appointments[i], showDate);
        }
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int inputYear = 0, inputMonth = 0, inputDay = 0, i = 0, counter = 0;
    int index[MAX_INDEX] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99 };
    int index1[MAX_INDEX] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99 };
    struct ClinicData* testData;
    struct Date testDate;

    testData = data;

    printf("Year        : ");
    scanf(" %d", &inputYear);
    printf("Month (1-12): ");
    scanf(" %d", &inputMonth);
    if (inputYear == 2024 && inputMonth == 2)
    {
        printf("Day (1-29)  : ");
        inputDay = inputIntRange(1, 29);
    }
    else if (inputYear != 2024 && inputMonth == 2)
    {
        printf("Day (1-28)  : ");
        inputDay = inputIntRange(1, 28);
    }
    else
    {
        printf("Day (1-31)  : ");
        inputDay = inputIntRange(1, 31);
    }
    testDate.year = inputYear;
    testDate.month = inputMonth;
    testDate.day = inputDay;

    printf("\n");
    displayScheduleTableHeader(&testDate, 0);
    for (i = 0; i < 15; i++)
    {
        if (testData->appointments[i].date.year == testDate.year)
        {
            if (testData->appointments[i].date.month == testDate.month)
            {
                if (testData->appointments[i].date.day == testDate.day)
                {
                    counter++;
                    index1[i] = i;
                    index[i] = findPatientIndexByPatientNum(testData->appointments[i].patientNum, testData->patients, AppointCounter);

                }

            }
        }
    }

    for (i = 0; i < AppointCounter; i++)
    {
        if ((index[i]!=99) && (index1[i]!=99))
        displayScheduleData(&data->patients[index[i]], &data->appointments[index1[i]], 0);

    }
    printf("\n");
}


// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoint, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int inputPtNum = 0, inputYear = 0, inputMonth = 0, inputDay = 0, i = 0, j = 0, counter = 0, foundPtNum = 0;
    int checkAppHour = 0, checkAppMin = 0, timeCorrect = 0, appCorrect = 0, getNewAppIndex = 0;
    int emptyIndex[50] = { 0 };

    struct Appointment* testApp;
    struct Appointment checkApp;
    struct Patient* testPt;
    testApp = appoint;
    testPt = patients;

    for (i = 0; i < maxAppointments; i++)
    {
        if (testApp[i].patientNum == 0)
        {
            emptyIndex[j++] = i;
            counter++;
        }
    }
    if (counter > 0)
    {
        printf("Patient Number: ");
        scanf(" %d", &inputPtNum);
        foundPtNum = findPatientIndexByPatientNum(inputPtNum, testPt, 20);
        if (foundPtNum > 0)
        {
            do
            {
                appCorrect = 0;
                printf("Year        : ");
                scanf(" %d", &inputYear);
                printf("Month (1-12): ");
                scanf(" %d", &inputMonth);
                if (inputYear == 2024 && inputMonth == 2)
                {
                    printf("Day (1-29)  : ");
                    inputDay = inputIntRange(1, 29);
                }
                else if (inputYear != 2024 && inputMonth == 2)
                {
                    printf("Day (1-28)  : ");
                    inputDay = inputIntRange(1, 28);
                }
                else
                {
                    printf("Day (1-31)  : ");
                    inputDay = inputIntRange(1, 31);
                }
                do
                {
                    timeCorrect = 0;
                    printf("Hour (0-23)  : ");
                    scanf(" %d", &checkAppHour);
                    printf("Minute (0-59): ");
                    scanf(" %d", &checkAppMin);
                    if ((checkAppHour >= START_HOUR && checkAppHour <= END_HOUR)&& ((checkAppMin == 0)||(checkAppMin == 30)))
                    {
                        if ((checkAppHour == END_HOUR) && (checkAppMin == 30))
                        {
                            printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                        }
                        else
                        {
                            checkApp.time.hour = checkAppHour;
                            checkApp.time.min = checkAppMin;
                            timeCorrect = 1;
                        }

                    }
                    else
                    {
                        printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
                    }
                } while (!timeCorrect);

                checkApp.date.year = inputYear;
                checkApp.date.month = inputMonth;
                checkApp.date.day = inputDay;

                for (i = 0; i < AppointCounter; i++)
                {
                    if (testApp[i].date.year == checkApp.date.year)
                    {
                        if (testApp[i].date.month == checkApp.date.month)
                        {
                            if (testApp[i].date.day == checkApp.date.day)
                            {
                                if (testApp[i].time.hour == checkApp.time.hour)
                                {
                                    if (testApp[i].time.min == checkApp.time.min)
                                    {
                                        printf("\n");
                                        printf("ERROR: Appointment timeslot is not available!\n\n");
                                    }

                                }
                                else
                                {
                                    getNewAppIndex = emptyIndex[0];
                                    appoint[getNewAppIndex].date.year = checkApp.date.year;
                                    appoint[getNewAppIndex].date.month = checkApp.date.month;
                                    appoint[getNewAppIndex].date.day = checkApp.date.day;
                                    appoint[getNewAppIndex].time.hour = checkApp.time.hour;
                                    appoint[getNewAppIndex].time.min = checkApp.time.min;
                                    appoint[getNewAppIndex].patientNum = inputPtNum;

                                    printf("\n");
                                    printf("*** Appointment scheduled! ***\n\n");
                                    clearInputBuffer();
                                    appCorrect = 1;
                                }

                            }

                        }
                    }
                }



            } while (!appCorrect);
         }


    }

}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
    int i = 0, counter = 0, inputPtNum = 0, found = 0, matchPtNum = 0;
    int inputYear = 0, inputMonth = 0, inputDay = 0;
    char answer = '\0';
    struct Appointment* checkApp;
    struct Appointment tempCheckingApp;

    checkApp = appointments;

    printf("Patient Number: ");
    scanf(" %d", &inputPtNum);
    for (i = 0; i < AppointCounter; i++)
    {
        if ((checkApp[i].patientNum != inputPtNum) && (checkApp[i].patientNum != 0))
        {
            counter++;
        }
        else
        {
            found++;
        }
    }
    if ((counter > 0)&&(found==0))
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
    if (found > 0)
    {
        printf("Year        : ");
        scanf(" %d", &inputYear);
        printf("Month (1-12): ");
        scanf(" %d", &inputMonth);
        if (inputYear == 2024 && inputMonth == 2)
        {
            printf("Day (1-29)  : ");
            inputDay = inputIntRange(1, 29);
        }
        else if (inputYear != 2024 && inputMonth == 2)
        {
            printf("Day (1-28)  : ");
            inputDay = inputIntRange(1, 28);
        }
        else
        {
            printf("Day (1-31)  : ");
            inputDay = inputIntRange(1, 31);
        }

        tempCheckingApp.date.year = inputYear;
        tempCheckingApp.date.month = inputMonth;
        tempCheckingApp.date.day = inputDay;

        for (i = 0; i < AppointCounter; i++)
        {
            if (checkApp[i].date.year == tempCheckingApp.date.year)
            {
                if (checkApp[i].date.month == tempCheckingApp.date.month)
                {
                    if (checkApp[i].date.day == tempCheckingApp.date.day)
                    {
                        if (checkApp[i].patientNum == inputPtNum)
                        {
                            printf("\n");
                            matchPtNum = findPatientIndexByPatientNum(inputPtNum, patients, MAX_INDEX);
                            if (matchPtNum != -1)
                            {
                                displayPatientData(&patients[matchPtNum], 1);
                                printf("Are you sure you want to remove this appointment (y,n): ");
                                answer = inputCharOption("yn");
                                clearInputBuffer();
                                if (answer == 'y')
                                {
                                    checkApp[i].patientNum = 0;
                                    putchar('\n');
                                    printf("Appointment record has been removed!\n\n");
                                }
                                else
                                {
                                    printf("Operation aborted.\n\n");
                                }
                            }
                        }
                     }

                }
            }
        }

    }

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int inputPatientNum = 0, index = 0, counter = 0;


    printf("Search by patient number: ");
    scanf("%d", &inputPatientNum);
    clearInputBuffer();
    putchar('\n');
    index = findPatientIndexByPatientNum(inputPatientNum, patient, max);
    if (index != -1)
    {
        counter++;
        displayPatientData(&patient[index], counter);
        putchar('\n');
    }
    else
    {
        printf("*** No records found ***\n");
        putchar('\n');
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, found = 0;
    char inputPhoneNum[PHONE_LEN + 1] = { '\0' };
    int index[MAX_INDEX] = { 0 };
    struct Patient test[MAX_INDEX];

    printf("Search by phone number: ");
    scanf(" %s", inputPhoneNum);
    clearInputBuffer();
    putchar('\n');
    for (i = 0; i < max; i++)
    {
        if ((strcmp(inputPhoneNum, patient->phone.number)) == 0)
        {
            found++;
            index[i] = i + 1;
            test[i] = *patient;
        }
        patient++;
    }

    if ((found == 0) && (strlen(inputPhoneNum) == 10))
    {
        displayPatientTableHeader();
        putchar('\n');
        printf("*** No records found ***\n");
        putchar('\n');
    }
    else if ((found == 0) && (strlen(inputPhoneNum) != 10))
    {
        printf("*** No records found ***\n");
        putchar('\n');
    }

    else if (found > 0)
    {
        displayPatientTableHeader();
        for (i = 0; i < max; i++)
        {
            if (index[i] != 0)
            {
                displayPatientData(&test[index[i] - 1], 2);
            }
        }
        putchar('\n');
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0, highPatientNum = 0;
    highPatientNum = patient[0].patientNumber;
    for (i = 0; i < max; i++)
    {

        if (highPatientNum < patient[i].patientNumber)
        {
            highPatientNum = patient[i].patientNumber;
        }

    }
    return highPatientNum + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
            return i;
    }
    return -1;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    char inputName[NAME_LEN] = { '\0' };

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    //scanf(" %[^\n]s", inputName);
    inputCString(inputName, 15, 15);
    clearInputBuffer();
    putchar('\n');
    strcpy(patient->name, inputName);
    inputPhoneData(&patient->phone);

}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection, match = 0;
    char inputPhoneNum[PHONE_LEN + 5];

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");

    selection = inputIntRange(1, 4);
    putchar('\n');

    switch (selection)
    {

    case 1:
        strcpy(phone->description, "CELL");
        printf("Contact: CELL\n");
        printf("Number : ");
        scanf(" %s", inputPhoneNum);
        if (strlen(inputPhoneNum) != 10)
        {
            do
            {
                match = 0;
                printf("Invalid 10-digit number! Number: ");
                scanf(" %s", inputPhoneNum);
                if (strlen(inputPhoneNum) == 10)
                    match = 1;
            } while (!match);
        }
        clearInputBuffer();
        strcpy(phone->number, inputPhoneNum);
        putchar('\n');
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("Contact: HOME\n");
        printf("Number : ");
        scanf(" %s", inputPhoneNum);
        if (strlen(inputPhoneNum) != 10)
        {
            do
            {
                match = 0;
                printf("Invalid 10-digit number! Number: ");
                scanf(" %s", inputPhoneNum);
                if (strlen(inputPhoneNum) == 10)
                    match = 1;
            } while (!match);
        }
        clearInputBuffer();
        strcpy(phone->number, inputPhoneNum);
        putchar('\n');
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("Contact: WORK\n");
        printf("Number : ");
        scanf(" %s", inputPhoneNum);
        if (strlen(inputPhoneNum) != 10)
        {
            do
            {
                match = 0;
                printf("Invalid 10-digit number! Number: ");
                scanf(" %s", inputPhoneNum);
                if (strlen(inputPhoneNum) == 10)
                    match = 1;
            } while (!match);
        }
        clearInputBuffer();
        strcpy(phone->number, inputPhoneNum);
        putchar('\n');
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }


}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;

    FILE* fp = NULL;
    fp = fopen("patientData.txt","r");
    if (fp != NULL)
    {
        while (i < max && fscanf(fp, "%4d|%15[^|]|%4[^|]|%10[^|\n]\n",
            &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description,
            patients[i].phone.number)!=EOF)
        {
            i++;
        }

        fclose(fp);
        fp = NULL;
        return i;
    }
    else
    {
        printf("Failed to open file\n");
    }
    return 0;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i = 0;

    FILE* fp = NULL;
    fp = fopen("appointmentData.txt", "r");
    if (fp != NULL)
    {
        while ((i < max) && fscanf(fp, "%4d,%4d,%d,%d,%2d,%d\n",&appoints[i].patientNum, &appoints[i].date.year,&appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF)
        {
            i++;
            AppointCounter++;
        }

        fclose(fp);
        fp = NULL;

    }
    else
    {
        printf("Failed to open file\n");
    }
    return i;
}
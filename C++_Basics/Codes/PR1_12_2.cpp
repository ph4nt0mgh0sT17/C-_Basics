#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Patient
{
	string Name;
	string Surname;
	string PersonalId;
	string Disease;
	string HealthInsurance;
};

bool hasPatientTuberculosis(Patient patient);
bool hasPatientInsurance(Patient patient);
string* getRecord(string recordString);
Patient getPatient(string *record);
void printPatientsSurnames(Patient *patients, int n);
void printPatientInfo(Patient *patients, int n);

int main(void)
{
	string recordInput;
	Patient *patients = new Patient[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Zadejte prijmeni, jmeno, rodne cislo, nemoc a zdravotni pojistovnu pacienta:" << endl;
		getline(cin, recordInput);
		string *record = getRecord(recordInput);
		patients[i] = getPatient(record);

		delete[] record;
		record = nullptr;
	}

	printPatientInfo(patients, 5);

	delete[] patients;
	patients = nullptr;

#ifndef __PROGTEST__
	system("pause");
#endif /* __PROGTEST__ */

	return 0;
}

bool hasPatientTuberculosis(Patient patient)
{
	return (patient.Disease == "tbc");
}

bool hasPatientInsurance(Patient patient)
{
	return (patient.HealthInsurance == "211");
}

string* getRecord(string recordString)
{
	string *record = new string[5];
	int index = 0;
	bool isPatientStored = false;
	stringstream ss("");
	for (unsigned int i = 0; i < recordString.length(); i++)
	{
		if (recordString.at(i) == ' ')
		{
			if (!isPatientStored)
			{
				isPatientStored = true;
				ss >> record[index];
				ss.clear();
				ss.str("");
				index++;
				continue;
			}

			else
			{
				continue;
			}
		}

		ss << recordString.at(i);
		isPatientStored = false;
	}

	ss >> record[index];

	return record;
}

Patient getPatient(string *record)
{
	Patient patient;
	patient.Surname = record[0];
	patient.Name = record[1];
	patient.PersonalId = record[2];
	patient.Disease = record[3];
	patient.HealthInsurance = record[4];

	return patient;
}

void printPatientsSurnames(Patient *patients, int n)
{
	cout << "Prijmeni vsech pacientu jsou:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << patients[i].Surname << endl;
	}
}

void printPatientInfo(Patient *patients, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (hasPatientTuberculosis(patients[i]))
		{
			cout << "Jmeno a prijmeni pacienta s tbc:" << endl;
			cout << patients[i].Name << " " << patients[i].Surname << endl;
		}

		if (hasPatientInsurance(patients[i]))
		{
			cout << "Jmeno a prijmeni pacientu s pojistovnou 211 je:" << endl;
			cout << patients[i].Name << " " << patients[i].Surname << endl;
		}
	}

	printPatientsSurnames(patients, n);
}


// projekt1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
using namespace std;
//wyswietla populacje w pierwszym dniu
const int MAX_DAYS = 100;
void showPopulation(int day, int susceptible, int infected, int recovered, int total) {
	cout << "Day: " << day << endl;
	cout << "Susceptible: " << susceptible << endl;
	cout << "Infected: " << infected << endl;
	cout << "Recovered: " << recovered << endl;
	cout << "Total: " << total << endl;
}
//symuluje kolejny dzien epidemii
void simulateDay(int& day, int& susceptible, int& infected, int& recovered, int& total, double infectionRate, double recoveryRate, int& newInfections, int& newRecoveries) {
	int newInfected = floor(infected * infectionRate);
	int newRecovered = floor(infected * recoveryRate);

	newInfections = min(newInfected, susceptible);
    newRecoveries = min(newRecovered, infected);
	susceptible = susceptible - newInfections;
	infected = infected + newInfections - newRecoveries;
	recovered = recovered + newRecoveries;
	day++;
	cout << endl;
}
//sprawdzenie poprawnosci danych
bool checkPopulation(int susceptible, int infected, int recovered) {
	if (susceptible >= 0 && infected >= 0 && recovered >= 0 && susceptible + infected + recovered == 100) {
		return true;
	}
	else {
		cout << "Abnormal population status!" << endl;
		return false;
	}
}
//zamiana danych przez uzytkownika
bool changeParameters(double& infectionRate, double& recoveryRate) {
	cout << "Change parameters - infectionRate and recoveryRate in the interval [0,1]; " << endl;
	cin >> infectionRate >> recoveryRate;
	if (infectionRate > 1 || recoveryRate > 1 || infectionRate < 0 || recoveryRate < 0) {
		cout << "Your parameters are incorrect!" << endl;
		return false;
	}
	cout << "Parameters changed" << endl;
	return true;
}
	

int main() {
	int susceptible = 80;
	int infected = 10;
	int recovered = 10;
	int day = 0;
	double infectionRate = 0.20;
	double recoveryRate = 0.10;
	int choice;
	int population_History[MAX_DAYS + 1][3] = {};  //[dzien][3]
	population_History[0][0] = 80;
	population_History[0][1] = 10;
	population_History[0][2] = 10;
	int dailyNewInfections[MAX_DAYS] = {};
	int dailyNewRecoveries[MAX_DAYS] = {};

	do {
		int total = susceptible + infected + recovered;
		showPopulation(day, susceptible, infected, recovered, total);
		cout << endl;
		cout << "=== Epidemic Symulator ===" << endl;
		cout << "1. Simulate next day" << endl;
		cout << "2. Change model parameters" << endl;
		cout << "3. Show simulation history." << endl;
		cout << "4. Exit" << endl;
		cout << "Your choice: " << endl;
		cin >> choice;
		cout << endl;


		switch (choice) {
		case 1:
		{
			int newInfections;
			int newRecoveries;
			cout << "Simulating next day.." << endl;
			if (day < MAX_DAYS) {
				simulateDay(day, susceptible, infected, recovered, total, infectionRate, recoveryRate, newInfections, newRecoveries);
			}
			else {
				cout << "Maximum day reached." << endl;
				break;
			}
			if (!checkPopulation(susceptible, infected, recovered)) {
				break;
			}
			if (day >= 0 && day <= MAX_DAYS) {
				population_History[day][0] = susceptible;
				population_History[day][1] = infected;
				population_History[day][2] = recovered;
			}
			if (day - 1 >= 0 && day - 1 < MAX_DAYS) {
				dailyNewInfections[day - 1] = newInfections;
				dailyNewRecoveries[day - 1] = newRecoveries;
			}
			break;
		}

		case 2:
			changeParameters(infectionRate, recoveryRate);
			break;
		case 3:
			cout << "Population history" << endl;
			for (int i = 0; i <= day; i++) {
				cout << "Day: " << i << endl;
				cout << "Susceptible: " << population_History[i][0] << "\t";
				cout << "Infected: " << population_History[i][1] << "\t";
				cout << "Recovered: " << population_History[i][2] << "\t";
				if (i == 0) {
					cout << "- \t\t\t -";
					cout << endl;
				}
				else {
					cout << "Daily infections: " << dailyNewInfections[i - 1] << "\t";
					cout << "Daily recoveries: " << dailyNewRecoveries[i - 1] << "\t";
					cout << endl;
				}
			} cout << endl;
			break;


		case 4:
			cout << "Exiting epidemic simulator.." << endl;
			break;
		default:
			cout << "Incorrect choice!" << endl;
			break;
		}
		}

		while (choice != 4);


		return 0;
	}




// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
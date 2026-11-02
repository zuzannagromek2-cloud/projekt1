// projekt1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
using namespace std;
//wyswietla populacje w pierwszym dniu
void showPopulation(int day, int susceptible, int infected, int recovered, int total) {
	cout << "Day: " << day << endl;
	cout << "Susceptible: " << susceptible << endl;
	cout << "Infected: " << infected << endl;
	cout << "Recovered: " << recovered << endl;
	cout << "Total: " << total << endl;
}
//symuluje kolejny dzien epidemii
void simulateDay(int& day, int& susceptible, int& infected, int& recovered, int& total, double infectionRate, double recoveryRate) {
	int newInfected = floor(infected * infectionRate);
	int newRecovered = floor(infected * recoveryRate);

	int newInfections = min(newInfected, susceptible);
	int newRecoveries = min(newRecovered, infected);
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
void changeParameters(double& infectionRate, double& recoveryRate) {
	cout << "Change parameters - infectionRate and recoveryRate in the interval [0,1]; " << endl;
	cin >> infectionRate >> recoveryRate;
	if (infectionRate > 1 && recoveryRate > 1 || infectionRate < 0&& recoveryRate < 0) {
		cout << "Your parameters are incorrect!" << endl;
	}
}
	

int main() {
	int susceptible = 80;
	int infected = 10;
	int recovered = 10;
	int day = 0;
	double infectionRate = 0.20;
	double recoveryRate = 0.10;
	int choice;
	do {
		int total = susceptible + infected + recovered;
		showPopulation(day, susceptible, infected, recovered, total);

		cout << "=== Epidemic Symulator ===" << endl;
		cout << "1. Simulate next day" << endl;
		cout << "2. Change model parameters" << endl;
		cout << "3. Exit" << endl;
		cout << "Your choice: " << endl;
		cin >> choice;
		cout << endl;


		switch (choice) {
		case 1:
			cout << "Simulating next day.." << endl;
			simulateDay(day, susceptible, infected, recovered, total, infectionRate, recoveryRate);
			checkPopulation(susceptible, infected, recovered);
			break;
		case 2:
			changeParameters(infectionRate, recoveryRate);
			simulateDay(day, susceptible, infected, recovered, total, infectionRate, recoveryRate);
			checkPopulation(susceptible, infected, recovered);
			break;
		case 3:
			cout << "Exiting epidemic simulator.." << endl;
			break;
		default:
			cout << "Incorrect choice!" << endl;
			break;
		}
	}
	
		while (choice != 3);


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

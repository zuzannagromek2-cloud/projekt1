// projekt1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;
void showPopulation(int day, int susceptible, int infected, int recovered, int total) {
	cout << "Day: " << day << endl;
	cout << "Susceptible: " << susceptible << endl;
	cout << "Infected: " << infected << endl;
	cout << "Recovered: " << recovered << endl;
	cout << "Total: " << total << endl;
}
int main() {
	int susceptible = 80;
	int infected = 10;
	int recovered = 10;
	int day = 0;
	int total = susceptible + infected + recovered;
	double infectionRate = 0.20;
	double recoveryRate = 0.10;
	int choice;
	showPopulation(day, susceptible, infected, recovered, total);

	cout << "=== Epidemic Symulator ===" << endl;
	cout << "1. Simulate next day" << endl;
	cout << "2. Change model parameters" << endl;
	cout << "3. Exit" << endl;
	cout << "Your choice: " << endl;
	cin >> choice;

	switch (choice){
		case 1:
			cout << "Simulating next day.." << endl;
			day++;
			break;
		case 2:
			cout << "Enter infectionRate and recoveryRate:" << endl;
			cin >> infectionRate >> recoveryRate;
			break;
		case 3:
			cout << "Exiting epidemic simulator.." << endl;
			break;
		default:
		 cout << "Incorrect choice!" << endl;
			break;
}


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

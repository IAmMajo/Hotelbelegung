using namespace std;

#include <windows.h>
#include <iostream>
#include <string>

bool rooms [6] [10];

int getInput(const string message, const int maximum) {
  cout <<
    endl <<
    message <<
    endl;
  string input;
  getline(cin, input);

  /* Rückgabe der Eingabe als Zahl, wenn die Eingabe eine Zahl zwischen 1 und
  maximum ist. Ansonsten erfolgt ein Selbstaufruf. */
  return (input.length() == 1 || input.length() == 2 && isdigit(input[1])) &&
    isdigit(input[0]) &&
    stoi(input) > 0 &&
    stoi(input) <= maximum
    ? stoi(input)
    : getInput(message, maximum);
}

void showRooms() {}

void showRoom() {}

void checkIn() {}

void checkOut() {}

int main() {
  /* Ändern der von der Konsole benutzten Zeichenkodierung zu UTF-8, damit
  alle Zeichen richtig dargestellt werden. */
  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);

  while (1) {
    const int action = getInput(
      "Was möchtest du tun?\n1: Den aktuellen Status des gesamten Hotels "
      "abrufen\n2: Den aktuellen Status eines einzelnen Zimmers (frei/belegt) "
      "abrufen\n3: Einchecken\n4: Auschecken",
      4
    );
    action == 1
      ? showRooms()
      : action == 2
      ? showRoom()
      : action == 3
      ? checkIn()
      : checkOut();
  }
}

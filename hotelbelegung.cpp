using namespace std;

#include <windows.h>

bool rooms [6] [10];

int main() {
  /* Änderung der von der Konsole benutzten Zeichenkodierung zu UTF-8, damit
  alle Zeichen richtig dargestellt werden. */
  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
  return 0;
}

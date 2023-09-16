#include <ncurses.h>
#include <string.h>

int main(int argc, char **argv) {

  // Mensagem aparece na tela
  char mesg[] = "Digite uma mensagem: ";
  char str[80];

  // para armazenar o número de linhas e o número de colunas da tela
  int row, col;

  // inicia a ncurses
  initscr();

  // obtém o número de linhas e colunas
  getmaxyx(stdscr, row, col);

  // imprime a mensagem no centro da tela
  mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
  getstr(str);
  mvprintw(LINES - 2, 0, "Você digitou: %s", str);
  getch();
  endwin();

  return 0;
}

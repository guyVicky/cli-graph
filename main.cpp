#include <iostream>
#include <cmath>
#include <curses.h>

using namespace std;

void render_sin(int mid, int p);
void setup_lines(int mid);

int main()
{
    initscr();
    curs_set(0);
    echo();

    int mid = (LINES / 2) + (LINES % 2);
    int p = 2;
    setup_lines(mid);
    render_sin(mid, 2);

    while (1)
    {
        char c = getch();
        switch (c)
        {
        case '+':
            clear();
            refresh();
            setup_lines(mid);
            p += 1;
            render_sin(mid, p);
            break;
        case '-':
            clear();
            refresh();
            setup_lines(mid);
            p -= 1;
            render_sin(mid, p);
            break;
        default:
            break;
        }
    }
    endwin();
    return 0;
}

void render_sin(int mid, int p)
{
    mvprintw(8, 20, "y = sin(x)");
    for (int i = 0; i < COLS; i++)
    {
        int x = mid - (mid - 1) * sin((i * 1.0 / COLS) * M_PI * p);
        mvaddch(x, i, '*');
        refresh();
        napms(20);
    }
}

void setup_lines(int mid)
{
    mvhline(mid, 0, '-', COLS - 1);
    mvaddch(mid, COLS - 1, '>');
    mvvline(0, 0, '|', LINES);
    mvaddch(0, 0, '^');
    mvaddch(LINES - 1, 0, 'v');
}

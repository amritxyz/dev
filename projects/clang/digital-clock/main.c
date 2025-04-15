/*
 * Copyright (C) 2024 amritxyz
 * https://amritxyz.github.io
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "main.h"

int main(void)
{
    int hour = 0, minute = 0, second = 0;
    int rows, cols;

    // Initialize ncurses
    initscr();            // Initialize screen
    timeout(1000);        // Set 1 second timeout for non-blocking input
    noecho();             // Disable input echo
    curs_set(0);          // Hide cursor

    // Get terminal size
    getmaxyx(stdscr, rows, cols);
    int center_row = rows / 2;
    int center_col = (cols - 10) / 2;

    while (1)
    {
        // Move cursor to the center
        move(center_row, center_col);
        clrtoeol(); // Clear the current line

        // Print the time
        printw("%02d : %02d : %02d", hour, minute, second);
        refresh();

        // Update stopwatch time
        second++;
        if (second == 60) {
            minute++;
            second = 0;
        }

        if (minute == 60) {
            hour++;
            minute = 0;
        }

        if (hour == 24) {
            hour = 0;
            minute = 0;
            second = 0;
        }

        sleep(1);
    }

    endwin();
    return EXIT_SUCCESS;
}

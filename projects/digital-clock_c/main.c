#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void
clear_screen_and_move_cursor(int row, int col)
{
	/* Move the cursor to the desired row and column */
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

int main(void)
{
	int hour, minute, second;
	hour = minute = second = 0;

	int rows, cols;

	while (1)
	{
		/* Get the terminal size using the `stty` command (every time before updating) */
		FILE *fp = popen("stty size", "r");
		fscanf(fp, "%d %d", &rows, &cols);
		fclose(fp);

		int center_row = rows / 2;
		int center_col = (cols - 10) / 2; /* 10 is the length of "XX:XX:XX" (time string) */

		/* Clear the terminal and move the cursor to the center */
		system("clear");
		clear_screen_and_move_cursor(center_row, center_col);

		/* Print the time */
		printf("%02d : %02d : %02d", hour, minute, second);
		fflush(stdout);

		/* Update the stopwatch time */
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

	return 0;
}


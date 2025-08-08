#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define NUM_WORMS 4
#define TRAIL_LENGTH 4

sem_t sem; // semaphore to synchronize access to shared resource

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
    int trail[TRAIL_LENGTH][2];
    int last_locations[5][2]; // holds last 5 locations
    int trail_length;
} Worm;
void* wormmove(void* arg) {
    Worm* worm = (Worm*) arg;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (1) {
    // Wait for the semaphore to be unlocked
    sem_wait(&sem);

    // Generate a random direction for the worm to move in
    int index = rand() % 4;
    worm->dx = directions[index][0];
    worm->dy = directions[index][1];

    // Move the worm in its current direction
    int prev_x = worm->x;
    int prev_y = worm->y;
    worm->x += worm->dx;
    worm->y += worm->dy;

    // Add the previous position to the trail
    worm->trail[worm->trail_length % TRAIL_LENGTH][0] = prev_x;
    worm->trail[worm->trail_length % TRAIL_LENGTH][1] = prev_y;
    worm->trail_length++;

    // If the trail length is greater than or equal to 5, replace the last location with a space
    if (worm->trail_length >= 5) {
        int last_x = worm->last_locations[(worm->trail_length - 4) % 5][0];
        int last_y = worm->last_locations[(worm->trail_length - 4) % 5][1];
        mvprintw(last_y, last_x, " ");
    }

    // Save the current position in the last_locations array
    worm->last_locations[worm->trail_length % 5][0] = prev_x;
    worm->last_locations[worm->trail_length % 5][1] = prev_y;

    // If the worm has hit an edge, turn around
    if (worm->y <= 1) {
        worm->dy = 1;
        worm->y = 2;
    } else if (worm->y >= ROWS - 1) {
        worm->dy = -1;
        worm->y = ROWS - 2;
    } else if (worm->x <= 1) {
        worm->dx = 1;
        worm->x = 2;
    } else if (worm->x >= COLS - 1) {
        worm->dx = -1;
        worm->x = COLS - 2;
    } 
    //else if (worm->x = prev_x && worm->y = prev_y){
   
    // Draw the worm's trail
    for (int i = 0; i < TRAIL_LENGTH; i++) {
        int x = worm->trail[i][0];
        int y = worm->trail[i][1];
        if (x != 0 && y != 0 ) {
            mvprintw(y, x, ".");
        }
    }
    // Draw the worm's head at its current position
    mvprintw(worm->y, worm->x, "@");
    // Refresh the screen to show the changes
    refresh();

    // Unlock the semaphore
    sem_post(&sem);

    // Wait for a short time
    usleep(2500);
}

        }


int main() {
    int i;
    pthread_t threads[NUM_WORMS];
    Worm worms[NUM_WORMS] = {{10, 10, 0, 1}, {11, 10, 0, -1}, {12, 10, 1, 0}, {18, 10, -1, 0}};

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    // Set up the outer grid
    char grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
    if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
    grid[i][j] = '+';
    } else {
    grid[i][j] = ' ';
}
}
}
// Print the outer grid
for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
        mvprintw(i, j, "%c", grid[i][j]);
    }
}

// Initialize the semaphore
sem_init(&sem, 0, 1);

// Create the worm threads
for (i = 0; i < NUM_WORMS; i++) {
    pthread_create(&threads[i], NULL, wormmove, (void*) &worms[i]);
}

// Wait for the threads to finish
for (i = 0; i < NUM_WORMS; i++) {
    pthread_join(threads[i], NULL);
}

// Clean up
sem_destroy(&sem);
endwin();

return 0;
}




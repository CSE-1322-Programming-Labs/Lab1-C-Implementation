#include <iostream>
#include <iterator>

//Constants
const int NUM_ROWS = 4;
const int NUM_COLS = 13;

//forward declarations here.
char **make_forward();

void print_array(char **array);

char get_opposite(char curr);

char **get_opposite_car(char **array);

void print_car_crash(char **array, char **opposite_car);


//Main method
int main() {
    print_car_crash(make_forward(), get_opposite_car(make_forward()));
    return 0;
}

//This function will print out a full car crash.
void print_car_crash(char **array, char **opposite_car) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            std::cout << array[i][j];
        }
        for (int k = 0; k < NUM_COLS; k++) {
            std::cout << opposite_car[i][k];
        }
        std::cout << std::endl;
    }
}

//This function will get the opposite car.
char **get_opposite_car(char **array) {
    char **oppositeCar = new char *[NUM_ROWS];

    for (int i = 0; i < NUM_ROWS; i++) {
        oppositeCar[i] = new char[NUM_COLS];
    }


    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            oppositeCar[i][NUM_COLS-j-1] = get_opposite(array[i][j]);
        }
    }

    return oppositeCar;
}

//This method will print the array for us
void print_array(char **array) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}

//This method will return the reverse of whatever was passed into it.
char get_opposite(char curr) {
    switch (curr) {
        case '(':
            return ')';
        case ')':
            return '(';
        case '/':
            return '\\';
        case '\\':
            return '/';
        default:
            return curr;
    }
}

//Return a pointer to a 2d array back to the caller.
char **make_forward() {

    char **pixel = new char *[NUM_ROWS];

    for (int i = 0; i < NUM_ROWS; i++) {
        pixel[i] = new char[NUM_COLS];
    }

    pixel[0][0] = ' ';
    pixel[0][1] = ' ';
    pixel[0][2] = '_';
    pixel[0][3] = '_';
    pixel[0][4] = '_';
    pixel[0][5] = '_';
    pixel[0][6] = '_';
    pixel[0][7] = '_';
    pixel[0][8] = ' ';
    pixel[0][9] = ' ';
    pixel[0][10] = ' ';
    pixel[0][11] = ' ';
    pixel[0][12] = ' ';
    pixel[1][0] = ' ';
    pixel[1][1] = '/';
    pixel[1][2] = '|';
    pixel[1][3] = '_';
    pixel[1][4] = '|';
    pixel[1][5] = '|';
    pixel[1][6] = '_';
    pixel[1][7] = '\\';
    pixel[1][8] = '\'';
    pixel[1][9] = '.';
    pixel[1][10] = '_';
    pixel[1][11] = '_';
    pixel[1][12] = ' ';
    pixel[2][0] = '(';
    pixel[2][1] = ' ';
    pixel[2][2] = ' ';
    pixel[2][3] = ' ';
    pixel[2][4] = '_';
    pixel[2][5] = ' ';
    pixel[2][6] = ' ';
    pixel[2][7] = ' ';
    pixel[2][8] = ' ';
    pixel[2][9] = '_';
    pixel[2][10] = ' ';
    pixel[2][11] = '_';
    pixel[2][12] = '\\';
    pixel[3][0] = '=';
    pixel[3][1] = '\'';
    pixel[3][2] = '-';
    pixel[3][3] = '(';
    pixel[3][4] = '_';
    pixel[3][5] = ')';
    pixel[3][6] = '-';
    pixel[3][7] = '-';
    pixel[3][8] = '(';
    pixel[3][9] = '_';
    pixel[3][10] = ')';
    pixel[3][11] = '-';
    pixel[3][12] = '\'';
    return pixel;
}



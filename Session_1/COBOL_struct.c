#include <stdio.h>
#include <stdint.h>

typedef struct COBOL_struct
{
    char name[21]; // 20 characters + null terminator
    struct {
        uint16_t year; // At least 4 digits
        uint8_t month; // 2 digits
        uint8_t day; // 2 digits
    } date_of_entry;
    float ects_points; // Assuming 3 digits before the decimal and 1 after can be represented by a float
} STUDENT;

int main() {
    STUDENT student = {
        .name = "Emma Fowler",
        .date_of_entry = {
            .year = 2024,
            .month = 2,
            .day = 5
        },
        .ects_points = 125.5f
    };

    // print statements
    printf("Name: %s\n", student.name);
    printf("Date of entry: %u-%u-%u\n", student.date_of_entry.day, student.date_of_entry.month, student.date_of_entry.year);
    printf("ECTS Points: %.1f\n", student.ects_points);

    return 0;
}
typedef struct {
    int array[10];
} returnStackArray;

returnStackArray newArray() {
    returnStackArray returnStackArray;
    for (int i = 0; i < 10; ++i) {
        returnStackArray.array[i] = i;
    }
    return returnStackArray;
}

int main() {
    returnStackArray aw = newArray();
}

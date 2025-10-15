#include <cstring>
#include <iostream>

class information_hiding {
    public:
        information_hiding(const char* name) {
            nameM = new char[strlen(name) + 1];
            strcpy(nameM, name);
        }
        const char* get_name() const {
            return this->nameM;
        }
    private:
        char* nameM;
};

int main() {
    //char* name = "アル";
    char name[] = "Aru";
    information_hiding ex = information_hiding(name);
    std::cout << "Name of example: " << ex.get_name() << std::endl;

    // should be able to move pointer.
    //char* namePointer = ex.get_name();        //can't assign due to const modifier
    //namePointer++;

    std::cout << "Name of example: " << ex.get_name() << std::endl;
};
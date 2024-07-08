#ifndef ATRONAUT_H
#define ASTRONAUT_H

#include <string>
#include <vector>

class Astronaut {
    private:
        std::string name, cpf;
        int status;
        std::vector<int> idOfJourneys;

    public:
        Astronaut(std::string name, std::string cpf);
        void setStatus(int value);
        void showAstronaut();
        void addId(int id);
        void showId();
        int getStatus() const;
        std::string getName() const;
        std::string getCpf() const;
};

#endif
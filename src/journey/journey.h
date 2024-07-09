#ifndef JOURNEY_H
#define JOURNEY_H

#include "../astronaut/astronaut.h"
#include <vector>
#include <iostream>

class Journey
{
private:
    int id, status;
    std::vector<Astronaut> astrosInJourney;

public:
    Journey(int id);

    void addAstronaut(Astronaut astronaut);
    void removeAstronaut(const std::string cpf, int idAux);
    void listAstronaut() const;
    void changeJourneyStatus(int status);
    void removeAstronautByCpf(std::string cpfToBeRemoved, int id);

    std::vector<Astronaut> getAstrosInJourney();
    int getID();
    int getStatus();
    void setStatus(int status);

    ~Journey();
};

#endif
#ifndef JOURNEY_H
#define JOURNEY_H

#include "../astronaut/astronaut.h"
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>s

class Journey{
    private:
    int id, status;
    std::vector<std::shared_ptr<Astronaut>> astrosInJourney;

    public:
    Journey(int id);

    void addAstronaut(std::shared_ptr<Astronaut> astronaut);
    void removeAstronaut(const std::string cpf);
    void listAstronaut() const;
    void changeJourneyStatus(int status);
    void removeAstronautByCpf(std::string cpfToBeRemoved);
    
    std::vector<std::shared_ptr<Astronaut>>& getAstrosInJourney();
    int getID();
    int getStatus();
    void setStatus(int status);
    
    ~Journey();
};

#endif
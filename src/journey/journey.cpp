#include "journey.h"
#include <iostream>
#include <vector>

using namespace std;

Journey::Journey(int num) : id(num), status(1) {};

void Journey::addAstronaut(Astronaut astronaut)
{
    astrosInJourney.push_back(astronaut);
}

void Journey::removeAstronautByCpf(std::string cpfToBeRemoved, int id)
{
    for (auto it = astrosInJourney.begin(); it != astrosInJourney.end(); ++it)
    {
        if (it->getCpf() == cpfToBeRemoved)
        {
            printf("encontrei");
            astrosInJourney.erase(it);
            continue;
        }
    }

    printf("num ");
}

void Journey::changeJourneyStatus(int status)
{

    if (status == 0)
    {
        this->status = 0;
        std::cout << "A viagem foi finalizada sem êxito!" << std::endl;
        for (int i = 0; i < astrosInJourney.size(); i++)
        {
            astrosInJourney[i].setStatus(0);
        }
    }
    else if (status == 2)
    {
        this->status = 2;
        std::cout << "A viagem foi lançada com sucesso!" << std::endl;
        for (int i = 0; i < astrosInJourney.size(); i++)
        {
            astrosInJourney[i].setStatus(2);
        }
    }
    else if (status == 3)
    {
        this->status = 3;
        std::cout << "A viagem foi finalizada com êxito!" << std::endl;
        for (int i = 0; i < astrosInJourney.size(); i++)
        {
            astrosInJourney[i].setStatus(1);
        }
    }
}

std::vector<Astronaut> Journey::getAstrosInJourney()
{
    return astrosInJourney;
}

int Journey::getID()
{
    return id;
}

int Journey::getStatus()
{
    return status;
}

Journey::~Journey() {}
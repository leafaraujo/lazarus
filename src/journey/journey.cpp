#include "journey.h"

Journey::Journey(int num){
    int id = num;
    int status = 1;
}

void Journey::addAstronaut(std::shared_ptr<Astronaut> astronaut){
    astrosInJourney.push_back(astronaut);
}

void Journey::removeAstronautByCpf(std::string cpfToBeRemoved){
    auto it = std::find_if(astrosInJourney.begin(), astrosInJourney.end(),
                               [cpfToBeRemoved](const std::shared_ptr<Astronaut>& astronaut) {
                                   return astronaut->getCpf() == cpfToBeRemoved;
                               });

        if (it != astrosInJourney.end()) {
            astrosInJourney.erase(it);
            std::cout << "Astronauta com CPF " << cpfToBeRemoved << " removido da jornada." << std::endl;
        } 
        else {
            std::cout << "Astronauta com CPF " << cpfToBeRemoved << " não encontrado na jornada." << std::endl;
        }
}

void Journey::changeJourneyStatus(int status){
    
    if(status == 0){
        this->status = 0;
        std::cout << "A viagem foi finalizada sem êxito!" << std::endl;
        for(int i =0; i < astrosInJourney.size(); i++){
            astrosInJourney[i]->setStatus(0);
        }
    }
    else if(status == 2){
        this->status = 2;
        std::cout << "A viagem foi lançada com sucesso!" << std::endl;
        for(int i =0; i < astrosInJourney.size(); i++){
            astrosInJourney[i]->setStatus(2);
        }
    }
    else if(status == 3){
        this->status = 3;
        std::cout << "A viagem foi finalizada com êxito!" << std::endl;
        for(int i =0; i < astrosInJourney.size(); i++){
            astrosInJourney[i]->setStatus(1);
        }
    }
}

std::vector<std::shared_ptr<Astronaut>>& Journey::getAstrosInJourney(){
    return astrosInJourney;
}

int Journey::getID(){
    return id;
}

int Journey::getStatus(){
    return status;
}

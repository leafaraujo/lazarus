#include "astronaut.h"
#include <iostream>

Astronaut::Astronaut(std::string personName, std::string personCPF){
    name = personName;
    cpf = personCPF;
    status = 1;
}

void Astronaut::setStatus(int personStatus){
    this->status = personStatus;
}

int Astronaut::getStatus() const{
    return status;
}

std::string Astronaut::getName() const{
    return name;
}

std::string Astronaut::getCpf() const{
    return cpf;
}

void Astronaut::addId(int id){
    idOfJourneys.push_back(id);
}

void Astronaut::showId(){
    int journeys = idOfJourneys.size();
    if(journeys == 0){
        std::cout << "Ele não está cadastrado em nenhuma viagem." <<std::endl;
    }
    else if(journeys == 1){
        std::cout << "Ele está cadastrado na viagem com ID: " << idOfJourneys[0] << std::endl;
    }
    else{
        std::cout << "Ele está cadastrado nas seguintes viagens: " << std::endl;
        for(int i = 0; i < journeys ; i++){
            std::cout << "ID: " << idOfJourneys[i] << std::endl;
        }
    }
}

void Astronaut::showAstronaut(){
    std::cout << "Nome: " << name << std::endl;
    std::cout << "CPF: " << cpf << std::endl;
    if(status == 1){
        std::cout << "Status: Vivo"<< std::endl;
    }
    else if(status == 0){
        std::cout << "Status: Morto"<< std::endl;
    }
    else{
        std::cout << "Status: Em viagem"<< std::endl;
    }
}
#ifndef TORNO_H
#define TORNO_H

#include "Maquina.h"
#include "Motor.h"

namespace planta {

class Torno : public Maquina {
private:
    Motor husillo;  // composicion: el husillo vive y muere con el torno

    void ejecutarCiclo() override;

public:
    explicit Torno(const std::string& nombre);

    int tiempoCicloSeg() const override;
};

}  // namespace planta

#endif
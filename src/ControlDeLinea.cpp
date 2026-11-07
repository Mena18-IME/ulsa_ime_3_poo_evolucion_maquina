#include "ControlDeLinea.h"

#include <algorithm>
#include <iostream>

namespace planta {

bool ControlDeLinea::agregar(Maquina* maquina) {
    if (maquina == nullptr) {
        return false;
    }
    if (std::find(maquinas.begin(), maquinas.end(), maquina) != maquinas.end()) {
        return false;  // duplicada
    }
    maquinas.push_back(maquina);
    return true;
}

void ControlDeLinea::ejecutarTurno(int ciclos) {
    for (Maquina* m : maquinas) {
        for (int i = 0; i < ciclos; i++) {
            m->procesar();
        }
    }
}

void ControlDeLinea::imprimirReporte() const {
    std::cout << "--- Reporte de la linea ---\n";
    if (maquinas.empty()) {
        std::cout << "La linea no tiene maquinas\n";
        return;
    }
    int total = 0;
    for (const Maquina* m : maquinas) {
        m->mostrarEstado();
        total += m->getPiezasProcesadas();
    }
    std::cout << "Total de piezas: " << total << '\n';
}

} 
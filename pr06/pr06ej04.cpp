// Examen diciembre de 2018

bool mismosElementos(Pila &p, Cola &c) {
    while (!esVaciaPila(p) && !esVaciaCola(c) &&
           primeroEnPila(p) == primeroEnCola(c)) {
        desapilar(p);
        desencolar(c);
    }
    if (esVaciaPila(p) && esVaciaCola(c))
        return true;
    else {
        vaciarPila(p);
        vaciarCola(c);
        return false;
    }
}

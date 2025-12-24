# Visualizzatore di Frattali di Julia in C/SDL

Questo progetto implementa un motore di rendering grafico per la visualizzazione degli **Insiemi di Julia** nel piano complesso, utilizzando la libreria **SDL2 (Simple DirectMedia Layer)**.

## Fondamenti Matematici

L'insieme di Julia $J_c$ per una funzione olomorfa $f(z) = z^2 + c$ è definito come il confine (boundary) dell'insieme dei punti che non divergono all'infinito sotto l'iterazione della successione ricorsiva:

$$z_{n+1} = z_n^2 + c$$

Dove $z$ e $c$ sono numeri complessi $\in \mathbb{C}$. Il comportamento dinamico di questa successione determina la morfologia del frattale:
- Se la successione $\{z_n\}$ è limitata, il punto $z_0$ appartiene all'insieme di Julia "pieno".
- Se $|z_n| \to \infty$, il punto appartiene al set di Fatou.

[Image of Julia set on the complex plane]

## Rappresentazione nel Piano di Gauss

Per la visualizzazione grafica, il software opera un **isomorfismo** tra lo spazio discreto dei pixel dello schermo e una regione rettangolare del **Piano di Gauss**. 

### Mapping delle Coordinate
Ogni pixel $(u, v)$ della finestra viene mappato in un numero complesso $z = x + iy$ mediante una trasformazione lineare:
- **Asse Reale ($Re$):** $x = x_{min} + \frac{u}{Width} \cdot (x_{max} - x_{min})$
- **Asse Immaginario ($Im$):** $y = y_{max} - \frac{v}{Height} \cdot (y_{max} - y_{min})$

Questo permette di esplorare il frattale variando i limiti del dominio e osservando i dettagli a diverse scale (zoom).

## Implementazione dell'Algoritmo (Escape Time)

Il rendering utilizza l'algoritmo **Escape Time**. Per ogni pixel, calcoliamo il numero di iterazioni necessarie affinché il modulo del numero complesso superi la soglia di fuga (solitamente $|z| > 2$).

1. **Iterazione Complessa:** Il calcolo è ottimizzato espandendo $z^2 + c$ nelle sue componenti reali:
   - $x_{n+1} = x_n^2 - y_n^2 + c_{re}$
   - $y_{n+1} = 2x_n y_n + c_{im}$
2. **Colorazione:** Il colore del pixel è funzione del numero di iterazioni compiute, fornendo una rappresentazione visiva della velocità di divergenza.

## Caratteristiche del Software
- **Preset di Costanti:** Accesso rapido a valori noti di $c$ (es. Dendrite, Coniglio di Douady, Galassie).
- **Rendering Dinamico:** Utilizzo dei buffer di memoria SDL per una visualizzazione fluida del piano gaussiano.
# Session 1 · Hello, physical world

**Tue 03/11** · _Tangible interaction, Arduino, basic electricity, a first LED circuit_

**Team:** _Eira Turró, Xènia Gual, Carla Milene_

---

## Challenge: Signal light

Design a signal with LEDs and a buzzer that means something to someone: a heartbeat, “wait”, “go”, an alarm, SOS…

**Must have**

- [x] At least 2 LEDs, each with a correct resistor
- [x] A pattern with 3 timings: short, medium, long (e.g. 150, 400, 1000 ms)
- [x] Timings stored in variables, not typed in `delay()`
- [x] Wires in the right colours

**Hand in by 11:30**

- Code
- Photo of the circuit

---

## What we built

Un senyal SOS en codi Morse amb Arduino: dos LEDs i un brunzidor s’encenen i sonen alhora.
La S és curta (400 ms), la O és més llarga (1000 ms) i un remat final de 3 segons tanca la paraula.

## Materials

| Component / material | Quantity | Notes                                |
| -------------------- | -------- | ------------------------------------ |
| Arduino Uno          | 1        |                                      |
| Cable USB            | 1        |                                      |
| Protoboard           | 1        |                                      |
| Resistencies         | 2        |                                      |
| Brunzidor            | 1        |                                      |
| Jumpers              | 7        | 2 blancs, 2 negre, 2 groc, 1 taronja |

## Photo

![Automatic night light: photo](media/photo-1.jpeg")
![Automatic night light: photo](media/photo-2.jpeg")
![Automatic night light: photo](media/photo-3.png")

## Video

"video_proj1.mp4"

## Code

- Arduino sketch: [`ti01/ti01.ino`](ti01/ti01.ino)

## Problems and fixes

Al principi, el més difícil va ser entendre com funcionava, perquè mai no ho havíem fet. Ens hi vam quedar més estona, fins a la una, per provar-ho fora de classe, i al final ens va sortir.

## Going further

Des del principi volíem traduir el codi Morse. No hem anat gaire més enllà, però hem jugat amb els ritmes i amb les pauses.

## Use of AI

Vam demanar a la IA, per començar, com funcionava el codi Morse (senyals curts i llargs). A l’hora d’escriure el codi, però, el vam fer nosaltres: les seves respostes no donaven els temps en números com demanàvem i, a més, no les enteníem. Al final li vam demanar que el revisés i ens va detectar una errada d’escriptura en una paraula, que ens va servir perquè el codi acabés de funcionar.

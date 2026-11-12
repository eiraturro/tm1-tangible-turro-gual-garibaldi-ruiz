# Session 3 · Sensing the environment

**Tue 10/11** · _Light, temperature, distance, pressure, knock and sound sensors; thresholds_

**Team:** _Eira Turró, Raul Ruiz, Xènia Gual, Carla Milene_

---

## Challenge: Automatic night light

A light that turns on by itself when the room goes dark, for a real place: a hallway, a child’s room, a stair.

**Must have**

- [x] LDR reading the room light
- [x] Turns on in the dark, off in the light, no flicker (two thresholds)
- [x] Thresholds come from your own measurements
- [x] Inside or on an object, not a bare breadboard
- [x] **One more sense:** only on when someone is near (distance), **or** a knock/clap overrides it, **or** brighter when it is cold (DHT11 + PWM)

**Hand in by 11:30**

- Code
- Video

---

## What we built

El projecte consisteix en una caixa amb aparença de regal que incorpora un sistema d'il·luminació i so automàtic.

Quan la caixa està tancada, el LED roman apagat i no s'emet cap so. En canvi, quan s'obre, s'encén automàticament la llum LED. A més, el sistema incorpora un sensor de so que detecta un soroll fort, com ara un aplaudiment, i activa una melodia. En el nostre prototip actual, en detectar el so, es reprodueix una única nota, però la idea final és que soni la cançó de «Per molts anys» o alguna altra melodia d'aniversari.

Un cop la melodia s'ha acabat, el sistema deixa de reproduir música. Finalment, quan es torna a tancar la caixa i deixa d'entrar-hi llum, el LED s'apaga automàticament i el sistema torna al seu estat inicial.

## Materials

| Component / material    | Quantity | Notes                                           |
| ----------------------- | -------- | ----------------------------------------------- |
| Arduino Uno             | 1        |                                                 |
| Cable USB               | 1        |                                                 |
| Protoboard              | 1        |                                                 |
| Sensor LDR              | 1        |                                                 |
| Sensor de so / microfòn | 1        |                                                 |
| Buzzer                  | 1        |                                                 |
| Resistencies            | 2        |                                                 |
| Led                     | 1        |                                                 |
| Jumpers                 | 12       | 3 vermells, 3 grocs, 3 blancs, 1 blau, 2 negres |

## Photo

![Automatic night light: photo](media/photo-1.jpeg")

## Video

"video_proj3.mp4"

## Code

- Arduino sketch: [`ti03/ti03.ino`](ti03/ti03.ino)

## Your measurements

| Situation                  | LDR value (light) | Sound sensor value |
| -------------------------- | ----------------- | ------------------ |
| Room light - caixa oberta  | light >= 80       | ---------          |
| Dark - caixa tancada       | light < 80        | ---------          |
| **Threshold ON** (below)   | 80 or above       | ---------          |
| **Threshold OFF** (above)  | Below 80          | ---------          |
| No sound                   | ---------         | <= 100             |
| Applause / loud sound      | ---------         | > 100              |
| **Threshold ON** (buzzer)  | ---------         | > 100              |
| **Threshold OFF** (buzzer) | ---------         | <= 100             |

## Problems and fixes

- Connexió del LED: Teníem el LED connectat al voltatge i, per això, funcionava al revés del que indicàvem al codi (HIGH i LOW).
- Codi: Ens va costar aconseguir que el so només sonés quan féssim un aplaudiment i no automàticament en obrir la caixa. Primer s'havia d'encendre el LED amb la llum i, després, en detectar un aplaudiment, havia de sonar la melodia.
- Sensor analògic: Al principi ens va costar entendre com funcionava i com interpretar els valors que ens proporcionava el sensor analògic.

## Going further

La nostra idea inicial era que, en detectar un aplaudiment, sonés la cançó de «Per molts anys». Tot i això, com que hem fet un prototip, de moment només hem aconseguit reproduir una única nota o so.

## Use of AI

La IA ens ha ajudat sobretot a l'inici del projecte, quan estàvem perduts i no sabíem com començar el codi. Ens ha proporcionat una primera base i ens ha ajudat a afegir comentaris per entendre'l millor. Tot i això, algunes explicacions eren complicades i, finalment, hem acabat de completar i entendre el codi gràcies a les explicacions i l'ajuda d'en Jordi.

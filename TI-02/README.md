# Session 2 · Digital and analog inputs

**Thu 05/11** · _Buttons, pull-up resistors, edge detection, Serial Monitor, potentiometer, PWM, `map()`_

**Team:** _Eira Turró, Raul Ruiz, Xènia Gual_

---

## Challenge: Hand-dimmed lamp (graded)

**Must have**

- [x] A potentiometer controls brightness smoothly
- [x] A button toggles the lamp on and off
- [x] Brightness is kept when you switch back on
- [x] The Serial Monitor shows the knob value

**Hand in by 11:30**

- Code
- A 10-second video

---

## What we built

Hem construït una làmpada per posar a l'entrada de l'habitació d'un adolescent. La seva funció és comunicar als altres si té ganes de socialitzar o prefereix estar sol.

Quan la llum està molt intensa, significa que no vol que ningú entri ni el molesti. Quan la llum és més fluixa, significa que està més obert a socialitzar. Quan la llum està apagada, vol dir que està disponible i que els altres poden entrar.

La intensitat es regula amb un potenciòmetre i es pot encendre o apagar amb un botó.

## Materials

| Component / material | Quantity | Notes |
| Arduino Uno | 1 | |
| Cable USB | 1 | |
| Protoboard | 1 | |
| Resistencies | 1 | |
| Led | 1 | |
| Button | 1 | |
| Potenciòmetre | 1 | |
| Jumpers | 8 | 2 blancs, 2 negres, 2 grocs, 1 taronja, 1 vermell|

## Photo

![Automatic night light: photo](media/photo-1.jpeg")
![Automatic night light: photo](media/photo-2.jpeg)

## Video

"video_proj2.mp4"

## Code

- Arduino sketch: [`ti02/ti02.ino`](ti02/ti02.ino)

## The toggle

// int state = digitalRead(BUTTON_PIN);

if (lastState == HIGH && state == LOW) {
on = !on;
delay(30);
}
lastState = state;

## Problems and fixes

Ens ha costat entendre els termes a l'Arduino, perquè tot el tema de muntar sí que ens ha sortit.

## Going further

No hem fet més enllà perquè no ens ha donat temps, però sí he hem afegit el detall de quan regulem la intensitat el valor més baix és de 50, no de 0 perquè 0 és quan cliques el botó d'apagat.

## Use of AI

Ens ha ajudat a corretgir temes del codi, a trobar errors i a fer-nos comentaris per entendre les coses. A més, ens ha ajudat amb el funcionament de regular la intensitat, que en un inci no ho haviem aconseguit fer.

<details>
  <summary>Tema 2</summary>

  # Cerința temei:
  Crearea unui joc asemănător cu TypeRacer

  # Descrierea task-ului
  În acest proiect, vom crea un joc de tip TypeRacer care include funcționalități de start/stop pentru rundă, selectarea dificultății și afișarea unui indicator de stare prin intermediul unui LED RGB.

  ### LED RGB - Indicator de stare:
  - **Stare de repaus:** LED-ul va lumina alb.
  - **Pornire runda:** După apăsarea butonului de start, LED-ul va clipi timp de 3 secunde, indicând o numărătoare inversă până la începutul rundei.
  - **În timpul rundei:** LED-ul va fi verde atunci când textul introdus este corect și se va schimba în roșu dacă apare o greșeală.

  ### Buton Start/Stop:
  - **Modul de repaus:** Dacă jocul este oprit, apăsarea butonului va iniția o nouă rundă după o numărătoare inversă de 3 secunde.
  - **În timpul rundei:** Dacă runda este activă, apăsarea butonului va opri runda imediat.

  ### Butonul de dificultate:
  - **Selectarea dificultății:** Acest buton controlează viteza cu care apar cuvintele în timpul jocului și poate fi utilizat doar atunci când jocul este în stare de repaus.
  - **Ciclarea dificultății:** La fiecare apăsare a butonului, dificultatea va schimba între modurile `Easy`, `Medium` și `Hard`.
  - **Mesaj de confirmare:** La schimbarea dificultății, un mesaj de tipul “Easy/Medium/Hard mode on!” va fi transmis prin serial.

  ### Generarea cuvintelor:
  - **Dicționar de cuvinte:** Se va crea o listă de cuvinte care vor fi folosite în timpul jocului.
  - **Afișarea cuvintelor:** În fiecare rundă, cuvintele vor fi afișate în terminal într-o ordine aleatorie.
  - **Validarea cuvintelor:** Dacă jucătorul scrie corect cuvântul afișat, următorul cuvânt va apărea imediat. În caz de greșeală, un nou cuvânt va apărea după un interval specific, în funcție de dificultatea selectată.

  ### Alte observații:
  - **Durata rundei:** Fiecare rundă are o durată fixă de 30 de secunde.
  - **Rezultate:** La finalul fiecărei runde, se va afișa în terminal numărul de cuvinte scrise corect.

  # Componente utilizate
  - Arduino UNO (ATmega328P microcontroller)
  - 1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
  - 2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
  - 5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
  - Breadboard
  - Fire de legătură

  # Poze ale setup-ului fizic
  ![Imagine WhatsApp 2024-11-06 la 00 09 06_14701aef](https://github.com/StefanAdrian2003/Teme-Robotica/blob/main/Tema2/media/1.jpg)
  ![Imagine WhatsApp 2024-11-06 la 00 09 07_a03e628d](https://github.com/StefanAdrian2003/Teme-Robotica/blob/main/Tema2/media/2.jpg)
  ![Imagine WhatsApp 2024-11-06 la 00 09 07_eb885a7e](https://github.com/StefanAdrian2003/Teme-Robotica/blob/main/Tema2/media/3.jpg)
  ![Imagine WhatsApp 2024-11-06 la 00 09 08_5c36632d](https://github.com/StefanAdrian2003/Teme-Robotica/blob/main/Tema2/media/4.jpg)

  # Video cu funcționalitatea montajului fizic
  [Watch the demo video](https://github.com/StefanAdrian2003/Teme-Robotica/blob/main/Tema2/media/video.mp4)

  # Schema electrică
  ![image](https://github.com/user-attachments/assets/63aef517-2f51-4c86-b28e-1833cfb0421c)

  
</details>




<details>
  <summary>Tema 3: Quick Time</summary>
  
  # Descrierea task-ului:
În acest proiect, vom dezvolta un joc competitiv de reflexe pentru doi jucători, care vor concura pentru a obține cel mai mare punctaj. Jocul testează viteza de reacție și include mai multe runde. 

- **Fiecare jucător:** are propriile LED-uri și butoane. LED-urile RGB indică culoarea activă, iar scopul este ca jucătorul să apese rapid butonul corespunzător culorii afișate.
- **Afișarea scorurilor:** se realizează pe un LCD și este actualizată în timp real.
- **Finalul jocului:** jucătorul cu cel mai mare punctaj este declarat câștigător.

---

## **Componente utilizate**
- **6x LED-uri** (2 grupuri a câte 3 LED-uri, fiecare grup cu culori diferite)
- **2x LED RGB** (1 pentru fiecare jucător)
- **6x Butoane** (3 pentru fiecare jucător)
- **1x LCD**
- **1x Servomotor** (pentru indicarea progresului sau timpul final)
- **2x Breadboard**
- **Fire de legătură**
- **2x Arduino UNO**

---

## **Implementare**

### **1. Inițializare joc**
- Jocul începe cu afișarea unui mesaj de bun venit pe LCD.
- Apăsarea unui buton declanșează startul jocului. Posibilități pentru implementare:
  - Apăsarea oricărui buton.
  - Buton dedicat pentru startul jocului (marcat pe breadboard).
  - Buton suplimentar pentru start/resetare.

---

### **2. Desfășurarea rundelor**
- **Fiecare jucător:** are asociate 3 butoane și un LED RGB.
- **La începutul fiecărei runde:** LED-ul RGB al jucătorului activ se aprinde într-o culoare specifică.
- **Jucătorul activ:** apasă cât mai rapid butonul corespunzător culorii afișate. Punctajul este acordat pe baza vitezei de reacție.
- **Actualizarea scorului:** pe LCD după fiecare rundă.

---

### **3. Timpul și finalizarea jocului**
- **Servomotorul:** indică progresul rundelor și se rotește complet la sfârșitul jocului.
- **La final:** LCD-ul afișează numele câștigătorului și scorul final.

---

## **Detalii tehnice**

### **1. Comunicarea SPI între 2 plăci Arduino**
- **Master Arduino UNO:** Controlează LCD-ul și servomotorul, monitorizând punctajele.
- **Slave Arduino UNO:** Controlează butoanele și LED-urile jucătorilor, trimițând informații către master.

### **2. Implementarea butoanelor**
- Fiecare jucător are 3 butoane corespunzătoare celor 3 LED-uri de culori diferite.
- Multiplexarea butoanelor se poate realiza pentru a reduce numărul de pini utilizați.

### **3. LED-urile**
- LED-urile RGB indică culorile pentru butoanele jucătorilor.
- LED-urile trebuie să se stingă când nu este rândul unui jucător.

### **4. LCD**
- Utilizează biblioteca `LiquidCrystal` pentru control.
- Afișează punctajele în timp real.

### **5. Servomotorul**
- Indică progresul jocului prin rotații.

---

## **Libertatea de personalizare**
- Punctajele acordate pe baza vitezei de reacție.
- Intervalul de timp dintre runde.
- Durata totală a jocului.

---

## **Schema electrică**
Urmează să fie realizată o schemă electrică detaliată utilizând Fritzing pentru conectarea tuturor componentelor (Arduino UNO, butoane, LED-uri, LCD, servomotor).

---

## **Concluzii**
Proiectul "Quick Time" este un joc de reflexe care testează viteza de reacție a jucătorilor și include multiple componente hardware pentru funcționalități interactive. Acesta reprezintă o oportunitate excelentă de a lucra cu comunicarea SPI între două plăci Arduino și de a integra mai multe module într-un singur sistem.


  
</details>

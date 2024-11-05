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
  [Watch the demo video]()

  # Schema electrică
  ![image](https://github.com/user-attachments/assets/63aef517-2f51-4c86-b28e-1833cfb0421c)

  
</details>

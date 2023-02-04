                Algoritmi Hibrizi de Sortare
    Pentru a implementa programul se rulează comanda "make" care 
creează fișierele generareTeste, timSort, introSort, verify după care 
rulează scriptul cleaning.sh și script.sh
    Pentru a rula algoritmul TimSort se rulează comanda "make run-p1".
Pentru a rula algoritmul IntroSort se rulează comanda "make run-p2".
Pentru a rula cel mai bun agoritm(în urma analizelor s-a depistat
TimSort ca fiind un algoritm mai efectiv) se rulează "make run-best".
    Pentru a efectua o verificare a corectitudinii sortării se rulează 
comanda "make result" în urma căreia în folderul ./out apare 
rezultatul verificării tuturor testelor.

    Comenzile "make run-p1", "make run-p2" și "make run-best" 
creează un fișier în folderul ./out denumit runtimeResult.txt în 
care apar toate rulările testelor cu runtime-ul lor plus o statistică 
de tipul Best, Medium și Worst runtime.

    Scriptul script.sh oferă posibilitate userului să aleagă câte 
teste de input vrea acesta să creeze și câte valori să existe în 
aceste fișiere.
    În primă instanță scriptul verifică daca există sau nu folderele 
de in și out și le creează dacă acestea lipsesc.
    Primul for creează un fișier de numere de input și un fișier 
în care va păstra un set de numere de la 1 la numărul de teste ales 
de user acestea fiind seedul pentru funția random.
    Al doilea for însă folosește programul generareTeste pentru a 
genera testele cu valori complet random și care nu se vor asemăna 
între ele.

    Programul generareTeste folosește ca input seedul din script și 
creează la fiecare iterație din for-ul din script câte un fișier de 
test cu numere random.

    Programul introSort într-un for deschide fișierul testX.in, 
X fiind numărul testului, citește valorile într-un array după care 
aplică algoritmul de IntroSort pe acel array. Totodată programul 
calculează runtime-ul de rulare pentru fiecare test și îl pune 
într-un alt array pentru ca ulterior acesta să apară în fișierul 
runtimeResult.txt.

    Programul timSort face același lucru ca și programul 
de mai sus cu singura diferență că aplică pe array algoritmul 
TimSort.

    Programul verifyProgramm folosește ca fișiere de intrare 
fișierele din folderul ./out și verifică corectitudinea sortării 
valorile în acele fișiere prin compararea pas cu pas a câte 
două numere alăturate. Dacă nu gasește greșeli programul scrie 
în fișierul ./out/verifyProgramm.txt TestX passed sau failed dacă 
măcar o valoare nu este sortată corect.

    Scriptul clening.sh va rula doar în momentul în care userul 
după ce a dat comanda make nu a date make clean și va șterge astfel 
fișierele de in și out.



Butcan Vlad 325CD

Algoritm IntroSort:
https://www.programmingalgorithms.com/algorithm/intro-sort/c/

Algoritm TimSort rescris din C++ în C:
https://www.geeksforgeeks.org/timsort/

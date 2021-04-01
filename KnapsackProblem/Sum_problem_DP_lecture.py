def suma_1(zbior, cel):
    DP = [False] * (cel + 1)  # dp[i] mowi nam czy jestesmy z podanego zbioru w stanie stworzyc
    # liczbe True - mozemy False - nie mozemy  dp[0] = 1 bo liczbe 0 mozemy stworzyc nie biorac zadnego
    # elementu, jest to nasz stan brzegowy.
    DP[0] = True
    #taktyka jest prosta, jeśli potrafimy stworzyć liczbę i to na pewno potrafimy
    #stworzyc tez liczbe i + k, gdzie k to aktualnie rozpatrywana liczba ze zbioru
    for liczba in zbior:
        # to_update = []
        # for i in range(0, cel - liczba + 1): # iterujemy sie tylko do cel - liczba
        #     #aby nie wyleciec poza tablice, pozatym rozpatrywanie liczb wiekszych od celu nie ma sensu
        #     if(DP[i] == True):
        #         to_update.append(i+liczba) #dostaniemy nieprawidlowa odpowiedz takie
        #         #cos spowoduje ze wszystkie wielokrotnosci zmiennej liczba dostana
        #         #wartosc True a kazda liczbe mozemy uzyc tylko 1 raz
        # for x in to_update:
        #     DP[x] = True
        for i in range(cel-liczba, -1, -1):
            if (DP[i] == True):
                DP[i+liczba] = True

    print(DP)
    print(DP[-1])

def suma_2(zbior, cel):
    s = sum(zbior)
    DP2 = [0] * (s+1) #Tutaj przechowujemy informacje o tym czy mozemy stworzyc dana liczbe
    DP2[0] = 1 #0 mozemy stworzyc zawsze
    ile = [0] * (s+1) # w tej tablicy przechowujemy ilosc wystapien w zbiorze kolejnych liczb
    C = [0] * (s+1) # W tej bedziemy przechowywac liczbe potrzebnych liczb typu k do stworzenia wszystkich mozliwych liczb

    for liczba in zbior:
        ile[liczba] += 1


    for i in range(1, s+1):
        if ile[i] > 0:
            print(f"Rozpatrujemy liczbe {i}")
            for j in range(0, s +1):
                if(DP2[j] == 0): #jesli jeszcze nie potrafimy stworzyc liczby j
                    C[j] = 100000 #potrzebujemy nieskonczenie wiele elementow i aby ja stworzyc
                else: #jesli juz potrafimy stworzyc liczbe j no to nie potrzebujemy zadnego elementu i aby ja stworzyc
                    C[j] = 0

            for j in range(0, s - i + 1):
                C[j + i] = min(C[i+j], C[j] + 1)
            print(f"tyle liczb {i} potrzebujemy aby stworzyc kolejne liczby: {C}")
            for j in range(0,s + 1):
                if C[j] <= ile[i]: #Jesli mamy wystarczajaca ilosc liczb i aby stworzyć liczbe j no to znaczy ze mozemy ja stworzyc
                    DP2[j] = 1
            print(DP2)

    print(DP2)
    print(DP2[cel])



liczby = [int(x) for x in input("Podaj zbior liczb: ").split()]
cel = int(input("Podaj liczbe ktora chcesz stworzyc z podanego zbioru: "))




#suma_1(liczby,cel)
suma_2(liczby, cel)



limit = int(input("Podaj maksymalna wagę "))
wagi = [int(x) for x in input("Podaj wagi ").split()]
wartosci = [int(x) for x in input("Podaj wartoci ").split()]
DP = [0] * (limit + 1) # Dp przechowuje maksymalna wartosc przedmiotow o sumarycznej
#masie i DP[5] -> maksymalna wartosc przedmiotow o lacznej masie 5
for i in range(len(wagi)): #iterujemy sie po kazdym przedmiocie
    for j in range(limit - wagi[i], -1, -1): #schodzimy w dół aby nie
    #dodac jednego elementu do plecaka kilka razy!
    #aktualizujemy lub nie maksymalna wartosc dla  kazdej wagi jaka mozemy uzyskać
        DP[j+wagi[i]] = max(DP[j+wagi[i]], DP[j] + wartosci[i])
    print(DP)

suma_wartosci = sum(wartosci)

DP2 = [limit+1] * (suma_wartosci + 1) # kazdy element DP przechowuje minimalna wage dla posiadania wartosci i
# DP2[5] -> min waga ktora da wartosc 5
DP2[0] = 0
for i in range(len(wartosci)):
    for j in range(suma_wartosci - wartosci[i], -1, -1):
        DP2[j+wartosci[i]] = min(DP2[j+wartosci[i]], DP2[j] + wagi[i])

    print(DP2)

print(DP[-1])

for i in range(suma_wartosci,-1,-1):
    if DP2[i] <= limit:
        print(i)
        break
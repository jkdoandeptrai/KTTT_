w = ['010', '0001', '0110','1100','00011','00110','11110','101011']
t = ['10','101','100']
def tu_ma(w):
    # buoc 1
    S0 = w
    X = []
    X.append(S0)
    S1 = []
    # Tim S1
    for wi in S0:
        for wj in S0:
            if wi == wj:
                pass
            else:
                if wi == wj[ : len(wi)] and len(wi) < len(wj):
                    S1.append( wj[ len(wi): ] )
                elif wj == wi[ : len(wj)] and len(wi) > len(wj):
                    S1.append(  wi[len(wj) :])
    if len(S1) == 0:
        return "Bo ma tach duoc"
    S1 = set(S1)
    S1 = list(S1)
    X.append(S1)
    checking = True
    while checking:
        temp = []
        # so sanh S(k) voi S(k-1)
        for wi in  S0:
            for wj in X[len(X) -1]:
                if wi == wj:
                    pass
                elif wj == wi[ : len(wj)] and len(wi) > len(wj):
                    temp.append(  wi[len(wj) :])
        for wj in  X[ len(X) - 1]:
            for wi in S0:
                if wj == wi:
                    pass
                elif wi == wj[ : len(wi)] and len(wi) < len(wj):
                    temp.append( wj[ len(wi): ] )
        # check dk :
        temp = set(temp)
        temp = list(temp)
        print("S(k) =" , str(temp))
        if len(temp) == 0:
            return "Bo ma tach duoc"
        for St in X:
            if temp == St:
                return "Bo ma tach duoc"
        for i in w:
            if i in temp:
                return "Bo ma khong tach duoc"
        X.append(temp)
        print(X) 
print(tu_ma(w))
            
            
        



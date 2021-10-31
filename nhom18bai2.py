# Bai 2: Viết chương trình để thực hiện tính lượng tin của 1 nguồn tin gồm một dãy : Nhóm thực hiện: Nhóm 18
# các ký tự.
import math
# nhập dãy kí tự:
seqOfbit = [bit for bit in input("Nhap day ki tu: ")]     
#---------------------------------------------------# 
def I_xi(x,base):
    return -math.log(x,base)
#---------------------------------------------------#
def luongTin(seq : list ,base = '2'):                                      # ham tinh lương tin:
    setOfSeq = set(seq)                                                    # luu nhung ki tu khac nhau
    unitOfI = ''
    ### xac dinh don vi cua luong tin I
    # base = 2 or 10 or e
    if base == "2": 
        unitOfI = "(bit)"
        base = 2
    elif base.lower() == 'e':
        unitOfI = "(nat)"
        base = math.e
    elif base =='10':
        unitOfI = "(hartley)"
        base = 10
    else :
        print("Loi co so, xin thu lai!")
        return None 
    ### moi phan tu trong freqOf_xi chua 3 phan tu:
    ###                                             1: I(xi)
    ###                                             2: P(xi)*I(xi)
    ###                                             3: xi
    freqOf_xi = sorted(
        [ 
            # P(xi) = seq.count(i)/len(seq) :
            [I_xi ( seq.count(i)/len(seq) ,base),I_xi (seq.count(i)/len(seq)
            ,base)*seq.count(i)/len(seq), i]
            for i in setOfSeq 
        ]
    , key = lambda x: x[1]  )
    ### Luu luong tin trung binh:
    averageOfI = sum(i[1] for i in freqOf_xi )
    # In ra man hinh ket qua:
    for Ixi in freqOf_xi:
        print(f'Luong tin cua  \'{Ixi[2]}\'    : {abs(Ixi[0].__round__(5))}  {unitOfI} ')
    # In luong tin trung binh ra man hinh:
    print(f'Luong tin trung binh  : {averageOfI.__round__(5)}  {unitOfI}')
x = input("Nhap co so(2,e,10) : ")
luongTin(seqOfbit,x)


#Mai Ngọc Đoàn và nhóm 18
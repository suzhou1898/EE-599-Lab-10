import random
import os
for i in range(10):
    vn=random.randint(3,15)
    en=random.randint(vn-1,vn*(vn-1)/2)
    list1=list(range(vn))
    list2=[]
    for x in list1:
     for y in list(range(x)):
            list3=[x,y]
            list2.append(list3)

    s=random.sample(list2,en)
    print(s)
    f=open("input.txt","w")
    f.truncate()
    f.write(str(vn))
    f.write("\n")
    string1=""
    for x in s:
        string2=""
        for y in x:
            string2=string2+str(y)+","
        string1=string1+string2+" "
    f.write(string1[:len(string1)-1])
    f.close()
    os.system("g++ -std=c++11 -o test EE599_Lab10_p1_3372029142.cpp")
    os.system("./test")



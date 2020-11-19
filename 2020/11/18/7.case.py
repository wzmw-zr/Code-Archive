x = int(input())

if x<1000:
    bouns = x*0.1
    print(bouns)
elif 1001<x<2000:
    bouns = 100 + (x-1000)*0.2
    print(bouns)
else:
    bouns = 100 + 200 + (x-2000)*0.3
    print(bouns)

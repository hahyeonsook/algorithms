progresses=[93,30,55]
speeds=[1, 30, 5]
answer=[]

while progresses:
    n=0
    for i in range(len(progresses)):
        progresses[i] += speeds[i]
    while progresses[0] >= 100:
        progresses.pop(0)
        speeds.pop(0)
        n += 1
        if not progresses: break
    if n != 0: answer.append(n)
print(answer)

progresses=[93,30,55]
speeds=[1, 30, 5]
Q=[]

for p, s in zip(progresses, speeds):
    if len(Q) == 0 or Q[-1][0]<-((p-100)//s):
        print('<-?', Q[-1][0]<-((p-100)//s))
        Q.append([-((p-100)//s), 1])
        print(Q)
    else:
        Q[-1][1] += 1
        print("else:", Q)
print([q[1] for q in Q])
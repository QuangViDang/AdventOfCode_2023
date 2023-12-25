
data = open('2023_21_input.txt').read().split('\n')

def display(space, frontier):
    txt = ''
    for j in range(h):
        for i in range(w):
            if complex(i,j) not in frontier:
                txt += space[complex(i,j)]
            else:
                txt += 'O'
        txt+='\n'
    print(txt)
    
w, h = len(data[0]), len(data)
deltas = [1 + 0j, -1 + 0j, 0 + 1j, 0 - 1j]
steps = 64
space = {}
done = set()

for j in range(h):
    for i in range(w):
        space[complex(i,j)] = data[j][i]
        if data[j][i] == 'S':
            start = complex(i,j)
            space[complex(i,j)] = '.'
        
def neighs(z):    
    nexts = [z+d for d in deltas if z+d in space and space[z + d] != '#']
    for w in nexts:
        done.add(w)        
    return nexts

cur = start
done.add(cur)
frontier = [cur]

for r in range(1, steps + 1):
    newfront =[]
    while len(frontier) > 0:
        n = frontier.pop()
        newfront += [z for z in neighs(n) if z not in newfront]
    if len(newfront) == 0:
        break
    else:
        frontier = newfront.copy()  
        
print(len(frontier))
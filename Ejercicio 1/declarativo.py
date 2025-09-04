estudiantes = [
    ["Camilo", 4.5],
    ["Luis", 3.0],
    ["Sara", 4.1],
    ["Andres", 2.4]
]

n = len(estudiantes)

for i in range(n):
    for j in range(0, n - i - 1):
        if estudiantes[j][1] < estudiantes[j+1][1]:
            estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]
        elif estudiantes[j][1] == estudiantes[j+1][1] and estudiantes[j][0] > estudiantes[j+1][0]:
            estudiantes[j], estudiantes[j+1] = estudiantes[j+1], estudiantes[j]

for estudiante in estudiantes:
    print(estudiante)
